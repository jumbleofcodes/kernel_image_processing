#include "PGMHandler.h"

PGMHandler::~PGMHandler() {
    delete this->header;
    delete this->image;
}

PGMHandler::PGMHandler(Header* h) {
    this->header = new Header(h);
    this->image = new ImageTemplate<PixelGray>;
}

bool PGMHandler::readData(std::ifstream *ifs) {
    (*ifs).ignore(256, '\n');

    if (this->header->getMagicNumber() == "P2") { // P2 è ASCII PGM
        int gg;
        while ((*ifs) >> gg) {
            this->image->addPixel(PixelGray(gg));
        }
        (*ifs).close();
        return true;
    } else if (this->header->getMagicNumber() == "P5") { // P5 è PGM binario
        char c, gg;
        for (int i = 0; i < (this->header->getWidth() * this->header->getHeight()); i++) {
            (*ifs).read(&c, 1);
            gg = c;
            this->image->addPixel(PixelGray(gg));
        }
        (*ifs).close();
        return true;
    }
    else {
        (*ifs).close();
        return false;
    }
}

void PGMHandler::saveData(std::ofstream *ofs) {
    if (this->header->getMagicNumber() == "P2") { // P2 è ASCII PGM

        for (auto itr = this->image->getImageData().begin(); itr != this->image->getImageData().end(); itr++) {
            (*ofs) << (int)(*itr).getG() << std::endl;
        }
    }
    else if (this->header->getMagicNumber() == "P5") { // P5 è PGM binario

        for (auto itr = this->image->getImageData().begin(); itr != this->image->getImageData().end(); itr++) {
            (*ofs) << (*itr).getG();
        }
    }
}

void PGMHandler::applyFilter(int codice) {
    auto filtri = new KernelImageProcessing(this->header, codice);
    this->image->setImageData(filtri->convolution_process(this->image));
}
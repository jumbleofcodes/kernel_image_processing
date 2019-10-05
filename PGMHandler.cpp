#include "PGMHandler.h"

PGMHandler::~PGMHandler() {
    delete this->header;
    delete this->immagine;
}

PGMHandler::PGMHandler(Header* h) {
    this->header = new Header(h);
    this->immagine = new ImageTemplate<PixelGray>;
}

bool PGMHandler::readData(std::ifstream *ifs) {
    (*ifs).ignore(256, '\n');

    if (this->header->getMagicNumber() == "P2") { // P2 è ASCII PGM
        int gg;
        while ((*ifs) >> gg) {
            this->immagine->addPixel(PixelGray(gg));
        }
        (*ifs).close();
        return true;
    } else if (this->header->getMagicNumber() == "P5") { // P5 è PGM binario
        char c, gg;
        for (int i = 0; i < (this->header->getWidth() * this->header->getHeight()); i++) {
            (*ifs).read(&c, 1);
            gg = c;
            this->immagine->addPixel(PixelGray(gg));
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

        for (auto itr = this->immagine->getImageData().begin(); itr != this->immagine->getImageData().end(); itr++) {
            (*ofs) << (int)(*itr).getG() << std::endl;
        }
    }
    else if (this->header->getMagicNumber() == "P5") { // P5 è PGM binario

        for (auto itr = this->immagine->getImageData().begin(); itr != this->immagine->getImageData().end(); itr++) {
            (*ofs) << (*itr).getG();
        }
    }
}

void PGMHandler::applyFilter(int codice) {
    auto filtri = new KernelImageProcessing(this->header, codice);
    this->immagine->setImageData(filtri->convolution_process(this->immagine));
}
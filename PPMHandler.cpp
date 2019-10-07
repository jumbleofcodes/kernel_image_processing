#include "PPMHandler.h"

PPMHandler::~PPMHandler() {
    delete this->header;
    delete this->image;
}

PPMHandler::PPMHandler(Header* h) {
    this->header = new Header(h);
    this->image = new ImageTemplate<PixelRGB>;
}

bool PPMHandler::readData(std::ifstream *ifs) {
    (*ifs).ignore(256, '\n');

    if (this->header->getMagicNumber() == "P3") { // P3 è ASCII PPM
        int rr, gg, bb;
        while ((*ifs) >> rr >> gg >> bb) {
            this->image->addPixel(PixelRGB(rr, gg, bb));
        }
        (*ifs).close();
        return true;
    }
    else if (this->header->getMagicNumber() == "P6") { // P6 è PPM binario
        char c, rr, gg, bb;
        for (int i = 0; i < (this->header->getWidth() * this->header->getHeight()); i++) {
            (*ifs).read(&c, 1);
            rr = c;
            (*ifs).read(&c, 1);
            gg = c;
            (*ifs).read(&c, 1);
            bb = c;
            this->image->addPixel(PixelRGB(rr, gg, bb));
        }
        (*ifs).close();
        return true;
    }
    else {
        (*ifs).close();
        return false;
    }
}

void PPMHandler::saveData(std::ofstream *ofs) {
    if (this->header->getMagicNumber() == "P3") { // P3 è ASCII PPM
        // output dei pixel: PER IMMAGINI ASCII SERVONO DATI DI TIPO INT E SPAZIO TRA DATI

        for (auto itr = this->image->getImageData().begin(); itr != this->image->getImageData().end(); itr++) {
            (*ofs) << (int)(*itr).getR() << " " << (int)(*itr).getG() << " " << (int)(*itr).getB() << std::endl;
        }
    }
    else if (this->header->getMagicNumber() == "P6") { // P6 è PPM binario
        // output dei pixel: PER IMMAGINI CON CODIFCA BINARIA SERVONO DATI DI TIPO UNSIGNED CHAR

        for (auto itr = this->image->getImageData().begin(); itr != this->image->getImageData().end(); itr++) {
            (*ofs) << (*itr).getR() << (*itr).getG() << (*itr).getB();
        }
    }
}

void PPMHandler::applyFilter(int code) {
    auto filtri = new KernelImageProcessing(this->header, code);
    this->image->setImageData(filtri->convolution_process(this->image));
}

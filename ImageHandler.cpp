#include "ImageHandler.h"

ImageHandler::ImageHandler(std::string nomefile) {
    this->nome = nomefile;
}

ImageHandler::~ImageHandler() {
    delete this->header;
    delete this->imgData;
}

bool ImageHandler::readFile() {
    this->header = new HeaderHandler();

    std::ifstream ifs;
    bool lettura = this->header->readHeader(&ifs, this->nome);
    if (!lettura) {
        std::cout << "Errore nella lettura dell'header" << std::endl;
        std::cout << "HeaderHandler.cpp riga 46" << std::endl;
        return false;
    }

    this->header->stampa();
    std::string tipo = this->header->getHeader()->getMagicNumber();

    if (tipo == "P3" || tipo == "P6") {
        this->imgData = new PPMHandler(this->header->getHeader());
        bool lettura_dati = this->imgData->readData(&ifs);
        if (!lettura_dati) {
            std::cout << "Errore nella lettura dei dati" << std::endl;
            std::cout << "PPMHandler.cpp riga 44" << std::endl;
            return false;
        }

    } else if (tipo == "P2" || tipo == "P5") {
        this->imgData = new PGMHandler(this->header->getHeader());
        bool lettura_dati = this->imgData->readData(&ifs);
        if (!lettura_dati) {
            std::cout << "Errore nella lettura dei dati" << std::endl;
            std::cout << "PGMHandler.cpp riga 39" << std::endl;
            return false;
        }
    }
    return true;
}

void ImageHandler::applyFilter(int i) {
    this->imgData->applyFilter(i);
}

void ImageHandler::saveFile() {
    std::ofstream ofs;
    this->header->saveHeader(&ofs, this->nome);
    this->imgData->saveData(&ofs);
    ofs.close();
}
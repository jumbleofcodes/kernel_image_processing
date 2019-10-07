#include "ImageHandler.h"

ImageHandler::ImageHandler(std::string filename) {
    this->name = filename;
}

ImageHandler::~ImageHandler() {
    delete this->header;
    delete this->imgData;
}

bool ImageHandler::readFile() {
    this->header = new HeaderHandler();

    std::ifstream ifs;
    bool reader = this->header->readHeader(&ifs, this->name);
    if (!reader) {
        std::cout << "An error occured while reading the header!" << std::endl;
        return false;
    }

    this->header->print();
    std::string tipo = this->header->getHeader()->getMagicNumber();

    if (tipo == "P3" || tipo == "P6") {
        this->imgData = new PPMHandler(this->header->getHeader());
        bool file_reader = this->imgData->readData(&ifs);
        if (!file_reader) {
            std::cout << "An error occured! File_data not read!" << std::endl;
            return false;
        }

    } else if (tipo == "P2" || tipo == "P5") {
        this->imgData = new PGMHandler(this->header->getHeader());
        bool data_reader = this->imgData->readData(&ifs);
        if (!data_reader) {
            std::cout << "An error occured! File_data not read!" << std::endl;
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
    this->header->saveHeader(&ofs, this->name);
    this->imgData->saveData(&ofs);
    ofs.close();
}
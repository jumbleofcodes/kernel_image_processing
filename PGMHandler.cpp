#include "PGMHandler.h"

PGMHandler::~PGMHandler() {
    delete this->image;
}

PGMHandler::PGMHandler(std::string fn) {
    this->fileName = fn;
    this->magicNumber = "NN";
    this->width = 0;
    this->height = 0;
    this->color = 0;
    this->image = new ImageTemplate<PixelGray>;
}

bool PGMHandler::readFile() {
    std::ifstream ifs;
    ifs.open(this->fileName);
    while (ifs.good()) {
        // Read header data
        int i = 0;
        int j;
        std::string line;
        char p;

        ifs >> this->magicNumber;

        while (this->color == 0 && i < 3) {
            ifs >> p;
            if (p == '#') {
                std::getline(ifs, line);
            } else {
                ifs.putback(p);
                ifs >> j;
                if (i == 0) {
                    this->width = j;
                } else if (i == 1) {
                    this->height = j;
                } else if (i == 2) {
                    this->color = j;
                }
                i++;
            }
        }
        // Read pixel data
        ifs.ignore(256, '\n');

        if(this->magicNumber == "P2") {
            int gg;
            while (ifs >> gg) {
                this->image->addPixel(PixelGray(gg));
            }
            ifs.close();
            return true;
        } else if (this->magicNumber == "P5") {
            char gg;
            for (int k = 0; k < this->width * this->height; k++) {
                ifs.read(&gg, 1);
                this->image->addPixel(PixelGray(gg));
            }
            ifs.close();
            return true;
        } else {
            std::cerr << "Error! Cannot read file!" << std::endl;
        }
    }
    return false;
}

void PGMHandler::saveFile() {
    std::ofstream ofs;

    if (this->magicNumber == "P2") {
        ofs.open(this->fileName, std::ofstream::out);

        ofs << this->magicNumber << std::endl;
        ofs << this->width << " " << this->height << std::endl;
        ofs << this->color << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << (int)itr.getG() << std::endl;
        }
        ofs.close();
    }

    else if (this->magicNumber == "P5") {
        ofs.open(this->fileName, std::ios::binary);

        ofs << this->magicNumber << std::endl;
        ofs << this->width << " " << this->height << std::endl;
        ofs << this->color << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << itr.getG();
        }
        ofs.close();

    } else {
        std::cerr << "Error! Cannot save file!" << std::endl;
    }
}

void PGMHandler::applyFilter(int code) {
    auto filter = KernelImageProcessing(this->width, this->height, this->color);
    this->image->setImageData(filter.convolution_process(code, this->image));
}
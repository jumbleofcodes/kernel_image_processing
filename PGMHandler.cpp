#include "PGMHandler.h"

PGMHandler::~PGMHandler() {
    delete this->image;
}

PGMHandler::PGMHandler(std::string fn) {
    this->fileName = fn;
    /*this->magicNumber = "NN";
    this->width = 0;
    this->height = 0;
    this->color = 0;
    this->image = new ImageTemplate<PixelGray>;*/
}

bool PGMHandler::readFile() {
    std::string magicNumber;
    int width = 0;
    int height = 0;
    int color = 0;
    std::ifstream ifs;
    ifs.open(this->fileName);
    while (ifs.good()) {
        // Read header data
        int i = 0;
        int j;
        std::string line;
        char p;

        ifs >> magicNumber;

        while (color == 0 && i < 3) {
            ifs >> p;
            if (p == '#') {
                std::getline(ifs, line);
            } else {
                ifs.putback(p);
                ifs >> j;
                if (i == 0) {
                    width = j;
                } else if (i == 1) {
                    height = j;
                } else if (i == 2) {
                    color = j;
                }
                i++;
            }
        }

        this->image = new ImageTemplate<PixelGray>(magicNumber, width, height, color);

        // Read pixel data
        ifs.ignore(256, '\n');

        if(magicNumber == "P2") {
            int gg;
            while (ifs >> gg) {
                this->image->addPixel(PixelGray(gg));
            }
            ifs.close();
            return true;
        } else if (magicNumber == "P5") {
            char gg;
            for (int k = 0; k < width * height; k++) {
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

    if (this->image->getMagicNumber() == "P2") {
        ofs.open(this->fileName, std::ofstream::out);

        ofs << this->image->getMagicNumber() << std::endl;
        ofs << this->image->getWidth() << " " << this->image->getHeight() << std::endl;
        ofs << this->image->getColor() << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << (int)itr.getG() << std::endl;
        }
        ofs.close();
    }

    else if (this->image->getMagicNumber() == "P5") {
        ofs.open(this->fileName, std::ios::binary);

        ofs << this->image->getMagicNumber() << std::endl;
        ofs << this->image->getWidth() << " " << this->image->getHeight() << std::endl;
        ofs << this->image->getColor() << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << itr.getG();
        }
        ofs.close();

    } else {
        std::cerr << "Error! Cannot save file!" << std::endl;
    }
}

void PGMHandler::applyFilter(Filtro code) {
    auto filter = KernelImageProcessing();
    // auto filter = KernelImageProcessing(this->image->getWidth(), this->image->getHeight(), this->image->getColor());
    this->image->setImageData(filter.convolution_process(code, this->image));
}
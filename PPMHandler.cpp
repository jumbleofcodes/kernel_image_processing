#include "PPMHandler.h"

PPMHandler::~PPMHandler() {
    delete this->image;
}

PPMHandler::PPMHandler(std::string fn) {
    this->fileName = fn;
    this->magicNumber = "NN";
    this->width = 0;
    this->height = 0;
    this->color = 0;
    this->image = new ImageTemplate<PixelRGB>;
}

bool PPMHandler::readFile() {
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

        if (this->magicNumber == "P3") {
            int rr, gg, bb;
            while (ifs >> rr >> gg >> bb) {
                this->image->addPixel(PixelRGB(rr, gg, bb));
            }
            ifs.close();
            return true;

        } else if (this->magicNumber == "P6") {
            char c, rr, gg, bb;
            for (int i = 0; i < (this->width * this->height); i++) {
                ifs.read(&c, 1);
                rr = c;
                ifs.read(&c, 1);
                gg = c;
                ifs.read(&c, 1);
                bb = c;
                this->image->addPixel(PixelRGB(rr, gg, bb));
            }
            ifs.close();
            return true;

        } else {
            std::cerr << "Error! Cannot read file!" << std::endl;
        }
    }
    return false;
}

void PPMHandler::saveFile() {
    std::ofstream ofs;
    if (this->magicNumber != "P3" && this->magicNumber != "P6") {
        std::cerr << "Error! Cannot save file!" << std::endl;
        return;
    }

    else if (this->magicNumber == "P3") {
        ofs.open(this->fileName, std::ofstream::out);

        ofs << this->magicNumber << std::endl;
        ofs << this->width << " " << this->height << std::endl;
        ofs << this->color << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << (int)itr.getR() << " " << (int)itr.getG() << " " << (int)itr.getB() << std::endl;
        }
        ofs.close();
    }

    else if (this->magicNumber == "P6") {
        ofs.open(this->fileName, std::ios::binary);

        ofs << this->magicNumber << std::endl;
        ofs << this->width << " " << this->height << std::endl;
        ofs << this->color << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << itr.getR() << itr.getG() << itr.getB();
        }
        ofs.close();
    }
}

void PPMHandler::applyFilter(int code) {
    auto filter = new KernelImageProcessing(code, this->width, this->height, this->color);
    this->image->setImageData(filter->convolution_process(this->image));
}

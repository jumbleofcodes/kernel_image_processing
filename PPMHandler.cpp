#include "PPMHandler.h"

PPMHandler::~PPMHandler() {
    delete this->image;
}

PPMHandler::PPMHandler(std::string fn) {
    this->fileName = fn;
    /*this->magicNumber = "NN";
    this->width = 0;
    this->height = 0;
    this->color = 0;
    this->image = new ImageTemplate<PixelRGB>;*/
}

bool PPMHandler::readFile() {
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

        this->image = new ImageTemplate<PixelRGB>(magicNumber, width, height, color);

        // Read pixel data
        ifs.ignore(256, '\n');

        if (magicNumber == "P3") {
            int rr, gg, bb;
            while (ifs >> rr >> gg >> bb) {
                this->image->addPixel(PixelRGB(rr, gg, bb));
            }
            ifs.close();
            return true;

        } else if (magicNumber == "P6") {
            char c, rr, gg, bb;
            for (int i = 0; i < (width * height); i++) {
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

    if (this->image->getMagicNumber() == "P3") {
        ofs.open(this->fileName, std::ofstream::out);

        ofs << this->image->getMagicNumber() << std::endl;
        ofs << this->image->getWidth() << " " << this->image->getHeight() << std::endl;
        ofs << this->image->getColor() << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << (int)itr.getR() << " " << (int)itr.getG() << " " << (int)itr.getB() << std::endl;
        }
        ofs.close();
    }

    else if (this->image->getMagicNumber() == "P6") {
        ofs.open(this->fileName, std::ios::binary);

        ofs << this->image->getMagicNumber() << std::endl;
        ofs << this->image->getWidth() << " " << this->image->getHeight() << std::endl;
        ofs << this->image->getColor() << std::endl;

        for (auto itr : this->image->getImageData()) {
            ofs << itr.getR() << itr.getG() << itr.getB();
        }
        ofs.close();

    } else {
        std::cerr << "Error! Cannot save file!" << std::endl;
    }
}

void PPMHandler::applyFilter(Filtro code) {
    auto filter = KernelImageProcessing();
    // auto filter = KernelImageProcessing(this->image->getWidth(), this->image->getHeight(), this->image->getColor());
    this->image->setImageData(filter.convolution_process(code, this->image));
}
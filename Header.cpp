#include "Header.h"

Header::Header(std::string mn, int w, int h, int c) {
    this->magicNumber = mn;
    this->width = w;
    this->height = h;
    this->color = c;
}

Header::Header(Header *h) {
    this->magicNumber = h->getMagicNumber();
    this->width = h->getWidth();
    this->height = h->getHeight();
    this->color = h->getColor();
}

void Header::print() {
    std::cout << "Magic number: " << this->magicNumber << std::endl;
    // for (auto itr = this->commenti.begin(); itr < this->commenti.end(); itr++) {
    //     std::cout << (*itr) << std::endl;
    // }
    std::cout << "Dimensioni: " << this->width << " x " << this->height << std::endl;
    std::cout << "Range colori: " << this->color << std::endl;
}

// void Header::addComment(std::string comm) {
//     this->commenti.push_back(comm);
// }

// std::string Header::getComment(int index) {
//     return this->commenti[index];
// }

// int Header::commentiSize() {
//     return this->commenti.size();
// }

const std::string &Header::getMagicNumber() const {
    return magicNumber;
}

void Header::setMagicNumber(const std::string &magicNumber) {
    Header::magicNumber = magicNumber;
}

int Header::getWidth() const {
    return width;
}

void Header::setWidth(int width) {
    Header::width = width;
}

int Header::getHeight() const {
    return height;
}

void Header::setHeight(int height) {
    Header::height = height;
}

int Header::getColor() const {
    return color;
}

void Header::setColor(int color) {
    Header::color = color;
}

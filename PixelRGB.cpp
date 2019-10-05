#include "PixelRGB.h"

PixelRGB::PixelRGB(char rr, char gg, char bb) {
    this->r = (unsigned char)rr;
    this->g = (unsigned char)gg;
    this->b = (unsigned char)bb;
}

PixelRGB::PixelRGB(int rr, int gg, int bb) {
    this->r = (unsigned char)rr;
    this->g = (unsigned char)gg;
    this->b = (unsigned char)bb;
}

unsigned char PixelRGB::getR() const {
    return r;
}

unsigned char PixelRGB::getG() const {
    return g;
}

unsigned char PixelRGB::getB() const {
    return b;
}
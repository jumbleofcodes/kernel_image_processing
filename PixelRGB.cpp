#include "PixelRGB.h"

PixelRGB::PixelRGB(char rr, char gg, char bb) {
    this->r = (unsigned char)rr;
    this->g = (unsigned char)gg;
    this->b = (unsigned char)bb;
}

PixelRGB::PixelRGB(int rr, int gg, int bb) {
    if (rr < 0) {
        rr = 0;
    } else if (rr > 255) {
        rr = 255;
    }
    this->r = (unsigned char)rr;
    if (gg < 0) {
        gg = 0;
    } else if (rr > 255) {
        gg = 255;
    }
    this->g = (unsigned char)gg;
    if (bb < 0) {
        bb = 0;
    } else if (rr > 255) {
        bb = 255;
    }
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
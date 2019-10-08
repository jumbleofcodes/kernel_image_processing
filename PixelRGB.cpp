#include "PixelRGB.h"

PixelRGB::PixelRGB(char rr, char gg, char bb) {
    int rrr = (256 + (int)rr) % 256;
    this->r = (unsigned char)rrr;
    int ggg = (256 + (int)gg) % 256;
    this->g = (unsigned char)ggg;
    int bbb = (256 + (int)bb) % 256;
    this->b = (unsigned char)bbb;
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
    } else if (gg > 255) {
        gg = 255;
    }
    this->g = (unsigned char)gg;
    if (bb < 0) {
        bb = 0;
    } else if (bb > 255) {
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
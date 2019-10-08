#include "PixelRGB.h"

PixelRGB::PixelRGB(char rr, char gg, char bb, int maxValue) {
    int rrr = (maxValue + (int)rr) % maxValue;
    this->r = (unsigned char)rrr;
    int ggg = (maxValue + (int)gg) % maxValue;
    this->g = (unsigned char)ggg;
    int bbb = (maxValue + (int)bb) % maxValue;
    this->b = (unsigned char)bbb;
}

PixelRGB::PixelRGB(int rr, int gg, int bb, int maxValue) {
    if (rr < 0) {
        rr = 0;
    } else if (rr > (maxValue - 1)) {
        rr = maxValue - 1;
    }
    this->r = (unsigned char)rr;
    if (gg < 0) {
        gg = 0;
    } else if (gg > (maxValue - 1)) {
        gg = maxValue - 1;
    }
    this->g = (unsigned char)gg;
    if (bb < 0) {
        bb = 0;
    } else if (bb > (maxValue - 1)) {
        bb = maxValue - 1;
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
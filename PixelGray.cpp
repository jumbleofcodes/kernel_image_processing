#include "PixelGray.h"

PixelGray::PixelGray(char gg) {
    int ggg = (256 + (int)gg) % 256;
    this->g = (unsigned char)ggg;
}

PixelGray::PixelGray(int gg) {
    if (gg < 0) {
        gg = 0;
    } else if (gg > 255) {
        gg = 255;
    }
    this->g = (unsigned char)gg;
}

unsigned char PixelGray::getG() const {
    return g;
}
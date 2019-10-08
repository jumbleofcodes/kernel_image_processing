#include "PixelGray.h"

PixelGray::PixelGray(char gg) {
    this->g = (unsigned char)gg;
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
#include "PixelGray.h"

PixelGray::PixelGray(char gg) {
    this->g = (unsigned char)gg;
}

PixelGray::PixelGray(int gg) {
    this->g = (unsigned char)gg;
}

unsigned char PixelGray::getG() const {
    return g;
}
#include "PixelGray.h"

PixelGray::PixelGray(char gg, int maxValue) {
    int ggg = (maxValue + (int)gg) % maxValue;
    this->g = (unsigned char)ggg;
}

PixelGray::PixelGray(int gg, int maxValue) {
    if (gg < 0) {
        gg = 0;
    } else if (gg > (maxValue - 1)) {
        gg = maxValue - 1;
    }
    this->g = (unsigned char)gg;
}

unsigned char PixelGray::getG() const {
    return g;
}
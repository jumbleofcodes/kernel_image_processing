#ifndef KERNEL_IMAGE_PROCESSING_PIXELRGB_H
#define KERNEL_IMAGE_PROCESSING_PIXELRGB_H


class PixelRGB {
public:
    PixelRGB(char rr, char gg, char bb);
    PixelRGB(int rr, int gg, int bb);
    unsigned char getR() const;
    unsigned char getG() const;
    unsigned char getB() const;

private:
    unsigned char r, g, b;
};

#endif //KERNEL_IMAGE_PROCESSING_PIXELRGB_H

#ifndef KERNEL_IMAGE_PROCESSING_PIXELGRAY_H
#define KERNEL_IMAGE_PROCESSING_PIXELGRAY_H


class PixelGray {
public:
    explicit PixelGray(char gg, int maxValue);
    explicit PixelGray(int gg, int maxValue);

    unsigned char getG() const;

private:
    unsigned char g;
};


#endif //KERNEL_IMAGE_PROCESSING_PIXELGRAY_H

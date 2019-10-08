#ifndef KERNEL_IMAGE_PROCESSING_PGMHANDLER_H
#define KERNEL_IMAGE_PROCESSING_PGMHANDLER_H


#include "ImageTemplate.h"
#include "PixelGray.h"
#include "KernelImageProcessing.h"
#include "ImageHandler.h"
#include <fstream>
#include <string>
#include <iostream>

class PGMHandler: public ImageHandler {
public:
    explicit PGMHandler(std::string fn);
    bool readFile() override;
    void saveFile() override;
    ~PGMHandler() override;

    void applyFilter(int code) override;

private:
    std::string fileName;
    std::string magicNumber;
    int width, height, color;
    ImageTemplate<PixelGray>* image;
};


#endif //KERNEL_IMAGE_PROCESSING_PGMHANDLER_H

#ifndef KERNEL_IMAGE_PROCESSING_PPMHANDLER_H
#define KERNEL_IMAGE_PROCESSING_PPMHANDLER_H


#include "ImageTemplate.h"
#include "PixelRGB.h"
#include "KernelImageProcessing.h"
#include "ImageHandler.h"
#include <fstream>
#include <string>
#include <iostream>

class PPMHandler : public ImageHandler {
public:
    explicit PPMHandler(std::string fn);
    bool readFile() override;
    void saveFile() override;
    ~PPMHandler() override;
    void applyFilter(Filtro code) override;

private:
    std::string fileName;
    ImageTemplate<PixelRGB> *image{};
};


#endif //KERNEL_IMAGE_PROCESSING_PPMHANDLER_H

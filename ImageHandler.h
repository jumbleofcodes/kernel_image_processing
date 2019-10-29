#ifndef KERNEL_IMAGE_PROCESSING_IMAGEHANDLER_H
#define KERNEL_IMAGE_PROCESSING_IMAGEHANDLER_H


#include "KernelImageProcessing.h"

class ImageHandler {
public:
    virtual ~ImageHandler() = default;
    virtual bool readFile() = 0;
    virtual void saveFile() = 0;
    virtual void applyFilter(Filtro code) = 0;
};


#endif //KERNEL_IMAGE_PROCESSING_IMAGEHANDLER_H

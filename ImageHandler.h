#ifndef KERNEL_IMAGE_PROCESSING_IMAGEHANDLER_H
#define KERNEL_IMAGE_PROCESSING_IMAGEHANDLER_H


#include "DataHandler.h"
#include "PPMHandler.h"
#include "PGMHandler.h"
#include "HeaderHandler.h"
#include <fstream>
#include <string>

class ImageHandler {
public:
    explicit ImageHandler(std::string filename);
    ~ImageHandler();
    bool readFile();
    void applyFilter(int i);
    void saveFile();

private:
    std::string name;
    HeaderHandler* header;
    DataHandler* imgData;
};



#endif //KERNEL_IMAGE_PROCESSING_IMAGEHANDLER_H

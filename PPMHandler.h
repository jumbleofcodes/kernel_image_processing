#ifndef KERNEL_IMAGE_PROCESSING_PPMHANDLER_H
#define KERNEL_IMAGE_PROCESSING_PPMHANDLER_H


#include "ImageTemplate.h"
#include "KernelImageProcessing.h"
#include "PixelRGB.h"
#include "DataHandler.h"
#include "Header.h"
#include <fstream>

class PPMHandler: public DataHandler {
public:
    explicit PPMHandler(Header* h);
    bool readData(std::ifstream* ifs) override;
    void saveData(std::ofstream* ofs) override;
    ~PPMHandler() override;

    void applyFilter(int codice) override;

private:
    Header* header;
    ImageTemplate<PixelRGB>* immagine;
};



#endif //KERNEL_IMAGE_PROCESSING_PPMHANDLER_H

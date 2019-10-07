#ifndef KERNEL_IMAGE_PROCESSING_PGMHANDLER_H
#define KERNEL_IMAGE_PROCESSING_PGMHANDLER_H


#include "ImageTemplate.h"
#include "PixelGray.h"
#include "KernelImageProcessing.h"
#include "DataHandler.h"
#include "Header.h"
#include <fstream>

class PGMHandler: public DataHandler {
public:
    explicit PGMHandler(Header* h);
    bool readData(std::ifstream* ifs) override;
    void saveData(std::ofstream* ofs) override;
    ~PGMHandler() override;

    void applyFilter(int codice) override;

private:
    Header* header;
    ImageTemplate<PixelGray>* image;
};


#endif //KERNEL_IMAGE_PROCESSING_PGMHANDLER_H

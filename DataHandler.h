#ifndef KERNEL_IMAGE_PROCESSING_DATAHANDLER_H
#define KERNEL_IMAGE_PROCESSING_DATAHANDLER_H


#include <fstream>

class DataHandler {
public:
    virtual ~DataHandler() = default;
    virtual bool readData(std::ifstream* ifs) = 0;
    virtual void saveData(std::ofstream* ofs) = 0;
    virtual void applyFilter(int codice) = 0;
};


#endif //KERNEL_IMAGE_PROCESSING_DATAHANDLER_H

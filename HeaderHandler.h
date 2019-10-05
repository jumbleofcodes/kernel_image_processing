#ifndef KERNEL_IMAGE_PROCESSING_HEADERHANDLER_H
#define KERNEL_IMAGE_PROCESSING_HEADERHANDLER_H


#include <string>
#include <iostream>
#include <fstream>
#include "Header.h"

class HeaderHandler {
public:
    HeaderHandler();
    ~HeaderHandler();
    bool readHeader(std::ifstream* ifs, std::string n);
    void saveHeader(std::ofstream* ofs, std::string n);

    Header *getHeader() const;

    void stampa();

private:
    Header* header;
};
#endif //KERNEL_IMAGE_PROCESSING_HEADERHANDLER_H

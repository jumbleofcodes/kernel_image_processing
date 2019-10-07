#include "HeaderHandler.h"

HeaderHandler::HeaderHandler() {
    this->header = new Header("NN", 0, 0, 0);
}

HeaderHandler::~HeaderHandler() {
    delete this->header;
}

bool HeaderHandler::readHeader(std::ifstream *ifs, std::string n) {
    (*ifs).open(n);

    while ((*ifs).good()) {
        int i = 0;
        int j;
        std::string mn, line;
        char spy;
        (*ifs) >> mn;
        this->header->setMagicNumber(mn);

        while ((this->header->getColor() == 0) && (i < 3)) {
            (*ifs) >> spy;
            if (spy == '#') {
                // se c'è il carattere '#' salta la riga
                std::getline((*ifs), line);
                // this->header->addComment(line);
                std::cout << "Comment: " << spy << line << std::endl;
            } else {
                (*ifs).putback(spy);
                (*ifs) >> j;
                if(i == 0) {
                    this->header->setWidth(j);
                } else if (i == 1) {
                    this->header->setHeight(j);
                } else if (i == 2) {
                    this->header->setColor(j);
                    return true;
                }
                i++;
            }
        }
    }
    return false;
}

void HeaderHandler::saveHeader(std::ofstream *ofs, std::string n) {
    if (this->header->getMagicNumber() == "P2" || this->header->getMagicNumber() == "P3") {
        (*ofs).open(n, std::ofstream::out);
    } else if (this->header->getMagicNumber() == "P5" || this->header->getMagicNumber() == "P6") {
        (*ofs).open(n, std::ios::binary);
    } else {
        std::cout << "Not saved, lost file!" << std::endl;
        return;
    }
    (*ofs) << this->header->getMagicNumber() << std::endl;

    (*ofs) << this->header->getWidth() << " " << this->header->getHeight() << std::endl;
    (*ofs) << this->header->getColor() << std::endl;
    // for (int i = 0; i < this->header->commentiSize(); i++){
    // TODO: rimettere i commenti nelle immagini se possibile
    // }
}

Header *HeaderHandler::getHeader() const {
    return header;
}


void HeaderHandler::print() {
    this->header->print();
}

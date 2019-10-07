//
// Created by Monica Eron on 05/10/2019.
//

#ifndef KERNEL_IMAGE_PROCESSING_HEADER_H
#define KERNEL_IMAGE_PROCESSING_HEADER_H


#include <iostream>
#include <string>
#include <vector>

class Header {
public:
    Header(std::string mn, int w, int h, int c);
    explicit Header(Header* h);
    void print();

    // void addComment(std::string comm);
    // std::string getComment(int index);
    // int commentiSize();

    const std::string &getMagicNumber() const;
    void setMagicNumber(const std::string &magicNumber);
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    int getColor() const;
    void setColor(int color);

private:
    std::string magicNumber;
    // std::vector<std::string> commenti;
    int width, height, color;
};

#endif //KERNEL_IMAGE_PROCESSING_HEADER_H

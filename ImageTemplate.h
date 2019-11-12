#ifndef KERNEL_IMAGE_PROCESSING_IMAGETEMPLATE_H
#define KERNEL_IMAGE_PROCESSING_IMAGETEMPLATE_H

#include <vector>
#include <string>
#include <exception>

template<typename T>
class ImageTemplate {
public:

    ImageTemplate(const std::string &mn, int w, int h, int c) {
        this->magicNumber = mn;
        this->width = w;
        this->height = h;
        this->color = c;
    }

    const std::vector<T> &getImageData() const {
        return imageData;
    }

    void setImageData(const std::vector<T> &newImgData) {
        this->imageData.clear();
        this->imageData = newImgData;
    }

    void addPixel(T p) {
        this->imageData.push_back(p);
    }

    T getPixel(int pos) {
        return this->imageData[pos];
    }

    T getPixel(int x, int y) {
        return this->imageData[x * this->width + y];
    }

    void setPixel(int pos, T p) {
        this->imageData[pos] = p;
    }

    void setPixel(int x, int y, T p) {
        this->imageData[x * this->width + y] = p;
    }

    const std::string &getMagicNumber() const {
        return magicNumber;
    }

    void setMagicNumber(const std::string &mn) {
        ImageTemplate::magicNumber = mn;
    }

    int getWidth() const {
        return width;
    }

    void setWidth(int w) {
        ImageTemplate::width = w;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int h) {
        ImageTemplate::height = h;
    }

    int getColor() const {
        return color;
    }

    void setColor(int c) {
        ImageTemplate::color = c;
    }

private:
    std::vector<T> imageData;
    std::string magicNumber;
    int width{}, height{}, color{};
};

#endif //KERNEL_IMAGE_PROCESSING_IMAGETEMPLATE_H

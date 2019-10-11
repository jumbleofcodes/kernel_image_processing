#ifndef KERNEL_IMAGE_PROCESSING_IMAGETEMPLATE_H
#define KERNEL_IMAGE_PROCESSING_IMAGETEMPLATE_H

#include <vector>

template<typename T>
class ImageTemplate {
public:

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

private:
    std::vector<T> imageData;
};

#endif //KERNEL_IMAGE_PROCESSING_IMAGETEMPLATE_H

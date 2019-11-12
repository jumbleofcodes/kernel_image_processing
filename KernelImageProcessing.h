#ifndef KERNEL_IMAGE_PROCESSING_KERNELIMAGEPROCESSING_H
#define KERNEL_IMAGE_PROCESSING_KERNELIMAGEPROCESSING_H


#include "ImageTemplate.h"
#include "PixelRGB.h"
#include "PixelGray.h"

enum class Filtro {
    Identity, Emboss, Sharpen, Outline, BoxBlur, GaussianBlur
};

class KernelImageProcessing {
public:

    double k_emboss[3][3] = {{-2, -1, 0},
                             {-1, 1,  1},
                             {0,  1,  2}};
    double k_sharpen[3][3] = {{0,  -1, 0},
                              {-1, 5,  -1},
                              {0,  -1, 0}};
    double k_outline[3][3] = {{-1, -1, -1},
                              {-1, 8,  -1},
                              {-1, -1, -1}};
    double k_box_blur[3][3] = {{1, 1, 1},
                               {1, 1, 1},
                               {1, 1, 1}};
    double k_gaussian_blur[3][3] = {{1, 2, 1},
                                    {2, 4, 2},
                                    {1, 2, 1}};
    double k_identity[3][3] = {{0, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0}};

    std::vector<PixelGray> convolution_process(Filtro filterCode, ImageTemplate<PixelGray> *img);
    std::vector<PixelRGB> convolution_process(Filtro filterCode, ImageTemplate<PixelRGB> *img);

protected:
    void selectFilter(Filtro fc);

private:
    double kernel[3][3]{};
    double denominator{};
};

#endif //KERNEL_IMAGE_PROCESSING_KERNELIMAGEPROCESSING_H

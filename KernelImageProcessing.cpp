#include "KernelImageProcessing.h"


void KernelImageProcessing::selectFilter(Filtro fc) {
    switch (fc) {

        case Filtro::Emboss:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_emboss[i][j];
                }
            }
            this->denominator = 1;
            break;

        case Filtro::Sharpen:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_sharpen[i][j];
                }
            }
            this->denominator = 1;
            break;

        case Filtro::Outline:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_outline[i][j];
                }
            }
            this->denominator = 1;
            break;

        case Filtro::BoxBlur:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_box_blur[i][j];
                }
            }
            this->denominator = 9;
            break;

        case Filtro::GaussianBlur:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_gaussian_blur[i][j];
                }
            }
            this->denominator = 16;
            break;

        default: // identity
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_identity[i][j];
                }
            }
            this->denominator = 1;
            break;
    }
}

std::vector<PixelGray> KernelImageProcessing::convolution_process(Filtro filterCode, ImageTemplate<PixelGray> *img) {
    this->selectFilter(filterCode);

    std::vector<PixelGray> img_processed;

    for (int i = 0; i < img->getHeight(); i++) {
        for (int j = 0; j < img->getWidth(); j++) {
            double sum = 0;
            if (j != 0 && j != img->getWidth() - 1 && i != 0 && i != img->getHeight() - 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        try {
                            sum += img->getPixel(i + k - 1, j + l - 1).getG() *
                                   (this->kernel[k][l] / this->denominator);
                        }
                        catch (const char *msg) {
                            std::cerr << msg << std::endl;
                        }
                    }
                }
            }
            if (sum > img->getColor()) {
                sum = img->getColor();
            }
            PixelGray p = PixelGray((int) (sum));
            img_processed.push_back(p);
        }
    }
    return img_processed;
}

std::vector<PixelRGB> KernelImageProcessing::convolution_process(Filtro filterCode, ImageTemplate<PixelRGB> *img) {
    this->selectFilter(filterCode);

    std::vector<PixelRGB> img_processed;

    for (int i = 0; i < img->getHeight(); i++) {
        for (int j = 0; j < img->getWidth(); j++) {
            double r_sum = 0;
            double g_sum = 0;
            double b_sum = 0;
            if (j != 0 && j != img->getWidth() - 1 && i != 0 && i != img->getHeight() - 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        try {
                            r_sum += img->getPixel(i + k - 1, j + l - 1).getR() *
                                     (this->kernel[k][l] / this->denominator);
                            g_sum += img->getPixel(i + k - 1, j + l - 1).getG() *
                                     (this->kernel[k][l] / this->denominator);
                            b_sum += img->getPixel(i + k - 1, j + l - 1).getB() *
                                     (this->kernel[k][l] / this->denominator);
                        }
                        catch (const char *msg) {
                            std::cerr << msg << std::endl;
                        }
                    }
                }
            }
            if (r_sum > img->getColor()) {
                r_sum = img->getColor();
            }
            if (g_sum > img->getColor()) {
                g_sum = img->getColor();
            }
            if (b_sum > img->getColor()) {
                b_sum = img->getColor();
            }
            PixelRGB p = PixelRGB((int) r_sum, (int) g_sum, (int) b_sum);
            img_processed.push_back(p);
        }
    }
    return img_processed;
}
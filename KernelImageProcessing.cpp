#include "KernelImageProcessing.h"


KernelImageProcessing::KernelImageProcessing(int w, int h, int c) {
    this->width = w;
    this->height = h;
    this->color = c;
}

void KernelImageProcessing::selectFilter(int fc) {
    switch (fc) {

        case 1: // emboss
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_emboss[i][j];
                }
            }
            this->denominator = 1;
            break;

        case 2: // sharpen
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_sharpen[i][j];
                }
            }
            this->denominator = 1;
            break;

        case 3: // outline
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_outline[i][j];
                }
            }
            this->denominator = 1;
            break;

        case 4: // box blur
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_box_blur[i][j];
                }
            }
            this->denominator = 9;
            break;

        case 5: // gaussian blur
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

std::vector<PixelGray> KernelImageProcessing::convolution_process(int filterCode, ImageTemplate<PixelGray>* img) {
    this->selectFilter(filterCode);

    std::vector<PixelGray> img_processed;

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            double sum = 0;
            if (j != 0 && j != this->width - 1 && i != 0 && i != this->height - 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        sum += img->getImageData()[(i + k - 1) * this->width + j + l - 1].getG() * (this->kernel[k][l] / this->denominator);
                    }
                }
            }
            if (sum > this->color) {
                sum = this->color;
            }
            PixelGray p = PixelGray((int)(sum));
            img_processed.push_back(p);
        }
    }
    return img_processed;
}

std::vector<PixelRGB> KernelImageProcessing::convolution_process(int filterCode, ImageTemplate<PixelRGB>* img) {
    this->selectFilter(filterCode);

    std::vector<PixelRGB> img_processed;

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            double r_sum = 0;
            double g_sum = 0;
            double b_sum = 0;
            if (j != 0 && j != this->width - 1 && i != 0 && i != this->height - 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        r_sum += img->getImageData()[(i + k - 1) * this->width + j + l - 1].getR() * (this->kernel[k][l] / this->denominator);
                        g_sum += img->getImageData()[(i + k - 1) * this->width + j + l - 1].getG() * (this->kernel[k][l] / this->denominator);
                        b_sum += img->getImageData()[(i + k - 1) * this->width + j + l - 1].getB() * (this->kernel[k][l] / this->denominator);
                    }
                }
            }
            if (r_sum > this->color) {
                r_sum = this->color;
            }
            if (g_sum > this->color) {
                g_sum = this->color;
            }
            if (b_sum > this->color) {
                b_sum = this->color;
            }
            PixelRGB p = PixelRGB((int)r_sum, (int)g_sum, (int)b_sum);
            img_processed.push_back(p);
        }
    }
    return img_processed;
}
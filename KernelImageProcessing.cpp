#include "KernelImageProcessing.h"


KernelImageProcessing::KernelImageProcessing(Header *head, int codice) {
    this->h = head;

    switch (codice) {

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

        default: // identity (nessuna operazione)
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    this->kernel[i][j] = k_identity[i][j];
                }
            }
            this->denominator = 1;
            break;
    }
}

std::vector<PixelGray> KernelImageProcessing::convolution_process(ImageTemplate<PixelGray>* img) {
    std::vector<PixelGray> img_processed;

    for (int i = 0; i < this->h->getHeight(); i++) {
        for (int j = 0; j < this->h->getWidth(); j++) {
            double sum = 0;
            if (j != 0 && j != this->h->getWidth() - 1 && i != 0 && i != this->h->getHeight() - 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        sum += img->getImageData()[(i + k - 1) * this->h->getWidth() + j + l - 1].getG() * (this->kernel[k][l] / this->denominator);
                    }
                }
            }
            if (sum < 0) {
                sum = 0;
            } else if (sum > this->h->getColor()) {
                sum = this->h->getColor();
            }
            PixelGray p = PixelGray((int)(sum));
            img_processed.push_back(p);
        }
    }
    return img_processed;
}

std::vector<PixelRGB> KernelImageProcessing::convolution_process(ImageTemplate<PixelRGB>* img) {
    std::vector<PixelRGB> img_processed;

    for (int i = 0; i < this->h->getHeight(); i++) {
        for (int j = 0; j < this->h->getWidth(); j++) {
            double r_sum = 0;
            double g_sum = 0;
            double b_sum = 0;
            if (j != 0 && j != this->h->getWidth() - 1 && i != 0 && i != this->h->getHeight() - 1) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        r_sum += img->getImageData()[(i + k - 1) * this->h->getWidth() + j + l - 1].getR() * (this->kernel[k][l] / this->denominator);
                        g_sum += img->getImageData()[(i + k - 1) * this->h->getWidth() + j + l - 1].getG() * (this->kernel[k][l] / this->denominator);
                        b_sum += img->getImageData()[(i + k - 1) * this->h->getWidth() + j + l - 1].getB() * (this->kernel[k][l] / this->denominator);
                    }
                }
            }
            if (r_sum < 0){
                r_sum = 0;
            } else if (r_sum > this->h->getColor()) {
                r_sum = this->h->getColor();
            }
            if (g_sum < 0){
                g_sum = 0;
            } else if (g_sum > this->h->getColor()) {
                g_sum = this->h->getColor();
            }
            if (b_sum < 0){
                b_sum = 0;
            } else if (b_sum > this->h->getColor()) {
                b_sum = this->h->getColor();
            }
            PixelRGB p = PixelRGB((int)r_sum, (int)g_sum, (int)b_sum);
            img_processed.push_back(p);
        }
    }
    return img_processed;
}
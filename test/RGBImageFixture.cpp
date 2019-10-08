//
// Created by 7herion on 08/10/2019.
//

#include "gtest/gtest.h"
#include "../KernelImageProcessing.h"

class RGBImageProcessingSuite: public ::testing::Test {
protected:
    RGBImageProcessingSuite() {
        this->k = new KernelImageProcessing(3, 3, 256);
        this->colorImage = new ImageTemplate<PixelRGB>;
    }

    void SetUp() override {
        for (int i = 0; i < 9; i++) {
            this->colorImage->addPixel(PixelRGB(i - 1, i, i + 1, 256));
        }
    }

    ~RGBImageProcessingSuite() override {
        delete this->k;
        delete this->colorImage;
    }

    KernelImageProcessing* k;
    ImageTemplate<PixelRGB>* colorImage;
};

TEST_F(RGBImageProcessingSuite, ColorEmbossKernelTest) {
    std::vector<PixelRGB> img_processata = this->k->convolution_process(1, this->colorImage);
    ASSERT_EQ(25, (int)(img_processata[4].getR()));
    ASSERT_EQ(28, (int)(img_processata[4].getG()));
    ASSERT_EQ(29, (int)(img_processata[4].getB()));
}
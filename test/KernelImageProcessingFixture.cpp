//
// Created by 7herion on 08/10/2019.
//

#include "gtest/gtest.h"
#include "../KernelImageProcessing.h"

class KernelProcessingSuite: public ::testing::Test {
protected:
    KernelProcessingSuite() {
        this->k = new KernelImageProcessing(3, 3, 256);
        this->grayImage = new ImageTemplate<PixelGray>;
    }

    void SetUp() override {
        for (int i = 0; i < 9; i++) {
            this->grayImage->addPixel(PixelGray(i + 1, 256));
        }
    }

    ~KernelProcessingSuite() override {
        //void TearDown() override {
        delete this->k;
        delete this->grayImage;
    }

    KernelImageProcessing* k;
    ImageTemplate<PixelGray>* grayImage;
};

TEST_F(KernelProcessingSuite, GrayEmbossKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(1, this->grayImage);
    ASSERT_EQ(29, (int)(img_processata[4].getG()));
}

TEST_F(KernelProcessingSuite, GraySharpenKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(2, this->grayImage);
    ASSERT_EQ(5, (int)(img_processata[4].getG()));
}

TEST_F(KernelProcessingSuite, GrayOutlineKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(3, this->grayImage);
    ASSERT_EQ(0, (int)(img_processata[4].getG()));
}

TEST_F(KernelProcessingSuite, GrayBoxBlurKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(4, this->grayImage);
    ASSERT_EQ(5, (int)(img_processata[4].getG()));
}

TEST_F(KernelProcessingSuite, GrayGaussBlurKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(5, this->grayImage);
    ASSERT_EQ(5, (int)(img_processata[4].getG()));
}
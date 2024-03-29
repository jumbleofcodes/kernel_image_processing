#include "gtest/gtest.h"
#include "../KernelImageProcessing.h"

class GrayImageProcessingSuite : public ::testing::Test {
protected:
    GrayImageProcessingSuite() {
        this->k = new KernelImageProcessing();
        this->grayImage = new ImageTemplate<PixelGray>("NN", 3, 3, 256);
    }

    void SetUp() override {
        for (int i = 0; i < 9; i++) {
            this->grayImage->addPixel(PixelGray(i + 1));
        }
    }

    ~GrayImageProcessingSuite() override {
        delete this->k;
        delete this->grayImage;
    }

    KernelImageProcessing *k;
    ImageTemplate<PixelGray> *grayImage;
};

TEST_F(GrayImageProcessingSuite, GrayEmbossKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(Filtro::Emboss, this->grayImage);
    ASSERT_EQ(29, (int) (img_processata[4].getG()));
}

TEST_F(GrayImageProcessingSuite, GraySharpenKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(Filtro::Sharpen, this->grayImage);
    ASSERT_EQ(5, (int) (img_processata[4].getG()));
}

TEST_F(GrayImageProcessingSuite, GrayOutlineKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(Filtro::Outline, this->grayImage);
    ASSERT_EQ(0, (int) (img_processata[4].getG()));
}

TEST_F(GrayImageProcessingSuite, GrayBoxBlurKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(Filtro::BoxBlur, this->grayImage);
    ASSERT_EQ(5, (int) (img_processata[4].getG()));
}

TEST_F(GrayImageProcessingSuite, GrayGaussBlurKernelTest) {
    std::vector<PixelGray> img_processata = this->k->convolution_process(Filtro::GaussianBlur, this->grayImage);
    ASSERT_EQ(5, (int) (img_processata[4].getG()));
}
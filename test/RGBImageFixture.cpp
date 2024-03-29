#include "gtest/gtest.h"
#include "../KernelImageProcessing.h"

class RGBImageProcessingSuite : public ::testing::Test {
protected:
    RGBImageProcessingSuite() {
        this->k = new KernelImageProcessing();
        this->colorImage = new ImageTemplate<PixelRGB>("NN", 11, 3, 256);
    }

    void SetUp() override {
        PixelRGB p0 = PixelRGB(255, 255, 255);
        PixelRGB p1 = PixelRGB(0, 120, 255);
        PixelRGB p2 = PixelRGB(120, 255, 0);
        PixelRGB p3 = PixelRGB(255, 0, 120);

        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p1);
            this->colorImage->addPixel(p0);
        }
        for (int i = 0; i < 3; i++) {
            this->colorImage->addPixel(p2);
        }
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p0);
            this->colorImage->addPixel(p3);
        }
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p1);
            this->colorImage->addPixel(p0);
        }
        this->colorImage->addPixel(p2);
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p0);
        }
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p0);
            this->colorImage->addPixel(p3);
        }
        for (int i = 0; i < 3; i++) {
            this->colorImage->addPixel(p1);
        }
        this->colorImage->addPixel(p0);
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p2);
        }
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p0);
        }
        for (int i = 0; i < 3; i++) {
            this->colorImage->addPixel(p3);
        }
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p1);
            this->colorImage->addPixel(p0);
        }
        this->colorImage->addPixel(p2);
        for (int i = 0; i < 4; i++) {
            this->colorImage->addPixel(p0);
        }
        this->colorImage->addPixel(p3);
        this->colorImage->addPixel(p0);
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p1);
            this->colorImage->addPixel(p0);
        }
        for (int i = 0; i < 3; i++) {
            this->colorImage->addPixel(p2);
        }
        for (int i = 0; i < 2; i++) {
            this->colorImage->addPixel(p0);
        }
        this->colorImage->addPixel(p3);
        this->colorImage->addPixel(p0);
    }

    ~RGBImageProcessingSuite() override {
        delete this->k;
        delete this->colorImage;
    }

    KernelImageProcessing *k;
    ImageTemplate<PixelRGB> *colorImage;
};


TEST_F(RGBImageProcessingSuite, ColorEmbossKernelTest) {
    std::vector<PixelRGB> img_processata = this->k->convolution_process(Filtro::Emboss, this->colorImage);
    ASSERT_EQ(0, (int) (img_processata[12].getR()));
    ASSERT_EQ(120, (int) (img_processata[12].getG()));
    ASSERT_EQ(255, (int) (img_processata[12].getB()));

    ASSERT_EQ(255, (int) (img_processata[14].getR()));
    ASSERT_EQ(255, (int) (img_processata[14].getG()));
    ASSERT_EQ(0, (int) (img_processata[14].getB()));
}

TEST_F(RGBImageProcessingSuite, ColorSharpenKernelTest) {
    std::vector<PixelRGB> img_processata = this->k->convolution_process(Filtro::Sharpen, this->colorImage);
    ASSERT_EQ(255, (int) (img_processata[12].getR()));
    ASSERT_EQ(255, (int) (img_processata[12].getG()));
    ASSERT_EQ(255, (int) (img_processata[12].getB()));

    ASSERT_EQ(255, (int) (img_processata[14].getR()));
    ASSERT_EQ(255, (int) (img_processata[14].getG()));
    ASSERT_EQ(255, (int) (img_processata[14].getB()));
}

TEST_F(RGBImageProcessingSuite, ColorOutlineKernelTest) {
    std::vector<PixelRGB> img_processata = this->k->convolution_process(Filtro::Outline, this->colorImage);
    ASSERT_EQ(255, (int) (img_processata[12].getR()));
    ASSERT_EQ(255, (int) (img_processata[12].getG()));
    ASSERT_EQ(0, (int) (img_processata[12].getB()));

    ASSERT_EQ(255, (int) (img_processata[14].getR()));
    ASSERT_EQ(255, (int) (img_processata[14].getG()));
    ASSERT_EQ(255, (int) (img_processata[14].getB()));
}

TEST_F(RGBImageProcessingSuite, ColorBoxBlurKernelTest) {
    std::vector<PixelRGB> img_processata = this->k->convolution_process(Filtro::BoxBlur, this->colorImage);
    ASSERT_EQ(56, (int) (img_processata[12].getR()));
    ASSERT_EQ(150, (int) (img_processata[12].getG()));
    ASSERT_EQ(255, (int) (img_processata[12].getB()));

    ASSERT_EQ(124, (int) (img_processata[14].getR()));
    ASSERT_EQ(210, (int) (img_processata[14].getG()));
    ASSERT_EQ(170, (int) (img_processata[14].getB()));
}

TEST_F(RGBImageProcessingSuite, ColorGaussianBlurKernelTest) {
    std::vector<PixelRGB> img_processata = this->k->convolution_process(Filtro::GaussianBlur, this->colorImage);
    ASSERT_EQ(95, (int) (img_processata[12].getR()));
    ASSERT_EQ(170, (int) (img_processata[12].getG()));
    ASSERT_EQ(255, (int) (img_processata[12].getB()));

    ASSERT_EQ(157, (int) (img_processata[14].getR()));
    ASSERT_EQ(221, (int) (img_processata[14].getG()));
    ASSERT_EQ(191, (int) (img_processata[14].getB()));
}
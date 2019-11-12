#include "gtest/gtest.h"
#include "../ImageTemplate.h"
#include "../PixelGray.h"

class ExceptionTestSuite : public ::testing::Test {
protected:
    ExceptionTestSuite() {
        this->grayImage = new ImageTemplate<PixelGray>("NN", 3, 3, 256);
    }

    void SetUp() override {
        for (int i = 0; i < 9; i++) {
            this->grayImage->addPixel(PixelGray(i + 1));
        }
    }

    ~ExceptionTestSuite() override {
        delete this->grayImage;
    }

    ImageTemplate<PixelGray> *grayImage;
};


TEST_F(ExceptionTestSuite, NegativeGetPositionTest) {
    EXPECT_ANY_THROW(this->grayImage->getPixel(-1););
    EXPECT_ANY_THROW(this->grayImage->getPixel(-1, 0););
}

TEST_F(ExceptionTestSuite, GetIndexOutOfBoundTest) {
    EXPECT_ANY_THROW(this->grayImage->getPixel(this->grayImage->getWidth(), this->grayImage->getHeight()););
}

TEST_F(ExceptionTestSuite, NoGetExceptionTest) {
    EXPECT_NO_THROW(this->grayImage->getPixel(this->grayImage->getWidth() * this->grayImage->getHeight() -1));
}

TEST_F(ExceptionTestSuite, NegativeSetPositionTest) {
    PixelGray p = PixelGray(0);
    EXPECT_ANY_THROW(this->grayImage->setPixel(-1, p););
}

TEST_F(ExceptionTestSuite, SetIndexOutOfBoundTest) {
    PixelGray p = PixelGray(0);
    EXPECT_ANY_THROW(this->grayImage->setPixel(this->grayImage->getWidth() * this->grayImage->getHeight(), p););
}

TEST_F(ExceptionTestSuite, NoSetExceptionTest) {
    PixelGray p = PixelGray(0);
    EXPECT_NO_THROW(this->grayImage->setPixel(5, p));
}
//
// Created by 7herion on 08/10/2019.
//

#include "gtest/gtest.h"
#include "../PixelRGB.h"
#include "../PixelGray.h"

TEST(PixelRGB, RGBMaxIntTest) {
    int r = 689;
    int g = 350;
    int b = 256;
    PixelRGB p1 = PixelRGB(r, g, b);
    EXPECT_EQ(255, (int)p1.getR());
    EXPECT_EQ(255, (int)p1.getG());
    EXPECT_EQ(255, (int)p1.getB());
}

TEST(PixelRGB, RGBNegIntTest) {
    int r = -9;
    int g = -12;
    int b = -857;
    PixelRGB p2 = PixelRGB(r, g, b);
    EXPECT_EQ(0, (int)p2.getR());
    EXPECT_EQ(0, (int)p2.getG());
    EXPECT_EQ(0, (int)p2.getB());
}

TEST(PixelGray, GrayMinCharTest) {
    char a = 0;
    PixelGray p = PixelGray(a);
    EXPECT_EQ(0, (int)p.getG());
}

TEST(PixelGray, GrayMaxCharTest) {
    char a = -1;
    PixelGray p = PixelGray(a);
    EXPECT_EQ(255, (int)p.getG());
}

TEST(PixelGray, GrayMinCharValueTest) {
    char a = -128;
    PixelGray p = PixelGray(a);
    EXPECT_EQ(128, (int)p.getG());
}

TEST(PixelGray, GrayMaxCharValueTest) {
    char a = 127;
    PixelGray p = PixelGray(a);
    EXPECT_EQ(127, (int)p.getG());
}
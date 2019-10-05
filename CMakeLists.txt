cmake_minimum_required(VERSION 3.14)
project(kernel_image_processing)

set(CMAKE_CXX_STANDARD 11)

add_executable(kernel_image_processing main.cpp ImageTemplate.h ImageHandler.cpp ImageHandler.h DataHandler.cpp DataHandler.h Header.cpp Header.h HeaderHandler.cpp HeaderHandler.h KernelImageProcessing.cpp KernelImageProcessing.h PGMHandler.cpp PGMHandler.h PixelGray.cpp PixelGray.h PixelRGB.cpp PixelRGB.h PPMHandler.cpp PPMHandler.h)
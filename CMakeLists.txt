cmake_minimum_required(VERSION 3.14)
project(kernel_image_processing)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES ImageTemplate.h
        ImageHandler.cpp ImageHandler.h
        KernelImageProcessing.cpp KernelImageProcessing.h
        PGMHandler.cpp PGMHandler.h PPMHandler.cpp PPMHandler.h
        PixelGray.cpp PixelGray.h PixelRGB.cpp PixelRGB.h)
add_executable(kernel_image_processing main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(kernel_image_processing core)
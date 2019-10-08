cmake_minimum_required(VERSION 3.14)

add_subdirectory(./lib/googletest-master/googletest/)

set(gtest_SOURCE_DIR ./lib/googletest-master/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp PixelTests.cpp)
add_executable(runProjectTests ${TEST_SOURCE_FILES})
target_link_libraries(runProjectTests gtest gtest_main core)
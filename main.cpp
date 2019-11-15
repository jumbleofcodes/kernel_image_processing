#include "ImageHandler.h"
#include "PGMHandler.h"
#include "PPMHandler.h"
#include <iostream>

int main() {
    ImageHandler *imageHandler;
    std::string dir = "../images/";
    std::string fileName;
    std::string imageType;
    std::string save;
    int filterCode;

    std::cout << "Insert name of the file: " << std::endl;
    std::cin >> fileName;

    for (int i = 0; i < 4; i++) {
        imageType.push_back(fileName[fileName.size() - 4 + i]);
    }

    if (imageType != ".ppm" && imageType != ".pgm") {
        std::cout << "Insert image type (ppm/pgm): " << std::endl;
        std::cin >> imageType;
        fileName.append(".");
        fileName.append(imageType);
    }

    if (imageType == "ppm" || imageType == ".ppm") {
        imageHandler = new PPMHandler(dir.append(fileName));
    } else {
        imageHandler = new PGMHandler(dir.append(fileName));
    }

    if (imageHandler->readFile()) {
        std::vector<std::string> filterList = {"1 - Emboss",
                                               "2 - Sharpen",
                                               "3 - Outline",
                                               "4 - Box Blur",
                                               "5 - Gaussian Blur"};

        std::cout << "Insert the code of the filter you want to apply:" << std::endl;
        for (int i = 0; i < filterList.size(); i++) {
            std::cout << filterList[i] << std::endl;
        }
        std::cin >> filterCode;

        Filtro f = Filtro::Identity;

        switch (filterCode) {
            case 1:
                f = Filtro::Emboss;
                break;
            case 2:
                f = Filtro::Sharpen;
                break;
            case 3:
                f = Filtro::Outline;
                break;
            case 4:
                f = Filtro::BoxBlur;
                break;
            case 5:
                f = Filtro::GaussianBlur;
                break;
            default:
                break;
        }

        if (f != Filtro::Identity) {
            imageHandler->applyFilter(f);
            std::cout << "Do you want to save the new filtered image? (YES/NO)" << std::endl;
            std::cin >> save;
            if ((save == "YES") || (save == "yes") || (save == "Yes") || (save == "y") || (save == "Y")) {
                std::cout << "Saving..." << std::endl;
                imageHandler->saveFile();
            }
        } else {
            std::cerr << "Invalid filter code!" << std::endl;
        }
    } else {
        std::cerr << "File not found!" << std::endl;
    }
    std::cout << "Operation concluded!" << std::endl;

    delete imageHandler;
    return 0;
}
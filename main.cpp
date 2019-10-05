#include "ImageHandler.h"
#include "PGMHandler.h"
#include "PPMHandler.h"
#include <iostream>

int main() {
    std::cout << "We welcome you to: bring me the forks!" << std::endl;

    ImageHandler* imagehandler;
    std::string nomefile;
    std::string tipo;
    std::string salvataggio;
    int filtro;

    std::cout << "Inserisci il nome del file con estensione: " << std::endl;
    std::cin >> nomefile;

    for (int i = 0; i < 4; i++) {
        tipo.push_back(nomefile[nomefile.size() - 4 + i]);
    }

    if (tipo != ".ppm" && tipo != ".pgm") {
        std::cout << "Inserisci il tipo di immagine (ppm/pgm): " << std::endl;
        std::cin >> tipo;
        nomefile.append(".");
        nomefile.append(tipo);
    }

    imagehandler = new ImageHandler(nomefile);

    if (imagehandler->readFile()) {
        std::vector<std::string> listaFiltri = {"1 - Emboss",
                                                "2 - Sharpen",
                                                "3 - Outline",
                                                "4 - Box Blur",
                                                "5 - Gaussian Blur"};

        std::cout << "Inserisci il codice del filtro che si desidera utilizzare:" << std::endl;
        for (int i = 0; i < listaFiltri.size(); i++) {
            std::cout << listaFiltri[i] << std::endl;
        }
        std::cin >> filtro;

        if (filtro > 0 && filtro < listaFiltri.size() + 1) {
            imagehandler->applyFilter(filtro);
            std::cout << "Salvare le modifiche apportate? (SI/NO)" << std::endl;
            std::cin >> salvataggio;
            if ((salvataggio == "SI") || (salvataggio == "si") || (salvataggio == "Si")) {
                std::cout << "Salvataggio in corso..." << std::endl;
                imagehandler->saveFile();
            }
        } else {
            std::cout << "Filtro selezionato non disponibile al momento" << std::endl;
        }
    }
    std::cout << "Operazione conclusa" << std::endl;

    delete imagehandler;
    return 0;
}
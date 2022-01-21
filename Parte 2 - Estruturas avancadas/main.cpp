#include <iostream>

#include "interpretador.h"

int main() {

    Sculptor *s1;
    Interpretador parser;
    std::vector<FiguraGeometrica *> figs;
    figs = parser.parse("escultura.txt");
    s1 = new Sculptor(parser.getDimX(), parser.getDimY(), parser.getDimZ());

    for (size_t i = 0; i < figs.size(); i++) {
       std::cout << "draw\n";
       figs[i]->draw(*s1);
    }

    s1->writeOFF("teste.off");
    for (size_t i = 0; i < figs.size(); i++) {
       delete figs[i];
    }

    delete s1;

    return 0;
}

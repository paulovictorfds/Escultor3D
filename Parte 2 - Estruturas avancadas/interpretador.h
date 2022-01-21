#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>

#include "figurageometrica.h"

class Interpretador {
private:
    int dimX, dimY, dimZ;
    float r, g, b, alpha;
public:
    Interpretador();
    std::vector<FiguraGeometrica *> parse(std::string filename);
    int getDimX();
    int getDimY();
    int getDimZ();
};

#endif // INTERPRETADOR_H

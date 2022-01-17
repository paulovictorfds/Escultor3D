#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "interpretador.h"
#include "putvoxel.h"
#include "putbox.h"
#include "putsphere.h"
#include "putellipsoid.h"

Interpretador::Interpretador() { }

std::vector<FiguraGeometrica *> Interpretador::parse(std::string filename) {
    std::vector<FiguraGeometrica *> figs;
    std::ifstream ifs;
    std::stringstream ss;
    std::string s, token;

    ifs.open(filename.c_str());
    if (!ifs.is_open()){
        std::cout << "Erro ao abrir arquivo txt, verificar caminho" << std::endl;
        exit(1);
    }

    while (ifs.good()) {
        std::getline(ifs, s);
        if (ifs.good()) {
            ss.clear();
            ss.str(s);
            ss >> token;
            if (ss.good()) {
                if (token.compare("dim") == 0) {
                    ss >> dimX >> dimY >> dimZ;
                }
                else if (token.compare("putvoxel") == 0) {
                    int x0, y0, z0;
                    ss >> x0 >> y0 >> z0 >> r >> g >> b >> alpha;
                    figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, alpha));
                }
                else if (token.compare("putbox") == 0) {
                    int x0, x1, y0, y1, z0, z1;
                    ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> alpha;
                    figs.push_back(new PutBox(x0, x1 , y0, y1, z0, z1, r, g, b, alpha));
                }
                else if (token.compare("putsphere") == 0) {
                    int xcenter, ycenter, zcenter, radius;
                    ss  >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> alpha;
                    figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, alpha));
                }
                else if (token.compare("putellipsoid") == 0) {
                    int xcenter, ycenter, zcenter, rx, ry, rz;
                    ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> alpha;
                    figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, alpha));
                }
            }
        }
    }
    ifs.close();
    return(figs);
}

int Interpretador::getDimX(){
    return dimX;
}

int Interpretador::getDimY(){
    return dimY;
}

int Interpretador::getDimZ(){
    return dimZ;
}

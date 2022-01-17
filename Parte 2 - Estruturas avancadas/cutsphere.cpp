#include "cutsphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}

void CutSphere::draw(Sculptor &s) {
    for (int x = 0; x <= xcenter + radius; x++) {
        for (int y = 0; y <= ycenter + radius; y++) {
            for (int z = 0; z <= zcenter + radius; z++) {
                /* Caso seja satisfeita a equação da esfera
                   o método cutVoxel é chamado */
                if ((x - xcenter) * (x - xcenter) +
                    (y - ycenter) * (y - ycenter) +
                    (z - zcenter) * (z - zcenter) <= radius * radius)
                {
                    s.cutVoxel(x, y, z);
                }
            }
        }
    }
}

#include "putsphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float alpha) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;

    setColor(r, g, b, alpha);
}

void PutSphere::draw(Sculptor &s) {
    s.setColor(r, g, b, alpha);
    for (int x = 0; x <= xcenter + radius; x++) {
        for (int y = 0; y <= ycenter + radius; y++) {
            for (int z = 0; z <= zcenter + radius; z++) {
                /* Caso seja satisfeita a equação da esfera
                   o método putVoxel é chamado */
                if ((x - xcenter) * (x - xcenter) +
                    (y - ycenter) * (y - ycenter) +
                    (z - zcenter) * (z - zcenter) <= radius * radius)
                {
                    s.putVoxel(x, y, z);
                }
            }
        }
    }
}

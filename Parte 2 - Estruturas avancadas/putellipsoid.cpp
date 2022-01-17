#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float alpha) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    this->r = r;
    this->g = g;
    this->b = b;
    this->alpha = alpha;
}

void PutEllipsoid::draw(Sculptor &s) {
    s.setColor(r, g, b, alpha);
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {
                /* Caso seja satisfeita a equação da elipsoide
                   o método cutVoxel é chamado */
                if (static_cast< double >((x - xcenter) * (x - xcenter)) / (rx * rx) +
                    static_cast< double >((y - ycenter) * (y - ycenter)) / (ry * ry) +
                    static_cast< double >((z - zcenter) * (z - zcenter)) / (rz * rz) <= 1.0)
                {
                    s.putVoxel(x, y, z);
                }
            }
        }
    }
}

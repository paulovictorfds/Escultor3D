#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}

void CutEllipsoid::draw(Sculptor &s) {
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {
                /* Caso seja satisfeita a equação da elipsoide
                   o método cutVoxel é chamado */
                if (static_cast< float >((x - xcenter) * (x - xcenter)) / (rx * rx) +
                    static_cast< float >((y - ycenter) * (y - ycenter)) / (ry * ry) +
                    static_cast< float >((z - zcenter) * (z - zcenter)) / (rz * rz) <= 1.0)
                {
                    s.cutVoxel(x, y, z);
                }
            }
        }
    }
}

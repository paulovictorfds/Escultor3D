#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica {
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    ~CutEllipsoid() { }
    void draw(Sculptor &s);
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
};

#endif // CUTELLIPSOID_H

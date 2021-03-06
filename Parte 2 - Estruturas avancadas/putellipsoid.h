#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid : public FiguraGeometrica {
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float alpha);
    ~PutEllipsoid() { }
    void draw(Sculptor &s);
protected:
    int xcenter, ycenter, zcenter, rx, ry, rz;
};

#endif // PUTELLIPSOID_H

#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica {
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float alpha);
    ~PutSphere() { }
    void draw(Sculptor &s);
protected:
    int xcenter, ycenter, zcenter, radius;
};

#endif // PUTSPHERE_H

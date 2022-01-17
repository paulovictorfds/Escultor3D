#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "sculptor.h"
#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica {
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    ~CutSphere() { }
    void draw(Sculptor &s);
protected:
    int xcenter, ycenter, zcenter, radius;
};

#endif // CUTSPHERE_H

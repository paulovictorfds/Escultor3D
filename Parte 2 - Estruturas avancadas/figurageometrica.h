#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica {
protected:
    float r, g, b, alpha;
public:
    FiguraGeometrica();
    virtual ~FiguraGeometrica() { };
    virtual void draw(Sculptor &s) = 0;
    void setColor(float r, float g, float b, float alpha);    
};

#endif // FIGURAGEOMETRICA_H

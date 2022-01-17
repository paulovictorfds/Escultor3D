#ifndef PUTBOX_H
#define PUTBOX_H

#include "sculptor.h"
#include "figurageometrica.h"

class PutBox : public FiguraGeometrica {
public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float alpha);
    ~PutBox() { };
    void draw(Sculptor &s);
protected:
    int x0, x1, y0, y1, z0, z1;
    float r, g, b, alpha;
};

#endif // PUTBOX_H

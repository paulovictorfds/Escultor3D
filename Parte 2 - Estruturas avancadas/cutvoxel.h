#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "sculptor.h"
#include "figurageometrica.h"

class CutVoxel : public FiguraGeometrica {
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel() { }
    void draw(Sculptor &s);
protected:
    int x, y, z;
};

#endif // CUTVOXEL_H

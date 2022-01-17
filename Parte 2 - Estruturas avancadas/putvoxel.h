#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutVoxel : public FiguraGeometrica {
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float alpha);
    ~PutVoxel() { }
    void draw(Sculptor &s);
protected:
    int x, y, z;
    float r, g, b, alpha;
};

#endif // PUTVOXEL_H

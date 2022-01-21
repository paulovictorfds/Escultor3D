#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float alpha) {
    this->x = x;
    this->y = y;
    this->z = z;

    setColor(r, g, b, alpha);
}

void PutVoxel::draw(Sculptor &s) {
    s.setColor(r, g, b, alpha);
    s.putVoxel(x, y, z);    
}

#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
    float r, g, b; // Cores
    float alpha; // Transparency
    bool isOn; // Included or not
};

class Sculptor {

protected:
    Voxel ***v;
    // 3D matrix
    int nx, ny, nz; // Dimensions
    float r, g, b, alpha; // Current drawing color
public:
    Sculptor(int nx, int ny, int nz);
    ~Sculptor();
    void setColor(float r, float g, float b, float alpha);
    void putVoxel(int x, int y, int z);
    void cutVoxel(int x, int y, int z);
    void writeOFF(const char* filename);

};

#endif // SCULPTOR_H

#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

Sculptor::Sculptor(int nx, int ny, int nz) {
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;

    v = new Voxel** [nx];
    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel* [ny];
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel [nz];
        }
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                v[i][j][k].isOn = false;
            }
        }
    }

    std::cout << "Construtor Sculptor" << std::endl;
}

Sculptor::~Sculptor() {
    if (nx == 0 || ny == 0 || nz == 0) {
        std::cout << "Destrutor falhou" << std::endl;
        return;
    }

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete [] v[i][j];
        }
    }

    for(int i = 0; i < nx; i++) {
        delete [] v[i];
    }

    delete [] v;

    std::cout << "Destrutor Sculptor" << std::endl;
}

void Sculptor::setColor(float r, float g, float b, float alpha) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->alpha = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if (x < nx && y < ny && z < nz) {
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].alpha = alpha;
        v[x][y][z].isOn = true;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if (x < nx && y < ny && z < nz) {
        v[x][y][z].isOn = false;
    }
}

void Sculptor::writeOFF(const char* filename) {
    int NVoxels = 0, NVertices, NFaces;
    int faces = 0;

    std::ofstream fout;

    fout.open(filename);
    if (!fout.is_open()){
       exit(1);
       std::cout << "Nao foi possivel gravar no arquivo";
    }

    fout << "OFF \n";

    for (int x = 0;x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].isOn == true) {
                    NVoxels++;
                }
            }
        }
    }

    NVertices = NVoxels * 8;
    NFaces = NVoxels * 6;

    fout << NVertices << " " << NFaces << " " << 0 << std::endl;

    for (int x = 0; x < nz; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nx; z++) {
                if (v[x][y][z].isOn) {
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl
                         << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl
                         << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl
                         << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl
                         << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl
                         << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl
                         << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl
                         << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                 }
            }
        }
    }

    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].isOn) {
                    fout << std::fixed << 4 << " " << 0 + faces << " " << 3 + faces << " " << 2 + faces << " " << 1 + faces << " "
                         << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " <<
                            std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].alpha << std::endl
                         << 4 << " " << 4 + faces << " " << 5 + faces << " " << 6 + faces << " " << 7 + faces << " "
                         << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " <<
                            std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].alpha << std::endl
                         << 4 << " " << 0 + faces << " " << 1 + faces << " " << 5 + faces << " " << 4 + faces << " "
                         << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " <<
                            std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].alpha << std::endl
                         << 4 << " " << 0 + faces << " " << 4 + faces << " " << 7 + faces << " " << 3 + faces << " "
                         << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " <<
                            std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].alpha << std::endl
                         << 4 << " " << 3 + faces << " " << 7 + faces << " " << 6 + faces << " " << 2 + faces << " "
                         << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " <<
                            std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].alpha << std::endl
                         << 4 << " " << 1 + faces << " " << 2 + faces << " " << 6 + faces << " " << 5 + faces << " "
                         << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " <<
                            std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].alpha << std::endl;
                    faces += 8;
                 }
            }
        }
    }

    fout.close();
    std::cout << "Arquivo criado com sucesso" << std::endl;
}

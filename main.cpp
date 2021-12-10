#include "sculptor.h"
#include <iostream>

int main()
{
    // cria um escultor cuja matriz tem 10x10x10 voxels
    Sculptor teste(25,25,25);

    // para mudar a cor do voxel
    teste.setColor(0.0,0.0,1.0,1.0); // azul
    // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    teste.putBox(0,9,0,9,0,9);
    // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
    teste.cutBox(1,8,1,9,1,9);

    // esfera
    teste.setColor(0.0, 1.0, 1.0 , 0.8);
    teste.putSphere(12, 12, 12, 4);
    teste.cutSphere(12, 10, 12, 4);

    // elipsoide
    teste.setColor(1.0, 0.0, 1.0 , 0.8);
    teste.putEllipsoid(16, 16, 16, 2, 4, 2);

    // grava a escultura digital no arquivo "trono.off"
    teste.writeOFF("teste.off");

    return 0;
}

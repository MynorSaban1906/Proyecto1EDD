#ifndef CABECERAMATRIZ_H
#define CABECERAMATRIZ_H
#include "nodomatriz.h"
#include <iostream>
using namespace std;

class CabeceraMatriz:public NodoMatriz
{
public:
    CabeceraMatriz(int numero);
    void setNombre(int numero);
    int getNombre();
private:
    int numero;
};

#endif // CABECERAMATRIZ_H

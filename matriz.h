#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include "nodoobjeto.h"
#include "cabeceramatriz.h"
using namespace std;

class Matriz
{
public:
    Matriz();
    ~Matriz();
    void add(NodoObjeto*nuevo);
    void codigo();
private:
    CabeceraMatriz *Horizontal;
    CabeceraMatriz *Vertical;
    CabeceraMatriz *getVertical(int numero);
    CabeceraMatriz *getHorizontal(int numero );
    CabeceraMatriz *crearVertical(int numero);
    CabeceraMatriz *crearHorizontal(int numero);

    NodoMatriz*ObtenerUltimoV(CabeceraMatriz *cabecera,int numeroV);
    NodoMatriz*ObtenerUltimoH(CabeceraMatriz *cabecera,int numeroV);
};

#endif // MATRIZ_H

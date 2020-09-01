#include "cabeceramatriz.h"

CabeceraMatriz::CabeceraMatriz(int numero)
{
    this->numero=numero;
}
void CabeceraMatriz::setNombre(int numero){
    this->numero=numero;
}

int CabeceraMatriz::getNombre(){return this->numero;}

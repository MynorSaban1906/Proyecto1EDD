#ifndef NODOESTRUCTURA_H
#define NODOESTRUCTURA_H
#include <iostream>
#include "ArbolObjetoP.h" //arbol binario de busqueda con los objetos
#include "nodomatriz.h"      //Matriz dispersa que contiene los objetos

using namespace std;

class NodoEstructura
{
public:
    NodoEstructura(ArbolObjetoP *objetos,NodoMatriz *Matriz);
    ~NodoEstructura();

private:
    NodoEstructura *siguiente;
};

#endif // NODOESTRUCTURA_H

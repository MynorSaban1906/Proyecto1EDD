#ifndef NODOAVL_H
#define NODOAVL_H
#include <iostream>

using namespace std;

class NodoAVL
{
public:
    NodoAVL(int dato);
    void setDato(int dato);
    void setFactor(int factor);
    void setIzquierda(NodoAVL *izq);
    void setDerecha(NodoAVL *der);
    NodoAVL *getDerecha();
    NodoAVL *getIzquierda();
    int getfactor();
    int getDato();
private:
    int dato;
    int factorE;
    NodoAVL *izquierda;
    NodoAVL *derecha;
};

#endif // NODOAVL_H

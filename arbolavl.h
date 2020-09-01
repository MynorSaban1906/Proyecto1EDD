#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include "nodoavl.h"
#include "nodoobjeto.h"

class ArbolAVL
{
public:
    ArbolAVL();
    ~ArbolAVL();
    NodoAVL* getRaiz();
    void insertar(int valor);
    void generar();

private:
    NodoAVL * raiz;
    NodoAVL* insertar(NodoAVL *raiz,int dato,bool &hc);
    NodoAVL * rotacionII(NodoAVL *N, NodoAVL *n1);
    NodoAVL * rotacionDD(NodoAVL *N, NodoAVL *n1);
    NodoAVL * rotacionID(NodoAVL *N, NodoAVL *n1);
    NodoAVL * rotacionDI(NodoAVL *N, NodoAVL *n1);
    void Delete(NodoAVL* raiz);
        void generar(stringstream *cadena, NodoAVL* padre, NodoAVL* actual,bool izquierda);
};

#endif // ARBOLAVL_H

#ifndef NODOOBJETO_H
#define NODOOBJETO_H
#include <string>
#include <iostream>
using namespace std;

class NodoObjeto
{
public:
    NodoObjeto(int id,string name,char letter, string color,int Cx,int Cy);
    ~NodoObjeto();
    void setIzquierda(NodoObjeto *izq);
    void setDerecha(NodoObjeto *der);
    NodoObjeto *getDerecha();
    NodoObjeto *getIzquierda();
    int id;
    string name;
    string letter;
    string color;
    int Cx;
    int Cy;
private:
    NodoObjeto *izquierda;
    NodoObjeto *derecha;
};


#endif // NODOOBJETO_H

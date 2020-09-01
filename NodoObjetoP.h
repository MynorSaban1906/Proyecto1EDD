#ifndef NODOOBJETOP_H
#define NODOOBJETOP_H
#include <string>
#include <iostream>
using namespace std;

class NodoObjetoP
{
public:
    NodoObjetoP(int id,string name,char letter, string color,int Cx,int Cy);
    ~NodoObjetoP();
    void setIzquierda(NodoObjetoP *izq);
    void setDerecha(NodoObjetoP *der);
    NodoObjetoP *getDerecha();
    NodoObjetoP *getIzquierda();
    int id;
    string name;
    string letter;
    string color;
    int Cx;    int Cy;
private:
    NodoObjetoP *izquierda;
    NodoObjetoP *derecha;
};

#endif // NODOOBJETO_H

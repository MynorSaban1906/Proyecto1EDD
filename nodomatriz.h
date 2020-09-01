#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <iostream>
using namespace std;

class NodoMatriz
{
public:
    NodoMatriz();
    void setNorte(NodoMatriz *n);
    void setSur(NodoMatriz *n);
    void setEste(NodoMatriz *n);
    void setOeste(NodoMatriz *n);
    NodoMatriz *getNorte();
    NodoMatriz *getSur();
    NodoMatriz *getEste();
    NodoMatriz *getOeste();


private:
    NodoMatriz *Norte;
    NodoMatriz *Sur;
    NodoMatriz *Este;
    NodoMatriz *Oeste;
};

#endif // NODOMATRIZ_H

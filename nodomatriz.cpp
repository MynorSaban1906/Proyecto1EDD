#include "nodomatriz.h"

NodoMatriz::NodoMatriz()
{
    this->Sur=NULL;
    this->Norte=NULL;
    this->Este=NULL;
    this->Oeste=NULL;
}

NodoMatriz *NodoMatriz:: getSur(){return this->Sur;}
NodoMatriz *NodoMatriz:: getEste(){return this->Este;}
NodoMatriz *NodoMatriz:: getOeste(){return this->Oeste;}
NodoMatriz *NodoMatriz:: getNorte(){return this->Norte;}

void NodoMatriz::setSur(NodoMatriz *n){
    this->Sur=n;
}

void NodoMatriz::setNorte(NodoMatriz *n){
    this->Norte=n;
}

void NodoMatriz::setEste(NodoMatriz *n){
    this->Este=n;
}

void NodoMatriz::setOeste(NodoMatriz *n){
    this->Oeste=n;
}

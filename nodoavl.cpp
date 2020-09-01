#include "nodoavl.h"

#include <iostream>

using namespace std;

NodoAVL::NodoAVL(int dato)
{
    this->dato=dato;
    this->derecha=NULL;
    this->izquierda=NULL;

}

void NodoAVL::setDato(int dato){
    this->dato=dato;
}

void NodoAVL::setFactor(int factor){this->factorE=factor;}
void NodoAVL::setDerecha(NodoAVL *derecha){this->derecha=derecha;}
void NodoAVL::setIzquierda(NodoAVL *izquierda){this->izquierda=izquierda;}


int NodoAVL::getDato(){return this->dato;}
int NodoAVL::getfactor(){return this->factorE;}
NodoAVL* NodoAVL::getDerecha(){return this->derecha;}
NodoAVL* NodoAVL::getIzquierda(){return  this->izquierda;}

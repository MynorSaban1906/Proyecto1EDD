#include "nodoobjeto.h"

NodoObjeto::NodoObjeto(int id,string name,char letter, string color,int Cx,int Cy)
{
    this->id=id;
    this->name=name;
    this->letter=letter;
    this->color=color;
    this->Cx=Cx;
    this->Cy=Cy;
    this->izquierda=NULL;
    this->derecha=NULL;
}

void NodoObjeto::setDerecha(NodoObjeto *derecha){this->derecha=derecha;}
void NodoObjeto::setIzquierda(NodoObjeto *izquierda){this->izquierda=izquierda;}
NodoObjeto* NodoObjeto::getDerecha(){return this->derecha;}
NodoObjeto * NodoObjeto::getIzquierda(){return  this->izquierda;}


NodoObjeto::~NodoObjeto(){
    cout<<"Objeto Eliminado"<<endl;
}

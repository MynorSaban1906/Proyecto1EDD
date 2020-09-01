#include "NodoObjetoP.h"

NodoObjetoP::NodoObjetoP(int id,string name,char letter, string color,int Cx,int Cy)
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

void NodoObjetoP::setDerecha(NodoObjetoP *derecha){this->derecha=derecha;}
void NodoObjetoP::setIzquierda(NodoObjetoP *izquierda){this->izquierda=izquierda;}
NodoObjetoP* NodoObjetoP::getDerecha(){return this->derecha;}
NodoObjetoP * NodoObjetoP::getIzquierda(){return  this->izquierda;}


NodoObjeto::~NodoObjeto(){
    cout<<"Objeto Eliminado"<<endl;
}

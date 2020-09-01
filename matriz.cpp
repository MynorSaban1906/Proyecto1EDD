#include "matriz.h"


Matriz::Matriz()
{
    this->Horizontal=NULL;
    this->Vertical=NULL;

}
Matriz::~Matriz(){
    NodoMatriz *aux,*aux2,*temp,*temp2,*extra,*extra2;
    aux=this->Vertical;
    temp=this->Horizontal;
    while (aux!=NULL) {
        extra=aux->getSur();
        aux2=aux->getEste();
        while (aux2!=NULL) {
            extra2=aux2->getEste();
            delete  aux2;
            aux2=extra2;
        }
        delete  aux;
        aux=extra;
    }
    while (temp!=NULL) {
        temp2=temp->getEste();
        delete temp;
        temp=temp2;
    }

}


CabeceraMatriz *Matriz::crearHorizontal(int nombre){
    if(this->Horizontal==NULL){
        CabeceraMatriz * nueva = new CabeceraMatriz(nombre);
        this->Horizontal=nueva;
        return nueva;
    }
    CabeceraMatriz *aux =this->Horizontal;
    if(nombre.compare(aux->getNombre())<=0){
        CabeceraMatriz *nueva = new CabeceraMatriz(nombre);
        nueva->setEste(aux);
        this->Horizontal->setOeste(nueva);
        this->Horizontal=nueva;
        return  nueva;
    }
    while (aux->getEste()!=NULL) {
        if(nombre.compare(aux->getNombre())>0 && nombre.compare(((CabeceraMatriz*)aux->getEste())->getNombre())<=0){
            CabeceraMatriz* nueva = new CabeceraMatriz(nombre);
            CabeceraMatriz *temp=(CabeceraMatriz*)aux->getEste();
            temp->setOeste(nueva);
            nueva->setEste(temp);
            aux->setEste(nueva);
            nueva->setOeste(aux);
            return nueva;
            }
        aux=(CabeceraMatriz*)aux->getEste();
    }
    CabeceraMatriz *nuevo = new CabeceraMatriz(nombre);
    aux->setEste(nuevo);
    nuevo->setOeste(aux);
    return nuevo;
}

CabeceraMatriz *Matriz::crearVertical(int nombre){
    if(this->Vertical==NULL){
        CabeceraMatriz * nueva = new CabeceraMatriz(nombre);
        this->Vertical=nueva;
        return nueva;
    }
    CabeceraMatriz *aux =this->Vertical;
    if(nombre.compare(aux->getNombre())<=0){
        CabeceraMatriz *nueva = new CabeceraMatriz(nombre);
        nueva->setSur(this->Vertical);
        this->Vertical->setNorte(nueva);
        this->Vertical=nueva;
        return  nueva;
    }
    while (aux->getSur()!=NULL) {
        if(nombre.compare(aux->getNombre())>0 && nombre.compare(((CabeceraMatriz*)aux->getSur())->getNombre())<=0){
            CabeceraMatriz* nueva = new CabeceraMatriz(nombre);
            CabeceraMatriz *temp=(CabeceraMatriz*)aux->getSur();
            temp->setNorte(nueva);
            nueva->setSur(temp);
            aux->setNorte(nueva);
            nueva->setSur(aux);
            return nueva;
            }
        aux=(CabeceraMatriz*)aux->getSur();
    }
    CabeceraMatriz *nuevo = new CabeceraMatriz(nombre);
    aux->setSur(nuevo);
    nuevo->setNorte(aux);
    return nuevo;
}

NodoMatriz *Matriz::ObtenerUltimoH(CabeceraMatriz *cabecera, int nombre){
    if(cabecera->getEste()==NULL){ return cabecera;}
    NodoMatriz* aux=cabecera->getEste();
    while (aux->getEste()!=NULL) {
        if(nombre.compare(((Persona*)aux)->getNombre())<=0){
            return aux;
        } aux= aux->getEste();
    }
    if(nombre.compare(((Persona*)aux)->getNombre())<=0){
        return aux->getOeste();
    }
    return aux;
}

NodoMatriz *Matriz::ObtenerUltimoV(CabeceraMatriz *cabecera,int materia){
    if(cabecera->getSur()==NULL){ return cabecera;}
    NodoMatriz* aux=cabecera->getSur();
    while (aux->getSur()!=NULL) {
        if(materia.compare(((Persona*)aux)->getMateria())<=0){
            return aux;
        } aux= aux->getSur();
    }
    if(materia.compare(((Persona*)aux)->getMateria())<=0){
        return aux->getNorte();
    }
    return aux;
}


CabeceraMatriz *Matriz::getVertical(int nombre){
    if(this->Vertical==NULL){
        return NULL;
    }
    CabeceraMatriz *aux=this->Vertical;
    while (aux!=NULL) {
        if(((string)aux->getNombre()).compare(nombre)==0){
            return aux;
        }
        aux=(CabeceraMatriz*)aux->getSur();
    }
    return NULL;
}

CabeceraMatriz *Matriz::getHorizontal(int nombre){
    if(this->Horizontal==NULL){
        return NULL;
    }
    CabeceraMatriz *aux=this->Horizontal;
    while (aux!=NULL) {
        if(((string)aux->getNombre()).compare(nombre)==0){
            return aux;
        }
        aux=(CabeceraMatriz*)aux->getEste();
    }
    return NULL;
}



void Matriz::add(NodoMatriz *nuevo){
    CabeceraMatriz *vertical=this->getVertical(nuevo->getMateria());
    CabeceraMatriz *horizontal=this->getHorizontal(nuevo->getNombre());

    if(vertical==NULL){
        vertical=crearVertical(nuevo->getNombre());
    }
    if(horizontal==NULL){
        horizontal=crearHorizontal(nuevo->getNombre());
    }

    NodoMatriz *izquierda = ObtenerUltimoH(vertical,nuevo->getNombre());
    NodoMatriz *superior = ObtenerUltimoV(horizontal,nuevo->getMateria());
    if(izquierda->getEste()==NULL){
        izquierda->setEste(nuevo);
        nuevo->setOeste(izquierda);
    }else{
        NodoMatriz *temp =izquierda->getEste();
        izquierda->setEste(nuevo);
        nuevo->setOeste(izquierda);
        temp->setOeste(nuevo);
        nuevo->setEste(temp);
    }
    if(superior->getSur()==NULL){
        superior->setSur(nuevo);
        nuevo->setNorte(superior);
    }else{
        NodoMatriz *temp=superior->getSur();
        superior->setSur(nuevo);
        nuevo->setNorte(superior);
        temp->setNorte(nuevo);
        nuevo->setSur(temp);
    }

}

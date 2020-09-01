#include "arbolavl.h"
ArbolAVL::ArbolAVL()
{
    this->raiz=NULL;
}

ArbolAVL::~ArbolAVL(){
    Delete(this->raiz);
}

void ArbolAVL::Delete(NodoAVL *raiz){
    if(raiz==NULL){
        return;
    }
    Delete(raiz->getIzquierda());
    Delete(raiz->getDerecha());
}

NodoAVL* ArbolAVL::rotacionII(NodoAVL *n, NodoAVL *n1){
    n->setIzquierda(n1->getDerecha());
    n1->setDerecha(n);
    if(n1->getfactor()==1)
{
        n->setFactor(0);
        n1->setFactor(0);
    }else{
        n->setFactor(-1);
        n1->setFactor(1);
    }
    return n1;
}


NodoAVL* ArbolAVL::rotacionDD(NodoAVL *n, NodoAVL *n1){
    n->setIzquierda(n1->getIzquierda());
    n1->setIzquierda(n);
    if(n1->getfactor()==1){
        n->setFactor(0);
        n1->setFactor(0);
    }else{
        n->setFactor(1);
        n1->setFactor(-1);
    }
    return n1;
}


NodoAVL* ArbolAVL::rotacionID(NodoAVL *n, NodoAVL *n1){
    NodoAVL* n2=n1->getDerecha();
    n->setIzquierda(n2->getDerecha());
    n2->setDerecha(n);
    n1->setDerecha(n2->getIzquierda());

    if(n2->getfactor()==1){
        n1->setFactor(-1);
    }else{
        n1->setFactor(0);
    }
    if(n2->getfactor()==-1){
        n->setFactor(1);
    }else{
        n->setFactor(0);
    }

    n2->setFactor(0);
    return n2;
}


NodoAVL* ArbolAVL::rotacionDI(NodoAVL *n, NodoAVL *n1){
    NodoAVL* n2=n1->getIzquierda();
    n->setDerecha(n2->getIzquierda());
    n2->setIzquierda(n);
    n1->setIzquierda(n2->getDerecha());
    n2->setDerecha(n1);

    if(n2->getfactor()==1){
        n->setFactor(-1);
    }else{
        n->setFactor(0);
    }
    if(n2->getfactor()==-1){
        n->setFactor(1);
    }else{
        n->setFactor(0);
    }
    n2->setFactor(0);
    return n2;

}


NodoAVL* ArbolAVL::insertar(NodoAVL *raiz,int dato, bool &hc){
    NodoAVL *n1;
    if(raiz==NULL){
        raiz=new NodoAVL(dato);
        hc=true;
    }else if (dato<raiz->getDato()){
        NodoAVL*izq=insertar(raiz->getIzquierda(),dato,hc);
        raiz->setIzquierda(izq);
        if(hc){
            switch (raiz->getfactor()){
            case 1:
                raiz->setFactor(0);
                hc=false;
                break;
            case 0:
                raiz->setFactor(-1);
                break;
            case -1:
                n1=raiz->getIzquierda();
                if(n1->getfactor()==-1){
                    raiz=rotacionII(raiz,n1);
                }else{
                    raiz=rotacionID(raiz,n1);
                }
                hc=false;
                break;
            }

        }else if(dato>raiz->getDato()){
            NodoAVL* der=insertar(raiz->getDerecha(),dato,hc);
            raiz->setDerecha(der);
            if(hc){
                switch (raiz->getfactor()) {
                case 1:
                    n1=raiz->getDerecha();
                    if(n1->getDato()==1){
                        raiz=rotacionDD(raiz,n1);
                    }else{
                        raiz=rotacionDI(raiz,n1);
                    }
                    hc=false;
                    break;
                case 0:
                    raiz->setFactor(1);
                    break;
                case -1:
                    raiz->setFactor(0);
                    hc=false;

                }

            }


        }

    }
    return raiz;
}

void ArbolAVL::insertar(int valor){
    bool b =false;
    bool *a=&b;
    this->raiz=insertar(this->raiz,valor,*a);
}

NodoAVL *ArbolAVL::getRaiz(){
    return this->raiz;
}

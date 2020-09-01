#include "ArbolObjetoP.h"

ArbolObjetoP::ArbolObjetoP()
{
    this->cabeza=NULL;
}

ArbolObjetoP::~ArbolObjetoP(){
    delete this->cabeza;
}

void ArbolObjetoP::Delete(NodoObjeto *raiz){
    if(raiz==NULL){
        return;
    }
    Delete(raiz->getIzquierda());
    Delete(raiz->getDerecha());
}

void ArbolObjetoP::insertar(int id,string name,char letter, string color,int Cx,int Cy){
    this->cabeza=agregar(this->cabeza,id,name, letter,  color, Cx, Cy);
}

NodoObjeto* ArbolObjetoP::agregar(NodoObjeto* cabeza, int id,string name,char letter, string color,int Cx,int Cy){
    if(cabeza==NULL){
        cabeza= new NodoObjeto (id, name, letter,  color,
                                Cx,Cy);
    }else{
        if(id<cabeza->id){
            NodoObjeto* izq=agregar(cabeza->getIzquierda(),id, name, letter,  color, Cx,Cy);
            cabeza->setIzquierda(izq);
        }else if(id>cabeza->id){
            NodoObjeto* der=agregar(cabeza->getDerecha(),id, name, letter,  color, Cx,Cy);
            cabeza->setDerecha(der);
        }
    }
    return cabeza;
}

void ArbolObjetoP::imprimir(){
    if(this->cabeza!=NULL){
        cout<<"la raiz es :"<<cabeza->id<<endl;
        this->generar(this->cabeza,this->cabeza->getIzquierda(),true);
        this->generar(this->cabeza,this->cabeza->getDerecha(),false);
    }
}

void ArbolObjetoP::generar(NodoObjeto* padre,NodoObjeto* actual, bool ac){
    if(actual!=NULL){
       if(ac){
            cout<<"lado izquierdo "<<actual->name<<endl;
        }
        else if(padre->getDerecha()){
            cout<<"lado derecho "<<actual->name<<endl;
        }
        generar(actual,actual->getIzquierda(),true);
        generar(actual,actual->getDerecha(),false);
    }


}


//void ListaObjeto::buscar(string nombre){
//    int i=0;
//    NodoObjeto *aux=this->cabeza;
//    while(aux!=NULL){
//        if(aux->name==nombre){
//            cout<<"Encontrado"<<endl;
//            i=1;
//        }
//        aux=aux->getSiguiente();
//    }
//    if(i==0){
//        cout<<"Objeto no encontrado se ingresara"<<endl;
//        this->insertar(20,"mesa",'t',"azul",20,15);
//        this->imprimir();
//    }
//}

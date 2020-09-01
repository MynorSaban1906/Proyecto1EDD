#ifndef LISTAOBJETO_H
#define LISTAOBJETO_H
#include "nodoobjeto.h"

class ArbolObjetoP
{
public:
    ArbolObjetoP();
    ~ArbolObjetoP();
    NodoObjeto* agregar(NodoObjeto *nuevo,int id,string name,char letter, string color,int Cx,int Cy);
    NodoObjeto* get(int i);
    void imprimir();
    void buscar(string nombre);
    void insertar(int id,string name,char letter, string color,int Cx,int Cy);
    void Delete(NodoObjeto* cabeza);
    void generar(NodoObjeto* padre,NodoObjeto* actual, bool ac);
private:
    NodoObjeto *cabeza;
};
#endif // LISTAOBJETO_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "listaobjeto.h"
#include <nlohmann/json.hpp>
#include <cstdlib>
using namespace std;

using json=nlohmann::json;

void presentacion();
void menuPrincipal();
void CargaArchivo(string archivo);
string CargarProyecto(string arvhivo);
int conversion(string nombre);
int main()
{

    presentacion();
    menuPrincipal();

    return 0;
}

void presentacion(){
    cout<<"\t\t\t"<<"------------------------------------------------------------"<<endl;
    cout<<"\t\t\t"<<"| USAC                                                      |"<<endl;
    cout<<"\t\t\t"<<"| ESTRUCTURAS DE DATOS                                      |"<<endl;
    cout<<"\t\t\t"<<"| SECCION A                                                 |"<<endl;
    cout<<"\t\t\t"<<"| AUXILIAR : Marvin Martinez                                |"<<endl;
    cout<<"\t\t\t"<<"| ESTUDIANTE : Mynor Alison Isai Saban Che                  |"<<endl;
    cout<<"\t\t\t"<<"| CARNE: 201800516                                          |"<<endl;
    cout<<"\t\t\t"<<"-------------------------------------------------------------\n"<<endl;
}

void menuPrincipal(){
    int menu;
    cout<<"\n\t\t\tMenu Principal \n\n\n"<<endl;
    cout<<"1. Ver Proyectos\n2. Editar Proyectos\n3. Cargar Proyecto"<<endl;
    cout<<"4. Graficar Proyectos\n5. Cargar Librerias"<<endl;
    cout<<"Digite Opcion : ";cin>>menu;

    if(menu==1){
        cout<<"";
    }else if(menu==2){
        cout<<"";
    }else if(menu==3){
        string ruta;
        cout<<"\nDigite la direcion : "; cin>>ruta;
        CargarProyecto(ruta);
        cout<<"\n Proyecto Cargado"<<endl;
        menuPrincipal();
    }else if(menu==4){
        cout<<"";
    }else if(menu==5){
        string ruta;
        cout<<"\nDigite la direcion : "; cin>>ruta;
        CargaArchivo(ruta);
        cout<<"\n Librerias cargadas"<<endl;
        menuPrincipal();
    }




}

void CargaArchivo(string archivo){
    ifstream reader(archivo);
    json j;
    reader>>j;
    reader.close();

    ListaObjeto *lis= new ListaObjeto();

    int tamanio= j["Libreria"].size();
    int i=0;
    cout<<tamanio<<endl;
    while (i<=tamanio){
        if(j["Libreria"][i].size()==0){
            break;
            i=tamanio+1;
        }

        int id=j["Libreria"][i]["identificador"];
        string nombre=j["Libreria"][i]["nombre"];
        string letter=j["Libreria"][i]["letra"];
        char l=letter[0];
        string color=j["Libreria"][i]["color"];
        lis->insertar(id,nombre,l,color,0,0);
        i++;
    }
    lis->imprimir();
    delete lis;
    lis->imprimir();
}



string CargarProyecto(string archivo){
    ifstream reader(archivo);
    json j;
    reader>>j;
    reader.close();

    int tamanio= j["proyectos"].size();
    int i=0;
    cout<<tamanio<<endl;
    while (i<=tamanio){
        if(j["proyectos"][i].size()==0){
            break;
            i=tamanio+1;
        }

        else{
            string nombreP=j["proyectos"][i]["nombre"];
            cout<<nombreP<<endl;
            conversion(nombreP);
        }
        i++;
    }

    return "";
}


int conversion(string nombre){
    char name[]="";
    strcpy(name,nombre.c_str());
    int longitud= strlen (name);
    int ascii=0;
    for (int i=0;i<longitud;i++){
        int entero= nombre[i];
        cout<<nombre[i]<<"  "<<entero<<endl;
        ascii=ascii+entero;
    }

    cout << "\nsuma ascii : "<<ascii;
    return ascii;
}

/* -------------------------------------------------------------------+
* |
* (c) 2025 |
* EIF204 - Programación 2 |
* 1er ciclo 2025 |
* NRC 41371 – Grupo 05 |
* Proyecto 1 |
* |
* 1-1977-0043; Retana Segura, Efraín |
* |
* versión 1.0.0 2025-04-01 |
* |
* -------------------------------------------------------------------+
*/

#ifndef ADMINISTRADORALMACENAMIENTO_H
#define ADMINISTRADORALMACENAMIENTO_H
#include "GestorPrestamos.h"
#include "ListaMateriales.h"
#include "ListaPrestamos.h"
#include "ListaUsuarios.h"
#include "ManejoArchivos.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
class AdministradorAlmacenamiento {
private:
    ifstream entrada;
    ofstream salida;
    ifstream entradaAux;
    ofstream salidaAux;
    ifstream entradaAux2;
    ofstream salidaAux2;
    ifstream entrada2;
    ofstream salida2;
    ManejoArchivos convDatos;
public:
    AdministradorAlmacenamiento();
    void guardarMateriales(ListaMateriales*);
    void guardarUsuarios(ListaUsuarios*);
    void guardarPrestamos(ListaPrestamos*);
    void guardarGestor(GestorPrestamos* , const std::string& filename);
    ListaMateriales * recuperarMateriales() ;
    ListaUsuarios * recuperarUsuarios();
    ListaPrestamos * recuperarPrestamos(ListaUsuarios* usuarios, ListaMateriales* materiales) ;
    GestorPrestamos * recuperarGestor(GestorPrestamos* gestor, ListaUsuarios* usuarios, ListaMateriales* materiales, const std::string& filename);
};




#endif //ADMINISTRADORALMACENAMIENTO_H

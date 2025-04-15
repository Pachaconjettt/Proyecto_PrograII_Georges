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

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "ManejoArchivos.h"
#include "ListaMateriales.h"
#include "ListaUsuarios.h"
#include "Fecha.h"
#include <iostream>


class Biblioteca {
private:
    string nombre;
    ListaUsuarios* usuarios;
    ListaMateriales* mats;
    Fecha* currentDate;
public:
    Biblioteca();
    ~Biblioteca();
    //-------------------------------
    void setNombre(string nom);
    //-------------------------------
    void menu();
    //-------------------------------
    void InclusionDatosMats();

};



#endif //BIBLIOTECA_H

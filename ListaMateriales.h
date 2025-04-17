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
#ifndef LISTAMATERIALES_H
#define LISTAMATERIALES_H
#include "Lista.h"
#include "Material.h"
#include <sstream>
#include <iostream>

class Material;

class ListaMateriales {
private:
    Lista<Material>* subjects;
public:
    ListaMateriales();
    ~ListaMateriales();
//------------------------------------
    Lista<Material>* getLista();
    void agregarMaterial(Material* nuevo);
    void eliminarMaterial(string ID);
    Material* getMaterialEsp(string ID);
//------------------------------------
    string toString(); // El toString general
    string MaterialBasico();
//------------------------------------
};



#endif //LISTAMATERIALES_H

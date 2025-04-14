
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

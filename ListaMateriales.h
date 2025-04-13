
#ifndef LISTAMATERIALES_H
#define LISTAMATERIALES_H
#include "Lista.h"
#include "Material.h"


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
    string cursoBasico();
//------------------------------------
};



#endif //LISTAMATERIALES_H

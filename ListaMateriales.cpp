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

#include "ListaMateriales.h"
#include <sstream>
ListaMateriales::ListaMateriales() {subjects = new Lista<Material>;}
ListaMateriales::~ListaMateriales() {delete subjects;}

//------------------------------------------------------------------------------

Lista<Material> *ListaMateriales::getLista() {
    return subjects;
}

void ListaMateriales::agregarMaterial(Material *nuevo) { subjects->agregar(nuevo);}

void ListaMateriales::eliminarMaterial(string ID) {
    int borrar = 0;
    if (subjects->getNodoEsp(0)->getDato()->getNumCatalogo() == ID) {
        subjects->eliminarPos(0);
        return;
    }
    while (subjects->getNodoEsp(borrar)->getDato()->getNumCatalogo() != ID) {
        borrar++;
    }
    subjects->eliminarPos(borrar);
}

Material *ListaMateriales::getMaterialEsp(string ID) {
    int buscar = 0;
    if (subjects->getNodoEsp(0)->getDato()->getNumCatalogo() == ID) {
        return subjects->getNodoEsp(0)->getDato();
    }
    while (subjects->getNodoEsp(buscar)->getDato()->getNumCatalogo() != ID) {
        buscar++;
    }
    return subjects->getNodoEsp(buscar)->getDato();
}

//-----------------------------------------------------------------------------------

string ListaMateriales::toString() {
    stringstream s;
    s <<  *subjects << endl;
    return s.str();
}

string ListaMateriales::MaterialBasico() {
    stringstream s;
    s << "Listado de cursos: \n" << endl;
    for (int i = 0; i < subjects->getSize(); i++) {
        s << "->" << subjects->getNodoEsp(i)->getDato()->getNumCatalogo() << "-" << subjects->getNodoEsp(i)->getDato()->getNombre() << endl;
    }
    return s.str();
}


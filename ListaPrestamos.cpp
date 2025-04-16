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
#include "ListaPrestamos.h"

ListaPrestamos::ListaPrestamos() {prestamos = new Lista<Prestamo>;}
ListaPrestamos::~ListaPrestamos() {
    delete prestamos;
}
Lista<Prestamo> *ListaPrestamos::getLista() {
    return prestamos;
}
void ListaPrestamos::nuevoPrestamo(Prestamo *nuevo) {
    prestamos->agregar(nuevo);
}
string ListaPrestamos::toString() {
    stringstream s;
    s << *prestamos;
    return s.str() ;
}
Prestamo* ListaPrestamos::buscar(string numCatalogo) {
    int buscar = 0;
    if (prestamos->getNodoEsp(0)->getDato()->getMaterial()->getNumCatalogo() == numCatalogo) {
        return prestamos->getNodoEsp(0)->getDato();
    }
    while (prestamos->getNodoEsp(buscar)->getDato()->getMaterial()->getNumCatalogo() != numCatalogo) {
        buscar++;
    }
    return prestamos->getNodoEsp(buscar)->getDato();
}



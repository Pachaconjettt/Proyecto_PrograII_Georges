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
#ifndef LISTAPRESTAMOS_H
#define LISTAPRESTAMOS_H

#include "Prestamo.h"
#include "Lista.h"
#include "Nodo.h"
#include "Excepciones.h"


class ListaPrestamos {
private:
    Lista<Prestamo>* prestamos;
public:
    ListaPrestamos();
    ~ListaPrestamos();
    //-------------------------------------------------------------
    Lista<Prestamo>* getLista();
    void nuevoPrestamo(Prestamo* nuevo);
    //--------------------------------------------------------------
    string toString();
    Prestamo* buscar(string numCatalogo);
    //--------------------------------------------------------------
    //--------------------------------------------------------------
};



#endif //LISTAPRESTAMOS_H

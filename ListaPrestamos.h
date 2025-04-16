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

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
#include "ListaUsuarios.h"
ListaUsuarios::ListaUsuarios() {customers = new Lista<Usuario>;}
ListaUsuarios::~ListaUsuarios() {delete customers;}

//----------------------------------------------------

Lista<Usuario> *ListaUsuarios::getLista() {return customers;}

//----------------------------------------------------

void ListaUsuarios::agregarUsuario(Usuario *nuevo) {customers->agregar(nuevo);}

//---------------------------------------------------

void ListaUsuarios::eliminarUsuario(string ID) {
    int borrar = 0;
    if (customers->getNodoEsp(0)->getDato()->getIdentificacion() == ID) {
        customers->eliminarPos(0);
        return;
    }
    while (customers->getNodoEsp(borrar)->getDato()->getIdentificacion() != ID) {
        borrar++;
    }
    customers->eliminarPos(borrar);
}

Usuario *ListaUsuarios::getUsuario(string ID) {
    int buscar = 0;
    if (customers->getNodoEsp(0)->getDato()->getIdentificacion() == ID) {
        return customers->getNodoEsp(0)->getDato();
    }
    while (customers->getNodoEsp(buscar)->getDato()->getIdentificacion() != ID) {
        buscar++;
    }
    return customers->getNodoEsp(buscar)->getDato();
}


//----------------------------------------------------------------------------

string ListaUsuarios::Activos() {
    stringstream s;
    for (int i = 0; i < customers->getSize(); i++) {
        if (customers->getNodoEsp(i)->getDato()->getEstado() == 1) {
            s << *customers->getNodoEsp(i) << endl;
        }
    }
    return s.str();
}

string ListaUsuarios::Inactivos() {
    stringstream s;
    for (int i = 0; i < customers->getSize(); i++) {
        if (customers->getNodoEsp(i)->getDato()->getEstado() == 2) {
            s << *customers->getNodoEsp(i) << endl;
        }
    }
    return s.str();
}

//---------------------------------------------------------------------------

string ListaUsuarios::toString() {
    stringstream s;
    s << *customers << endl;
    return s.str();
}

string ListaUsuarios::sencilloClientes() {
    stringstream s;
    for (int i = 0; i < customers->getSize();  i++) {
        s << customers->getNodoEsp(i)->getDato()->getIdentificacion() << "-" << customers->getNodoEsp(i)->getDato()->getNombre() << endl;
    }
    return s.str();
}



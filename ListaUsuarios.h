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
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include "Lista.h"
#include "Excepciones.h"
#include "Usuario.h"
#include "Nodo.h"
#include <iostream>
#include <sstream>
#include <string>


class Usuario;
class ListaUsuarios {
private:
    Lista<Usuario>* customers;
public:
    ListaUsuarios();
    ~ListaUsuarios();
    //-------------------------------------------------
    Lista<Usuario>* getLista();
    void agregarUsuario(Usuario* nuevo);
    void eliminarUsuario(string ID);
    Usuario* getUsuario(string ID);
    string Activos();
    string Inactivos();
    //-------------------------------------------------
    string toString();
    string sencilloClientes();
};



#endif //LISTAUSUARIOS_H

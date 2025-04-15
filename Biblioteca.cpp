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
#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    nombre  = " ";
    usuarios = new ListaUsuarios;
    mats = new ListaMateriales;
}
Biblioteca::~Biblioteca() {

}

void Biblioteca::menu() {
    bool yes = true;
    int opcion;
    ManejoArchivos* m = new ManejoArchivos;
    cout << m->Logo() << endl;
    system("pause");
    system("cls");
}



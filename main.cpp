/* -------------------------------------------------------------------+
* |
* (c) 2025 |
* EIF204 - Programación 2 |
* 1er ciclo 2025 |
* NRC 41371 – Grupo 05 |
* Proyecto 1 |d
* |
* 1-1977-0043; Retana Segura, Efraín |
* |
* versión 1.0.0 2025-04-01 |
* |
* -------------------------------------------------------------------+
*/
#ifndef MAIN_H
#define MAIN_H

#include "Biblioteca.h"

int main() {
    system("color 03");

    Biblioteca* b = new Biblioteca;
    b->menu();
    return 0;
}

#endif // MAIN_H
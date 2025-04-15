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

#include "Excepciones.h"

void IntOutRange(int minR, int maxR, int var, bool cont) {
    if (var > maxR || var < minR) {
        throw invalid_argument("Fuera de rango!!!");
    }
    cont = false;
}

void intNegative(int n) {
    if (n < 0) {
        throw invalid_argument("No se pueden ingresar valores negativos!!!");
    }
}

void invalidChar(char comp, char dat) {
    if (comp != dat) {
        throw invalid_argument("Caracter no valido!!!");
    }
}
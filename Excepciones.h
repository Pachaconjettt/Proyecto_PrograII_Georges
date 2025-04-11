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
#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <iostream>
#include <sstream>
using namespace std;

//Control de excepciones muy generales
void inOutRange(int, minR, int maxR, int var, bool);
void intNegative(int n);
void invalidChar(char comp, char dat);



#endif //EXCEPCIONES_H

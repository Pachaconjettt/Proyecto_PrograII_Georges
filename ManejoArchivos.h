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
#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


class ManejoArchivos {
public:
    ManejoArchivos();
    string Logo();
};

int convertirInt(string s);
float convertirFloat(string s);
char convertirChar(string s);
bool convertirBool(string s);




#endif //MANEJOARCHIVOS_H

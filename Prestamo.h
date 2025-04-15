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

#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "Usuario.h"
#include "Material.h"
#include <string>


class Prestamo {
private:
    Usuario* user;
    Material* mats;
    string fechaPrestamo;
    string fechaDevolucion;
public:
    Prestamo(Usuario*,Material*,string,string);
    Usuario* getUsuario();
    Material* getMaterial();
    string getFechaPrestamo();
    string getFechaDevolucion();
    string toString();
};



#endif //PRESTAMO_H

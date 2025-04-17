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
#include "Prestamo.h"
#include <sstream>

// Constructor
Prestamo::Prestamo(Usuario* user, Material* mats, string fechaPrest, string fechaDev)
    : user(user), mats(mats), fechaPrestamo(fechaPrest), fechaDevolucion(fechaDev) {}

// Getters
Usuario* Prestamo::getUsuario() {
    return user;
}

Material* Prestamo::getMaterial() {
    return mats;
}

string Prestamo::getFechaPrestamo() {
    return fechaPrestamo;
}

string Prestamo::getFechaDevolucion() {
    return fechaDevolucion;
}

// toString method
string Prestamo::toString() const {
    std::stringstream s;
    s << "Usuario: " << user->getNombreCompleto()
      << ", Material: " << mats->getNombre()
      << ", Fecha de Préstamo: " << fechaPrestamo
      << ", Fecha de Devolución: " << fechaDevolucion;
    return s.str();
}
ostream& operator<<(ostream& output, const Prestamo& prestamo) {
    output << prestamo.toString();
    return output;
}
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
#ifndef GESTORPRESTAMOS_H
#define GESTORPRESTAMOS_H
#include "ListaPrestamos.h"
#include "ListaUsuarios.h"
#include "ListaMateriales.h"
#include <iostream>
#include <ctime>
#include <iomanip>
class GestorPrestamos {
private:
    ListaPrestamos* listaPrestamos;
    ListaUsuarios* usuarios;
    ListaMateriales* materiales;
public:
    GestorPrestamos(ListaUsuarios*,ListaMateriales*);
    ~GestorPrestamos();
    void registrarPrestamo(string& idUsuario, string& numCatalogo, const string& FechaPrestamo);
    void registrarDevolucion( const string& numCatalogo);
    void reportePrestamo() const;
    void reportePrestamosPorUsuario(const string& idUsuario) const;
    string calcularFechaDevolucion(string& fechaInicio, int dias);
private:
    string calcularFechaDevolucion(const string& fechaInicio, int dias) {
        // Parse the input date (format: YYYY-MM-DD)
        std::tm fecha = {};
        std::istringstream ss(fechaInicio);
        ss >> std::get_time(&fecha, "%Y-%m-%d");
        if (ss.fail()) {
            throw std::invalid_argument("Formato de fecha inválido. Use YYYY-MM-DD.");
        }

        // Add the specified number of days
        fecha.tm_mday += dias;
        std::mktime(&fecha); // Normalize the date (handles month/year overflow)

        // Convert back to string format
        std::ostringstream resultado;
        resultado << std::put_time(&fecha, "%Y-%m-%d");
        return resultado.str();
    }
};




#endif //GESTORPRESTAMOS_H

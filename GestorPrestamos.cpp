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
#include "GestorPrestamos.h"
GestorPrestamos::GestorPrestamos(ListaUsuarios * usuarios, ListaMateriales * mats) :usuarios(usuarios), materiales(mats) {
listaPrestamos = new ListaPrestamos();
}
GestorPrestamos::~GestorPrestamos() {
    delete listaPrestamos;
}
ListaPrestamos* GestorPrestamos::getListaPrestamos(){return listaPrestamos;}
void GestorPrestamos::registrarPrestamo(string &idUsuario, string &numCatalogo, const string &FechaPrestamo) {
    Usuario* Usuario = usuarios->getUsuario(idUsuario);
    Material* material = materiales->getMaterialEsp(numCatalogo);

    if (!Usuario || !material) {
        cout << "Usuario o material no encontrado" << endl;
        return;
    }
    if (material->getEstadoMaterial() != 1) { //Buen estado
        cout << "El material no esta disponible para prestamo" << endl;
        return;
    }
    int diasPrestamo = 0;
    if (dynamic_cast<Libro*>(material)) {
        diasPrestamo = 7;
    } else if (dynamic_cast<Revista*>(material)) {
        diasPrestamo = 2;
    } else if (dynamic_cast<MaterialDigital*>(material)) {
        diasPrestamo = 5;
    } else {
        std::cout << "Tipo de material no soportado para préstamo." << std::endl;
        return;
    }
    string fechaDevolucion = calcularFechaDevolucion(FechaPrestamo, diasPrestamo);
    Prestamo* nuevoPrestamo = new Prestamo(Usuario, material, FechaPrestamo, fechaDevolucion);
    listaPrestamos->nuevoPrestamo(nuevoPrestamo);

    std::cout << "Préstamo registrado exitosamente. Fecha de devolución: " << fechaDevolucion << std::endl;
}


void GestorPrestamos::registrarDevolucion(const std::string& numCatalogo) {
    Prestamo* prestamo = listaPrestamos->buscar(numCatalogo); // Use buscar to find the loan

    if (prestamo) {
        listaPrestamos->getLista()->eliminar(prestamo); // Remove the loan from the list
        std::cout << "Devolución registrada exitosamente." << std::endl;
    } else {
        std::cout << "Préstamo no encontrado." << std::endl;
    }
}

void GestorPrestamos::reportePrestamo() const {
    std::cout << "Reporte de préstamos activos:" << std::endl;
    std::cout << listaPrestamos->toString() << std::endl;
}
void GestorPrestamos::reportePrestamosPorUsuario(const std::string& idUsuario) const {
    std::cout << "Reporte de préstamos para el usuario: " << idUsuario << std::endl;

    Nodo<Prestamo>* actual = listaPrestamos->getLista()->getNodoEsp(0); // Start from the first node
    while (actual != nullptr) {
        Prestamo* prestamo = actual->getDato();
        if (prestamo->getUsuario()->getIdentificacion() == idUsuario) {
            std::cout << prestamo->toString() << std::endl;
        }
        actual = actual->getSig(); // Move to the next node
    }
}
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
#include "Excepciones.h"
Biblioteca::Biblioteca() {
    nombre  = " ";
    usuarios = new ListaUsuarios;
    mats = new ListaMateriales;
    currentDate =  new Fecha;
}
void Biblioteca::setNombre(string nom) {this->nombre = nom;}
Biblioteca::~Biblioteca() {

}
void Biblioteca::menu() {
    bool yes = true;
    int opcion;
    ManejoArchivos* m = new ManejoArchivos;
    cout << m->Logo() << endl;
    system("pause");
    system("cls");

    cout << *currentDate << endl;
    cout << "\nBienvenido a la Biblioteca -[ "  << nombre << " ]-" << endl << endl;
    system("pause");

    do {
        system("cls");
        cout << "\t     Menu Principal" << endl;
        cout << "\n_._._._._._._._._._._._._._._._._._._._" << endl;
        cout << "\n1. Inclusión de datos de materiales (libros, revistas, artículos, videos, material digital)" << endl;
        cout << "\n2. Modificación de datos de materiales" << endl;
        cout << "\n3. Inclusión de usuarios" << endl;
        cout << "\n4. Modificación de datos de usuarios" << endl;
        cout << "\n5. Registro de solicitudes de préstamo y devoluciones" << endl;
        cout << "\n6. Reporte de inventario de materiales" << endl;
        cout << "\n7. Reporte de usuarios" << endl;
        cout << "\n8. Reporte de materiales en préstamo (general y por tipo de material)" << endl;
        cout << "\n9. Reporte de préstamos por usuario" << endl;
        cout << "\n_._._._._._._._._._._._._._._._._._._._\n" << endl;
        cout << "\nDigite una opcion: ";
        cin >> opcion;

        try {
            IntOutRange(1, 9, opcion, yes);
        } catch (invalid_argument &e) {
            system("cls");
            cout << e.what() << "\n" << endl;
            system("pause");
            continue; // Reinicia el bucle
        }

        system("cls");
        switch (opcion) {
            case 1:
                InclusionDatosMats();
            break;
        }
    } while (opcion != 6);
}

void Biblioteca::InclusionDatosMats() {
    system("cls");
    cout << "Ingresa el nombre del material" << endl;
}





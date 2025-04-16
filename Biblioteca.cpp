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
                system("cls");
                InclusionDatosMats();
                cin.ignore();
                cin.get();
            break;
            case 2:
                system ("cls");
                ReporteDeMats();
                cin.ignore();
                cin.get();
        }
    } while (opcion != 6);
    system("cls");
}

void Biblioteca::InclusionDatosMats() {
    int tipoMaterial;
    cout << "Seleccione el tipo de material\n";
    cout << "1. Libro\n";
    cout << "2. Revista\n";

    cout << "3. Material Digital\n";
    cout << "Opcion: ";
    cin >> tipoMaterial;

    string NumClasificacion, NumCatalogo, Titulo, Autores, PalabrasClave;
    int EstadoMats;

    //Atributos especificos
    string ubicacionFisica, formato;
    int numero, volumen;
    bool accessH;

    cout << "Ingrese el número de clasificación: ";
    cin >> NumClasificacion;
    cout << "Ingrese el número de catálogo: ";
    cin >> NumCatalogo;
    cout << "Ingrese el título: ";
    cin.ignore();
    getline(cin, Titulo);
    cout << "Ingrese los autores: ";
    getline(cin, Autores);
    cout << "Ingrese las palabras clave: ";
    getline(cin, PalabrasClave);
    cout << "Ingrese el estado del material (1:Buen estado, 2: Minimo de daños, 3:Mal Estado): ";
    cin >> EstadoMats;

    Material* nuevoMaterial = nullptr;

    switch (tipoMaterial) {
        case 1: //Libro
            cout << "Ingrese la ubicacion fisica: ";
            cin.ignore();
            getline(cin, ubicacionFisica);
            nuevoMaterial = new Libro(NumClasificacion, NumCatalogo,Titulo,Autores,PalabrasClave,EstadoMats,ubicacionFisica);
            break;
        case 2: //Revista
            cout << "Ingrese la ubicacion fisica: ";
            cin.ignore();
            getline(cin, ubicacionFisica);
            cout << "Ingrese el número: ";
            cin >> numero;
            cout << "Ingrese el volumen: ";
            cin >> volumen;
            nuevoMaterial = new Revista(NumClasificacion, NumCatalogo,Titulo,Autores,PalabrasClave,EstadoMats,ubicacionFisica,numero,volumen);
            break;
        case 3: // Material Digital;
            cout << "Ingrese el formato: ";
            cin.ignore();
            getline(cin, formato);
            cout << "¿El acceso está habilitado? (1 = sí, 0 = no): ";
            cin >> accessH;
            nuevoMaterial = new MaterialDigital(NumClasificacion, NumCatalogo, Titulo, Autores, PalabrasClave, EstadoMats, formato, accessH);
            break;
        default:
            cout << "Opción no válida." << endl;
            return;
    }
    if (nuevoMaterial != nullptr) {
        mats->agregarMaterial(nuevoMaterial);
        cout << "Material agregado exitosamente" << endl;
    }
}



void Biblioteca::ReporteDeMats() {
cout << "\t\t\t Reporte de inventario de materiales \t\t\t" << endl;
    cout << mats->toString() << endl ;
}
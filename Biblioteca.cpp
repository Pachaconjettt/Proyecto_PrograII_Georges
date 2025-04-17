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
    archivos = new AdministradorAlmacenamiento();
    nombre  = " ";
    usuarios = archivos->recuperarUsuarios();
    mats = archivos->recuperarMateriales();
    prestamos = archivos->recuperarPrestamos(usuarios, mats);
    gestor = new GestorPrestamos(usuarios, mats);
    currentDate =  new Fecha;
}
void Biblioteca::setNombre(string nom) {this->nombre = nom;}
Biblioteca::~Biblioteca() {

}
void Biblioteca::menu() {
    bool yes = true;
    int opcion;
    ManejoArchivos* m = new ManejoArchivos;
    cout << m->Logo() << endl; // Este logo solo sirve si uno usa la forma de que todo los documentos este en la misma root(raiz del programa) que es algo que uno tiene que modificar en su propio editor/compilador
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
        cout << "\n10. Guardar Datos" << endl;
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
                system("cls");
                ModificarDatosMats();
                cin.ignore();
                cin.get();
            break;
            case 3:
                system("cls");
                InclusionUsuarios();
                cin.ignore();
                cin.get();
            break;
            case 4:
                system("cls");
                ModificacionUsuario();
                cin.ignore();
                cin.get();
            break;
            case 5:
                system("cls");
                RegistroPrestaYDevo();
                cin.ignore();
                cin.get();
            break;

            case 6:
                system ("cls");
                ReporteDeMats();
                cin.ignore();
                cin.get();
            break;

            case 7:
                system("cls");
                ReporteUsuarios();
                cin.ignore();
                cin.get();
            break;

            case 8:
                system("cls");
                ReportePrestamo();
                cin.ignore();
                cin.get();
            break;

            case 9:
                system("cls");
                ReportePrestamosXusuario();
                cin.ignore();
                cin.get();
            break;
            case 10:
                system("cls");
                guardarDatos();
                cin.ignore();
                cin.get();
        }
    } while (opcion != 11);
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

void Biblioteca::ModificarDatosMats() {
    string numCatalogo;
    cout << "Materiales registrados en el programa" << endl;
    cout << mats->toString() << endl;
    cout << "Ingrese el número de catálogo del material a modificar: ";
    cin >> numCatalogo;

    Material* material = mats->getMaterialEsp(numCatalogo);

    if (material == nullptr) {
        cout << "Material no encontrado." << endl;
        return;
    }

    cout << "Material encontrado: " << endl;
    cout << material->toString() << endl;

    int opcion;
    cout << "Seleccione el atributo a modificar:\n";
    cout << "1. Título\n";
    cout << "2. Autores\n";
    cout << "3. Palabras clave\n";
    cout << "4. Estado del material\n";

    // Opciones específicas para las clases hijas
    if (dynamic_cast<Libro*>(material)) {
        cout << "5. Ubicación física (Libro)\n";
    } else if (dynamic_cast<Revista*>(material)) {
        cout << "5. Ubicación física (Revista)\n";
        cout << "6. Número (Revista)\n";
        cout << "7. Volumen (Revista)\n";
    } else if (dynamic_cast<MaterialDigital*>(material)) {
        cout << "5. Formato (Material Digital)\n";
        cout << "6. Acceso habilitado (Material Digital)\n";
    }

    cout << "Opción: ";
    cin >> opcion;

    cin.ignore(); // Limpiar el buffer
    switch (opcion) {
        case 1: {
            string nuevoTitulo;
            cout << "Ingrese el nuevo título: ";
            getline(cin, nuevoTitulo);
            material->setTitulo(nuevoTitulo);
            break;
        }
        case 2: {
            string nuevosAutores;
            cout << "Ingrese los nuevos autores: ";
            getline(cin, nuevosAutores);
            material->setAutores(nuevosAutores);
            break;
        }
        case 3: {
            string nuevasPalabrasClave;
            cout << "Ingrese las nuevas palabras clave: ";
            getline(cin, nuevasPalabrasClave);
            material->setPalabras(nuevasPalabrasClave);
            break;
        }
        case 4: {
            int nuevoEstado;
            cout << "Ingrese el nuevo estado del material (1: Buen estado, 2: Mínimo de daños, 3: Mal estado): ";
            cin >> nuevoEstado;
            material->setEstadoMats(nuevoEstado);
            break;
        }
        case 5: {
            if (Libro* libro = dynamic_cast<Libro*>(material)) {
                string nuevaUbicacion;
                cout << "Ingrese la nueva ubicación física: ";
                cin.ignore();
                getline(cin, nuevaUbicacion);
                libro->setUbicacionFisica(nuevaUbicacion);
            } else if (Revista* revista = dynamic_cast<Revista*>(material)) {
                string nuevaUbicacion;
                cout << "Ingrese la nueva ubicación física: ";
                cin.ignore();
                getline(cin, nuevaUbicacion);
                revista->setUbicacionFisica(nuevaUbicacion);
            } else if (MaterialDigital* digital = dynamic_cast<MaterialDigital*>(material)) {
                string nuevoFormato;
                cout << "Ingrese el nuevo formato: ";
                cin.ignore();
                getline(cin, nuevoFormato);
                digital->setFormato(nuevoFormato);
            }
            break;
        }
        case 6: {
            if (Revista* revista = dynamic_cast<Revista*>(material)) {
                int nuevoNumero;
                cout << "Ingrese el nuevo número: ";
                cin >> nuevoNumero;
                revista->setNumero(nuevoNumero);
            } else if (MaterialDigital* digital = dynamic_cast<MaterialDigital*>(material)) {
                bool nuevoAcceso;
                cout << "¿El acceso está habilitado? (1 = sí, 0 = no): ";
                cin >> nuevoAcceso;
                digital->setAccessoHabilitado(nuevoAcceso);
            }
            break;
        }
        case 7: {
            if (Revista* revista = dynamic_cast<Revista*>(material)) {
                int nuevoVolumen;
                cout << "Ingrese el nuevo volumen: ";
                cin >> nuevoVolumen;

                revista->setVolumen(nuevoVolumen);
            }
            break;
        }
        default:
            cout << "Opción no válida." << endl;
            return;
    }

    cout << "Material modificado exitosamente." << endl;
}

void Biblioteca::InclusionUsuarios() {
    string identificacion, nombre, apellidos;
    int estado;
    cout << "Ingrese la identificación del usuario: ";
    cin >> identificacion;
    cout << "Ingrese el nombre del usuario: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese los apellidos del usuario: ";
    getline(cin, apellidos);
    cout << "Ingrese el estado del usuario (1: Activo, 2: Inactivo): ";
    cin >> estado;

    // Validar el estado
    if (estado != 1 && estado != 2) {
        cout << "Estado inválido. Debe ser 1 (Activo) o 2 (Inactivo)." << endl;
        return;
    }

    // Crear un nuevo usuario
    Usuario* nuevoUsuario = new Usuario(identificacion, nombre, apellidos, estado);

    // Agregar el usuario a la lista
    usuarios->agregarUsuario(nuevoUsuario);

    cout << "Usuario agregado exitosamente." << endl;
}
void Biblioteca::ModificacionUsuario() {
    string identificacion;
    cout << "Usuarios registrados en el programa :" << endl;
    cout << usuarios->toString() << endl;
    cout << "Ingrese la identificación del usuario a modificar: ";
    cin >> identificacion;

    Usuario* usuario = usuarios->getUsuario(identificacion);

    if (usuario == nullptr) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    cout << "Usuario encontrado: " << endl;
    cout << usuario->toString() << endl;

    int opcion;
    cout << "Seleccione el atributo a modificar:\n";
    cout << "1. Nombre\n";
    cout << "2. Apellidos\n";
    cout << "3. Estado\n";
    cout << "Opción: ";
    cin >> opcion;

    cin.ignore(); // Limpiar el buffer
    switch (opcion) {
        case 1: {
            string nuevoNombre;
            cout << "Ingrese el nuevo nombre: ";
            getline(cin, nuevoNombre);
            usuario->setNombre(nuevoNombre);
            break;
        }
        case 2: {
            string nuevosApellidos;
            cout << "Ingrese los nuevos apellidos: ";
            getline(cin, nuevosApellidos);
            usuario->setApellidos(nuevosApellidos);
            break;
        }
        case 3: {
            int nuevoEstado;
            cout << "Ingrese el nuevo estado (1: Activo, 2: Inactivo): ";
            cin >> nuevoEstado;
            if (nuevoEstado != 1 && nuevoEstado != 2) {
                cout << "Estado inválido. Debe ser 1 (Activo) o 2 (Inactivo)." << endl;
                return;
            }
            usuario->setEstado(nuevoEstado);
            break;
        }
        default:
            cout << "Opción no válida." << endl;
        return;
    }
    cout << "Usuario modificado exitosamente." << endl;
}

void Biblioteca::RegistroPrestaYDevo() {
    int opcion;
    do {
        cout << "\tRegistro de Préstamos y Devoluciones\n";
        cout << "1. Registrar Préstamo\n";
        cout << "2. Registrar Devolución\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Usuarios registrados en el programa" << endl;
                cout << usuarios->toString() << endl;
                string idUsuario, numCatalogo, fechaPrestamo;
                cout << "Ingrese el ID del usuario: ";
                cin >> idUsuario;
                cout << "Materiales registrados en el sistema" << endl;
                cout << mats->toString() << endl;
                cout << "Ingrese el número de catálogo del material: ";
                cin >> numCatalogo;
                cout << "Ingrese la fecha del préstamo (YYYY-MM-DD): ";
                cin >> fechaPrestamo;

                gestor->registrarPrestamo(idUsuario, numCatalogo, fechaPrestamo);
                break;
            }
            case 2: {
                string numCatalogo;
                gestor->reportePrestamo();
                cout << "Materiales registrados en el programa" << endl;
                cout << mats->toString() << endl;
                cout << "Ingrese el número de catálogo del material: ";
                cin >> numCatalogo;

                gestor->registrarDevolucion(numCatalogo);
                break;
            }
            case 3:
                cout << "Saliendo del registro de préstamos y devoluciones.\n";
            break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}
void Biblioteca::ReporteDeMats() {
cout << "\t\t\t Reporte de inventario de materiales \t\t\t" << endl;
    cout << mats->toString() << endl ;
}
void Biblioteca::ReporteUsuarios() {
    cout << "\t\t\t Reporte de Usuario \t\t\t" << endl;
    cout << usuarios->toString() << endl ;
}
void Biblioteca::ReportePrestamo() {
    cout << "\t\t\t Reporte de Prestamo \t\t\t" << endl;
    gestor->reportePrestamo();
}
void Biblioteca::ReportePrestamosXusuario() {
    string id;
    cout << "\t\t\t Reporte de Prestamo X Usuario\t\t\t" << endl;
    cout <<  "Usuarios Registrados en el sistema..." << endl;
    cout << usuarios->toString() << endl;
    cout << "Digite el nombre del usuario que desea ver los prestamos que lleva..." << endl;
    cin >> id;

    gestor->reportePrestamosPorUsuario(id);
}

void Biblioteca::guardarDatos() {
    // Save materials
    archivos->guardarMateriales(mats);

    // Save users
    archivos->guardarUsuarios(usuarios);

    // Save loans
    archivos->guardarPrestamos(prestamos);

    // Confirmation message
    cout << "Los datos han sido guardados exitosamente." << endl;
}

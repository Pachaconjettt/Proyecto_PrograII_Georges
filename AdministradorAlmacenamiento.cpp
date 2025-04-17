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
#include "AdministradorAlmacenamiento.h"
AdministradorAlmacenamiento::AdministradorAlmacenamiento() {}
void AdministradorAlmacenamiento::guardarMateriales(ListaMateriales* _lis) {
    salida.open("Materiales.txt");
    if (!salida.is_open()) {
        cerr << "Error: No se pudo abrir el archivo Materiales.txt para escritura." << endl;
        return;
    }

    Nodo<Material>* aux = _lis->getLista()->getNodoEsp(0);
    while (aux) {
        Material* material = aux->getDato();
        if (material) {
            material->guardar(salida); // Polymorphic save
            cout << "Guardando material: " << material->toString() << endl; // Debugging output
        } else {
            cerr << "Error: Nodo con material nulo." << endl;
        }
        aux = aux->getSig();
    }

    salida.close();
    cout << "Materiales guardados correctamente." << endl;
}
void AdministradorAlmacenamiento::guardarUsuarios(ListaUsuarios* _lis) {
    salidaAux.open("Usuarios.txt");
    if (salidaAux.good()) {
        Nodo<Usuario>* aux = _lis->getLista()->getNodoEsp(0);
        while (aux) {
            salidaAux << aux->getDato()->getIdentificacion() << "\t";
            salidaAux << aux->getDato()->getNombre()  << "\t";
            salidaAux << aux->getDato()->getApellidos() << "\t";
            salidaAux << aux->getDato()->getEstado() << "\n";
            aux = aux->getSig();
        }
    }
    salidaAux.close();
}
void AdministradorAlmacenamiento::guardarPrestamos(ListaPrestamos* _lis) {
    salida.open("Prestamos.txt");
    if (salida.good()) {
        Nodo <Prestamo>* aux = _lis->getLista()->getNodoEsp(0);
        while (aux) {
            salida << aux->getDato()->getUsuario()->getIdentificacion() << "\t";
            salida << aux->getDato()->getMaterial()->getNumCatalogo() << "\t";
            salida << aux->getDato()->getFechaPrestamo() << "\t";
            salida << aux->getDato()->getFechaDevolucion() << "\t";
            aux = aux->getSig();
        }
    }
    salida.close();
}
void AdministradorAlmacenamiento::guardarGestor(GestorPrestamos* gestor, const std::string& filename) {
    if (!gestor) {
        std::cerr << "Error: El gestor es nulo." << std::endl;
        return;
    }

    std::ofstream salida(filename);
    if (!salida.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << " para escritura." << std::endl;
        return;
    }

    Nodo<Prestamo>* aux = gestor->getListaPrestamos()->getLista()->getNodoEsp(0); // Get the first node
    while (aux) {
        Prestamo* prestamo = aux->getDato();
        if (prestamo) {
            salida << prestamo->getUsuario()->getIdentificacion() << "\t"
                   << prestamo->getMaterial()->getNumCatalogo() << "\t"
                   << prestamo->getFechaPrestamo() << "\t"
                   << prestamo->getFechaDevolucion() << "\n";
        }
        aux = aux->getSig(); // Move to the next node
    }

    salida.close();
    std::cout << "Datos del gestor guardados correctamente en " << filename << "." << std::endl;
}
ListaMateriales* AdministradorAlmacenamiento::recuperarMateriales() {
    ListaMateriales* listaAux = new ListaMateriales();
    entrada.open("Materiales.txt");
    string NumC, NumCata, Titulo, Autors, Palabras_s;
    string EstadoMat, numero, volumen;
    string Ubicacion,format;
    string accessH; // bool
    string tipo; // para comparar
    while (entrada >> tipo) {
        if (tipo == "1" ) {
            getline(entrada, NumC, '\t');
            getline(entrada, NumCata, '\t');
            getline(entrada, Titulo, '\t');
            getline(entrada, Autors, '\t');
            getline(entrada,Palabras_s, '\t');
            getline(entrada, EstadoMat, '\t');
            getline(entrada, Ubicacion, '\n');
            if (!NumC.empty() && !NumCata.empty() && !Titulo.empty() && !Autors.empty() && !Palabras_s.empty() && !EstadoMat.empty() && !Ubicacion.empty()) {
                Libro* book = new Libro(NumC,NumCata,Titulo,Autors,Palabras_s, convertirInt(EstadoMat), Ubicacion);
                listaAux->agregarMaterial(book);
            }
        }
        else if (tipo == "2") {
            getline(entrada, NumC, '\t');
            getline(entrada, NumCata, '\t');
            getline(entrada, Titulo, '\t');
            getline(entrada, Autors, '\t');
            getline(entrada,Palabras_s, '\t');
            getline(entrada, EstadoMat, '\t');
            getline(entrada, Ubicacion, '\t');
            getline(entrada, numero, '\t');
            getline(entrada, volumen, '\n');
            Revista* magazine = new Revista(NumC,NumCata,Titulo,Autors,Palabras_s, convertirInt(EstadoMat), Ubicacion,convertirInt(numero),convertirInt(volumen));
            listaAux->agregarMaterial(magazine);
        }
        else if (tipo == "3") {
            getline(entrada, NumC, '\t');
            getline(entrada, NumCata, '\t');
            getline(entrada, Titulo, '\t');
            getline(entrada, Autors, '\t');
            getline(entrada,Palabras_s, '\t');
            getline(entrada, EstadoMat, '\t');
            getline(entrada, format, '\t');
            getline(entrada, volumen, '\n');
            MaterialDigital* matDigital = new MaterialDigital(NumC,NumCata,Titulo,Autors,Palabras_s, convertirInt(EstadoMat), format, convertirBool(accessH));
            listaAux->agregarMaterial(matDigital);
        }
    }
    entrada.close();
    return listaAux;
}
ListaUsuarios* AdministradorAlmacenamiento::recuperarUsuarios() {
    ListaUsuarios* listaAux = new ListaUsuarios();
    entradaAux.open("Usuarios.txt");
    string ID, name, apellidos;
    string estado;
    Usuario* eldep = nullptr;
    while (entradaAux.good()) {
        getline(entradaAux,ID, '\t');
        getline(entradaAux, name, '\t');
        getline(entradaAux, apellidos, '\t');
        getline(entradaAux, estado, '\n');
        if (!ID.empty() && !name.empty() && !apellidos.empty() && !estado.empty()) {
            eldep = new Usuario(ID, name,apellidos, convertirBool(estado));
        }
        if (entradaAux.good() && eldep)
            listaAux->agregarUsuario(eldep);
    }
    entradaAux.close();
    return listaAux;
}
ListaPrestamos* AdministradorAlmacenamiento::recuperarPrestamos(ListaUsuarios* usuarios, ListaMateriales* materiales) {
    ListaPrestamos* listaAux = new ListaPrestamos();
    entrada.open("Prestamos.txt");
    if (entrada.good()) {
        string userId, materialId, fechaPrestamo, fechaDevolucion;
        while (entrada >> userId >> materialId >> fechaPrestamo >> fechaDevolucion) {
            Usuario* user = usuarios->getUsuario(userId); // Retrieve user by ID
            Material* material = materiales->getMaterialEsp(materialId); // Retrieve material by catalog number
            if (user && material) {
                Prestamo* prestamo = new Prestamo(user, material, fechaPrestamo, fechaDevolucion);
                listaAux->nuevoPrestamo(prestamo);
            }
        }
    }
    entrada.close();
    return listaAux;
}
GestorPrestamos* AdministradorAlmacenamiento::recuperarGestor(GestorPrestamos* gestor, ListaUsuarios* usuarios, ListaMateriales* materiales, const std::string& filename) {
    if (!gestor || !usuarios || !materiales) {
        std::cerr << "Error: El gestor, usuarios o materiales son nulos." << std::endl;
        return nullptr;
    }

    std::ifstream entrada(filename);
    if (!entrada.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << filename << " para lectura." << std::endl;
        return nullptr;
    }

    std::string userId, materialId, fechaPrestamo, fechaDevolucion;
    while (entrada >> userId >> materialId >> fechaPrestamo >> fechaDevolucion) {
        Usuario* user = usuarios->getUsuario(userId); // Retrieve user by ID
        Material* material = materiales->getMaterialEsp(materialId); // Retrieve material by catalog number

        if (user && material) {
            Prestamo* prestamo = new Prestamo(user, material, fechaPrestamo, fechaDevolucion);
            gestor->getListaPrestamos()->nuevoPrestamo(prestamo); // Add the loan to the gestor
        } else {
            std::cerr << "Advertencia: Usuario o material no encontrado para el préstamo." << std::endl;
        }
    }

    entrada.close();
    std::cout << "Datos del gestor recuperados correctamente desde " << filename << "." << std::endl;
    return gestor;
}
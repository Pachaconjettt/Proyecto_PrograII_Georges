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
    salida.open("Archivos/Materiales.txt");
    if (salida.good()) {
        Nodo<Material>* aux = _lis->getLista()->getNodoEsp(0);
        while (aux) {
            aux->getDato()->guardar(salida); //Polimorfico
            aux = aux->getSig();
        }
    }
    salida.close();
}
void AdministradorAlmacenamiento::guardarUsuarios(ListaUsuarios* _lis) {
    salida.open("Archivos/Usuarios.txt");
    if (salida.good()) {
        Nodo<Usuario>* aux = _lis->getLista()->getNodoEsp(0);
        while (aux) {
            salida << aux->getDato()->getIdentificacion() << "\t";
            salida << aux->getDato()->getNombre()  << "\t";
            salida << aux->getDato()->getEstado() << "\n";
            aux = aux->getSig();
        }
    }
    salida.close();
}
void AdministradorAlmacenamiento::guardarPrestamos(ListaPrestamos* _lis) {
    salida.open("Archivos/Prestamos.txt");
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
ListaMateriales* AdministradorAlmacenamiento::recuperarMateriales() {
    ListaMateriales* listaAux = new ListaMateriales();
    entrada.open("Archivos/Materiales.txt");
    if (entrada.good()) {
        string tipo, numClasificacion, numCatalogo, titulo, autores, palabrasClave, estadoMaterial, ubicacionFisica, formato, accesoHabilitado;
        string estado, numero, volumen;
        while (entrada >> tipo) {
            if (tipo == "1") { // Libro
                entrada >> numClasificacion >> numCatalogo >> titulo >> autores >> palabrasClave >> estado >> ubicacionFisica;
                Libro* libro = new Libro(numClasificacion, numCatalogo, titulo, autores, palabrasClave, convertirInt(estado), ubicacionFisica);
                listaAux->agregarMaterial(libro);
            } else if (tipo == "2") { // Revista
                entrada >> numClasificacion >> numCatalogo >> titulo >> autores >> palabrasClave >> estado >> ubicacionFisica >> numero >> volumen;
                Revista* revista = new Revista(numClasificacion, numCatalogo, titulo, autores, palabrasClave, convertirInt(estado), ubicacionFisica, convertirInt(numero), convertirInt(volumen));
                listaAux->agregarMaterial(revista);
            } else if (tipo == "3") { // MaterialDigital
                entrada >> numClasificacion >> numCatalogo >> titulo >> autores >> palabrasClave >> estado >> formato >> accesoHabilitado;
                MaterialDigital* materialDigital = new MaterialDigital(numClasificacion, numCatalogo, titulo, autores, palabrasClave, convertirInt(estado), formato, convertirBool(accesoHabilitado));
                listaAux->agregarMaterial(materialDigital);
            }
        }
    }
    entrada.close();
    return listaAux;
}
ListaUsuarios * AdministradorAlmacenamiento::recuperarUsuarios() {
 ListaUsuarios* listaAux = new ListaUsuarios();
 entrada.open("Archivos/Usuarios.txt");
    string identificacion, nombre, apellidos;
    string estado;
    Usuario* eldep = nullptr;
    while (entrada.good()) {
        getline(entrada, identificacion, '\t');
        getline(entrada, nombre, '\t');
        getline(entrada, apellidos, '\t');
        getline(entrada, estado, '\n');
        if (!identificacion.empty() && !nombre.empty() && !apellidos.empty() && !estado.empty()) {
            eldep = new Usuario(identificacion, nombre, apellidos, convertirInt(estado));
        }
        if (entrada.good() && eldep)
            listaAux->agregarUsuario(eldep);
    }
    entrada.close();
    return listaAux;
}
ListaPrestamos* AdministradorAlmacenamiento::recuperarPrestamos(ListaUsuarios* usuarios, ListaMateriales* materiales) {
    ListaPrestamos* listaAux = new ListaPrestamos();
    entrada.open("Archivos/Prestamos.txt");
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
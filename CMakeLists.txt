cmake_minimum_required(VERSION 3.30)
project(Proyecto_PrograII_Georges)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_PrograII_Georges main.cpp
        Biblioteca.cpp
        Biblioteca.h
        Excepciones.cpp
        Excepciones.h
        main.cpp
        nodo.h
        Lista.h
        ManejoArchivos.cpp
        ManejoArchivos.h
        Material.cpp
        Material.h
        ListaMateriales.cpp
        ListaMateriales.h
        Usuario.cpp
        Usuario.h
        ListaUsuarios.cpp
        ListaUsuarios.h
        Prestamo.cpp
        Prestamo.h
        Fecha.cpp
        Fecha.h
        ListaPrestamos.cpp
        ListaPrestamos.h
        GestorPrestamos.cpp
        GestorPrestamos.h
        AdministradorAlmacenamiento.cpp
        AdministradorAlmacenamiento.h)

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

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <sstream>
using namespace std;

// Clase de tipo plantilla por lo que no se necesita un cpp

template <typename T>
class Nodo {
private:
    T * dato;
    Nodo<T>* sig;
public:
    Nodo(T*);
    ~Nodo();
    //-----------------------------------------------------------
    void setSig(Nodo<T>*);
    void setDato(T*);
    //-----------------------------------------------------------
    T* getDato();
    Nodo<T>* getSig();
    //-----------------------------------------------------------
    string toString() const;
};

template<typename T>
Nodo<T>::Nodo(T * info) {
    this->dato = info;
    sig = NULL;
}
template<typename T>
Nodo<T>::~Nodo() {}

//---------------------------------------------------------------

template<typename T>
void Nodo<T>::setSig(Nodo<T> * next) {this->sig = next;}

template<typename T>
void Nodo<T>::setDato(T * info) {this->dato = info;}

//----------------------------------------------------------------

template<typename T>
T *Nodo<T>::getDato() {return this->dato;}

template <typename T>
Nodo<T> * Nodo<T>::getSig() {return this->sig;}

//---------------------------------------------------------------

template<typename T>
string Nodo<T>::toString() const {
    stringstream s;
    s << *dato;
    return s.str();
}

template <typename T>
ostream& operator<<(ostream& output, const Nodo<T>& n) {
    output << n.toString();
    return output;
}

#endif //NODO_H

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

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include "Excepciones.h"


template <typename T>
class Lista {
private:
    Nodo<T>* primero;
    int size;
public:
    Lista();
    ~Lista();
    //------------------------------------------------------------------
    int getSize();
    bool esVacia() const;
    void agregar(T* dato);
    void eliminarInicio();
    void eliminar(T* dato);
    void eliminarPos(int pos);
    Nodo<T>* getNodoEsp(int pos);
    //-------------------------------------------------------------------
    string toString() const;
    //------------------------------------------------------------------
};
//------------------------------------------------------------------------

template<typename T>
Lista<T>::Lista(): primero(NULL),size(0){}
template<typename T>
Lista<T>::~Lista() {
    while (!esVacia()) {
        eliminarInicio();
    }
}
//---------------------------------------------------------------------------
template<typename T>
int Lista<T>::getSize() {return size;}

template<typename T>
bool Lista<T>::esVacia() const {return primero == NULL; }

template <typename T>
void Lista<T>::eliminar(T* dato) {
    if (esVacia()) {
        throw std::runtime_error("La lista está vacía.");
    }

    Nodo<T>* actual = primero;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->getDato() == dato) { // Match found
            if (anterior == nullptr) { // The node to delete is the first node
                primero = actual->getSig();
            } else { // The node to delete is in the middle or end
                anterior->setSig(actual->getSig());
            }
            delete actual;
            size--;
            return;
        }
        anterior = actual;
        actual = actual->getSig();
    }

    throw std::runtime_error("El objeto no se encontró en la lista.");
}
template <typename T>
void Lista<T>::agregar(T* dato){
    Nodo<T>* nuevo = new Nodo<T>(dato);
    Nodo<T>* temp = primero;
    if (esVacia()) {
        primero = nuevo;
    }else {
        while (temp->getSig()) {
            temp = temp->getSig();
        }
        temp->setSig(nuevo);
    }
    size++;
}

//----------------------------------------------------------

template<typename T>
void Lista<T>::eliminarInicio() {
    Nodo<T>* actual = primero;
    primero = primero->getSig();
    delete actual;
    size--;
}
template <typename T>
void Lista<T>::eliminarPos(int pos) {
    Nodo<T>* actual = primero;
    Nodo<T>* borrar;

    if (pos > size || pos < 0 || pos == size) {
        throw invalid_argument("Posicion invalida!!!!");
    }
    if (pos == 0) {
        eliminarInicio();
        return;
    }
    for (int i = 0; i < pos - 1; i++) {
        if (actual->getSig() != nullptr) {
            actual = actual->getSig();
        }
    }
    borrar = actual->getSig();
    actual->setSig(borrar->getSig());
    delete borrar;
}
//--------------------------------------------------

template<typename T>
Nodo<T> *Lista<T>::getNodoEsp(int pos) {
    if (pos > size || pos < 0 || pos == size) {
        throw invalid_argument("Posicion invalida!!!");
    }
    if (pos == 0) {
        return primero;
    }
    Nodo<T>* actual = primero;
    for (int i = 0; i < pos; i++) {
        if (actual->getSig() != NULL) {
            actual = actual->getSig();
        }
    }
    return actual;
}

//----------------------------------------------------------------------

template<typename T>
string Lista<T>::toString() const {
    stringstream s;
    Nodo<T>* temp = primero;
    if (esVacia()) {
        s << "Esta vacia la lista...";
    }
    while (temp) {
        s << *temp;
        temp = temp->getSig();
    }
    return s.str();
}

//------------------------------------------------------------------------
template <typename T>
ostream& operator<<(ostream& output, const Lista<T>& list) {
    output << list.toString();
    return output;
}

#endif //LISTA_H

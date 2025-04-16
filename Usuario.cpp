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
#include "Usuario.h"

Usuario::Usuario(string ID,string name,string apellidos,int estate):identificacion(ID),nombre(name), apellidos(apellidos),estado(estate){}
Usuario::~Usuario() {

}
string Usuario::getIdentificacion(){return identificacion;}
string Usuario::getNombre() {return this->nombre;}
string Usuario::getNombreCompleto(){return nombre + " " + apellidos;}
bool Usuario::getEstado(){return this->estado;}
void Usuario::setIdentificacion(string id){this->identificacion = id;}
void Usuario::setNombre(string name){this->nombre = name;}
void Usuario::setApellidos(string apellidos){this->apellidos = apellidos;}
void Usuario::setEstado(int estates){this->estado = estates;}
//------------------------------------------------------------------------------
string Usuario::toString()const {
    stringstream s;
    s << "\t  Datos del usuario: " << endl;
    s << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n" << endl;

    s << "- Nombre: " << nombre << endl;
    s << "- C" << char(130) << "dula: " << identificacion << endl;
    s << "- Estado: ";
    switch (estado)	{
        case 1:
            s << "Activo" << endl;
        break;
        case 2:
            s << "Inactivo" << endl;
        break;
    }
    return s.str();
}
// Define the operator<<
ostream& operator<<(ostream& os, const Usuario& usuario) {
    os << usuario.toString();
    return os;
}
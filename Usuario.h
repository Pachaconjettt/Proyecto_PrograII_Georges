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
#ifndef USUARIO_H
#define USUARIO_H
#include <sstream>
#include <string>

using namespace std;


class Usuario {
private:
    string identificacion;
    string nombre;
    string apellidos;
    int estado;
public:
    Usuario(string,string,string,int);
    ~Usuario();
    string getIdentificacion();
    string getNombre();
    string getNombreCompleto();
    string getApellidos();
    bool getEstado();
    void setIdentificacion(string);
    void setNombre(string);
    void setApellidos(string);
    void setEstado(int);
    string toString() const;
};

ostream& operator<<(ostream& output, const Usuario& user);

#endif //USUARIO_H

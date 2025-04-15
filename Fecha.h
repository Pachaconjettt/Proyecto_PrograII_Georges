#ifndef FECHA_H
#define FECHA_H
#include <ctime>
#include <sstream>
#include <iostream>
#pragma warning(disable:4996)
#define max 3

using namespace std;

class Fecha {
private:

    int dia;
    int mes;
    int anio;

public:

    Fecha();
    Fecha(int, int, int);
    ~Fecha();
    //--------------------------------------------
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    int getDia();
    int getMes();
    int getAnio();
    //--------------------------------------------
    string toString() const;

};

ostream& operator<<(ostream& output, const Fecha& data);

#endif

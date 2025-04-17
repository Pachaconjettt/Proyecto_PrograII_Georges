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
#include "Fecha.h"
Fecha::Fecha() {
	time_t tempo = time(nullptr);
	struct tm* fechaActual = localtime(&tempo);

	dia = fechaActual->tm_mday;
	mes = fechaActual->tm_mon + 1;
	anio = fechaActual->tm_year + 1900;
}

Fecha::Fecha(int d, int m, int a) {
	dia = d;
	mes = m;
	anio = a;
}

Fecha::~Fecha() { }

//-----------------------------------------------------------------------------------------------------

void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

int Fecha::getDia() { return dia; }
int Fecha::getMes() { return mes; }
int Fecha::getAnio() { return anio; }

//-----------------------------------------------------------------------------------------------------

string Fecha::toString() const{
	stringstream s;

	if (dia < 10) {
		s << "0";
	}
	s << this->dia << " / ";
	if (mes < 10) {
		s << "0";
	}
	s << this->mes << " / ";
	s << this->anio;

	return s.str();
}

//-----------------------------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const Fecha& data) {
	output << data.toString();
	return output;
}
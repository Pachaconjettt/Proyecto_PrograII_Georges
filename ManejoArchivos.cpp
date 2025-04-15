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
#include "ManejoArchivos.h"

ManejoArchivos::ManejoArchivos() {

}

string ManejoArchivos::Logo() {
    string str;
    stringstream s;
    ifstream out("logo.txt", ios::in);
    if (!out) {
        cerr << "Error: Could not open logo.txt. Check the file path and permissions." << endl;
        return "";
    } else {
        while (!out.eof()) {
            getline(out, str);
            s << str << endl;
        }
        out.close();
    }
    return s.str();
}
int convertirInt(string s) { // Convierte un string a int, recibe un string y devuelve un int
    stringstream r(s); // se crea un objeto de la clase stringstream, se le pasa el string s como parametro para que lo convierta a int
    int v;
    r >> v; // se guarda el valor convertido en la variable v
    return v; // se devuelve el int
}

float convertirFloat(string s) { // Convierte un string a double, recibe un string y devuelve un double
    stringstream r(s); // Se crea un objeto de la clase stringstream, se le pasa el string s como parametro para que lo convierta a double
    double v;
    r >> v; // Se guarda el valor convertido en la variable v
    return v; // Se devuelve el double
}

char convertirChar(string s) { // Convierte un stirng a double, recibe un string y devuelve un double
    stringstream r(s); // Se crea un objeto de la clase stringstream, se le pasa el string s, como parametro para que lo convierta a char
    char v;
    r >> v; // Se guarda el valor convertido en la variable v
    return v; // Se devuelve el char
}

bool convertirBool(string s) {
    stringstream r(s); // se crea un objeto de la clase stringstream, se le pasa el string s como parametro para que lo convierta a bool
	bool v;
    r >> v; // se guarda el valor convertido en la variable v
    return v; //  Se devuelve un bool
}





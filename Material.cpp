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

#include "Material.h"
Material::Material(string NumC,string NumCata,string Titulo,string Autors,string Keyw, int EstadoMats)
    : NumClasificacion(NumC), Titulo(Titulo), Autores(Autors), Palabra_s_clave(Keyw), EstadoMaterial(EstadoMats){}

Material::Material(): NumClasificacion(""), NumCatalogo(""), Titulo(""), Autores(""),Palabra_s_clave(""), EstadoMaterial(0){}

Material::~Material(){}

//------------------------------------------------------------------------

Libro::Libro(string NumC,string NumCata,string Tituloo,string Autorees,string Key,int EstadoMats,string Ubi)
: Material(NumC,NumCata,Tituloo,Autorees,Key,EstadoMats),ubicacionFisica(Ubi){}

Libro::~Libro(){}

void Libro::prestar() {
    cout << "Prestando libro. Máximo de 7 dias" << endl;
}
void Libro::guardar(ofstream& out)  {
out  <<"Libro;"<< NumClasificacion << ";" << NumCatalogo << ";" << Titulo << ";" << Autores << ";" << Palabra_s_clave << ";" << EstadoMaterial << ";" << ubicacionFisica << "\n";
}
string Libro::getNumCatalogo() { return this->NumCatalogo;}

string Libro::getNombre()  {return this->Titulo;}

string Libro::toString() const {
    stringstream s;
    s << "Numero de clasificacion: " << NumClasificacion<< endl;
    s << "Numero de catalogo: " << NumCatalogo << endl ;
    s << "Titulo de la obra: " << Titulo << endl;
    s << "Autor/es: " << Autores << endl;
    s << "Palabras Claves: " << Palabra_s_clave << endl;
    s << "Estado del material(1:Buen estado, 2: Minimo de daños, 3:Mal Estado)" << EstadoMaterial << endl;
    s << "Ubicacion del libro :" << ubicacionFisica << endl;
    return s.str();
}
//-------------------------------------------------------------------------

Revista::Revista(string NumC,string NumCata,string Tituloo ,string Autores,string Key,int EstadoMats,string Ubi,int numF,int Volum) :
Material(NumC,NumCata, Tituloo, Autores, Key, EstadoMats), UbicacionFisica(Ubi), numero(numF), volumen(Volum) {}

Revista::~Revista() {

}

void Revista::prestar() {
    cout << "Prestando revista. Maximo de 2 dias" << endl;
}

void Revista::guardar(ofstream& out)  {
    out << "Revista;" << NumClasificacion << ";" << NumCatalogo << ";" << Titulo << ";" <<Autores << ";" << Palabra_s_clave << ";" << EstadoMaterial <<";"<<UbicacionFisica << ";" << numero << ";" << volumen << "\n";
}

string Revista::getNumCatalogo() { return this->NumCatalogo;}

string Revista::getNombre()  {return this->Titulo;}

string Revista::toString() const {
    stringstream s;
    s << "Numero de clasificacion: " << NumClasificacion<< endl;
    s << "Numero de catalogo: " << NumCatalogo << endl ;
    s << "Titulo de la obra: " << Titulo << endl;
    s << "Autor/es: " << Autores << endl;
    s << "Palabras Claves: " << Palabra_s_clave << endl;
    s << "Estado del material(1:Buen estado, 2: Minimo de daños, 3:Mal Estado)" << EstadoMaterial << endl;
    s << "Ubicacion de la revista :" << UbicacionFisica << endl;
    s << "Numero de revista :" << numero << endl;
    s << "Volumen de la revista: " << volumen << endl;
    return s.str();
}
//-----------------------------------------------------------------------

MaterialDigital::MaterialDigital(string NumC,string NumCata,string Tituloo, string Autores, string Key, int EstadoMats, string Format, bool Access)
    : Material(NumC, NumCata, Tituloo, Autores, Key, EstadoMats), formato(Format), accesoHabilitado(Access){
}
MaterialDigital::~MaterialDigital() {

}

void MaterialDigital::prestar() {
    cout << "Prestando material digital. Máximo de 5 dias" << endl;
}

void MaterialDigital::guardar(ofstream & out) {
    out << "Digital;" << NumClasificacion << ";" << NumCatalogo << ";" << Titulo << ";" << Autores << ";" << Palabra_s_clave << ";" << EstadoMaterial << ";" << formato << ";" << accesoHabilitado << "\n";
}

string MaterialDigital::getNumCatalogo() { return this->NumCatalogo;}

string MaterialDigital::getNombre() {return this->Titulo;}

string MaterialDigital::toString() const {
    stringstream s;
    s << "Numero de clasificacion: " << NumClasificacion<< endl;
    s << "Numero de catalogo: " << NumCatalogo << endl ;
    s << "Titulo de la obra: " << Titulo << endl;
    s << "Autor/es: " << Autores << endl;
    s << "Palabras Claves: " << Palabra_s_clave << endl;
    s << "Estado del material(1:Buen estado, 2: Minimo de daños, 3:Mal Estado): " << EstadoMaterial << endl;
    s << "Formato del material: " << formato << endl;
    s << "Acceso habilitado (1: si, 0: No):" << accesoHabilitado << endl;
    return s.str();
}

ostream& operator<<(ostream& os, const Material& material) {
    os << material.toString();
    return os;
}
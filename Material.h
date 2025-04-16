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

#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Material {
protected:
    string NumClasificacion;
    string NumCatalogo;
    string Titulo;
    string Autores;
    string Palabra_s_clave;
    int EstadoMaterial;
public:
    Material(string,string,string,string,string, int);
    Material();
    ~Material();
    virtual void prestar() = 0;
    virtual void guardar(ofstream&) = 0;
    virtual string getNumCatalogo() = 0;
    virtual string getNombre() = 0;
    virtual int getEstadoMaterial() = 0;
    virtual string toString() const  = 0;
    virtual void setNumClasificacion(string) = 0;
    virtual void setNumCatalogo(string) = 0;
    virtual void setTitulo(string) = 0;
    virtual void setAutores(string) = 0;
    virtual void setPalabras(string) = 0;
    virtual void setEstadoMats(int) = 0;
};

//------------------------------------------------------------------

class Libro: public Material {
private:
    string ubicacionFisica;
public:
    Libro(string,string,string,string,string,int,string);
    ~Libro();
    virtual void prestar() override;
    virtual void guardar(ofstream&) override;
    virtual string getNumCatalogo() override;
    virtual string getNombre() override;
    virtual int getEstadoMaterial() override;
    virtual string toString()  const override;
    virtual void setNumClasificacion(string) override;
    virtual void setNumCatalogo(string) override;
    virtual void setTitulo(string) override;
    virtual void setAutores(string) override;
    virtual void setPalabras(string) override;
    virtual void setEstadoMats(int)  override;
    void setUbicacionFisica(string);
};

//-----------------------------------------------------------------

class Revista: public Material {
private:
    string UbicacionFisica;
    int numero;
    int volumen;
public:
    Revista(string,string,string,string,string,int,string,int,int);
    ~Revista();
    virtual void prestar() override;
    virtual void guardar(ofstream&) override;
    virtual  string getNumCatalogo() override;
    virtual string getNombre() override;
    virtual int getEstadoMaterial() override;
    virtual string toString() const override;
    virtual void setNumClasificacion(string) override;
    virtual void setNumCatalogo(string) override;
    virtual void setTitulo(string) override;
    virtual void setAutores(string) override;
    virtual void setPalabras(string) override;
    virtual void setEstadoMats(int)  override;
    void setUbicacionFisica(string);
    void setNumero(int);
    void setVolumen(int);
};

//-----------------------------------------------------------------

class MaterialDigital : public Material {
private:
    string formato;
    bool accesoHabilitado;
public:
    MaterialDigital(string,string,string,string,string,int,string,bool);
    ~MaterialDigital();
    virtual void prestar() override;
    virtual void guardar(ofstream&) override;
    virtual string getNumCatalogo() override;
    virtual string getNombre() override;
    virtual int getEstadoMaterial() override;
    virtual string toString() const override;
    virtual void setNumClasificacion(string) override;
    virtual void setNumCatalogo(string) override;
    virtual void setTitulo(string) override;
    virtual void setAutores(string) override;
    virtual void setPalabras(string) override;
    virtual void setEstadoMats(int)  override;
    void setFormato(string);
    void setAccessoHabilitado(bool);
};
//-----------------------------------------------------------------
#endif //MATERIAL_H

ostream& operator<<(ostream& output, const Material& mats);
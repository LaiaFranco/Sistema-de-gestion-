#pragma once
#include<iostream>
#include <cstring>


using namespace std;
class Materia{
public:
    Materia ();
    Materia(int id, bool nivel, int anio, const char *nombre, int horas, bool estado);

    //setters
    void setCodigo (int cod);
    void setNivelEducativoMateria(bool nivel);
    void setAnioMateria(int anio);
    void setNombre (const char* nombre);
    void setCargaHoraria (int horas);
    void setEstado(bool estado);

    // getters
    int getCodigo();
    bool getNivelEducativoMateria();
    int  getAnioMateria();
    const char* getNombre();
    int getCargaHoraria();
    bool getEstado();

    // metodos
    void Mostrar();

private:
    int _codigo;
    bool _nivelEdMataria;
    int _anioMateria;
    char _nombre[30];
    int _cargaHoraria;
    bool _estado;
};


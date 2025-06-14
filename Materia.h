#pragma once
#include<iostream>
#include <cstring>
#include <string>

using namespace std;

class Materia {
public:
    Materia ();

    //setters
    void setCodigo (int cod);
    void setNombre (const char* nombre);
    void setCargaHoraria (int horas);
    void setActivo(bool activo);

    // getters
    int getCodigo();
    const char* getNombre();
    int getCargaHoraria();
    bool getActivo();

    // metodos
    void Cargar();
    void Mostrar();

private:
    int _codigo;
    char _nombre[30];
    int _cargaHoraria;
    bool _activo;
};


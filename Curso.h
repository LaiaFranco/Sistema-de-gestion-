#pragma once
#include<iostream>
#include <cstring>

using namespace std;

class Curso {
private:
    int _codigo;
    char _nombre[30];
    char _turno[10];  // Ej: "mañana", "tarde"
    int _vacantes;
    bool _activo;

public:
    Curso();

    void setCodigo(int codigo);
    void setNombre(const char* nombre);
    void setTurno(const char* turno);
    void setVacantes(int vacantes);
    void setActivo(bool activo);

    int getCodigo();
    const char* getNombre();
    const char* getTurno();
    int getVacantes();
    bool getActivo();

    void Cargar();
    void Mostrar();
};

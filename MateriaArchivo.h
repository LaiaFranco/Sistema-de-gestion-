#pragma once
#include "Materia.h"
#include <iostream>

class MateriaArchivo {
public:
    MateriaArchivo();
    void CargarMateria();
    int GeneradorDeCodigo();
    bool guardar(const Materia &reg);
    int contar();
    void ModificarEstado(const char *nombre, bool nivel, int anio);
    void ModificarCargaHoraria(const char *nombre, bool nivel, int anio);
    Materia leer(int pos);
    bool  modificarMateria(const Materia &reg, int pos);
    void listar();
    void listarMateriasXNombre(const char *nombre,bool nivel);

private:
    char _nombreArchivo[30];
};


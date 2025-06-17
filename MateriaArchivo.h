#pragma once
#include "Materia.h"

class MateriaArchivo {
private:
    char _nombreArchivo[30] = "materias.dat";

public:
    bool guardar(Materia reg);
    int contar();
    Materia leer(int pos);
    void listar();
};


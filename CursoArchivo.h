#pragma once
#include "Curso.h"

class CursoArchivo {
private:
    char _nombreArchivo[30];

public:
    CursoArchivo(const char* nombre = "cursos.dat");

    bool guardar(Curso reg);
    Curso leer(int pos);
    int getCantidadRegistros();
    int buscarPorCodigo(int codigo);
    bool modificar(Curso reg, int pos);
};

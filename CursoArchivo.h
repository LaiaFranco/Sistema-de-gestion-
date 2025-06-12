#pragma once
#include "Curso.h"

using namespace std;
class CursoArchivo {
public:
    CursoArchivo(const char* nombre = "cursos.dat");

    bool guardar(Curso reg);
    Curso leer(int pos);
    int CantidadRegistros();
    int buscarPorIdCurso(int id);
    bool modificar(const Curso &reg, int pos);
    bool bajaLogica(int id);
    bool altaLogica(int id);

private:
    char _nombreArchivo[30];
};

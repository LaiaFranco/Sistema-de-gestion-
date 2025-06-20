#pragma once
#include "Curso.h"

using namespace std;
class CursoArchivo {
public:
    CursoArchivo(const char* nombre = "Cursos.dat");
    int IncrementoID();
    void CargarCurso();
    bool guardar(Curso reg);
    Curso leer(int pos);
    int CantidadRegistros();
    int buscarPorIdCurso(int id);
    void buscarCursosDisponibles(bool nivel,int anio);
    bool modificar(const Curso &reg, int pos);
    bool bajaLogica(int id);
    bool altaLogica(int id);
    void ModificarEstado(bool nivel,int numAula, int numCurso);
    void ModificarCantAlumnos(bool nivel,int numAula, int numCurso);

private:
    char _nombreArchivo[30];
};

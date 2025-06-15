#pragma once
#include "Alumno.h"
#include "ArchivoAlumno.h"
#include "string"

class AlumnoManager{
public:
    int IncrementarLegajo();
    Alumno CargarAlumno();
    void ListarAlumnosActivos();
    void buscarAlumnoPorLegajo(int legajo);
    void buscarAlumnoPorDNI(string dni);
    void buscarAlumnoPorApellido(const char *apellido);

private:
    ArchivoAlumno _archiALu;

};

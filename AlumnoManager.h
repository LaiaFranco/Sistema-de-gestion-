#pragma once
#include "Alumno.h"
#include "ArchivoAlumno.h"

class AlumnoManager{
public:
    void CargarAlumno();
    void ListarAlumnosActivos();
    void buscarAlumnoPorLegajo(int legajo);
    void buscarAlumnoPorDNI(string dni);
    void buscarAlumnoPorApellido(const char *apellido);

private:
    ArchivoAlumno _archiALu;



};

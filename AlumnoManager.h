#pragma once
#include "Persona.h"
#include "Alumno.h"
#include "ArchivoAlumno.h"
#include "string"

class AlumnoManager{
public:
    int IncrementarLegajo();
    Alumno CargarAlumno();
    void ListarAlumnosActivos();
    void buscarAlumnoPorLegajo(int legajo);
    void buscarAlumnoPorDNI(int dni);
    void buscarAlumnoPorApellido(const char *apellido);
    void emisionCertificadoRegular( Alumno &reg);

private:
    ArchivoAlumno _archiALu;

};

#pragma once
#include "ArchivoInscripcion.h"
#include "inscripciones.h"
#include "Curso.h"
#include "CursoArchivo.h"
#include "Alumno.h"
#include "AlumnoManager.h"
#include <iostream>

using namespace std;
class InscripcionesManager{
public:
    int IncrementarInscripcion();
    void CargarInscripcion();
    void buscarCursoDisponible(int anio,bool nivelEducativo);
    void guardarRegistro(int idCurso, int legajo);

private:
    ArchivoInscripcion  archivoIns;
};

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
    void buscarCursoDisponible(bool nivelEducativo,int anio);
    void guardarRegistro(int idCurso, int legajo);
    void ReinscribirAlumno();
    void EstadoInscipcion();
    void emisionCertificadoParcial(Alumno &reg);
    void emisionCertificadoFinal(Alumno &reg);

private:
    ArchivoInscripcion  archivoIns;
};

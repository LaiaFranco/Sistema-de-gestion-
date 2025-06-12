#pragma once
#include "AlumnoManager.h"
#include<iostream>
#include <string>

using namespace std;
class inscripcion{
public:
    inscripcion();
    inscripcion(int idInscripcion,int legajoAlumno,int id,  int numeroCurso, float importeMatricula, bool adeudaMatricula,bool estado,Fecha fechaInscripcion);

void setIdInscripcion(int idInscripcion);
void setlegajoAlumno(int legajoAlumno);
void setIdCurso(int id);
void setimporteMatricula(float importeMatricula);
void setadeudaMatricula(bool adeudaMatricula);
void setEstado(bool estado);
void setfechaInscripcion(Fecha fechaInscripcion);

int getIdInscripcion();
int getlegajoAlumno();
int getIdCurso();
float getimporteMatricula();
bool getadeudaMatricula();
bool getEstado();
Fecha getfechaInscripcion();

void Mostrar();

private:
    int _idInscripcion;
    int _legajoAlumno;
    int _idCurso;
    float _importeMatricula;
    bool _adeudaMatricula;
    bool _estado;
    Fecha _fechaInscripcion;
};

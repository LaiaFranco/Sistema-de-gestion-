#pragma once
#include<iostream>
#include "Alumno.h"
#include "Fecha.h"

#include <cstring>

using namespace std;

class inscripcion {


private:

 int _legajoAlumno;
 int _numeroCurso;
 float _importeMatricula;
 bool _adeudaMatricula;
 Fecha fechaInscripcion;


public:

    inscripcion();
    inscripcion(int legajoAlumno, int numeroCurso, float importeMatricula,adeudaMatricula, Fecha fechaInscripcion);


void setlegajoAlumno(int legajoAlumno);
void setnumeroCurso(int numeroCurso);
void setimporteMatricula(float importeMatricula);
void setadeudaMatricula(bool adeudaMatricula);
void setfechaInscripcion(Fecha fechaInscripcion);

int getlegajoAlumno();
int getnumeroCurso();
float getimporteMatricula();
bool getadeudaMatricula();
Fecha getfechaInscripcion();

void mostrar();
void cargar();

};





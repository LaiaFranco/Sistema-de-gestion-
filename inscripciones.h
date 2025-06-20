#pragma once
#include "AlumnoManager.h"
#include<iostream>
#include <string>

using namespace std;
class inscripcion{
public:
    inscripcion();
    inscripcion(int idInscripcion,int legajoAlumno,int id,bool nivel,int anio, float importeMatricula, bool adeudaMatricula,bool estado,Fecha fechaInscripcion);

void setIdInscripcion(int idInscripcion);
void setlegajoAlumno(int legajoAlumno);
void setIdCurso(int id);
void setNivel(bool nivel);
void setANio(int anio);
void setimporteMatricula(float importeMatricula);
void setadeudaMatricula(bool adeudaMatricula);
void setEstado(bool estado);
void setfechaInscripcion(Fecha fechaInscripcion);

int getIdInscripcion();
int getlegajoAlumno();
int getIdCurso();
bool  getNivel();
int getANio();
float getimporteMatricula();
bool getadeudaMatricula();
bool getEstado();
Fecha getfechaInscripcion();

void Mostrar();

private:
    int _idInscripcion;
    int _legajoAlumno;
    bool _nivelEducativo;
    int _anioEducativo;
    int _idCurso;
    float _importeMatricula;
    bool _adeudaMatricula;
    bool _estado;
    Fecha _fechaInscripcion;
};


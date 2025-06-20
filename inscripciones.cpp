#include "Alumno.h"
#include "inscripciones.h"
#include <iostream>
#include <cstring>

using namespace std;

inscripcion::inscripcion()
:_fechaInscripcion(1,1,2023){

    _idInscripcion = 0;
    _legajoAlumno=0;
    _idCurso=0;
    _nivelEducativo=0;
    _anioEducativo = 0;
    _importeMatricula=0.0;
    _adeudaMatricula=false;
    _estado = false;
}


inscripcion::inscripcion(int idInscripcion,int legajoAlumno,int id, bool nivel, int anio, float importeMatricula, bool adeudaMatricula,bool estado,Fecha fechaInscripcion){

  setIdInscripcion(idInscripcion);
  setlegajoAlumno(legajoAlumno);
  setIdCurso(id);
  setNivel(nivel);
  setANio(anio);
  setimporteMatricula(importeMatricula);
  setEstado(estado);
  setfechaInscripcion(fechaInscripcion);
}

void inscripcion::setIdInscripcion(int idInscripcion){
    _idInscripcion = idInscripcion;
}

void inscripcion::setlegajoAlumno(int legajoAlumno){
     _legajoAlumno=legajoAlumno;

}

void inscripcion::setIdCurso(int id){

    _idCurso =id;
}
void inscripcion::setNivel(bool nivel){
    _nivelEducativo = nivel;
}
void inscripcion::setANio(int anio){
    _anioEducativo = anio;
}

void inscripcion::setimporteMatricula(float importeMatricula){

  _importeMatricula=importeMatricula;

}

void inscripcion::setadeudaMatricula(bool adeudaMatricula){

   _adeudaMatricula=adeudaMatricula;

}

void inscripcion::setEstado(bool estado){
    _estado = estado;
}

void inscripcion::setfechaInscripcion(Fecha fechaInscripcion){

   _fechaInscripcion = fechaInscripcion;
}

int inscripcion::getIdInscripcion(){
    return _idInscripcion;
}

int inscripcion::getlegajoAlumno(){
   return _legajoAlumno;
}


int inscripcion::getIdCurso(){
   return _idCurso;
}

bool  inscripcion::getNivel(){
    return _nivelEducativo;
}
int inscripcion::getANio(){
    return _anioEducativo;
}
float inscripcion::getimporteMatricula(){
    return _importeMatricula;

}

bool inscripcion::getadeudaMatricula(){

  return _adeudaMatricula;

}
bool inscripcion::getEstado(){
    return _estado;
}

Fecha inscripcion::getfechaInscripcion(){
   return _fechaInscripcion;
}

void inscripcion::Mostrar(){
   cout<<"ID DE INSCRIPCION: #" <<_idInscripcion<<endl;
   cout<< "LEGAJO ALUMNO: " <<_legajoAlumno << endl;
   cout<< "ID DE CURSO: "<< _idCurso << endl;
   cout<< "IMPORTE DE MATRICULA: "<< _importeMatricula << endl;
    if(_adeudaMatricula == 0){

    cout<<"*El alumno no adeuda la matricula*"<< endl;
    }
    else {
    cout<<"El alumno adeuda la matricula"<< endl;
    }

    cout<<"ESTADO: ";
    if(_estado== true){
        cout<<"ACTIVO"<<endl;
    }else{
        cout<<"INACTVO"<<endl;
    }

    cout<<"FECHA DE INSCRIPCION: ";
    _fechaInscripcion.Mostrar();
}

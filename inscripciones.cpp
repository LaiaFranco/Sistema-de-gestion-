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
    _importeMatricula=0.0;
    _adeudaMatricula=false;
    _estado = false;
}


inscripcion::inscripcion(int idInscripcion,int legajoAlumno,int id,  int numeroCurso, float importeMatricula, bool adeudaMatricula,bool estado,Fecha fechaInscripcion){

  _idInscripcion = idInscripcion;
  _legajoAlumno=legajoAlumno;
  _idCurso = id;
  _importeMatricula=importeMatricula;
  _adeudaMatricula=adeudaMatricula;
  _estado = estado;
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
   cout<<"Id de inscripcion: " <<_idInscripcion<<endl;
   cout<< "legajo del Alumno: " <<_legajoAlumno << endl;
   cout<< "Id de Curso: "<< _idCurso << endl;
   cout<< "Importe de Matricula: "<< _importeMatricula << endl;
    if(_adeudaMatricula == 1){

    cout<<"El alumno no adeuda la matricula"<< endl;
    }
    else {
    cout<<"El alumno adeuda la matricula"<< endl;
    }
    cout<<"Estado: "<<_estado;
    cout<<"Fecha de inscripcion: ";
    _fechaInscripcion.Mostrar();
}

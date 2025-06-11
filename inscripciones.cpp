#include "Alumno.h"
#include "inscripciones.h"
#include "ArchivoAlumno.h"
#include <iostream>
#include <cstring>


using namespace std;

inscripcion::inscripcion(){

    _legajoAlumno=0;
    _numeroCurso=0;
    _importeMatricula=0.0;
    _adeudaMatricula=false;

}


inscripcion::inscripcion(int legajoAlumno, int numeroCurso, float importeMatricula,bool adeudaMatricula, Fecha fechaInscripcion)

  _legajoAlumno=legajoAlumno;
  _numeroCurso=numeroCurso;
  _importeMatricula=importeMatricula;
  _adeudaMatricula=adeudaMatricula;



void legajoAlumno::setlegajoAlumno(int legajoAlumno){
     _legajoAlumno=legajoAlumno;

}

void numeroCurso::setnumeroCurso(int numeroCurso){

    _numeroCurso=numeroCurso;

}

void importeMatricula::setimporteMatricula(float importeMatricula){

  _importeMatricula=importeMatricula;

}

void inscripcion::setadeudaMatricula(bool adeudaMatricula){

   _adeudaMatricula=adeudaMatricula;

}

void inscripcion::fechaInscripcion(fecha fechaInscripcion){

   _fechaInscripcion=fechaInscripcion;
}


int legajoAlumno::getlegajoAlumno(){

   return _legajoAlumno;
}


int numeroCurso::getnumeroCurso(){

   return _numeroCurso;
}

float importeMatricula::getimporteMatricula(){

    return _importeMatricula;

}

bool adeudaMatricula::getadeudaMatricula(){

  return _adeudaMatricula;

}

fecha fechaInscripcion::getfechaInscripcion(){

   return _fechaInscripcion;

}


void inscripcion::cargar(){
 cout<< "Legajo del Alumno: "<<endl;
 cin>>_legajoAlumno;

 cout<<"Numero de Curso: "<<endl;
 cin>>_numeroCurso;

  if (_numeroCurso <= 0) {
    cout << "Numero de curso invalido. Intente nuevamente." << endl;
  }
 cin>>_numeroCurso;

 cout << "Fecha de inscripcion: " << endl;


 cout<<"Importe de Matricula: "<<endl;
 cin>>_importeMatricula;

 cout<< "Alumno adeuda matricula?(1.Si 2.No)"<<endl;
 cin>> _adeudaMatricula;

 _fechaInscripcion.Cargar();


}

void inscripcion::mostrar(){

  cout<< "legajo del Alumno: " <<_legajoAlumno << endl;

  cout<< "Numero de Curso: "<< _numeroCurso << endl;


  cout<< "Importe de Matricula: "<< _importeMatricula << endl;

  if(adeudaMatricula==false){

    cout<<"El alumno no adeuda la matricula"<< endl;
  }
  else {

    cout<<"El alumno adeuda la matricula"<< endl;
  }

 fechaInscripcion.Mostrar();


}
























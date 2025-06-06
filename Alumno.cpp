#include <iostream>
#include <cstring>
#include "Alumno.h"
#include "Persona.h"

using namespace std;
Alumno::Alumno(){
    _legajoAlumno = 0;
    _nivelAcademico = false;
    _anioAcademico = 0;
    _tutor[0] = '\0';
    _nombreTutor[0] = '\0';
    _apellidoTutor[0] = '\0';
    _tieneHermanos= false;
}

Alumno::Alumno(int tipoDocumento, string numDocumento,string nombres, string apellidos,
               int edad,string numTelefono, string direccion,string mail,bool estado,
               const Fecha& fechaNac,int legajoAlumno, bool nivelAcademico,int anioAcademico,
               string tutor, string nombreTutor, string apellidoTutor,bool tieneHermanos)
:Persona(tipoDocumento,numDocumento,nombres,apellidos, edad,
         numTelefono,direccion, mail, estado, fechaNac){
    setLegajoAlumno(legajoAlumno);
    setNivelAcademico(nivelAcademico);
    setAnioAcademico(anioAcademico);
    setTutor(tutor);
    setNombreTutor(nombreTutor);
    setApellidoTutor(apellidoTutor);
    setTieneHermanos(tieneHermanos);
}

void Alumno::setLegajoAlumno(int legajoAlumno){
    _legajoAlumno = legajoAlumno;
}
void Alumno::setNivelAcademico(bool nivelAcademico){
    _nivelAcademico = nivelAcademico;
}
void Alumno::setAnioAcademico(int anioAcademico){
    _anioAcademico = anioAcademico;
}
void Alumno::setTutor(string tutor){
    if(tutor.size()<=10){
        strcpy(_tutor,tutor.c_str());
    }
}
void Alumno::setNombreTutor(string nombreTutor){
    if(nombreTutor.size()<=30){
        strcpy(_nombreTutor,nombreTutor.c_str());
    }
}
void Alumno::setApellidoTutor(string apellidoTutor){
    if(apellidoTutor.size()<=30){
        strcpy(_apellidoTutor, apellidoTutor.c_str());
    }
}

void Alumno::setTieneHermanos(bool tieneHermanos){
    _tieneHermanos = tieneHermanos;
}

int Alumno::getLegajoAlumno(){
    return _legajoAlumno;
}
bool Alumno::getNivelAcademico(){
    return _nivelAcademico;
}
int Alumno::getAnioAcademico(){
    return _anioAcademico;
}
string Alumno::getTutor(){
    return _tutor;
}
string Alumno::getNombreTutor(){
    return _nombreTutor;
}
string Alumno::getApellidoTutor(){
    return _apellidoTutor;
}
bool Alumno::getTieneHermanos(){
    return _tieneHermanos;
}

void Cargar(){

}
void Mostrar();



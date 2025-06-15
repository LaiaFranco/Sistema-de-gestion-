#include "Alumno.h"
#include <iostream>
#include <cstring>

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


void Alumno::Mostrar(){

    cout<<"-----DATOS PERSONALES-----"<<endl;
    cout<<"LEGAJO: "<<getLegajoAlumno()<<endl; ///terminarlo
    cout<<"TIPO DE DOCUMENTO: ";
    MostrarTipoDocumento(getTipoDocumento());
    cout<<endl;
    cout<<"NOMBRES: "<<getNombres()<<endl;
    cout<<"APELLIDOS: "<<getApellidos()<<endl;
    cout<<"EDAD: "<<getEdad()<<endl;
    cout<<"FECHA NACIMIENTO: ";
    getFechaNac().Mostrar();
    cout<<"NUMERO DE TELEFONO: "<<getNumTelefono()<<endl;
    cout<<"DIRECCION: "<<getDireccion()<<endl;
    cout<<"MAIL: "<<getMail()<<endl;
    cout<<"NIVEL ACADEMICO(0-Primario, 1-Secundario): ";
    if(getNivelAcademico()==1){
        cout<<"SECUNDARIO"<<endl;
    }else{
        cout<<"PRIMARIO"<<endl;
    }
    cout<<"ANIO ACADEMICO(1-PRIMER,2-SEGUNDO,3-TERCERO,ETC): "<<getAnioAcademico()<<endl;
    cout<<"TUTOR A CARGO: "<<getTutor()<<endl;
    cout<<"NOMBRE TUTOR: "<<getNombreTutor()<<endl;
    cout<<"APELLIDO TUTOR: "<<getApellidoTutor()<<endl;
    cout<<"TIENE HERMANOS: ";
    if(getTieneHermanos()==1){
        cout<<"SI"<<endl;
    }else{cout<<"NO"<<endl;}
    cout<<"ESTADO: ";
    if(getEstado()){
        cout<<"ACTIVO"<<endl;
    }else{cout<<"INACTIVO"<<endl;}
}


#pragma once
#include "Persona.h"
#include<iostream>

using namespace std;
class Alumno: public Persona{

public:
    Alumno();
    Alumno(int tipoDocumento, string numDocumento,string nombres, string apellidos,int edad,string numTelefono, string direccion,string mail,bool estado,const Fecha& fechaNac,int legajoAlumno, bool nivelAcademico, int anioAcademico, string tutor, string nombreTutor, string apellidoTutor, bool tieneHermanos);

    void setLegajoAlumno(int legajoAlumno);
    void setNivelAcademico(bool nivelAcademico);
    void setAnioAcademico(int anioAcademico);
    void setTutor(string tutor);
    void setNombreTutor(string nombreTutor);
    void setApellidoTutor(string apellidoTutor);
    void setTieneHermanos(bool tieneHermanos);

    int getLegajoAlumno();
    bool getNivelAcademico();
    int getAnioAcademico();
    string getTutor();
    string getNombreTutor();
    string getApellidoTutor();
    bool getTieneHermanos();


    bool Cargar(int legajo);
    void Mostrar();

private:
    int _legajoAlumno;
    bool _nivelAcademico; ///primario o secundario
    int _anioAcademico; ///de 1 a 6 para primaria y secundario
    char _tutor[10]; ///mama, papa, perro o gato
    char _nombreTutor[30];
    char _apellidoTutor[30];
    bool _tieneHermanos;

};

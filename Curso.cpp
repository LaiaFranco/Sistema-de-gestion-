#include "Curso.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
Curso::Curso() {
    _idCurso = 0;
    _numeroCurso = 0;
    _numeroAula = 0;
    _descripcion[0] = '/0';
    _turno = false;  // EJ, turno maniana o tarde
    _cantMaximaAlumnos = 0;
    _estado = false;
}
Curso::Curso(int id,int numero, int numAula,string descripcion,bool turno,int cantMax,bool estado){
    setIdCursoo(id);
    setNumeroCurso(numero);
    setNumeroAula(numAula);
    setDescripcion(descripcion);
    setTurno(turno);
    setCantidadMaximaAlumnos(cantMax);
    setEstado(estado);
}

void Curso::setIdCursoo(int id){
    _idCurso = id;
}
void Curso::setNumeroCurso(int numero){
   if(numero>=1 && numero<=6){
    _numeroCurso = numero;
   }else{
       cout<<"EL NUMERO NO CORRESPONDE"<<endl;
   }
}

void Curso::setNumeroAula(int numAula){
    if(numAula>=1 && numAula<=20){
        _numeroAula = numAula;
    }
}
void Curso::setNivelEducativo(bool nivel){
    _nivelEducativo = nivel;
}

void Curso::setDescripcion(string descripcion){
    if(descripcion.size()<=100){
        strcpy(_descripcion,descripcion.c_str());
    }
}

void Curso::setTurno(bool turno){
    _turno = turno;
}

void Curso::setCantidadMaximaAlumnos(int cantMax){
    if(cantMax<=30){
        _cantMaximaAlumnos = cantMax;
    }
}

void Curso::setCantidadAlumnosInscriptos(int cantidad){
    _cantAlumnosInscriptos = cantidad;
}

void Curso::setEstado(bool estado){
    _estado = estado;
}

int Curso::getIdCurso(){return _idCurso;}
int Curso::getNumeroCurso(){return _numeroCurso;}
int Curso::getNumeroAula(){return _numeroAula;}
bool Curso::getNivelEducativo(){return _nivelEducativo;}
string Curso::getDescripcion(){return _descripcion;}
bool Curso::getTurno(){return _turno;}
int Curso::getCantidadMaximaAlumnos(){return _cantMaximaAlumnos;}
int Curso::getCantiadaAlumnosInscriptos(){return _cantAlumnosInscriptos;}
bool Curso::getEstado(){return _estado;}

void Curso::Cargar(){
    int id, numeroCurso,  numAula;
    string descripcion;
    bool turno;
    int cantMax;
    bool estado;
    cout<<"----- DATOS PARA UN CURSO -----"<<endl;
    cout<<"ID: ";
    cin>>id;
    setIdCursoo(id);
    cout<<endl;
    cout<<"NUMERO DE CURSO(DEL 1 AL 6): ";
    cin>>numeroCurso;
    setNumeroCurso(numeroCurso);
    cout<<endl;
    cout<<"NUMERO DE AULA(del 1 al 20): ";
    cin>>numAula;
    setNumeroAula(numAula);
    cout<<endl;
    cout<<"DESCRIPCION: ";
    cin.ignore();
    cin>>descripcion;
    setDescripcion(descripcion);
    cout<<endl;
    cout<<"TURNO(0-MANIANA, 1-TARDE): ";
    cin>>turno;
    setTurno(turno);
    cout<<endl;
    cout<<"CANTIDAD MAXIMA(hasta 30 alumnos por curso): ";
    cin>>cantMax;
    setCantidadMaximaAlumnos(cantMax);
    cout<<endl;
    cout<<"ESTADO: ACTIVO"<<endl;
    estado = true;
    setEstado(estado);
}

void Curso::Mostrar(){
    cout<<"----- DATOS DEL CURSO -----"<<endl;
    cout<<"ID: ";
    getIdCurso();
    cout<<endl;
    cout<<"NUMERO CURSO: ";
    getNumeroCurso();
    cout<<endl;
    cout<<"NUMERO DE AULA: ";
    getNumeroAula();
    cout<<endl;
    cout<<"DESCRIPCION: ";
    getDescripcion();
    cout<<endl;
    cout<<"TURNO: ";
    getTurno();
    cout<<endl;
    cout<<"CANTIDAD MAXIMA DE ALUMNOS: ";
    getCantidadMaximaAlumnos();
    cout<<endl;
    cout<<"ESTADO: ";
    getEstado();
    cout<<endl;
}

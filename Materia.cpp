#include <iostream>
#include <cstring>
#include <string>
#include "Materia.h"

using namespace std;

Materia::Materia() {
    _codigo = 0;
    _nombre[0] = '\0';
    _cargaHoraria = 0;
    _estado = true;
}
Materia::Materia(int id,bool nivel, int anio, const char *nombre, int horas, bool estado){
    setCodigo(id);
    setNivelEducativoMateria(nivel);
    setAnioMateria(anio);
    setNombre(nombre);
    setCargaHoraria(horas);
    setEstado(estado);
}


void Materia::setCodigo(int cod) {
    _codigo = cod;
}

void Materia::setNivelEducativoMateria(bool nivel){
    _nivelEdMataria = nivel;
}
void Materia::setAnioMateria(int anio){
  if(anio>=1 && anio<=6){
    _anioMateria = anio;
    }
}
void Materia::setNombre(const char* nombre) {
    strncpy(_nombre, nombre, 29);
    _nombre[29] = '\0';  // por seguridad
}

void Materia::setCargaHoraria(int horas) {
    _cargaHoraria = horas;
}

void Materia::setEstado(bool estado) {
    _estado = estado;
}

int Materia::getCodigo() {
    return _codigo;
}

bool Materia::getNivelEducativoMateria(){
    return _nivelEdMataria;
}
int Materia:: getAnioMateria(){
    return _anioMateria;
}
const char* Materia::getNombre() {
    return _nombre;
}

int Materia::getCargaHoraria() {
    return _cargaHoraria;
}

bool Materia::getEstado() {
    return _estado;
}


void Materia::Mostrar() {
    string vAnios[6] ={"PRIMERO","SEGUNDO","TERCERO","CUARTO","QUINTO","SEXTO"};

    cout << "ID DE MATERIA: #" << _codigo << endl;
    cout << "NOMBRE: " << _nombre << endl;
    cout<<"NIVEL EDUCATIVO: ";
    if(_nivelEdMataria==0){
        cout<<"PRIMARIA"<<endl;
    }else {
        cout<<"SECUNDARIA"<<endl;
    }
    cout<<"ANIO ACADEMICO: "<<_anioMateria<<"-"<<vAnios[_anioMateria-1]<<endl;
    cout << "CARGA HORARIA: " << _cargaHoraria << " horas" << endl;

    if (_estado) {
        cout << "ESTADO: Activa" << endl;
    } else {
        cout << "ESTADO: Inactiva" << endl;
    }
}

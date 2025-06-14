#include <iostream>
#include <cstring>
#include <string>
#include "Materia.h"

using namespace std;

Materia::Materia() {
    _codigo = 0;
    _nombre[0] = '\0';
    _cargaHoraria = 0;
    _activo = true;
}

void Materia::setCodigo(int cod) {
    _codigo = cod;
}

void Materia::setNombre(const char* nombre) {
    strncpy(_nombre, nombre, 29);
    _nombre[29] = '\0';  // por seguridad
}

void Materia::setCargaHoraria(int horas) {
    _cargaHoraria = horas;
}

void Materia::setActivo(bool activo) {
    _activo = activo;
}

int Materia::getCodigo() {
    return _codigo;
}

const char* Materia::getNombre() {
    return _nombre;
}

int Materia::getCargaHoraria() {
    return _cargaHoraria;
}

bool Materia::getActivo() {
    return _activo;
}

void Materia::Cargar() {
    cout << "Código de materia: ";
    cin >> _codigo;
    cin.ignore();

    cout << "Nombre de materia: ";
    cin.getline(_nombre, 30);

    cout << "Carga horaria (en horas): ";
    cin >> _cargaHoraria;

    _activo = true;
}

void Materia::Mostrar() {
    cout << "Código: " << _codigo << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Carga horaria: " << _cargaHoraria << " horas" << endl;

    if (_activo) {
        cout << "Estado: Activa" << endl;
    } else {
        cout << "Estado: Inactiva" << endl;
    }
}

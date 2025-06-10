#include "Curso.h"
#include <iostream>
#include <cstring>
using namespace std;

Curso::Curso() {
    _codigo = 0;
    _nombre[0] = '\0';
    _turno[0] = '\0';
    _vacantes = 0;
    _activo = false;
}

void Curso::setCodigo(int codigo) {
    _codigo = codigo;
}

void Curso::setNombre(const char* nombre) {
    strncpy(_nombre, nombre, 29);
    _nombre[29] = '\0';
}

void Curso::setTurno(const char* turno) {
    strncpy(_turno, turno, 9);
    _turno[9] = '\0';
}

void Curso::setVacantes(int vacantes) {
    _vacantes = vacantes;
}

void Curso::setActivo(bool activo) {
    _activo = activo;
}

int Curso::getCodigo() { return _codigo; }
const char* Curso::getNombre() { return _nombre; }
const char* Curso::getTurno() { return _turno; }
int Curso::getVacantes() { return _vacantes; }
bool Curso::getActivo() { return _activo; }

void Curso::Cargar() {
    cout << "Código del curso: ";
    cin >> _codigo;
    cin.ignore();

    cout << "Nombre del curso: ";
    cin.getline(_nombre, 30);

    cout << "Turno (mañana/tarde/noche): ";
    cin.getline(_turno, 10);

    cout << "Vacantes disponibles: ";
    cin >> _vacantes;

    _activo = true;
}

void Curso::Mostrar() {
    cout << "Código: " << _codigo << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Turno: " << _turno << endl;
    cout << "Vacantes: " << _vacantes << endl;
    if (_activo) {
        cout << "Estado: Activo" << endl;
    } else {
        cout << "Estado: Inactivo" << endl;
    }
}

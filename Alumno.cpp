#include <iostream>
#include <cstring>
#include "Alumno.h"
using namespace std;

void Alumno::setCodigoCurso(int c) { _codigoCurso = c; }
void Alumno::setEstado(bool e) { _estado = e; }
void Alumno::setDeuda(float d) { _deuda = d; }

int Alumno::getCodigoCurso() { return _codigoCurso; }
bool Alumno::getEstado() { return _estado; }
float Alumno::getDeuda() { return _deuda; }

void Alumno::cargar() {
    cargarDatosBasicos(); // método heredado de Persona

    cout << "Código de curso: ";
    cin >> _codigoCurso;

    cout << "Deuda ($): ";
    cin >> _deuda;

    _estado = true; // por defecto se inscribe activo
}

void Alumno::mostrar() {
    mostrarDatosBasicos(); // método heredado

    cout << "Curso: " << _codigoCurso << endl;
    cout << "Deuda: $" << _deuda << endl;
    if (_estado) {
        cout << "Estado: Activo" << endl;
    } else {
        cout << "Estado: Inactivo" << endl;
    }
}

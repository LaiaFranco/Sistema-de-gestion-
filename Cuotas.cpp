#include "Cuota.h"
#include <iostream>
#include <cstring>
using namespace std;

Cuota::Cuota() {
    _legajoAlumno = 0;
    _dni[0] = '\0';
    _monto = 0.0;
    _pagado = false;
}

Cuota::Cuota(int legajo, const char* dni, Fecha vencimiento, float monto, bool pagado) {
    setLegajo(legajo);
    setDNI(dni);
    setFechaVencimiento(vencimiento);
    setMonto(monto);
    setPagado(pagado);
}

void Cuota::setLegajo(int legajo) { _legajoAlumno = legajo; }

void Cuota::setDNI(const char* dni) {
    strncpy(_dni, dni, sizeof(_dni));
    _dni[sizeof(_dni) - 1] = '\0';
}

void Cuota::setFechaVencimiento(Fecha f) { _fechaVencimiento = f; }

void Cuota::setMonto(float monto) { _monto = monto; }

void Cuota::setPagado(bool pagado) { _pagado = pagado; }

int Cuota::getLegajo() { return _legajoAlumno; }

const char* Cuota::getDNI() { return _dni; }

Fecha Cuota::getFechaVencimiento() { return _fechaVencimiento; }

float Cuota::getMonto() { return _monto; }

bool Cuota::getPagado() { return _pagado; }

void Cuota::cargar() {
    cout << "LEGAJO DEL ALUMNO: ";
    cin >> _legajoAlumno;
    cout << "DNI: ";
    cin.ignore();
    cin.getline(_dni, 12);
    int d, m, a;
    cout << "FECHA DE VENCIMIENTO (dia mes anio): ";
    cin >> d >> m >> a;
    _fechaVencimiento = Fecha(d, m, a);
    cout << "MONTO: ";
    cin >> _monto;
    _pagado = false;
}

void Cuota::mostrar() {
    cout << "LEGAJO: " << _legajoAlumno << " | DNI: " << _dni << " | ";
    cout << "VENCIMIENTO: ";
    _fechaVencimiento.Mostrar();
    cout << " | MONTO: $" << _monto << " | ESTADO: ";
    if (_pagado) {
        cout << "PAGADO" << endl;
    } else {
        cout << "IMPAGO" << endl;
    }
}

#pragma once
#include "Fecha.h"

class Cuota {

public:
    Cuota();
    Cuota(int legajo, const char* dni, Fecha vencimiento, float monto, bool pagado);

    void setLegajo(int legajo);
    void setDNI(const char* dni);
    void setFechaVencimiento(Fecha f);
    void setMonto(float monto);
    void setPagado(bool pagado);

    int getLegajo();
    const char* getDNI();
    Fecha getFechaVencimiento();
    float getMonto();
    bool getPagado();

    void cargar();
    void mostrar();

private:
    int _legajoAlumno;
    char _dni[12];
    Fecha _fechaVencimiento;
    float _monto;
    bool _pagado;
};

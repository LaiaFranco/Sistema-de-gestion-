
#include<iostream>
#pragma once
#include "Fecha.h"

#include "Persona.h"

class Alumno : public Persona {
private:
    int _codigoCurso;
    bool _estado;
    float _deuda;

public:
    void setCodigoCurso(int c);
    void setEstado(bool e);
    void setDeuda(float d);

    int getCodigoCurso();
    bool getEstado();
    float getDeuda();

    void cargar();
    void mostrar();
};

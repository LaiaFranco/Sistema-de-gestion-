#pragma once
#include<iostream>

class Fecha{

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia();
    int getMes();
    int getAnio();

    bool EsBiciesto(int anio);
    bool ValidarFecha(int dia, int mes, int anio);

    void Cargar();
    void Mostrar();



private:
    int _dia;
    int _mes;
    int _anio;

};

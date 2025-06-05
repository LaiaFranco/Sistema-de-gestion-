#include<iostream>
#include<cstdlib>
#include "Fecha.h"
using namespace std;

Fecha::Fecha(){
    _dia = 1;
    _mes = 1;
    _anio = 2023;
}
Fecha::Fecha(int dia, int mes, int anio){
    if(ValidarFecha(dia,mes,anio)){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }else {
        _dia = 1;
        _mes = 1;
        _anio = 2023;
    }

}


void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

bool Fecha::EsBiciesto(int anio){
    if((anio%4 == 0 && anio%100 !=0)||(anio%400 == 0))
        return true;
}

bool Fecha::ValidarFecha(int dia, int mes, int anio){
    if(anio < 1) return false;
    if(mes < 1 || mes >12)return false;

    switch(mes){
        case 4: case 6: case 9: case 11:
            return dia >= 1 && dia<=30;
            break;
        case 2:
            if(EsBiciesto(anio)){
                return dia >= 1 && dia<=28;
            }else {
                return dia >= 1 && dia<=29;
            }
            break;
        default:
            return dia >=1 && dia <=31;          }
}




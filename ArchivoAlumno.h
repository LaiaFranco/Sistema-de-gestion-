#pragma once
#include "Alumno.h"
#include<iostream>
#include<string>

class ArchivoAlumno{
public:
    ArchivoAlumno(); ///listo
    int CantidadRegistros(); ///listo
    bool agregarAlumno(const Alumno &reg);
    void  listarRegistros();///listo, me va a listar todos los activos
    void  listarInactivos();///listo
    void listarAlumnoEspecifico(Alumno registro); ///listo
    int buscarAlumno(const char *apellido);
    int buscarAlumnoPorDni (int dni);///listo
    int buscarAlumno(int legajo);///listo
    int ValidarDni();
    Alumno leerAlumno(int pos);///listo pero fijarse
    bool modificarAlumno(const Alumno &reg, int pos);///listo
    bool bajaLogica(int dni);//listo
    bool altaLogica(int dni);///listo
    Alumno buscarAlumnoXDni(int dni);


private:
   char _nombreArchivo[30];
   int _tamanioRegistro;
};

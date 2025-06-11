#pragma once
#include "Alumno.h"
#include<iostream>
#include<string>

class ArchivoAlumno{
public:
    ArchivoAlumno(const char *nombre="Alumno.dat"); ///listo
    int CantidadRegistros(); ///listo
    bool agregarAlumno(Alumno reg); ///listo
    void  listarRegistros();///listo, me va a listar todos los activos
    void  listarInactivos();///listo
    void listarAlumnoEspecifico(Alumno registro); ///listo
    int buscarAlumno(const char *apellido);
    int buscarAlumno (string dni);///listo
    int buscarAlumno(int legajo);///listo
    Alumno leerAlumno(int pos);///listo pero fijarse
    bool modificarAlumno(const Alumno &reg, int pos);///listo
    bool bajaLogica(string dni);//listo
    bool altaLogica(string dni);///listo


private:
   char _nombreArchivo[30];
   int _tamanioRegistro;



};

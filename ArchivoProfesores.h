#pragma once
#include "Profesores.h"
#include"ArchivoProfesores.h"
#include<iostream>
#include<string>


class ArchivoProfesores{

  public:
      ArchivoProfesores();

    int CantidadRegistros();
    bool agregarProfesor(const Profesores &reg);

    void  listarRegistros();
    void  listarInactivos();
    void listarProfesorEspecifico(Profesores registro);
    int buscarProfesor(const char *apellido);
    int buscarProfesorXDni (int dni);
    int buscarProfesor(int legajo);
    Profesores leerProfesor(int pos);
    bool modificarProfesor(const Profesores &reg, int pos);
    bool bajaLogica(int dni);
    bool altaLogica(int dni);

 private:
   char _nombreArchivo[30];
   int _tamanioRegistro;
};

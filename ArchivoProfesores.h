#pragma once
#include "Profesores.h"
#include<iostream>
#include<string>


class ArchivoProfesores{

  public:
      ArchivoProfesores(const char *nombre= "Profesores.dat");

    int CantidadRegistros();
    bool agregarProfesor(Profesores reg);

    void  listarRegistros();
    void  listarInactivos();
    void listarProfesorEspecifico(Profesores registro);
    int buscarProfesor(const char *apellido);
    int buscarProfesor (std::string dni);
    int buscarProfesor(int legajo);
    Profesores leerProfesor(int pos);
    bool modificarProfesor(const Profesores &reg, int pos);
    bool bajaLogica(std::string dni);
    bool altaLogica(std:: string dni);

 private:
   char _nombreArchivo[30];
   int _tamanioRegistro;
};

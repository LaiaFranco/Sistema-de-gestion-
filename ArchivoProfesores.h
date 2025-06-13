#pragma once
#include "Profesores.h"
#include<iostream>
#include<string>


class ArhivoProfesores{

  public:
      ArchivoProfesores(const char *nombre= "Profesores.dat");
      
    int CantidadRegistros();
    bool agregarProfesor(profesores reg);
     
    void  listarRegistros();
    void  listarInactivos();
    void listarProfesorEspecifico(profesores registro); 
    int buscarProfesor(const char *apellido);
    int buscarProfesor (std::string dni);
    int buscarProfesor(int legajo);
    profesores leerProfesor(int pos);
    bool modificarProfesor(const profesores &reg, int pos);
    bool bajaLogica(std::string dni);
    bool altaLogica(std:: string dni);
        
 private:
   char _nombreArchivo[30];
   int _tamanioRegistro;

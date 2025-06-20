#pragma once
#include "ProfesoresxCurso.h"
#include<iostream>
#include<string>

class ArchivoProfesoresxCurso{
 public:

     ArchivoProfesoresxCurso(char const *nombre ="profesoresxcurso.dat");


    int CantidadRegistro();
    bool agregarRelacion(ProfesoresxCurso reg);
    void listarRegistroTotal();
    void listarPorProfesor(int legajoProfesor);
    void listarPorCurso(int  idCurso);
    int buscarRelacion( ProfesoresxCurso reg);
    bool modificarRegistro(ProfesoresxCurso &reg, int pos);
    bool bajaLogica(int  legajoProfesor, int  idCurso );
    bool altaLogica(int legajoProfesor, int idCurso);
    ProfesoresxCurso leerProfesoresxCurso(int pos);



    private:
      char _nombreArchivo[30];
      int _tamanioRegistro;

};

#pragma once
#include<iostream>
#include <string>

using namespace std;




class ProfesoresxCurso{


 public:
    ProfesoresxCurso();
    ProfesoresxCurso(int legajoProfesor, int idCurso);
     
  void setLegajoProfesor(int legajoProfesor);
  void setIdCuros(int idCurso);
  void setEstado(bool Estado);
  
  
  int getLegajoProfesor();
  int getIdCurso();
  bool getEstado();
  
  
     
  void cargar();
  void mostrar();
 
     
     
 private:
    
   int  _legajoProfesor;
   int _idCurso;
   bool _estado;


};

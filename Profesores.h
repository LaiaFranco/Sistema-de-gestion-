#pragma once
#include "Persona.h"
#include<iostream>


using namespace std;

class Profesores : public Persona{
public:
    Profesores();
    Profesores( int tipoDocumento,std::string numDocumento, std::string nombres,std::string apellidos,std::string numTelefono,std::string direccion,
               std::string mail, Fecha fechaNac, int edad, bool estado, int legajoProfesor, int idMateria,int anioIngreso, std::string cbu,float sueldo);




   void  setLegajoProfesor(int legajoProfesor);
   void  setIdMateria(int idMateria);
   void  setAnioIngreso(int anioIngreso);
   void  setCbu(std::string cbu);
   void  setSueldo(float sueldo);


  int getLegajoProfesor();
  int getIdMateria();
  int getAnioIngreso();
  std::string getCbu();
  float getSueldo();


  void cargar(int legajoP);
  void mostrar();

  private:

    int _legajoProfesor;
    int _idMateria;
    int _anioIngreso;
    std::string _cbu;
    float _sueldo;

};


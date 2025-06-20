#pragma once
#include "Persona.h"
#include<iostream>


using namespace std;

class Profesores : public Persona{
public:
    Profesores();
    Profesores( int tipoDocumento, int numDocumento, std::string nombres,std::string apellidos,std::string numTelefono,std::string direccion,
               std::string mail, Fecha fechaNac, int edad, bool estado, int legajoProfesor, int idMateria,int indice,int anioIngreso, const char *cbu,float sueldo);

   void  setLegajoProfesor(int legajoProfesor);
   void  setIdMateria(int idMateria,int i);
   void  setAnioIngreso(int anioIngreso);
   void  setCbu(const char *cbu);
   void  setCantidad(int cant);
   void  setSueldo(float sueldo);


  int getLegajoProfesor();
  int getIdMateria(int i);
  int getAnioIngreso();
  int getCantidad();
  const char *getCbu();
  float getSueldo();

  int mostrarIdMaterias();
  void AgrandarVector();
  void agregarIdMateria(int id);
  void mostrar();

  private:
    int _legajoProfesor;
    int *_idMateria;
    int cantidad; ///lo qure contiene el vector
    int capacidad; ///a la cantidad que puede llegar a contener el vector;
    int _anioIngreso;
    char  _cbu[23];
    float _sueldo;

};


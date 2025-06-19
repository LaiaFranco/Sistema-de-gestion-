#pragma once
#include"ProfesoresPorCurso.h"
#include "ArchivoProfesoresxCurso.h"



class ManagerProfesoresxCurso{

  public:
      
      bool agregarRelacion(const ProfesoresxCurso& reg);
      void listarPorProfesor(int legajoProfesor);
      void listarPorCurso(int idCurso);
      bool modificarRegistro(const ProfesoresxCurso& reg);
      bool altaLogica(const ProfesoresxCurso& reg);
      bool bajaLogica(const ProfesoresxCurso& reg);
      

     private:
      ArchivoProfesoresxCurso _archiProfesorxCurso;
      ArchivoProfesores _archiProfesores;
      ArchivoCursos _archiCursos;


};

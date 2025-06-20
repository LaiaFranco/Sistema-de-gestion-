#include "ManagerProfesoresxCurso.h"
#include<iostream>
#include<cstdlib>
#include <string>
#include <cstdio>

using namespace std;

bool ManagerProfesoresxCurso::agregarRelacion(const ProfesoresxCurso& reg){

    if(_archiProfesores.buscarProfesor(reg.getLegajoProfesor())==-1){

        cout<<"NO EXISTE EL PROFESOR"<<endl;
        return false;
    }

    if(_archiCursos.buscarIdCurso(reg.getIdCurso())==-1){

        cout<<"NO EXISTE EL CURSO"<<endl;
        return false;
    }

    if(_archiProfesorxCurso.buscarRelacion(reg)!=-1){

        cout<<"LA RELACION YA EXISTE"<<endl;
        return false;
    }
    return _archiProfesorxCurso.agregarRelacion(reg);


};

void ManagerProfesoresxCurso::listarPorProfesor(int legajoProfesor){

    if (_archiProfesores.buscarProfesor(legajoProfesor)==-1){

        cout<<"EL PROFESOR CON LEGAJO"<< legajoProfesor<<"NO EXISTE"<<endl;
        return;
    }
    _archiProfesoresxCurso.listarPorProfesor(legajoProfesor);


}
void ManagerProfesoresxCurso::listarPorCurso(int idCurso){

  if(_archiCursos.buscarIdCurso(idCurso)==-1){

    cout<<"EL ID CURSO "<<idCurso<<"NO EXISTE"<<endl;
    return;
  }

  _archiCursos.listarPorCurso(idCurso);

}
bool ManagerProfesoresxCurso::modificarRegistro(const ProfesoresxCurso& reg) {
    int pos = _archiProfesorxCurso.buscarRelacion(reg);

    if (pos == -1) {
        std::cout << "ERROR: La relación no existe y no se puede modificar." << std::endl;
        return false;
    }

    return _archiProfesorxCurso.modificarRegistro(reg, pos);
}
bool ManagerProfesoresxCurso::altaLogica(const ProfesoresxCurso& reg) {
    int pos = _archiProfesorxCurso.buscarRelacion(reg);

    if (pos == -1) {
        std::cout << "ERROR: La relación no existe. No se puede dar de alta." << std::endl;
        return false;
    }

    ProfesoresxCurso r = _archiProfesorxCurso.leerProfesoresxCurso(pos);

    if (r.getEstado()) {
        std::cout << "La relación ya está activa." << std::endl;
        return false;
    }

    r.setEstado(true);
    return _archiProfesorxCurso.modificarRegistro(r, pos);
}
bool ManagerProfesoresxCurso::bajaLogica(const ProfesoresxCurso& reg) {
    int pos = _archiProfesorxCurso.buscarRelacion(reg);

    if (pos == -1) {
        std::cout << "ERROR: La relación no existe. No se puede dar de baja." << std::endl;
        return false;
    }

    ProfesoresxCurso r = _archiProfesorxCurso.leerProfesoresxCurso(pos);

    if (!r.getEstado()) {
        std::cout << "La relación ya está inactiva." << std::endl;
        return false;
    }

    r.setEstado(false);
    return _archiProfesorxCurso.modificarRegistro(r, pos);
}


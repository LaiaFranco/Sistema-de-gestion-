#include "ProfesoresManager.h"
#include<iostream>
#include<cstring>
#include <string>

using namespace std;
bool ProfesoresManager::ValidarDNI(){
    Profesores prof;
    std::string nuevoDni;
            cout<<"INGRESE DNI(sin puntos): ";
            cin>>nuevoDni;
            for(int i=0; i<_archiProf.CantidadRegistros();i++){
                    prof = _archiProf.leerProfesor(i);
            if(prof.getNumeroDocumento()== nuevoDni && prof.ValiadarFormatoDni(nuevoDni)){
                return true;
            }else {return false; }
            }
}
int ProfesoresManager::IncrementarLegajo(){
    int legajo;
    legajo = _archiProf.CantidadRegistros()+1;

    return legajo;
}

int ProfesoresManager::CargarProfesor(){
    Profesores reg;

    if(!ValidarDNI()){
        reg.cargar(IncrementarLegajo());
    if((_archiProf.agregarProfesor(reg))){
        cout<<"SE GUARDO CORRECTAMENTE" <<endl;
        return reg.getLegajoProfesor();
    }else{
        cout<<"HUBO UN ERROR, NO SE PUDO GUARDAR"<<endl;
        return -1;
        }
    }else{
        cout<<"ESE DNI YA ESTA REGISTRADO"<<endl;
        return 0;
    }
}

void ProfesoresManager::buscarProfesorPorLegajo(int legajo){
    Profesores reg;
    int posicion;
    posicion = _archiProf.buscarProfesor(legajo);
    reg = _archiProf.leerProfesor(posicion);
    reg.mostrar();
}

void ProfesoresManager::buscarProfesorPorDNI(std::string dni){
    Profesores reg;
    int posicion;
    posicion = _archiProf.buscarProfesor(dni);
    reg = _archiProf.leerProfesor(posicion);
    reg.mostrar();
}
void ProfesoresManager::buscarProfesorPorApellido(const char *apellido){
    Profesores reg;
    int posicion;
    for(int i = 0;i < _archiProf.CantidadRegistros();i++){
        posicion = _archiProf.buscarProfesor(apellido);
        reg = _archiProf.leerProfesor(posicion);
        if(reg.getEstado()== true){
                reg.mostrar();
        }
    }
}

void ProfesoresManager::ListarProfesoresActivos(){
    Profesores reg;

    cout<<"------ALUMNOS ACTIVOS-------"<<endl;
    _archiProf.listarRegistros();
    cout<<endl;
}

#include "ProfesoresManager.h"
#include<iostream>
#include<cstring>
#include <string>

using namespace std;
bool ProfesoresManager::ValidarDNI(){
    profesores prof;
    std::string nuevoDni;
            cout<<"INGRESE DNI(sin puntos): ";
            cin>>nuevoDni;
            for(int i=0; i<_archiProf.CantidadRegistros();i++){
                    alu = _archiProf.leerProfesor(i);
            if(alu.getNumeroDocumento()== nuevoDni && prof.ValiadarFormatoDni(nuevoDni)){
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
    profesores reg;

    if(!ValidarDNI()){
        reg.Cargar(IncrementarLegajo());
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
    profesores reg;
    int posicion;
    posicion = _archiProf.buscarProfesor(legajo);
    reg = _archiProf.leerProfesor(posicion);
    reg.Mostrar();
}

void ProfesoresManager::buscarProfesorPorDNI(std::string dni){
    profesores reg;
    int posicion;
    posicion = _archiProf.buscarProfesor(dni);
    reg = _archiProf.leerProfesor(posicion);
    reg.Mostrar();
}
void ProfesoresManager::buscarProfesorPorApellido(const char *apellido){
    profesores reg;
    int posicion;
    for(int i = 0;i < _archiProf.CantidadRegistros();i++){
        posicion = _archiProf.buscarProfesor(apellido);
        reg = _archiProf.leerProfesor(posicion);
        if(reg.getEstado()== true){
                reg.Mostrar();
        }
    }
}

void ProfesoresManager::ListarProfesoresActivos(){
    profesores reg;

    cout<<"------ALUMNOS ACTIVOS-------"<<endl;
    _archiProf.listarRegistros();
    cout<<endl;
}

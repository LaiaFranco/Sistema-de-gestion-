#include "AlumnoManager.h"
#include<iostream>
#include<cstring>
#include <string>

using namespace std;
bool AlumnoManager::ValidarDNI(){
    Alumno alu;
    string nuevoDni;
            cout<<"INGRESE DNI(sin puntos): ";
            cin>>nuevoDni;
            for(int i=0; i<_archiALu.CantidadRegistros();i++){
                    alu = _archiALu.leerAlumno(i);
            if(alu.getNumeroDocumento()== nuevoDni && alu.ValiadarFormatoDni(nuevoDni)){
                return true;
            }else {return false; }
            }
}
int AlumnoManager::IncrementarLegajo(){
    int legajo;
    legajo = _archiALu.CantidadRegistros()+1;

    return legajo;
}

int AlumnoManager::CargarAlumno(){
    Alumno reg;

    if(!ValidarDNI()){
        reg.Cargar(IncrementarLegajo());
    if((_archiALu.agregarAlumno(reg))){
        cout<<"SE GUARDO CORRECTAMENTE" <<endl;
        return reg.getLegajoAlumno();
    }else{
        cout<<"HUBO UN ERROR, NO SE PUDO GUARDAR"<<endl;
        return -1;
        }
    }else{
        cout<<"ESE DNI YA ESTA REGISTRADO"<<endl;
        return 0;
    }
}

void AlumnoManager::buscarAlumnoPorLegajo(int legajo){
    Alumno reg;
    int posicion;
    posicion = _archiALu.buscarAlumno(legajo);
    reg = _archiALu.leerAlumno(posicion);
    reg.Mostrar();
}

void AlumnoManager::buscarAlumnoPorDNI(string dni){
    Alumno reg;
    int posicion;
    posicion = _archiALu.buscarAlumno(dni);
    reg = _archiALu.leerAlumno(posicion);
    reg.Mostrar();
}
void AlumnoManager::buscarAlumnoPorApellido(const char *apellido){
    Alumno reg;
    int posicion;
    for(int i = 0;i < _archiALu.CantidadRegistros();i++){
        posicion = _archiALu.buscarAlumno(apellido);
        reg = _archiALu.leerAlumno(posicion);
        if(reg.getEstado()== true){
                reg.Mostrar();
        }
    }
}

void AlumnoManager::ListarAlumnosActivos(){
    Alumno reg;

    cout<<"------ALUMNOS ACTIVOS-------"<<endl;
    _archiALu.listarRegistros();
    cout<<endl;
}


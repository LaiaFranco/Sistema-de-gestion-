#include "AlumnoManager.h"
#include<iostream>
#include<cstdlib>

using namespace std;
void AlumnoManager::CargarAlumno(){
    Alumno reg;

    reg.Cargar();
    if(_archiALu.agregarAlumno(reg)){
        cout<<"SE GUARDO CORRECTAMENTE" <<endl;
    }else{
        cout<<"HUBO UN ERROR, NO SE PUDO GUARDAR"<<endl;
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
    for(int i = 0;i < _archiALu.CantidadRegistros();i++)
    {
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


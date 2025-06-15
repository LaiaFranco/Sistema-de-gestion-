#include "AlumnoManager.h"
#include<iostream>
#include<cstring>
#include <string>
#include <cstdio>

using namespace std;

int AlumnoManager::IncrementarLegajo(){
    int legajo;
    legajo = _archiALu.CantidadRegistros()+1;

    return legajo;
}

Alumno AlumnoManager::CargarAlumno(){
    Alumno reg;
    int tipoDni;
    string numeroDni;
    cout<<"INGRESAR TIPO DE DNI(1-DNI): ";
    cin>>tipoDni;
    cin.clear();
    fflush(stdin);
    reg.setTipoDocumento(tipoDni);
    numeroDni = _archiALu.ValidarDni();
    if(numeroDni!= "YA EXISTE ESE DNI"){
        string nombres,apellidos,numTelefono,direccion,mail;
        string tutor, nombreTutor,apellidoTutor;
        int edad,legajo,nivelAcademico,anioAcademico;
        int dia, mes,anio;
        bool tieneHermanos;
        cout<<"DNI:"<<numeroDni;
        reg.setNumDocumento(numeroDni);
        cout<<endl;
        cout<<"LEGAJO: ";
        legajo = IncrementarLegajo();
        reg.setLegajoAlumno(legajo);
        cout<<legajo<<endl;
        cout<<"NOMBRES: ";
        cin.clear();
        fflush(stdin);
        getline(cin,nombres);
        reg.setNombres(nombres);
        fflush(stdin);
        cout<<"APELLIDOS: ";
        getline(cin,apellidos);
        reg.setApellidos(apellidos);
        fflush(stdin);
        cout<<"EDAD: ";
        cin>>edad;
        cout<<endl;
        reg.setEdad(edad);
        cout<<"FECHA DE NACIMIENTO "<<endl;
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
        reg.setFechaNac(Fecha(dia,mes,anio));
        cout<<"NUMERO DE TELEFONO: ";
        cin.ignore();
        getline(cin,numTelefono,'\n');
        reg.setNumTelefono(numTelefono);
        fflush(stdin);
        cout<<"DIRECCION: ";
        cin.ignore();
        getline(cin,direccion,'\n');
        reg.setDireccion(direccion);
        fflush(stdin);
        cout<<"MAIL: ";
        getline(cin, mail,'\n');
        reg.setMail(mail);
        reg.setEstado(true);
        cout<<"NIVEL ACADEMICO(0-Primario,1-Secundario): ";
        cin>>nivelAcademico;
        reg.setNivelAcademico(nivelAcademico);
        cout<<endl;
        cout<<"ANIO ACADEMICO(1-Primero,2-Segundo,3-Tercero,etc): " ;
        cin>>anioAcademico;
        reg.setAnioAcademico(anioAcademico);

        cout<<"========DATOS DEL TUTOR========="<<endl;
        cout<<"TUTOR A CARGO(mama,papa,otro): ";
        cin.ignore();
        getline(cin,tutor);
        reg.setTutor(tutor);
        cout<<"NOMBRE/S  TUTOR: ";
        getline(cin,nombreTutor);
        reg.setNombreTutor(nombreTutor);
        cout<<"APELLIDO/S TUTOR :" ;
        getline(cin,apellidoTutor);
        reg.setApellidoTutor(apellidoTutor);
        cout<<"TIENE HERMANOS(1-SI,0-NO): ";
        cin>>tieneHermanos;
        _archiALu.agregarAlumno(reg);
        return reg;
    }else{
        cout<<"ESE DNI YA CORRESPONDE A UN ESTUDIANTE"<<endl;
        reg.setLegajoAlumno(0);
        return reg;

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


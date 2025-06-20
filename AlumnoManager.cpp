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
    int  numeroDni;
    cout<<"INGRESAR TIPO DE DNI(1-DNI, 2-OTRO): ";
    cin>>tipoDni;
    reg.setTipoDocumento(tipoDni);
    numeroDni = _archiALu.ValidarDni();
    if(numeroDni!= 0){
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
        reg.setTieneHermanos(tieneHermanos);
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

    for(int i=0; i<_archiALu.CantidadRegistros();i++){
    reg = _archiALu.leerAlumno(i);
    if(reg.getLegajoAlumno()==legajo){
    reg.Mostrar();
    }
    }
}

void AlumnoManager::buscarAlumnoPorDNI(int dni){
    Alumno reg;

    for(int i=0; i<_archiALu.CantidadRegistros();i++){
    reg = _archiALu.leerAlumno(i);
    if(reg.getNumeroDocumento()==dni){
    reg.Mostrar();
    }
    }
}
void AlumnoManager::buscarAlumnoPorApellido(const char *apellido){
    Alumno reg;

    for(int i = 0;i < _archiALu.CantidadRegistros();i++){
        reg = _archiALu.leerAlumno(i);
        if(reg.getApellidos()== apellido){
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

void AlumnoManager::emisionCertificadoRegular( Alumno &reg){
    int dia,mes,anio;
    string VMes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre","Diciembre"};
    cout<<"|| FECHA DE HOY ||"<<endl;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES (1-enero,2-febrero,etc): ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    cout<<endl;
    system("cls");
    cout<<"CERTIFICADO DE ALUMNO REGULAR"<<endl<<endl;
    cout<<"La Dirección del IGB, Istituto General Belgrano, certifica que: "<<endl;
    cout<<"El/la alumno/a "<<reg.getNombres()<<" "<<reg.getApellidos()<<", "<<"DNI " <<reg.getNumeroDocumento()<<" cursa regularmente el " << reg.getAnioAcademico()<<" º "<< "anio del nivel ";
    if( reg.getNivelAcademico()){
        cout<<"secudario ";
    }else {
        cout<<"primario ";
    }
    cout<<"en este establecimiento, durante el ciclo lectivo "<<anio<<endl;
    cout<<"Se extiende el presente certificado a pedido del interesado, a los "<<dia<< " dias del mes de "<<VMes[mes-1]<< " de "<< anio;
    cout<<" para ser presentado ante quien corresponda."<<endl;

    cout<<endl<<endl<<endl;
    cout<<"Firma y sello"<<endl;
}


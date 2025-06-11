#include "Alumno.h"
#include "Persona.h"
#include "ArchivoAlumno.h"
#include <iostream>
#include <cstring>

using namespace std;
Alumno::Alumno(){
    _legajoAlumno = 0;
    _nivelAcademico = false;
    _anioAcademico = 0;
    _tutor[0] = '\0';
    _nombreTutor[0] = '\0';
    _apellidoTutor[0] = '\0';
    _tieneHermanos= false;
}

Alumno::Alumno(int tipoDocumento, string numDocumento,string nombres, string apellidos,
               int edad,string numTelefono, string direccion,string mail,bool estado,
               const Fecha& fechaNac,int legajoAlumno, bool nivelAcademico,int anioAcademico,
               string tutor, string nombreTutor, string apellidoTutor,bool tieneHermanos)
:Persona(tipoDocumento,numDocumento,nombres,apellidos, edad,
         numTelefono,direccion, mail, estado, fechaNac){
    setLegajoAlumno(legajoAlumno);
    setNivelAcademico(nivelAcademico);
    setAnioAcademico(anioAcademico);
    setTutor(tutor);
    setNombreTutor(nombreTutor);
    setApellidoTutor(apellidoTutor);
    setTieneHermanos(tieneHermanos);
}

void Alumno::setLegajoAlumno(int legajoAlumno){
    _legajoAlumno = legajoAlumno;
}
void Alumno::setNivelAcademico(bool nivelAcademico){
    _nivelAcademico = nivelAcademico;
}
void Alumno::setAnioAcademico(int anioAcademico){
    _anioAcademico = anioAcademico;
}
void Alumno::setTutor(string tutor){
    if(tutor.size()<=10){
        strcpy(_tutor,tutor.c_str());
    }
}
void Alumno::setNombreTutor(string nombreTutor){
    if(nombreTutor.size()<=30){
        strcpy(_nombreTutor,nombreTutor.c_str());
    }
}
void Alumno::setApellidoTutor(string apellidoTutor){
    if(apellidoTutor.size()<=30){
        strcpy(_apellidoTutor, apellidoTutor.c_str());
    }
}

void Alumno::setTieneHermanos(bool tieneHermanos){
    _tieneHermanos = tieneHermanos;
}

int Alumno::getLegajoAlumno(){
    return _legajoAlumno;
}
bool Alumno::getNivelAcademico(){
    return _nivelAcademico;
}
int Alumno::getAnioAcademico(){
    return _anioAcademico;
}
string Alumno::getTutor(){
    return _tutor;
}
string Alumno::getNombreTutor(){
    return _nombreTutor;
}
string Alumno::getApellidoTutor(){
    return _apellidoTutor;
}
bool Alumno::getTieneHermanos(){
    return _tieneHermanos;
}



bool Alumno::Cargar(char* nuevoDni){
    ArchivoAlumno archiALu;
    Persona per;

     if(strcmp(nuevoDni,"NADA")==0 && ValiadarFormatoDni(nuevoDni)==1){
            cout<<"INGRESE DNI: ";
            cin>>nuevoDni;
            per.setNumDocumento(nuevoDni);
            string numeroDni= per.getNumeroDocumento();
            if(archiALu.buscarAlumno(numeroDni)>=0){
                cout<<"YA EXISTE USUARIO CON ESTE NUMERO DNI."<<endl;
                return false;
            }
        }
        else{
             per.setNumDocumento(nuevoDni);
        }
    cout<<"-----DATOS PERSONALES-----"<<endl;
    _legajoAlumno = archiALu.CantidadRegistros();
    cout<<"LEGAJO: "<<_legajoAlumno<<endl;
    int  tipoDocumento;
    cout<<"TIPO DE DOCUMENTO(1-DNI, 2-PASAPORTE, 3-LIBRETA CIVICA): ";
    cin>>tipoDocumento;
    per.setTipoDocumento(tipoDocumento);
    cout<<endl;
    string nombres;
    cout<<"NOMBRES: ";
    cin.ignore();
    cin>>nombres;
    per.setNombres(nombres);
    cout<<endl;
    string apellidos;
    cout<<"APELLIDOS: ";
    cin.ignore();
    cin>>apellidos;
    per.setApellidos(apellidos);
    cout<<endl;
    int edad;
    cout<<"EDAD: ";
    cin>>edad;
    per.setEdad(edad);
    cout<<endl;
    int dia;
    int mes;
    int anio;
    cout<<"FECHA NACIMIENTO: ";
    cout<<"DIA: ";
    cin>>dia;
    cout<<endl;
    cout<<"MES: ";
    cin>>mes;
    cout<<endl;
    cout<<"ANIO: ";
    cin>>anio;
    cout<<endl;
    per.setFechaNac(Fecha(dia,mes,anio));
    string numTelefono;
    cout<<"NUMERO DE TELEFONO: " ;
    cin.ignore();
    cin>>numTelefono;
    per.setNumTelefono(numTelefono);
    cout<<endl;
    string direccion;
    cout<<"DIRECCION: ";
    cin.ignore();
    cin>>direccion;
    per.setDireccion(direccion);
    cout<<endl;
    string mail;
    cout<<"MAIL: ";
    cin.ignore();
    cin>>mail;
    per.setMail(mail);
    cout<<endl;
    bool estado=true ;
    per.setEstado(estado);
    cout<<"NIVEL ACDEMICO(0-Primario, 1-Secundario): ";
    cin>> _nivelAcademico;
    cout<<endl;
    cout<<"ANIO ACADEMICO(1-PRIMER,2-SEGUNDO,3-TERCERO,ETC): ";
    cin>>_anioAcademico;
    cout<<endl;
    cout<<"TUTOR A CARGO(madre/padre/otro):";
    cin.ignore();
    cin.getline(_tutor,10);
    cout<<endl;
    cout<<"NOMBRE TUTOR: ";
    cin.ignore();
    cin.getline(_nombreTutor,30);
    cout<<endl;
    cout<<"APELLIDO TUTOR: " ;
    cin.ignore();
    cin.getline(_apellidoTutor,30);
    cout<<endl;
    cout<<"TIENE HERMANOS?(1-SI, 0-NO):";
    cout<<_tieneHermanos;
        return true;
}

void Alumno::Mostrar(){
    Persona per;
    cout<<"-----DATOS PERSONALES-----"<<endl;
    cout<<"LEGAJO: "<<getLegajoAlumno()<<endl; ///terminarlo
    cout<<"TIPO DE DOCUMENTO: ";
    per.MostrarTipoDocumento(getTipoDocumento());
    cout<<endl;
    cout<<"NOMBRES: "<<getNombres()<<endl;
    cout<<"APELLIDOS: "<<getApellidos()<<endl;
    cout<<"EDAD: "<<getEdad()<<endl;
    cout<<"FECHA NACIMIENTO: ";
    per.getFechaNac();
    cout<<endl;
    cout<<"NUMERO DE TELEFONO: "<<getNumTelefono()<<endl;
    cout<<"DIRECCION: ";
    per.getDireccion();
    cout<<endl;
    cout<<"MAIL: "<<getMail()<<endl;
    cout<<"NIVEL ACADEMICO(0-Primario, 1-Secundario): ";
    if(getNivelAcademico()==1){
        cout<<"SECUNDARIO"<<endl;
    }else{
        cout<<"PRIMARIO"<<endl;
    }
    cout<<"ANIO ACADEMICO(1-PRIMER,2-SEGUNDO,3-TERCERO,ETC): "<<getAnioAcademico()<<endl;
    cout<<"TUTOR A CARGO: "<<getTutor()<<endl;
    cout<<"NOMBRE TUTOR: "<<getNombreTutor()<<endl;
    cout<<"APELLIDO TUTOR: "<<getApellidoTutor()<<endl;
    cout<<"TIENE HERMANOS: ";
    if(getTieneHermanos()==1){
        cout<<"SI"<<endl;
    }else{cout<<"NO"<<endl;}
    cout<<"ESTADO: ";
    if(getEstado()){
        cout<<"ACTIVO"<<endl;
    }else{cout<<"INACTIVO"<<endl;}


}


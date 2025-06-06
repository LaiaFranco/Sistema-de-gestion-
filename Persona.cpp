#include "Persona.h"
#include "iostream"
#include "cstring"

using namespace std;
Persona::Persona():_fechaNac(1,1,2023){
        _tipoDocumento = 0;
        _numDocumento[0] = '\0';
        _nombres[0]= '\0';
        _apellidos[0]= '\0';
        _numTelefono[0]= '\0';
        _direccion[0]= '\0';
        _mail[0]= '\0';
        _estado = false;
}

Persona::Persona(int  tipoDocumento, string numDocumento,string nombres, string apellidos,int edad,string numTelefono, string direccion,string mail,bool estado, const Fecha& fechaNac){
    setTipoDocumento(tipoDocumento);
    setNumDocumento(numDocumento);
    setNombres(nombres);
    setApellidos(apellidos);
    setEdad(edad);
    setNumTelefono(numTelefono);
    setDireccion(direccion);
    setMail(mail);
    setEstado(estado);
    setFechaNac(fechaNac);
}

void Persona::setTipoDocumento(int tipoDocumento){
    _tipoDocumento = tipoDocumento;
}

void Persona::setNumDocumento(string numDocumento){
   if(numDocumento.size()<=8){
   strcpy(_numDocumento,numDocumento.c_str());
   }
}

void Persona::setNombres(string nombres){
    strcpy(_nombres, nombres.c_str());

}
void Persona::setApellidos (string apellidos){
    strcpy(_apellidos,apellidos.c_str());
}

void Persona::setEdad(int edad){
    _edad = edad;
}

void Persona::setNumTelefono (string numTelefono){
        strcpy(_numTelefono, numTelefono.c_str());
}

void Persona::setDireccion(string direccion){
        strcpy(_direccion, direccion.c_str());

}

void Persona::setMail (string mail){
        strcpy(_mail,mail.c_str());
}
void Persona::setEstado(bool estado){
    _estado = estado;
}


void Persona::setFechaNac(const Fecha& fechaNac){
    _fechaNac = fechaNac;
}

int Persona::getTipoDocumento(){
    return _tipoDocumento;
}

string Persona::getNumeroDocumento(){
    return _numDocumento;
}
string Persona::getNombres(){
    return _nombres;
}
string Persona::getApellidos(){
    return _apellidos;
}
int Persona::getEdad(){
    return _edad;
}
string Persona::getNumTelefono(){
    return _numTelefono;
}
string Persona::getDireccion(){
    return _direccion;
}
string Persona::getMail(){
    return _mail;
}
bool Persona::getEstado(){
    return _estado;
}
Fecha Persona:: getFechaNac(){
    return _fechaNac;
}

void Persona::Cargar(){
    cout<<"-----DATOS PERSONALES-----"<<endl;
    cout<<"TIPO DE DOCUMENTO(1-DNI, 2-PASAPORTE, 3-LIBRETA CIVICA): ";
    cin>>_tipoDocumento;
    cout<<endl;
    cout<<"NUMERO: ";
    cin>>_numDocumento;
    cout<<endl;
    cout<<"NOMBRES: ";
    cin.ignore();
    cin.getline(_nombres,50);
    cout<<endl;
    cout<<"APELLIDOS: ";
    cin.ignore();
    cin.getline(_apellidos,50);
    cout<<endl;
    cout<<"EDAD: ";
    cin>>_edad;
    cout<<endl;
    cout<<"FECHA NACIMIENTO: ";
    _fechaNac.Cargar();
    cout<<"NUMERO DE TELEFONO: " ;
    cin.ignore();
    cin.getline(_numTelefono,15);
    cout<<endl;
    cout<<"DIRECCION: ";
    cin.ignore();
    cin.getline(_direccion,20);
    cout<<endl;
    cout<<"MAIL: ";
    cin.ignore();
    cin.getline(_mail,50);
    cout<<endl;
    _estado = true;

}


void Persona::Mostrar(){
    cout<<"TIPO DE DOCUMENTO: "<<getTipoDocumento()<<endl;
    cout<<"NUMERO DE DOCUMENTO: "<<getNumeroDocumento()<<endl;
    cout<<"NOMBRES: "<<getNombres()<<endl;
    cout<<"APELLIDOS: "<<getApellidos()<<endl;
    cout<<"EDAD: "<<getEdad()<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    _fechaNac.Mostrar();
    cout<<"MAIL: " <<getMail()<<endl;
    cout<<"ESTADO: " <<getEstado()<<endl;
}




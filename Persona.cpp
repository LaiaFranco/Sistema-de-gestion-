#include "Persona.h"
#include "iostream"
#include "cstring"

using namespace std;
Persona::Persona():_fechaNac(1,1,2023){
        _tipoDocumento = 0;
        _numDocumento[0] = '\0';
        _nombres[0]= '\0';
        _apellidos[0]= '\0';
        _numTelefono[0]= '\0';;
        _direccion[0]= '\0';
        _mail[0]= '\0';

}

Persona::Persona(int  tipoDocumento, string numDocumento,string nombres, string apellidos, string numTelefono, string direccion,string mail, const Fecha& fechaNac){
    setTipoDocumento(tipoDocumento);
    setNumDocumento(numDocumento);
    setNombres(nombres);
    setApellidos(apellidos);
    setNumTelefono(numTelefono);
    setDireccion(direccion);
    setMail(mail);
    setFechaNac(fechaNac);
}

void Persona::setTipoDocumento(int tipoDocumento){
    _tipoDocumento = tipoDocumento;
}

void Persona::setNumDocumento(string numDocumento){
    strcpy(_numDocumento,numDocumento.c_str());
}

void Persona::setNombres(string nombres){
    strcpy(_nombres, nombres.c_str());

}
void Persona::setApellidos (string apellidos){
    strcpy(_apellidos,apellidos.c_str());
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
void Persona::setFechaNac(const Fecha& fechaNac){
    _fechaNac = fechaNac;
}

    string getTipoDocumento();
    string getNumeroDocumento();
    string getNombres();
    string getApellidos();
    string getNumTelefono();
    string getDireccion();
    string getMail();
    Fecha getFechaNac();








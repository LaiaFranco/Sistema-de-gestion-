#pragma once
#include<iostream>
#include "cstring"
#include "string"
#include"Fecha.h"
using namespace std;
class Persona{

public:
    Persona();
    Persona(int tipoDocumento, string numDocumento,string nombres, string apellidos, string numTelefono, string direccion,string mail, const Fecha& fechaNac);

    void setTipoDocumento(int  tipoDocumento);
    void setNumDocumento(string numDocumento);
    void setNombres(string nombres);
    void setApellidos (string apellidos);
    void setNumTelefono (string numTelefono);
    void setDireccion(string direccion);
    void setMail (string mail);
    void setFechaNac(const Fecha& fechaNac);

    int  getTipoDocumento();
    string getNumeroDocumento();
    string getNombres();
    string getApellidos();
    string getNumTelefono();
    string getDireccion();
    string getMail();
    Fecha getFechaNac();


private:
    int  _tipoDocumento;
    char _numDocumento [8];
    char _nombres [50];
    char _apellidos[50];
    char _numTelefono [15];
    char _direccion[20];
    char _mail[50];
    Fecha _fechaNac;


};


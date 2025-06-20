#include "ArchivoProfesores.h"
#include <cstring>
#include<iostream>



ArchivoProfesores::ArchivoProfesores(){
    const char *nombre= "Profesores.dat";
    strcpy(_nombreArchivo,nombre);
    _nombreArchivo[29] = '\0';
    _tamanioRegistro = sizeof(Profesores);
}

int ArchivoProfesores::CantidadRegistros(){
    FILE *pProfesores;
    pProfesores = fopen(_nombreArchivo,"rb");
    if(pProfesores== nullptr){
            return 0;
    }
    fseek(pProfesores,0,SEEK_END);
    int tam= ftell(pProfesores);

    int CantidadRegistros = tam/_tamanioRegistro;
    return CantidadRegistros;
}

bool ArchivoProfesores::agregarProfesor(const Profesores &reg){
    int escribio;
    FILE *pProfesor;
    pProfesor = fopen(_nombreArchivo,"ab");
    if(pProfesor == nullptr){
        return -1;
    }
    escribio = fwrite(&reg,_tamanioRegistro,1,pProfesor);

    fclose(pProfesor);
    return escribio;
}

void ArchivoProfesores::listarRegistros(){
    Profesores reg;
    FILE *pProfesor;

    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getEstado()){
            reg.mostrar();
        }
    }

    fclose(pProfesor);
}

void ArchivoProfesores::listarInactivos(){
    Profesores reg;
    FILE *pProfesor;

    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor== nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getEstado()==0){
            reg.mostrar();
        }
    }

    fclose(pProfesor);
}

void ArchivoProfesores::listarProfesorEspecifico(Profesores registro){
    FILE *pProfesor;

    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor==nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    int leer= fread(&registro,_tamanioRegistro,1,pProfesor);
    if(leer==1){
        registro.mostrar();
    }

    fclose(pProfesor);
}

int ArchivoProfesores::buscarProfesorXDni(int dni){
     Profesores reg;
    int posicion=0;

    FILE *pProfesor;
    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor== nullptr){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getNumeroDocumento()== dni){
            fclose(pProfesor);
            return posicion;
        }
        posicion++;
    }
    fclose(pProfesor);
    return -1;
}

int ArchivoProfesores::buscarProfesor(int legajo){
     Profesores reg;
    int posicion=0;

    FILE *pProfesor;
    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor== nullptr){
       /// cout<<"ERROR DE ARCHIVO"<<endl;
       return -1;
    }
    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getLegajoProfesor()== legajo){
            fclose(pProfesor);
            return posicion;
        }
        posicion++;
    }
    fclose(pProfesor);
    return -1;
}

int ArchivoProfesores::buscarProfesor(const char* apellido){
     Profesores reg;
    int posicion=0;

    FILE *pProfesor;
    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor== nullptr){
       /// cout<<"ERROR DE ARCHIVO"<<endl;
       return -1;
    }
    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getApellidos()== apellido){
            fclose(pProfesor);
            return posicion;
        }
        posicion++;
    }
    fclose(pProfesor);
    return -1;
}


Profesores ArchivoProfesores::leerProfesor(int pos){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb");
    if(pArchivo== nullptr){
        return Profesores();
    }
    Profesores reg;
    fseek(pArchivo,_tamanioRegistro*pos,SEEK_SET);
    fread(&reg,_tamanioRegistro,1,pArchivo);

    fclose(pArchivo);
    return reg;
}

bool ArchivoProfesores::modificarProfesor(const Profesores &reg, int pos){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb+");
    if(pArchivo==nullptr){
        return 0;
    }
    fseek(pArchivo,pos*_tamanioRegistro,0);
    bool escribio = fwrite(&reg,_tamanioRegistro,1,pArchivo);

    fclose(pArchivo);
    return escribio;
}

bool ArchivoProfesores::bajaLogica(int dni){
    Profesores reg;
    ArchivoProfesores archi;
    int pos=archi.buscarProfesor(dni);
    if(pos==-1) return false;
    reg = archi.leerProfesor(pos);
    reg.setEstado(false);
    return archi.modificarProfesor(reg,pos);
}

bool ArchivoProfesores::altaLogica(int dni){
    Profesores reg;
    ArchivoProfesores archi;
    int pos=archi.buscarProfesor(dni);
    if(pos==-1) return false;
    reg = archi.leerProfesor(pos);
    reg.setEstado(true);
    return archi.modificarProfesor(reg,pos);
}

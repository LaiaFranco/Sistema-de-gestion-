#include "ArchivoAlumno.h"
#include<iostream>
#include<cstdlib>

using namespace std;

ArchivoAlumno::ArchivoAlumno(){
    const char *nombre = "Alumno.dat";
    strcpy(_nombreArchivo,nombre);
    _nombreArchivo[29] = '\0';
    _tamanioRegistro = sizeof(Alumno);
}
int ArchivoAlumno::CantidadRegistros(){
    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
            return 0;
    }
    fseek(pAlumno,0,SEEK_END); //ubica el puntero en lo ultimo del archivo
    int tam= ftell(pAlumno);

    int CantidadRegistros = tam/_tamanioRegistro;
    return CantidadRegistros;
}

bool ArchivoAlumno::agregarAlumno(const Alumno &reg){
    int escribio;
    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo,"ab");
    if(pAlumno == nullptr){
        return false;
    }
    escribio = fwrite(&reg,_tamanioRegistro,1,pAlumno);

    fclose(pAlumno);
    return escribio;
}

void ArchivoAlumno::listarRegistros(){
    Alumno reg;
    FILE *pAlumno;

    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,pAlumno)==1){
        if(reg.getEstado()){
            reg.Mostrar();
        }
    }

    fclose(pAlumno);
}

void ArchivoAlumno::listarInactivos(){
    Alumno reg;
    FILE *pAlumno;

    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,pAlumno)==1){
        if(reg.getEstado()==0){
            reg.Mostrar();
        }
    }

    fclose(pAlumno);
}

void ArchivoAlumno::listarAlumnoEspecifico(Alumno registro){
    FILE *pAlumno;

    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno==nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    int leer= fread(&registro,_tamanioRegistro,1,pAlumno);
    if(leer==1){
        registro.Mostrar();
    }

    fclose(pAlumno);
}

int ArchivoAlumno::buscarAlumnoPorDni(int dni){
     Alumno reg;
    int posicion=0;

    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    while(fread(&reg,_tamanioRegistro,1,pAlumno)==1){
        if(reg.getNumeroDocumento()== dni){
            fclose(pAlumno);
            return posicion;
        }
        posicion++;
    }
    fclose(pAlumno);
    return -1;
}

int ArchivoAlumno::buscarAlumno(int legajo){
     Alumno reg;
    int posicion=0;

    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
       /// cout<<"ERROR DE ARCHIVO"<<endl;
       return -1;
    }
    while(fread(&reg,_tamanioRegistro,1,pAlumno)==1){
        if(reg.getLegajoAlumno()== legajo){
            fclose(pAlumno);
            return posicion;
        }
        posicion++;
    }
    fclose(pAlumno);
    return -1;
}

int ArchivoAlumno::buscarAlumno(const char* apellido){
     Alumno reg;
    int posicion=0;

    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
       /// cout<<"ERROR DE ARCHIVO"<<endl;
       return -1;
    }
    while(fread(&reg,_tamanioRegistro,1,pAlumno)==1){
        if(reg.getApellidos()== apellido){
            fclose(pAlumno);
            return posicion;
        }
        posicion++;
    }
    fclose(pAlumno);
    return -1;
}

int  ArchivoAlumno::ValidarDni(){
    Alumno alu;
    int dni;

    cout<<"INGRESAR DNI: ";
    cin>>dni;
            for(int i=0; i< CantidadRegistros();i++){
                    alu = leerAlumno(i) ;
            if(alu.getNumeroDocumento()== dni){
                return 0;
                break;
            }
            }
        return dni;
}


Alumno ArchivoAlumno::leerAlumno(int pos){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb");
    if(pArchivo== nullptr){
        return Alumno();
    }
    Alumno reg;
    fseek(pArchivo,_tamanioRegistro*pos,SEEK_SET);
    fread(&reg,_tamanioRegistro,1,pArchivo);

    fclose(pArchivo);
    return reg;
}

bool ArchivoAlumno::modificarAlumno(const Alumno &reg, int pos){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb+");
    if(pArchivo==nullptr){
        return -1;
    }
    fseek(pArchivo,pos*_tamanioRegistro,0);
    bool escribio = fwrite(&reg,_tamanioRegistro,1,pArchivo);

    fclose(pArchivo);
    return escribio;
}

bool ArchivoAlumno::bajaLogica(int dni){
    Alumno reg;
    ArchivoAlumno archi;
    int pos=archi.buscarAlumno(dni);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg = archi.leerAlumno(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarAlumno(reg,pos);
}

bool ArchivoAlumno::altaLogica(int dni){
    Alumno reg;
    ArchivoAlumno archi;
    int pos=archi.buscarAlumno(dni);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg = archi.leerAlumno(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return archi.modificarAlumno(reg,pos);
}

Alumno ArchivoAlumno::buscarAlumnoXDni(int dni){
    Alumno reg;
    int posicion=0;

    FILE *pAlumno;
    pAlumno = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return Alumno();
    }
    while(fread(&reg,_tamanioRegistro,1,pAlumno)==1){
        if(reg.getNumeroDocumento()== dni){
            fclose(pAlumno);
            return reg;
        }
        posicion++;
    }
    fclose(pAlumno);
    return Alumno();
}

#include "ArchivoInscripcion.h"
#include <iostream>
#include <string>
using namespace std;
ArchivoInscripcion::ArchivoInscripcion(const char *nombre){
    strcpy(_nombreArchivo,nombre);
    _nombreArchivo[29] = '\0';
    _tamanioRegistro = sizeof(inscripcion);
}
int ArchivoInscripcion::CantidadRegistros(){
    FILE *pInscripcion;
    pInscripcion = fopen(_nombreArchivo,"rb");
    if(pInscripcion== nullptr){
            return 0;
    }

    fseek(pInscripcion,0,SEEK_END); //ubica el puntero en lo ultimo del archivo
    int tam= ftell(pInscripcion);

    int CantidadRegistros = tam/_tamanioRegistro;
    return CantidadRegistros;

    fclose(pInscripcion);
}

bool ArchivoInscripcion::agregarInscripcion(const inscripcion &reg){
    int escribio;
    FILE *p;
    p = fopen(_nombreArchivo,"ab");
    if(p == nullptr){
        return -1;
    }
    escribio = fwrite(&reg,_tamanioRegistro,1,p);

    pclose(p);
    return escribio;
}

void ArchivoInscripcion::listarIncripciones(){
    inscripcion reg;
    FILE *p;

    p = fopen(_nombreArchivo,"rb");
    if(p==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,p)==1){
        if(reg.getEstado()){
            reg.Mostrar();
        }
    }
    fclose(p);

}
void ArchivoInscripcion::listarInactivos(){
    inscripcion reg;
    FILE *p;

    p = fopen(_nombreArchivo,"rb");
    if(p== nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,p)==1){
        if(reg.getEstado()==0){
            reg.Mostrar();
        }
    }
    fclose(p);
}

void ArchivoInscripcion::listarInscripcionPorAnio(int anio){
    inscripcion registro;
    FILE *p;

    p = fopen(_nombreArchivo,"rb");
    if(p== nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    while(fread(&registro,_tamanioRegistro,1,p)==1){
        if(registro.getfechaInscripcion().getAnio()==anio){
            registro.Mostrar();
        }
    }
    fclose(p);
}

int ArchivoInscripcion::buscarInscripcion(int idCurso){
    inscripcion reg;
    int posicion=0;

    FILE *p;
    p = fopen(_nombreArchivo,"rb");
    if(p== nullptr){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    while(fread(&reg,_tamanioRegistro,1,p)==1){
        if(reg.getIdCurso() == idCurso){
            fclose(p);
            return posicion;
        }
        posicion++;
    }
    fclose(p);
    return -1;
}

int ArchivoInscripcion::buscarInscripcionPorLegajo(int legajo){
    inscripcion reg;
    int posicion=0;

    FILE *p;
    p = fopen(_nombreArchivo,"rb");
    if(p== nullptr){
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    while(fread(&reg,_tamanioRegistro,1,p)==1){
        if(reg.getlegajoAlumno() == legajo){
            fclose(p);
            return posicion;
        }
        posicion++;
    }
    fclose(p);
    return -1;
}

inscripcion ArchivoInscripcion::leerInscripcion(int pos){
    FILE *p;
    p = fopen(_nombreArchivo,"rb");
    if(p== nullptr){
        return inscripcion();
    }

    inscripcion reg;
    fseek(p,_tamanioRegistro*pos,SEEK_END);
    fread(&reg,_tamanioRegistro,1,p);

    fclose(p);
    return reg;
}

bool ArchivoInscripcion:: modificarInscripcion(const inscripcion &reg, int pos){
    FILE *p;
    p = fopen(_nombreArchivo,"rb+");
    if(p==nullptr){
        return -1;
    }
    fseek(p,pos*_tamanioRegistro,0);
    bool escribio = fwrite(&reg,_tamanioRegistro,1,p);

    fclose(p);
    return escribio;
}

bool ArchivoInscripcion::bajaLogica(int idInscripcion){
    inscripcion reg;

    int pos=buscarInscripcion(idInscripcion);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg = leerInscripcion(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return modificarInscripcion(reg,pos);
}

bool ArchivoInscripcion::altaLogica(int idInscripcion){
    inscripcion reg;

    int pos= buscarInscripcion(idInscripcion);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg = leerInscripcion(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return modificarInscripcion(reg,pos);

}

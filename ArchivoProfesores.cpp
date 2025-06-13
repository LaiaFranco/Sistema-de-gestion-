#include"Profesores.h"
#include<iostream>
#include<cstdlib>

using namespace std;

ArchivoProfesores::ArchivoProfesores(const char *nombre){
    strcpy(_nombreArchivo,nombre);
    _nombreArchivo[29] = '\0';
    _tamanioRegistro = sizeof(profesores);
}
int ArchivoProfesores::CantidadRegistros(){
    FILE *pProfesores;
    pProfesores = fopen(_nombreArchivo,"rb");
    if(pProfesores== nullptr){
            return 0;
    }
    fseek(pProfesores,0,SEEK_END); 
    int tam= ftell(pAlumno);

    int CantidadRegistros = tam/_tamanioRegistro;
    return CantidadRegistros;
}

bool ArchivoProfesores::agregarProfesor(Alumno reg){
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
    profesores reg;
    FILE *pProfesor;

    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getEstado()){
            reg.Mostrar();
        }
    }

    fclose(pProfesor);
}

void ArchivoProfesores::listarInactivos(){
    Alumno reg;
    FILE *pProfesor;

    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor== nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getEstado()==0){
            reg.Mostrar();
        }
    }

    fclose(pProfesor);
}

void ArchivoProfesores::listarProfesorEspecifico(profesores registro){
    FILE *pProfesor;

    pProfesor = fopen(_nombreArchivo,"rb");
    if(pProfesor==nullptr){
        cout<<"ERROR EN EL ARCHIVO"<<endl;
    }

    int leer= fread(&registro,_tamanioRegistro,1,pProfesor);
    if(leer==1){
        registro.Mostrar();
    }

    fclose(pProfesor);
}

int ArchivoProfesores::buscarProfesor(string dni){
     profesores reg;
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
     profesores reg;
    int posicion=0;

    FILE *pProfesor;
    pProfesor = fopen(_nombreArchivo,"rb");
    if(pAlumno== nullptr){
       /// cout<<"ERROR DE ARCHIVO"<<endl;
       return -1;
    }
    while(fread(&reg,_tamanioRegistro,1,pProfesor)==1){
        if(reg.getLegajoAlumno()== legajo){
            fclose(pProfesor);
            return posicion;
        }
        posicion++;
    }
    fclose(pProfesor);
    return -1;
}

int ArchivoProfesores::buscarProfesor(const char* apellido){
     profesores reg;
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


profesores ArchivoProfesores::leerProfesor(int pos){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb");
    if(pArchivo== nullptr){
        return profesores();
    }
    profesores reg;
    fseek(pArchivo,_tamanioRegistro*pos,SEEK_END);
    fread(&reg,_tamanioRegistro,1,pArchivo);

    fclose(pArchivo);
    return reg;
}

bool ArchivoProfesores::modificarProfesor(const profesores &reg, int pos){
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

bool ArchivoProfesores::bajaLogica(string dni){
    profesores reg;
    ArchivoProfesores archi;
    int pos=archi.buscarProfesor(dni);
    if(pos==-1) return false;
    reg = archi.leerProfesor(pos);
    reg.setEstado(false);
    return archi.modificarProfesor(reg,pos);
}

bool ArchivoProfesores::altaLogica(string dni){
    profesores reg;
    ArchivoProfesores archi;
    int pos=archi.buscarProfesor(dni);
    if(pos==-1) return false;
    reg = archi.leerProfesor(pos);
    reg.setEstado(true);
    return archi.modificarProfesor(reg,pos);
}

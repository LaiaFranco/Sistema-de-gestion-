#include"ProfesoresPorCurso.h"
#include"ArchivoProfesoresxCurso.h"
#include <cstring>
#include<iostream>
#include<cstdlib>



 ArchivoProfesoresxCurso::ArchivoProfesoresxCurso(const char *nombre){
 
    strcpy(_nombreArchivo,nombre);
    _nombreArchivo[29] = '\0';
    _tamanioRegistro = sizeof(ProfesoresxCurso);
 
 
}

 int ArchivoProfesoresxCurso::CantidadRegistro(){
 
 FILE *pProfesoresxCurso;
 pProfesoresxCurso=fopen (_nombreArchivo,"rb");
 
 if (pProfesoresxCurso==nullptr){
    
    return 0;
 }
 
 fseek (pProfesoresxCurso,0,SEEK_END);
 int tam=ftell(pProfesoresxCurso);
 int CantidadRegistro=tam/_tamanioRegistro;
 return CantidadRegistro;
 
 
}

bool ArchivoProfesoresxCurso::agregarRelacion(ProfesoresxCurso reg){

int escribio;
FILE *pProfesoresxCurso;
pProfesoresxCurso=fopen(_nombreArchivo,"ab")
if(pProfesoresxCurso==nullptr){
    
 return -1;   
}
escribio=fwrite(&reg,_tamanioRegistro,1,pProfesoresxCurso);

fclose(pProfesoresxCurso);
return escribio;

}

void ArchivoProfesoresxCurso::listarRegistroTotal(){

 ProfesoresXCurso reg;
 FILE *pProfesoresxCurso;
 pProfesoresxCurso=fopen (_nombreArchivo,"rb")
 if(pProfesoresxCurso==nullptr){
    
    cout<<"ERROR! NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    
 }
     while(fread(&reg,_tamanioRegistro,1,pProfesoresxCurso)==1){
        if(reg.getEstado()){
            reg.mostrar();
        }
 }
  
  fclose(pProfesoresxCurso);

}

void ArchivoProfesoresxCurso::listarPorProfesor(int legajoProfesor){
    
   FILE *pProfesoresxCurso;
   
   pProfesoresxCurso=fopen(_nombreArchivo,"rb") 
    if(pProfesoresxCurso==nullptr){
    
    cout<<"ERROR! NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    
    return -1;
    
 }
 ProfesoresxCurso reg;
 while(fread(&reg,_tamanioRegistro,1,pProfesoresxCurso)==1){
    
 if (reg.getLegajoProfesor() == legajoProfesor && reg.getEstado()) {
            reg.mostrar();
        }
    }

    fclose(pProfesoresxCurso);
}


void ArchivoProfesoresxCurso::listarPorCurso(int  idCurso){

 FILE *pProfesoresxCurso;
   
   pProfesoresxCurso=fopen(_nombreArchivo,"rb") 
    if(pProfesoresxCurso==nullptr){
    
    cout<<"ERROR! NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    
    return -1;

}
ProfesoresxCurso reg;
while(fread(&reg,_tamanioRegistro,1,pProfesoresxCurso)==1){
    
 if (reg.getidCurso() == idCurso )) {
            reg.mostrar();
        }
    }

    fclose(pProfesoresxCurso);
}
void ArchivoProfesoresxCurso::buscarRelacion(ProfesoresxCurso reg);




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
pProfesoresxCurso=fopen(_nombreArchivo,"ab");
if(pProfesoresxCurso==nullptr){

 return false;
}
escribio=fwrite(&reg,_tamanioRegistro,1,pProfesoresxCurso);

fclose(pProfesoresxCurso);
return escribio;

}

void ArchivoProfesoresxCurso::listarRegistroTotal(){

 ProfesoresXCurso reg;
 FILE *pProfesoresxCurso;
 pProfesoresxCurso=fopen (_nombreArchivo,"rb");
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

    

}
ProfesoresxCurso reg;
while(fread(&reg,_tamanioRegistro,1,pProfesoresxCurso)==1){

 if (reg.getidCurso() == idCurso )) {
            reg.mostrar();
        }
    }

    fclose(pProfesoresxCurso);
}
int ArchivoProfesoresxCurso::buscarRelacion(ProfesoresxCurso buscReg){
  int posicion=0;
 FILE *pProfesoresxCurso;
 pProfesoresxCurso=fopen(_nombreArchivo,"rb");
 if(pProfesoresxCurso==nullptr){
    
    cout<<"ERROR! NO SE PUDO ABRIR EL ARCHIVO"<<endl;
    
    return -2;
 }
 ProfesoresxCurso reg;
 while(fread(&reg,_tamanioRegistro,1,pProfesoresxCurso)==1){
    
    if(reg.getLegajoProfesor()== buscReg.getLegajoProfesor()&& reg.getIdCurso()==buscReg.getIdCurso()&& reg.getEstado()) {
       
       fclose(pProfesoresxCurso);
        return posicion;
     }
     
     posicion++;
 }
 
 fclose(pProfesoresxCurso);
 return-1;
 
}
bool ArchivoProfesoresxCurso:: modificarRegistro(ProfesoresxCurso &reg, int pos){

  FILE *pProfesoresxCurso;
  pProfesoresxCurso=fopen(_nombreArchivo,"rb+");
  if(pProfesoresxCurso==nullptr){
    
    cout<<"ERROR! NO SE PUDO ABRIR EL ARCHIVO"<<endl;
      return-1;
}

 fseek(pProfesoresxCurso,pos*_tamanioRegistro,SEEK_SET);
    bool escribio = fwrite(&reg,_tamanioRegistro,1,pProfesoresxCurso);

    fclose(pProfesoresxCurso);
    return escribio;

}
bool ArchivoProfesoresxCurso::bajaLogica(int legajoProfesor, int idCurso) {
    ProfesoresxCurso reg;
    int pos = buscarRelacion(ProfesoresxCurso(legajoProfesor, idCurso)); 
    
    if (pos == -1){
        
        return false; 
    }
    
    
    reg = leerProfesoresxCurso(pos);  
    
    reg.setEstado(false);  
    
    return modificarRegistro(reg, pos);  
}

bool ArchivoProfesoresxCurso::altaLogica(int legajoProfesor, int idCurso) {
    ProfesoresxCurso reg;
    int pos = buscarRelacion(ProfesoresxCurso(legajoProfesor, idCurso)); 
    
    if (pos == -1) {
        
     return false;  
    }
    reg = leerProfesoresxCurso(pos);  
    
    reg.setEstado(true);  
    
    return modificarRegistro(reg, pos);  
}
ProfesoresxCurso ArchivoProfesoresxCurso::leerProfesor(int pos){
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb");
    if(pArchivo== nullptr){
        return ProfesoresxCurso();
    }
    ProfesoresxCurso reg;
    fseek(pArchivo,_tamanioRegistro*pos,SEEK_SET);
    fread(&reg,_tamanioRegistro,1,pArchivo);

    fclose(pArchivo);
    return reg;
}


#include <iostream>
#include <cstring>
#include"ProfesoresPorCurso.h"


using namespace std;

 ProfesoresxCurso::ProfesoresxCurso{


 _legajoProfesor=0;
 _idCurso=0;
 _estado=true;


 }

 ProfesoresxCurso::ProfesoresxCurso(int legajoProfesor, int idCurso){

 setLegajoProfesor( legajoProfesor);
 setIdCurso( idCurso);
 setEstado( Estado);

}


 void ProfesoresxCurso::setLegajoProfesor(int legajoProfesor){

 _legajoProfesor=legajoProfesor;

 }

 void ProfesoresxCurso::setIdCuros(int idCurso){

 _idCurso=idCurso;

 }

 void ProfesoresxCurso::setEstado(bool Estado){

 _estado=Estado;

 }
 int ProfesoresxCurso::getLegajoProfesor()  {
    return _legajoProfesor;
}

int ProfesoresxCurso::getIdCurso()  {
    return _idCurso;
}

bool ProfesoresxCurso::getEstado()  {
    return _estado;
}

 void ProfesoresxCurso::cargar(){


 cout<<"INGRESE SU LEGAJO: "<<endl;
 cin>> _legajoProfesor;

 cout<<"INGRESE EL ID DEL CURSO: "<<endl;
 cin>>_idCurso;

 _estado = true;


 }

 void ProfesoresxCurso::mostrar(){

 cout<<"LEGAJO NUMERO: "<< getlegajoprofesor()<<endl;

 cout<<"ID DE CURSO: "<<getIdCurso()<<endl;

 if (_estado) {
        cout << "ESTADO: Activo" << endl;
    } else {
        cout << "ESTADO: Inactivo" << endl;
    }
}

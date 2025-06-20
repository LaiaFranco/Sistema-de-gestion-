#include "Profesores.h"
#include "Persona.h"
#include <iostream>
#include <cstring>


using namespace std;
Profesores::Profesores(){
      _legajoProfesor=0;
      cantidad = 0;
      capacidad = 1;
      _idMateria = new int [capacidad];
      _anioIngreso=0;
      _cbu[0]= '\0';
      _sueldo=0.0;
}


Profesores::Profesores(int tipoDocumento , int numDocumento, std::string nombres,std::string apellidos,std::string numTelefono,std::string direccion,
               std::string mail, Fecha fechaNac, int edad, bool estado, int legajoProfesor, int idMateria,int indice,int anioIngreso, const char *cbu,float sueldo)
      :Persona(tipoDocumento,numDocumento,nombres,apellidos, edad,
         numTelefono,direccion, mail, estado, fechaNac){

    setLegajoProfesor( legajoProfesor);
    setIdMateria(idMateria,indice);
    setAnioIngreso( anioIngreso);
    setCbu(cbu);
    setSueldo(sueldo);

 }


 void Profesores::setLegajoProfesor(int legajoProfesor){

       _legajoProfesor=legajoProfesor;

}

 void Profesores::setIdMateria(int idMateria, int i){
    i = i-1;
    if(i < 0){
        cout << "Índice inválido (menor que 1)" << endl;
        return;
    }

    // Si el índice es mayor o igual a capacidad, agrandamos
    if(i >= capacidad){
        AgrandarVector();
    }

    // Si el índice es mayor o igual a cantidad, ajustamos cantidad también
    if(i >= cantidad){
        cantidad = i + 1;
    }

    _idMateria[i] = idMateria;
}

  void Profesores::setAnioIngreso(int anioIngreso){

    _anioIngreso=anioIngreso;

  }

  void Profesores::setCbu(const char *cbu){
      if(strlen(cbu)==22){
        strcpy(_cbu,cbu);
        _cbu[23] = '\0';
      }

  }
  void Profesores:: setCantidad(int cant){
      cantidad = cant;
  }

  void Profesores::setSueldo(float sueldo){

    _sueldo=sueldo;

  }


  int Profesores::getLegajoProfesor(){

      return _legajoProfesor;
  }

  int Profesores::getCantidad(){
      return cantidad;
  }

  int Profesores::getIdMateria(int i) {
    if (i >= 0 && i < cantidad) {
        return _idMateria[i];
    } else {
        return -1; // índice inválido
    }
}
  int Profesores::mostrarIdMaterias(){
        cout<<"---- MATERIAS DEL PROFESOR ----"<<endl;
        for(int i=0;i<cantidad;i++){
                cout<<"Materia N: "<<i+1<<_idMateria[i]<<endl;
        }
        cout<<endl;
    }

  int Profesores::getAnioIngreso(){

   return _anioIngreso;

  }

  const char *Profesores::getCbu(){

    return _cbu;
  }

  float Profesores::getSueldo(){

  return _sueldo;
  }

void Profesores::AgrandarVector(){
    int NuevaCapacidad = capacidad +1;
    int *Vec = new int[NuevaCapacidad];
    if(Vec==nullptr){cout<<"vector con basura"<<endl;}

    for(int i=0; i<cantidad;i++){
        Vec[i] = _idMateria[i];
    }

    delete[] _idMateria;
    _idMateria = Vec;
    capacidad = NuevaCapacidad;
}

void Profesores::agregarIdMateria(int id){
    if(cantidad >= capacidad){
        AgrandarVector();
    }
    _idMateria[cantidad++] = id;
}


  void Profesores::mostrar(){
    cout<<"-----DATOS PERSONALES-----"<<endl;
    cout<<"LEGAJO: "<<getLegajoProfesor()<<endl;
    cout<<"TIPO DE DOCUMENTO: ";
    MostrarTipoDocumento(getTipoDocumento());
    cout<<endl;
    cout<<"NOMBRES: "<<getNombres()<<endl;
    cout<<"APELLIDOS: "<<getApellidos()<<endl;
    cout<<"EDAD: "<<getEdad()<<endl;
    cout<<"FECHA NACIMIENTO: ";
    getFechaNac().Mostrar();
    cout<<"NUMERO DE TELEFONO: "<<getNumTelefono()<<endl;
    cout<<"DIRECCION: "<<getDireccion()<<endl;
    cout<<"MAIL: "<<getMail()<<endl;

    cout<< "============DATOS INSTITUCIONALES ======="<<endl;
    cout<<"MATERIA: "<<mostrarIdMaterias()<<endl;
    cout<<"AÑO DE INGRESO A LA INSITUCION: "<<getAnioIngreso()<<endl;
    cout<< "NUMERO DE CBU: "<<getCbu()<<endl;
    cout<<"MONTO DE SUELDO: "<<getSueldo()<<endl;

  }




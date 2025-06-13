#include "Profesores.h"
#include <iostream>
#include <cstring>


using namespace std;


  profesores::profesores(){

      _legajoProfesor=0;
      _idMateria=0;
      _anioDeIngreso=0;
      _cbu[0]= '\0';
      _sueldo=0.0;

  }


    profesores::profesores(( int tipoDocumento,std::string numDocumento, std::string nombres,std::string apellidos,std::string numTelefono,std::string direccion
               std::string mail, Fecha fechaNac,int legajoProfesor, int idMateria,int anioIngreso, std::string cbu,float sueldo)

      :Persona(tipoDocumento,numDocumento,nombres,apellidos, edad,
         numTelefono,direccion, mail, estado, fechaNac){

    setLegajoProfesor( legajoProfesor);
    setIdMateria(idMateria);
    setAnioIngreso( anioIngreso);
    setCbu(cbu);
    setSueldo(sueldo);




 void profesores::setLegajoProfesor(int legajoProfesor){

       _legajoProfesor=legajoProfesor;

}

 void profesores::setIdMateria(int idMateria){

     _idMateria=idMateria;

 }


  void profesores::setAnioIngreso(int anioIngreso){

    _anioIngreso=anioIngreso;

  }


  void profesores::setCbu(std::string cbu){

      _cbu=cbu;

  }

  void profesores::setSueldo(float sueldo){

    _sueldo=sueldo;

  }


  int profesores::getLegajoProfesor(){

      return _legajoProfesor;
  }

  int profesores::getIdMateria(){

      return _idMateria;
  }

  int profesores::getAnioIngreso(){

   return _anioIngreso;

  }

  std::string profesores::getCbu(){

    return _cbu;
  }

  float profesores::getSueldo(){

  return _sueldo;
  }


  bool profesores::cargar(){

   cout<< "=============DATOS PERSONALES ============"<< endl;
   cout<<endl;
      _legajoProfesor=legajoP;
   cout<< "Su Legajo es: "<< _legajoProfesor<< endl;
   int  tipoDocumento;
    cout<<"TIPO DE DOCUMENTO(1-DNI, 2-PASAPORTE, 3-LIBRETA CIVICA): ";
    cin>>tipoDocumento;
    setTipoDocumento(tipoDocumento);
    string nombres;
    cout<<"NOMBRES: ";
    getline(cin,nombres);
    setNombres(nombres);
    string apellidos;
    cout<<"APELLIDOS: ";
    getline(cin,apellidos);
    setApellidos(apellidos);
    int edad;
    cout<<"EDAD: ";
    cin>>edad;
    setEdad(edad);
    int dia;
    int mes;
    int anio;
    cout<<"===FECHA NACIMIENTO=== "<<endl;
    cout<<endl;
    cout<<"DIA: ";
    cin>>dia;
    cout<<endl;
    cout<<"MES: ";
    cin>>mes;
    cout<<endl;
    cout<<"ANIO: ";
    cin>>anio;
    cout<<endl;
    setFechaNac(Fecha(dia,mes,anio));
    string numTelefono;
    cout<<"NUMERO DE TELEFONO: " ;
    getline(cin,numTelefono);
    setNumTelefono(numTelefono);
    string direccion;
    cout<<"DIRECCION: ";
    getline(cin,direccion);
    setDireccion(direccion);
    string mail;
    cout<<"MAIL: ";
    getline(cin,mail);
    setMail(mail);
    cout<<endl;
    bool estado=true ;
    setEstado(estado);
    cout<< "============DATOS INSTITUCIONALES ======="<<endl;
    cout<<endl;
    cout<<"MATERIA"<<endl;
    cin>> _idMateria<<endl;
    cout<<"AÑO DE INGRESO A LA INSITUCION"<<endl;
    cin>>_anioIngreso<<endl;
    cout<< "NUMERO DE CBU(11 digitos)"<< endl;
    cin>>_cbu;
    int contador=0;
    for(int x=0; _cbu[x]; x++){

        contador++;
    }
    if (contador!=11){

    cout<< "CBU incorrecto, vuelva a escribirlo"<<endl;
    }


}
    cout<<"MONTO DE SUELDO"<<endl;
    cin>>_sueldo;



  }


  void profesores::mostrar(){

    cout<<"-----DATOS PERSONALES-----"<<endl;
    cout<<"LEGAJO: "<<getLegajoProfedor()<<endl;
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
    cout<<"MATERIA: "<<getIdMateria()<<endl;
    cout<<"AÑO DE INGRESO A LA INSITUCION: "<<getAnioIngreso()<<endl;
    cout<< "NUMERO DE CBU: "<<getCbu()<<endl;
    cout<<"MONTO DE SUELDO: "<<getSueldo()<<endl;




































  }




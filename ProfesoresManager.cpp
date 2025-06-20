#include "ProfesoresManager.h"
#include<iostream>
#include<cstring>
#include <string>

using namespace std;
int ProfesoresManager::ValidarDNI(){
    Profesores prof;
    int dni;

    cout<<"INGRESAR DNI: ";
    cin>>dni;
            for(int i=0; i< _archiProf.CantidadRegistros();i++){
                    prof = _archiProf.leerProfesor(i) ;
            if(prof.getNumeroDocumento()== dni){
                return 0;
                break;
            }
            }
        return dni;
}
int ProfesoresManager::IncrementarLegajo(){
    int legajo;
    legajo = _archiProf.CantidadRegistros()+1;
    return legajo;
}

int ProfesoresManager::CargarProfesor(){
    Profesores reg;
    MateriaArchivo archiMat;
    int tipoDni;
    int  numeroDni;
    cout<<"INGRESAR TIPO DE DNI(1-DNI, 2-OTRO): ";
    cin>>tipoDni;
    reg.setTipoDocumento(tipoDni);
    numeroDni = ValidarDNI();
    if(numeroDni!= 0){
        string nombres,apellidos,numTelefono,direccion,mail;
        int edad,legajo;
        int dia, mes,anio;
        cout<<"DNI:"<<numeroDni;
        reg.setNumDocumento(numeroDni);
        cout<<endl;
        cout<<"LEGAJO: ";
        legajo = IncrementarLegajo();
        reg.setLegajoProfesor(legajo);
        cout<<legajo<<endl;
        cout<<"NOMBRES: ";
        cin.clear();
        fflush(stdin);
        getline(cin,nombres);
        reg.setNombres(nombres);
        fflush(stdin);
        cout<<"APELLIDOS: ";
        getline(cin,apellidos);
        reg.setApellidos(apellidos);
        fflush(stdin);
        cout<<"EDAD: ";
        cin>>edad;
        cout<<endl;
        reg.setEdad(edad);
        cout<<"FECHA DE NACIMIENTO "<<endl;
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
        reg.setFechaNac(Fecha(dia,mes,anio));
        cout<<"NUMERO DE TELEFONO: ";
        cin.ignore();
        getline(cin,numTelefono,'\n');
        reg.setNumTelefono(numTelefono);
        fflush(stdin);
        cout<<"DIRECCION: ";
        cin.ignore();
        getline(cin,direccion,'\n');
        reg.setDireccion(direccion);
        fflush(stdin);
        cout<<"MAIL: ";
        getline(cin, mail,'\n');
        reg.setMail(mail);
        reg.setEstado(true);

        bool nivel;
        int anioIngreso;
        char cbu[22];
        cout<<"ANIO DE INGRESO AL INSTITUTO: ";
        cin>>anioIngreso;
        reg.setAnioIngreso(anioIngreso);
        cout<<"CBU: ";
        cin>>cbu;
        reg.setCbu(cbu);
        float sueldo;
        cout<<"SUELDO(en pesos): $";
        cin>>sueldo;
        reg.setSueldo(sueldo);
        char nombre [30];
        cout<<"--- ASIGNACION DE MATERIA ---"<<endl;
        cout<<"NOMBRE DE MATERIA A DAR: ";
        cin>>nombre;
        cout<<"NIVEL ACADEMICO(0-Primaria, 1-Secundaria): ";
        cin>>nivel;
        archiMat.listarMateriasXNombre(nombre,nivel);
        cout<<endl;
        int idMateria;
        int i=1;
        cout<<"CATIDAD DE MATERIAS QUE VA A DAR: ";
        cout<<i<<endl;
        cout<<"INGRESAR ID DE MATERIA a SELECCIONAR: ";
        cin>>idMateria;
        reg.setIdMateria(idMateria,i);

        bool ok;
        ok =_archiProf.agregarProfesor(reg);
        if(ok){
                cout<<endl;
            cout<<"SE GUARDO CORRECTAMENTE"<<endl;
        }else{
            cout<<endl;
            cout<<"NO SE PUDO GUARDAR"<<endl;
        }
    }
}



void ProfesoresManager::buscarProfesorPorLegajo(int legajo){
    Profesores reg;
    int posicion;
    posicion = _archiProf.buscarProfesor(legajo);
    reg = _archiProf.leerProfesor(posicion);
    reg.mostrar();
}

void ProfesoresManager::buscarProfesorPorDNI(int dni){
    Profesores reg;
    int posicion;
    posicion = _archiProf.buscarProfesor(dni);
    reg = _archiProf.leerProfesor(posicion);
    reg.mostrar();
}
void ProfesoresManager::buscarProfesorPorApellido(const char *apellido){
    Profesores reg;
    int posicion;
    for(int i = 0;i < _archiProf.CantidadRegistros();i++){
        posicion = _archiProf.buscarProfesor(apellido);
        reg = _archiProf.leerProfesor(posicion);
        if(reg.getEstado()== true){
                reg.mostrar();
        }
    }
}

void ProfesoresManager::ListarProfesoresActivos(){
    Profesores reg;

    cout<<"------PROFESORES ACTIVOS-------"<<endl;
    _archiProf.listarRegistros();
    cout<<endl;
}

bool ProfesoresManager::modificarCantMaterias(int legajo){
    Profesores reg;

    for(int i=0; i<_archiProf.CantidadRegistros();i++){
            reg = _archiProf.leerProfesor(i);
            if(reg.getLegajoProfesor()==legajo){
                    bool opcion;
                cout<<"DESEA AGREGAR O SACAR UNA MATERIA?(1-Agregar, 0-Eliminar)";
                cin>>opcion;
                 if (opcion) {
                int idMateria, pos;
                cout << "Ingrese ID de la materia a agregar: ";
                cin >> idMateria;

                pos = reg.getCantidad() + 1;
                reg.setIdMateria(idMateria, pos);
                cout << "Materia agregada correctamente." << endl;
            } else {
                int indice;
                reg.mostrarIdMaterias();
                cout<<"=================="<<endl;
                cout << "Ingrese el número de materia a eliminar (1 a " << reg.getCantidad() << "): ";
                cin >> indice;

                if (indice > 0 && indice <= reg.getCantidad()) {
                    for (int j=indice - 1; j < reg.getCantidad() - 1; j++) {
                        reg.setIdMateria(reg.getIdMateria(j + 2), j + 1);
                    }
                    reg.setCantidad(reg.getCantidad() - 1);
                    cout << "Materia eliminada correctamente." << endl;
                } else {
                    cout << "Índice inválido." << endl;
                    return false;
                }
            }
            bool ok;

            ok=_archiProf.modificarProfesor(reg, i);
            return ok;
        }
    }
    cout << "Profesor no encontrado." << endl;
    return false;
}

void ProfesoresManager::modificarSueldo(int legajo){
    Profesores reg;
    for(int i=0;i<_archiProf.CantidadRegistros();i++){
        reg = _archiProf.leerProfesor(i);
        if(reg.getLegajoProfesor()==legajo){
            float nuevoSueldo;
            cout<<"INGRESE EL NUEVO SUELDO DEL PROFESOR: ";
            cin>>nuevoSueldo;
            reg.setSueldo(nuevoSueldo);
            bool ok;
             ok = _archiProf.modificarProfesor(reg,i);
             if(ok){
                reg.mostrar();
                 cout<<"SE MODIFICO CORRECTAMENTE" <<endl;
             }else {
                 cout<<"NO SE PUDO MODIFICAR"<<endl;
             }
        }
    }

}

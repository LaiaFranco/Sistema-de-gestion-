#include "InscripcionesManager.h"
#include <iostream>

using namespace std;
int InscripcionesManager::IncrementarInscripcion(){
    int idInscripcion;
    idInscripcion = archivoIns.CantidadRegistros()+1;
    return idInscripcion;
}
void InscripcionesManager::buscarCursoDisponible(bool nivelEducativo,int anio){
    CursoArchivo archiCur;
    archiCur.buscarCursosDisponibles(nivelEducativo,anio);
}

void InscripcionesManager::CargarInscripcion(){
    AlumnoManager aluMan;
    Alumno alu;
    inscripcion ins;
    int nivel;
    int anio;
    int idCurso;
    cout<<"PASO 1."<<endl;
    cout<<"======= DATOS DEL ALUMNO =========="<<endl;
    alu = aluMan.CargarAlumno();
    int leg = alu.getLegajoAlumno();
    if(leg!= 0){
    cout << "LEGAJO DEL ALUMNO CARGADO: " << alu.getLegajoAlumno() << endl;
    ins.setlegajoAlumno(alu.getLegajoAlumno());
    cout<<endl;
    cout<<"PASO 2."<<endl;
    cout<<"======= DATOS SOBRE ASIGNACION DE CURSO ===="<<endl;
    cout<<"NIVEL EDUCATIVO(0-primaria, 1-secundaria): ";
    nivel=alu.getNivelAcademico();
    cout<<nivel;
    cout<<endl;
    cout<<"ANIO DE PREFERENCIA(1-primero,2-segundo,etc): ";
    anio= alu.getAnioAcademico();
    cout<<anio;
    cout<<endl;
    cout<<"LOS CURSOS DISPONIBLES SON: "<<endl;
    CursoArchivo archiCur;
    archiCur.buscarCursosDisponibles(nivel,anio);
    cout<<endl;
    cout<<"INGRESE ID DE CURSO A SELECCIONAR: ";
    cin>>idCurso;
    ins.setIdCurso(idCurso);
    cout<<"PASO 3."<<endl;
    cout<<"====== MATRICULACION ==============="<<endl;
    int idInscripcion;
    idInscripcion = IncrementarInscripcion();
    ins.setIdInscripcion(idInscripcion);
    ins.setNivel(nivel);
    ins.setANio(anio);
    cout<<"ID DE INSCRIPCION: #";
    cout<<idInscripcion<<endl;
    int dia;
    int mes;
    int anioFecha;
    cout<<"===FECHA INSCRIPCION=== "<<endl;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anioFecha;
    ins.setfechaInscripcion(Fecha(dia,mes,anioFecha));
    bool pago;
    float importe;
    cout<<"IMPORTE DE MATRICULA: $";
    cin>>importe;
    ins.setimporteMatricula(importe);
    cout<<"MATRICULA PAGA (0-SI,1-NO): ";
    cin>>pago;
    ins.setadeudaMatricula(pago);

    cout<<"ESTADO DE INSCRIPCION: ";
    bool estado;
    if(pago== 0){
        cout<<"ACTIVO"<<endl;
        estado = 1;
    }else{
        cout<<"INACTIVO"<<endl;
        estado = 0;
    }
    ins.setEstado(estado);
    if(archivoIns.agregarInscripcion(ins)){
        cout<<"SE GUARDO CORRECTAMENTE LA INSCRIPCION" <<endl;
    }else {
    cout<<"HUBO UN ERROR, NO SE PUDO GUARDAR"<<endl;
    }
    }
}

void InscripcionesManager::ReinscribirAlumno(){
   ArchivoAlumno archiAlu;
   Alumno alu;
    cout<<"====== REINSCRIPCION DE ALUMNO ======="<<endl;
    int dni;
    cout<<"INGRESE DNI DEL ALUMNO(sin puntos): ";
    cin>>dni; cout<<endl;
    int legajo;
    alu = archiAlu.buscarAlumnoXDni(dni);
    legajo = alu.getLegajoAlumno();
    if(alu.getLegajoAlumno()==0){
        cout<<"ALUMNO NO ENCONTRADO"<<endl;
        return;
    }else{
        cout<<"ALUMNO CON LEGAJO: "<<alu.getLegajoAlumno(); cout<<endl;
        cout<<"NOMBRE Y APELLIDO: "<<alu.getNombres()<<" "<<alu.getApellidos(); cout<<endl;
        int nuevoAnio;
        bool nivelEducativo;
        cout<<"INGRESE NIVEL EDUCATIVO(0-Primaria,1-Secundaria): ";
        cin>>nivelEducativo; cout<<endl;
        cout<<"INGRESE ANIO A REINSCRIBIR(1-PRIMERO, 2-SEGUNDO,ETC..)" ;
        cin>>nuevoAnio; cout<<endl;
        if(alu.getAnioAcademico()== nuevoAnio){
            cout<<"ALUMNO REPITENTE" <<endl;
            alu.setAnioAcademico(nuevoAnio);
        }
        alu.setNivelAcademico(nivelEducativo);
        alu.setAnioAcademico(nuevoAnio);
        int edad;
        cout<<"EDAD DEL ALUMNO: ";
        cin>>edad; cout<<endl;
        alu.setEdad(edad);

        int posicion;
        posicion = archiAlu.buscarAlumno(dni);
        if(archiAlu.modificarAlumno(alu,posicion)){
            cout<<"SE MODIFICARON LOS DATOS DEL ALUMNO CORRECTAMENTE"<<endl;
        }else{
            cout<<"HUBO UN ERROR EN LA MODIFICACION"<<endl;
        }

        inscripcion ins;
        ins.setlegajoAlumno(legajo);

        cout<<"CURSOS DISPONIBLES: "<<endl;
        buscarCursoDisponible(nivelEducativo,nuevoAnio);
        cout<<endl;
        int idCurso;
        cout<<"SELECCIONE ID DE CURSO: ";
        cin>>idCurso;
        ins.setIdCurso(idCurso);

        int idIns;
        bool okBaja;
        for(int i=0; i<archivoIns.CantidadRegistros();i++){
              inscripcion insTemp  = archivoIns.leerInscripcion(i);
              if(insTemp.getlegajoAlumno()== alu.getLegajoAlumno() && insTemp.getEstado()==true){
               int id= insTemp.getIdInscripcion();
               okBaja = archivoIns.bajaLogica(id);
               if(okBaja){
                cout<<"LA INSCRIPCION ANTERIOR SE DIO DE BAJA CORRECTAMENTE"<<endl;
               }else {
                   cout<<"NO SE PUDO DAR DE BAJA LA INSCRICION ANTERIOR"<<endl;
               }
              }
        }

        cout<<"ID DE INSCRIPCION: # ";
        idIns = IncrementarInscripcion();
        cout<<idIns<<endl;
        ins.setIdInscripcion(idIns);

        int dia,mes,anio;
        cout<<"==== FECHA DE REINSCRIPCION ==== "<<endl;
        cout<<"DIA: ";
        cin>>dia; cout<<endl;
        cout<<"MES: ";
        cin>>mes; cout<<endl;
        cout<<"ANIO: ";
        cin>>anio; cout<<endl;
        ins.setfechaInscripcion(Fecha(dia,mes,anio));
        float importe;
        cout<<"IMPORTE DE MATRICULA: ";
        cin>>importe; cout<<endl;
        ins.setimporteMatricula(importe);

        bool adeuda;
        cout<<"ADEUDA MATRICULA(0-No o 1-SI): ";
        cin>>adeuda; cout<<endl;
        ins.setadeudaMatricula(adeuda);

        bool estado;
        if(adeuda == 0){
        cout<<"ESTADO DE INSCRIPCION: " <<"ACTIVO"<<endl;
        estado = true;
        }else {
        cout<<"ESTADO DE INSCRIPCION: "<<"INACTIVO (hasta abonar matricula)" <<endl;
        estado = false;
        }
        ins.setEstado(estado);
        bool guardo;
        guardo = archivoIns.agregarInscripcion(ins);
        if(guardo == true ){
            cout<<"SE GUARDO CORRECTAMENTE LA REINCRIPCION"<<endl;
        }else{
            cout<<"NO SE GUARDO LA REINSCRIPCION" <<endl;
        }

        system ("cls");

        ///mostrar reinscripcion
        cout<<"=== DATOS DE REINSCRIPCION ====" <<endl;
        alu.Mostrar();
        cout<<endl;
        ins.Mostrar();
    }
}

void InscripcionesManager::EstadoInscipcion(){
    inscripcion ins;
    Alumno alu;
    ArchivoAlumno archiAlu;

    int opcion;
    cout<<"=== ESTADO DE INSCRIPCION ==="<<endl;
    cout<<"DESEA VER: "<<endl;
    cout<<"1.INSCRIPCIONES DE ESTADO ACTIVO"<<endl;
    cout<<"2.INSCRIPCIONES DE ESTADO INACTIVO"<<endl;
    cout<<"3.INCRIPCIONES DE AMNOS ESTADOS"<<endl;
    cout<<endl;
    cout<<"OPCION: ";
    cin>>opcion;
    cout<<endl;
    if(opcion>=1 && opcion<=3){
        switch(opcion){
        case 1:{
            system("cls");
            int dni;
            int legajo;
            cout<<"INGRESE DNI DEL ALUMNO(sin puntos): ";
            cin>>dni; cout<<endl;
            cout<<"==== INSCRIPCIONES ACTIVAS PARA ESE DNI ==== " <<endl;
            for(int i=0; i<archiAlu.CantidadRegistros();i++){
                alu = archiAlu.leerAlumno(i);
                if(alu.getNumeroDocumento()== dni){
                    cout<<"ALUMNO: "<<alu.getNombres()<<" "<<alu.getApellidos()<<endl;
                    legajo = alu.getLegajoAlumno();
                    cout<<"LEGAJO: "<<alu.getLegajoAlumno()<<endl;

                }
            }

            for(int i=0; i<archivoIns.CantidadRegistros();i++){
                    ins = archivoIns.leerInscripcion(i);
                if(ins.getlegajoAlumno()==legajo && ins.getEstado()==true){
                    ins.Mostrar();
                }
            }

            break;
        }
        case 2:{
            int dni;
            int legajo;
            cout<<"INGRESE DNI DEL ALUMNO(sin puntos): "<<endl;
            cin>>dni; cout<<endl;
            cout<<"==== INSCRIPCIONES ACTIVAS PARA ESE DNI ==== " <<endl;
            for(int i=0; i<archiAlu.CantidadRegistros();i++){
                alu = archiAlu.leerAlumno(i);
                if(alu.getNumeroDocumento()== dni){
                    cout<<"ALUMNO: "<<alu.getNombres()<<" "<<alu.getApellidos()<<endl;
                    legajo = alu.getLegajoAlumno();
                    cout<<"LEGAJO: "<<alu.getLegajoAlumno()<<endl;
                }
            }

            for(int i=0; i<archivoIns.CantidadRegistros();i++){
                    ins = archivoIns.leerInscripcion(i);
                if(ins.getlegajoAlumno()==legajo && ins.getEstado()==false){
                    ins.Mostrar();
                }
            }
            bool op;
            cout<<"==========================================================="<<endl;
            cout<<"DESEA MODIFICAR ESTADO POR FALTA DE PAGO?(0-No, 1-Si) :";
            cin>>op;
            int id;
            if(op == 1){
            cout<<"ID DE INSCRIPCION: ";
            cin>>id; cout<<endl;
            for(int i=0; i<archivoIns.CantidadRegistros();i++){
                    ins = archivoIns.leerInscripcion(i);
                if(ins.getlegajoAlumno()==legajo){
                    ins.Mostrar();
                }
            }
            }

            break;
        }

        case 3:{
             int dni;
            int legajo;
            cout<<"INGRESE DNI DEL ALUMNO(sin puntos): "<<endl;
            cin>>dni; cout<<endl;
            cout<<"==== INSCRIPCIONES ACTIVAS PARA ESE DNI ==== " <<endl;
            for(int i=0; i<archiAlu.CantidadRegistros();i++){
                alu = archiAlu.leerAlumno(i);
                if(alu.getNumeroDocumento()== dni){
                    cout<<"ALUMNO: "<<alu.getNombres()<<" "<<alu.getApellidos()<<endl;
                    legajo = alu.getLegajoAlumno();
                    cout<<"LEGAJO: "<<alu.getLegajoAlumno()<<endl;
                }
                for(int i=0; i<archivoIns.CantidadRegistros();i++){
                if(ins.getlegajoAlumno()==legajo){
                    ins.Mostrar();
                }
            }


            break;
        }
        }
    }
    }
}
void InscripcionesManager::emisionCertificadoParcial(Alumno &reg){
    int VecANio[6] = {1,2,3,4,5,6,};
    bool Vec[6]={false};
    int legajo;
    bool nivel;
    inscripcion ins;

    legajo = reg.getLegajoAlumno();
    nivel = reg.getNivelAcademico();

    for(int i=0; i<archivoIns.CantidadRegistros();i++){
            ins = archivoIns.leerInscripcion(i);
            if(ins.getlegajoAlumno()==legajo && ins.getNivel()==nivel){
                 int anio = ins.getANio();
                if (anio >= 1 && anio <= 6) {
                    Vec[anio - 1] = true;
            }
            }
    }

    for (int i = 0; i < 6; i++) {
    cout << "Vec[" << i << "] = " << Vec[i] << endl;
}

    cout<<"CERTIFICADO DE ESTDIOS PARCIALES"<<endl<<endl;
    cout<<"La Dirección de IGB, Instituto Gneral Belgrano, certifica que: "<<endl;
    cout<<"El/La alumno/a"<< reg.getNombres()<<" "<<reg.getApellidos()<<"DNI " <<reg.getNumeroDocumento()<<" ha aprobado satisfactoriamente los siguientes cursos en este establecimiento:"<<endl;
    for(int i=0;i<6;i++){
        if(Vec[i]==true){
            cout<<i+1<<".º anio: COMPLETO ";
        }
    }
    cout<<endl<<endl;
    cout<<"Del nivel: ";
    if(nivel){
        cout<<"SECUNDARIO"<<endl;
    }else {
        cout<<"PRIMARIO"<<endl;
    }

}

void InscripcionesManager::emisionCertificadoFinal(Alumno &reg){
    bool Vec[6]={false};
    int legajo;
    bool nivel;
    int anioRec;
    inscripcion ins;

    legajo = reg.getLegajoAlumno();
    nivel = reg.getNivelAcademico();

    for(int i=0; i<archivoIns.CantidadRegistros();i++){
            ins = archivoIns.leerInscripcion(i);
            if(ins.getlegajoAlumno()==legajo && ins.getNivel()==nivel){
                 int anio = ins.getANio();
                if (anio >= 1 && anio <= 6) {
                    Vec[anio - 1] = true;
            }
            if(ins.getANio()==6){
                anioRec= ins.getfechaInscripcion().getAnio();
            }
            }
    }

    int cont=0;
    for(int i=0;i<6;i++){
        if(Vec[i]==true){
            cont++;
        }
    }
    if(cont==6){
        cout<<"CERTIFICADO FINALIZACION DE ESTUDIOS"<<endl<<endl;
        cout<<"La Direccion del Instituto General Belgrano (IGB) certifica que: "<<endl;
        cout<<"El/La alumno/a"<< reg.getNombres()<<" "<<reg.getApellidos()<<", DNI " <<reg.getNumeroDocumento()<<"ha finalizado sus estudios correspondientes al Nivel";
        if(reg.getNivelAcademico()){
            cout<<" Secundario";
        }else {
            cout<<"Primario";
        }
        cout<<"conforme al diseño curricular vigente, durante el ciclo lectivo";
        cout<<anioRec +1<<endl;

    cout<<endl;

    cout<<endl<<endl;
    cout<<"FIRMA Y SELLO"<<endl;
    }
}

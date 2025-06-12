#include "InscripcionesManager.h"
#include <iostream>

using namespace std;
int InscripcionesManager::IncrementarInscripcion(){
    int idInscripcion;
    idInscripcion = archivoIns.CantidadRegistros()+1;
    return idInscripcion;
}
void InscripcionesManager::buscarCursoDisponible(int anio,bool nivelEducativo){
    Curso curso;
    CursoArchivo archiCur;
    for(int i=0;i<archiCur.CantidadRegistros();i++){
        curso = archiCur.leer(i);
    if(curso.getNumeroCurso()== anio && curso.getNivelEducativo()== nivelEducativo && curso.getEstado()){
        if(curso.getCantidadMaximaAlumnos() > curso.getCantiadaAlumnosInscriptos()){
            cout<<"ID DE CURSO: "<<curso.getIdCurso()<<endl;
            cout<<"NUMERO DE CURSO: "<<curso.getNumeroCurso()<<endl;
            cout<<"AULA: "<<curso.getNumeroAula()<<endl;
            cout<<"TURNO: "<<curso.getTurno()<<endl;
            cout<<"=================="<<endl;
            cout<<endl;
        }
    }
    }
}

void InscripcionesManager::CargarInscripcion(){
    AlumnoManager aluMan;
    inscripcion ins;

    int anio;
    bool nivel;
    int idCurso;
    cout<<"PASO 1."<<endl;
    cout<<"======= DATOS DEL ALUMNO =========="<<endl;
    int legajo = aluMan.CargarAlumno();
    ins.setlegajoAlumno(legajo);
    cout<<endl;
    cout<<"PASO 2."<<endl;
    cout<<"======= DATOS SOBRE ASIGNACION DE CURSO ===="<<endl;
    cout<<"INGRESE ANIO DE PREFERENCIA(1-primero,2-segundo,etc): ";
    cin>>anio;
    cout<<"INGRESE NIVEL EDUCATIVO(0-primaria, 1-secundaria): ";
    cin>>nivel;
    cout<<"LOS CURSOS DISPONIBLES SON: ";
    buscarCursoDisponible(anio,nivel);
    cout<<"INGRESE ID DE CURSO A SELECCIONAR: ";
    cin>>idCurso;
    ins.setIdCurso(idCurso);
    cout<<"PASO 3."<<endl;
    cout<<"====== MATRICULACION ==============="<<endl;
    cout<<"IMPORTE DE MATRICULA: $50.000";
    ins.setimporteMatricula(50000);
    bool pago;
    cout<<"MATRICULA PAGA (1-SI,0-NO): ";
    cin>>pago;
    ins.setadeudaMatricula(pago);
    cout<<"ESTADO DE INSCRIPCION: ";
    bool estado;
    if(pago== 1){
        cout<<"ACTIVO"<<endl;
        estado = true;
    }else{
        cout<<"INACTIVO"<<endl;
        estado = false;
    }
    ins.setEstado(estado);
    int dia;
    int mes;
    int anioFecha;
    cout<<"FECHA ACTUAL "<<endl;
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anioFecha;
    ins.setfechaInscripcion(Fecha(dia,mes,anioFecha));
    ins.setIdInscripcion(IncrementarInscripcion());
    archivoIns.agregarInscripcion(ins);
}

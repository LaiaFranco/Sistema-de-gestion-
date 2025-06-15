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
    cout<<endl;
    cout<<"LOS CURSOS DISPONIBLES SON: ";
    buscarCursoDisponible(anio,nivel);
    cout<<"INGRESE ID DE CURSO A SELECCIONAR: ";
    cin>>idCurso;
    ins.setIdCurso(idCurso);
    cout<<"PASO 3."<<endl;
    cout<<"====== MATRICULACION ==============="<<endl;
    int idInscripcion;
    idInscripcion = IncrementarInscripcion();
    ins.setIdInscripcion(idInscripcion);
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
    if(ins.getfechaInscripcion().getAnio()==2025||ins.getfechaInscripcion().getAnio()==2024){
    cout<<"IMPORTE DE MATRICULA: $50.000"<<endl;
    ins.setimporteMatricula(50000);
    cout<<"MATRICULA PAGA (1-SI,0-NO): ";
    cin>>pago;
    ins.setadeudaMatricula(pago);
    }
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
    if(archivoIns.agregarInscripcion(ins)){
        cout<<"SE GUARDO CORRECTAMENTE LA INSCRIPCION" <<endl;
    }else {
    cout<<"HUBO UN ERROR, NO SE PUDO GUARDAR"<<endl;
    }
    }
}

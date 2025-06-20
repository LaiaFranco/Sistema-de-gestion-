#include <cstdio>
#include <cstring>
#include "CursoArchivo.h"

using namespace std;
CursoArchivo::CursoArchivo(const char* nombre) {
    strncpy(_nombreArchivo, nombre, 29);
    _nombreArchivo[29] = '\0';
}

int CursoArchivo::IncrementoID(){
    int id;
    id = CantidadRegistros() +1;
    return id;
}
void CursoArchivo::CargarCurso(){
    Curso cur;
    int id, numeroCurso,  numAula;
    char descripcion[100];
    bool turno, nivel;
    int cantMax;
    bool estado;
    cout<<"----- DATOS PARA CURSO -----"<<endl;
    cout<<"ID: #";
    id = IncrementoID();
    cout<<id<<endl;
    cur.setIdCursoo(id);
    cout<<"NUMERO DE CURSO(DEL 1 AL 6): ";
    cin>>numeroCurso;
    cur.setNumeroCurso(numeroCurso);
    cout<<"NUMERO DE AULA(del 1 al 20): N ";
    cin>>numAula;
    cur.setNumeroAula(numAula);
    cout<<"NIVEL EDUCATICO(0-Primaria,1-Secundaria): ";
    cin>>nivel;
    cur.setNivelEducativo(nivel);
    cout<<"DESCRIPCION: ";
    cin.ignore();
    cin.getline(descripcion,100,'\n');
    cur.setDescripcion(descripcion);
    cout<<"TURNO(0-MANIANA, 1-TARDE): ";
    cin>>turno;
    cur.setTurno(turno);
    cout<<"CANTIDAD MAXIMA(hasta 30 alumnos por curso): ";
    cin>>cantMax;
    cur.setCantidadMaximaAlumnos(cantMax);
    cout<<endl;
    cout<<"ESTADO: ACTIVO"<<endl;
    estado = true;
    cur.setEstado(estado);

    bool ok;
    ok = guardar(cur);
    if(ok){
        cout<<endl;
        cout<<"<< EL CURSO DE GUARDO CORRECTAMENTE >>"<<endl;
    }else{
        cout<<"ERROR, NO SE PUDO GUARDAR"<<endl;
    }

}

bool CursoArchivo::guardar(Curso reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Curso), 1, p);
    fclose(p);
    return ok;
}

Curso CursoArchivo::leer(int pos){
    Curso reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Curso), SEEK_SET);
    fread(&reg, sizeof(Curso), 1, p);
    fclose(p);
    return reg;
}

int CursoArchivo::CantidadRegistros() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Curso);
}

int CursoArchivo::buscarPorIdCurso(int id){
    Curso reg;
    FILE * p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(Curso), 1, p) == 1) {
        if (reg.getIdCurso() == id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

void CursoArchivo::buscarCursosDisponibles(bool nivel, int anio){
    Curso reg;
    FILE * p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;

    bool hayCurso;
    while (fread(&reg, sizeof(Curso), 1, p) == 1) {
        if (reg.getNivelEducativo() == nivel && reg.getNumeroCurso()== anio && reg.getEstado()== true){
            reg.Mostrar();
            hayCurso = true;
        }
    }
     fclose(p);
    if(!hayCurso){
        cout<<"NO HAY CURSOS DISPONIBLES PARA ESE ANIO Y NIVEL"<<endl;
    }
}
bool CursoArchivo::modificar(const Curso &reg, int pos) {
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Curso), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Curso), 1, p);
    fclose(p);
    return ok;
}

bool CursoArchivo::bajaLogica(int id){
    Curso reg;
    int pos = buscarPorIdCurso(id);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg = leer(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return modificar(reg,pos);
}

bool CursoArchivo::altaLogica(int id){
    Curso reg;
    int pos = buscarPorIdCurso(id);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg = leer(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return modificar(reg,pos);
}

void CursoArchivo::ModificarEstado(bool nivel,int numAula, int numCurso){
    Curso reg;
    for(int i=0;i<CantidadRegistros();i++){
        reg = leer(i);
        if(reg.getNivelEducativo()==nivel && reg.getNumeroAula()== numAula && reg.getNumeroCurso()==numCurso){
           cout<<"== CURSO == "<<endl;
            reg.Mostrar();
            cout<<endl;
            bool mod;
            cout<<"DESEA MODIFICAR EL ESTADO? (1-Si,0-No): "<<endl;
            cin>>mod;
            if(mod){
                    bool estado;
                cout<<"ESTADO(1-Activo, 0-Inactivo): ";
                cin>>estado;
                reg.setEstado(estado);
                if(modificar(reg,i)){
                   cout<<endl;
                    cout<<"SE MODIFICO CORRECTAMENTE"<<endl;
                    cout<<">>|| MODIFICACION ||<<"<<endl;
                    reg.Mostrar();
                }else {
                    cout<<"NO SE PUDO MODIFICAR"<<endl;
                }
            }
        }
    }
}

void CursoArchivo::ModificarCantAlumnos(bool nivel,int numAula, int numCurso){
     Curso reg;
    for(int i=0;i<CantidadRegistros();i++){
        reg = leer(i);
        if(reg.getNivelEducativo()==nivel && reg.getNumeroAula()== numAula && reg.getNumeroCurso()==numCurso){
           cout<<"== CURSO == "<<endl;
            reg.Mostrar();
            cout<<endl;
            bool  mod;
            cout<<"DESEA MODIFICAR LA CANTIDAD MAXIMA DE ALUMNOS? (1-SI,0-NO): "<<endl;
            cin>>mod;
            if(mod){
                    int cantidad;
                cout<<"CANTIDAD MAXIMA(maximo permitido es 30): ";
                cin>>cantidad;
                reg.setCantidadMaximaAlumnos(cantidad);
                if(modificar(reg,i)){
                   cout<<endl;
                    cout<<"SE MODIFICO CORRECTAMENTE"<<endl;
                    cout<<">>|| MODIFICACION ||<<"<<endl;
                    reg.Mostrar();
                }else {
                    cout<<"NO SE PUDO MODIFICAR"<<endl;
                }
            }
        }
    }
}

#include "MateriaArchivo.h"
#include <iostream>

using namespace std;
MateriaArchivo::MateriaArchivo(){
    const char *nombre = "Materias.dat";
    strcpy(_nombreArchivo,nombre);
    _nombreArchivo[29] = '\0';
}
void MateriaArchivo::CargarMateria(){
    Materia mat;
    cout<<"==== CARGA DE MATERIA ===="<<endl;
    char nombre [30];
    cout << "NOMBRE DE MATERIA: ";
    cin.ignore();
    cin.getline(nombre,30,'\n');
    mat.setNombre(nombre);
    bool nivel;
    cout<<"NIVEL EDUCATIVO(0-Primaria, 1-Secundaria): ";
    cin>>nivel;
    mat.setNivelEducativoMateria(nivel);

    int anio;
    cout<<"ANIO DE LA MATERIA(1-primero, 2-segundo,3-tercero,etc): ";
    cin>>anio;
    mat.setAnioMateria(anio);

    int idMateria;
    idMateria = GeneradorDeCodigo();
    cout << "ID DE MATERIA: #"<<idMateria<<endl;
    mat.setCodigo(idMateria);

    int cargaHoraria;
    cout << "CARGA HORARIA(semanal): ";
    cin >> cargaHoraria;
    mat.setCargaHoraria(cargaHoraria);

    bool estado;
    cout<<"ESTADO DE MATERIA(0-Inactiva,1-Activa): ";
    cin>>estado; cout<<endl;
    mat.setEstado(estado);

   bool ok;
   ok= guardar(mat);
    if(ok == true){
        cout<<"LA MATERIA SE CARGO CORRECTAMENTE"<<endl;
    }else{
        cout<<"HUBO UN ERROR, NO SE PUDO CARGAR LA MATERIA"<<endl;
    }

}


int MateriaArchivo::GeneradorDeCodigo(){
    int id;
    id = contar() +1;
    return id;
}
bool MateriaArchivo::guardar(const Materia &reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if(p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Materia), 1, p);
    fclose(p);
    return ok;
}

int MateriaArchivo::contar() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if(p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Materia);
    fclose(p);
    return cant;
}

Materia MateriaArchivo::leer(int pos) {
    Materia reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if(p == nullptr) return reg;
    fseek(p, pos * sizeof(Materia), SEEK_SET);
    fread(&reg, sizeof(Materia), 1, p);
    fclose(p);
    return reg;
}
void MateriaArchivo::ModificarEstado(const char *nombre, bool nivel, int anio){
    Materia reg;
    bool ok;
    for(int i=0;i<contar();i++){
            reg=leer(i);
    if(strcmp(reg.getNombre(),nombre)==0 && reg.getNivelEducativoMateria()==nivel && reg.getAnioMateria()==anio){
        reg.Mostrar();
        cout<<"DESEA MODIFICAR EL ESTADO(0-No,1-Si): ";
        cin>>ok;
        if(ok==1){
                bool estado;
            cout<<"ESTADO(0-Inactivo, 1-Activo):";
            cin>>estado;
            bool mod;
            reg.setEstado(estado);
            mod = modificarMateria(reg,i);
            if(mod){
                    cout<<endl;
                    cout<<"SE MODIFICO CORRECTAMENTE"<<endl;
                    cout<<">>|| MODIFICACION ||<<"<<endl;
                    reg.Mostrar();
            }else{
                cout<<"NO SE PUDO MODIFICAR"<<endl;
            }
        }
    }
    }
}

void MateriaArchivo::ModificarCargaHoraria(const char *nombre, bool nivel, int anio){
    Materia reg;
    bool ok;
    for(int i=0;i<contar();i++){
            reg=leer(i);
    if(strcmp(reg.getNombre(),nombre)==0 && reg.getNivelEducativoMateria()==nivel && reg.getAnioMateria()==anio){
        cout<<"====DATOS MATERIA===="<<endl;
        reg.Mostrar();
        cout<<"DESEA MODIFICAR LA CARGA HORARIA(0-No,1-Si): ";
        cin>>ok;
        if(ok==1){
            int cargaHoararia;
            cout<<"CARGA HORARIA NUEVA:";
            cin>>cargaHoararia;
            bool mod;
            reg.setCargaHoraria(cargaHoararia);
            mod = modificarMateria(reg,i);
            if(mod){
                    cout<<endl;
                    cout<<"SE MODIFICO CORRECTAMENTE"<<endl;
                    cout<<">>|| MODIFICACION ||<<"<<endl;
                    reg.Mostrar();
            }else{
                cout<<"NO SE PUDO MODIFICAR"<<endl;
            }
        }
    }
    }

}
bool MateriaArchivo::modificarMateria(const Materia &reg, int pos){
    FILE *p;
    p = fopen(_nombreArchivo,"rb+");
    if(p==nullptr){
        return -1;
    }
    fseek(p,pos*sizeof(Materia),0);
    bool escribio = fwrite(&reg,sizeof(Materia),1,p);

    fclose(p);
    return escribio;
}

void MateriaArchivo::listar() {
    Materia reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if(p == nullptr) {
        cout << "No se pudo abrir el archivo de materias." << endl;
        return;
    }
    while(fread(&reg, sizeof(Materia), 1, p) == 1) {
        if (reg.getEstado()) {
            reg.Mostrar();
            cout << "-------------------" << endl;
        }
    }
    fclose(p);
}
void MateriaArchivo::listarMateriasXNombre(const char *nombre,bool nivel){
    Materia reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if(p == nullptr) {
        cout << "No se pudo abrir el archivo de materias." << endl;
        return;
    }
    while(fread(&reg, sizeof(Materia), 1, p) == 1) {
        if (strcmp(reg.getNombre(),nombre)==0 && reg.getNivelEducativoMateria()==nivel) {
            reg.Mostrar();
            cout << "-------------------" << endl;
        }
    }
    fclose(p);
}

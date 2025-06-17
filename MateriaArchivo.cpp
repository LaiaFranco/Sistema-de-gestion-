#include "MateriaArchivo.h"
#include <iostream>
#include <cstdio>
using namespace std;

bool MateriaArchivo::guardar(Materia reg) {
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

void MateriaArchivo::listar() {
    Materia reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if(p == nullptr) {
        cout << "No se pudo abrir el archivo de materias." << endl;
        return;
    }
    while(fread(&reg, sizeof(Materia), 1, p) == 1) {
        if (reg.getActivo()) {
            reg.Mostrar();
            cout << "-------------------" << endl;
        }
    }
    fclose(p);
}

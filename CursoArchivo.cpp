#include <cstdio>
#include <cstring>
#include "CursoArchivo.h"

CursoArchivo::CursoArchivo(const char* nombre) {
    strncpy(_nombreArchivo, nombre, 29);
    _nombreArchivo[29] = '\0';
}

bool CursoArchivo::guardar(Curso reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Curso), 1, p);
    fclose(p);
    return ok;
}

Curso CursoArchivo::leer(int pos) {
    Curso reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Curso), SEEK_SET);
    fread(&reg, sizeof(Curso), 1, p);
    fclose(p);
    return reg;
}

int CursoArchivo::getCantidadRegistros() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Curso);
}

int CursoArchivo::buscarPorCodigo(int codigo) {
    Curso reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return -1;
    int pos = 0;
    while (fread(&reg, sizeof(Curso), 1, p) == 1) {
        if (reg.getCodigo() == codigo) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool CursoArchivo::modificar(Curso reg, int pos) {
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) return false;
    fseek(p, pos * sizeof(Curso), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Curso), 1, p);
    fclose(p);
    return ok;
}

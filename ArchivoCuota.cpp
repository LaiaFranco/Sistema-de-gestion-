#include "ArchivoCuota.h"
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

bool ArchivoCuota::guardar(Cuota reg) {
    FILE* p = fopen(_nombreArchivo, "ab");
    if (p == nullptr) return false;
    bool ok = fwrite(&reg, sizeof(Cuota), 1, p);
    fclose(p);
    return ok;
}

int ArchivoCuota::contar() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Cuota);
    fclose(p);
    return cant;
}

Cuota ArchivoCuota::leer(int pos) {
    Cuota reg;
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return reg;
    fseek(p, pos * sizeof(Cuota), SEEK_SET);
    fread(&reg, sizeof(Cuota), 1, p);
    fclose(p);
    return reg;
}

void ArchivoCuota::listarPorAlumno(int legajo) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo de cuotas." << endl;
        return;
    }
    Cuota reg;
    while (fread(&reg, sizeof(Cuota), 1, p) == 1) {
        if (reg.getLegajo() == legajo) {
            reg.mostrar();
        }
    }
    fclose(p);
}

void ArchivoCuota::listarPorDNI(const char* dni) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "Error al abrir archivo de cuotas." << endl;
        return;
    }
    Cuota reg;
    bool encontrado = false;
    while (fread(&reg, sizeof(Cuota), 1, p) == 1) {
        if (strcmp(reg.getDNI(), dni) == 0) {
            reg.mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron cuotas para el DNI ingresado." << endl;
    }
    fclose(p);
}

bool ArchivoCuota::marcarComoPagada(int legajo, Fecha vencimiento) {
    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == nullptr) return false;
    Cuota reg;
    for (int i = 0; fread(&reg, sizeof(Cuota), 1, p) == 1; i++) {
        if (reg.getLegajo() == legajo &&
            reg.getFechaVencimiento().getMes() == vencimiento.getMes() &&
            reg.getFechaVencimiento().getAnio() == vencimiento.getAnio()) {
            reg.setPagado(true);
            fseek(p, sizeof(Cuota) * i, SEEK_SET);
            fwrite(&reg, sizeof(Cuota), 1, p);
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

bool ArchivoCuota::existeCuota(int legajo, Fecha vencimiento) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return false;
    Cuota reg;
    while (fread(&reg, sizeof(Cuota), 1, p) == 1) {
        if (reg.getLegajo() == legajo &&
            reg.getFechaVencimiento().getMes() == vencimiento.getMes() &&
            reg.getFechaVencimiento().getAnio() == vencimiento.getAnio()) {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

void ArchivoCuota::listarImpagas() {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo de cuotas." << endl;
        return;
    }
    Cuota reg;
    bool hayImpagas = false;
    while (fread(&reg, sizeof(Cuota), 1, p) == 1) {
        if (!reg.getPagado()) {
            reg.mostrar();
            hayImpagas = true;
        }
    }
    if (!hayImpagas) {
        cout << "No hay cuotas impagas registradas." << endl;
    }
    fclose(p);
}

float ArchivoCuota::recaudacionDelMes(int mes, int anio) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    float total = 0;
    Cuota reg;
    while (fread(&reg, sizeof(Cuota), 1, p) == 1) {
        Fecha f = reg.getFechaVencimiento();
        if (f.getMes() == mes && f.getAnio() == anio && reg.getPagado()) {
            total += reg.getMonto();
        }
    }
    fclose(p);
    return total;
}

float ArchivoCuota::recaudacionAnual(int anio) {
    FILE* p = fopen(_nombreArchivo, "rb");
    if (p == nullptr) return 0;
    float total = 0;
    Cuota reg;
    while (fread(&reg, sizeof(Cuota), 1, p) == 1) {
        Fecha f = reg.getFechaVencimiento();
        if (f.getAnio() == anio && reg.getPagado()) {
            total += reg.getMonto();
        }
    }
    fclose(p);
    return total;
}

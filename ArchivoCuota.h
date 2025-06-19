#pragma once
#include "Cuota.h"

class ArchivoCuota {
public:
    bool guardar(Cuota reg);
    int contar();
    Cuota leer(int pos);
    void listarPorAlumno(int legajo);
    void listarPorDNI(const char* dni);
    bool marcarComoPagada(int legajo, Fecha vencimiento);
    bool existeCuota(int legajo, Fecha vencimiento);
    void listarImpagas();
    float recaudacionDelMes(int mes, int anio);
    float recaudacionAnual(int anio);

private:
    char _nombreArchivo[30] = "cuotas.dat";


};

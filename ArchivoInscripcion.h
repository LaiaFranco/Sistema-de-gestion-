#pragma once
#include "inscripciones.h"
#include <iostream>
#include<string>
#include<cstring>

using namespace std;
class ArchivoInscripcion{
public:
    ArchivoInscripcion();
    int CantidadRegistros();
    bool agregarInscripcion(const inscripcion &reg);
    void  listarIncripciones();
    void  listarInactivos();
    void listarInscripcionPorAnio(int anio);
    int buscarInscripcion(int idCurso);
    int buscarInscripcionPorLegajo(int legajo);
    inscripcion leerInscripcion(int pos);
    bool modificarInscripcion(const inscripcion &reg, int pos);
    bool bajaLogica(int idInscripcion);
    bool altaLogica(int idIncripcion);

private:
    char _nombreArchivo[30];
    int _tamanioRegistro;
};

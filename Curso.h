#pragma once
#include<iostream>
#include <cstring>
#include <string>

using namespace std;
class Curso{
public:
    Curso();
    Curso(int id,int numero, int numAula,string descripcion,bool turno,int cantMax,bool estado);

    void setIdCursoo(int id);
    void setNumeroCurso(int numero);
    void setNumeroAula(int numAula);
    void setNivelEducativo(bool nivel);
    void setDescripcion(string descripcion);
    void setTurno(bool turno);
    void setCantidadMaximaAlumnos(int cantMax);
    void setCantidadAlumnosInscriptos(int cantidad);
    void setEstado(bool estado);

    int getIdCurso();
    int getNumeroCurso();
    int getNumeroAula();
    bool getNivelEducativo();
    string getDescripcion();
    bool getTurno();
    int getCantidadMaximaAlumnos();
    int getCantiadaAlumnosInscriptos();
    bool getEstado();

    void Cargar();
    void Mostrar();

private:
    int _idCurso;
    int _numeroCurso;
    int _numeroAula;
    bool _nivelEducativo;
    char _descripcion[100];
    bool _turno;  // EJ, turno maniana o tarde
    int _cantMaximaAlumnos;
    int _cantAlumnosInscriptos;
    bool _estado;
};

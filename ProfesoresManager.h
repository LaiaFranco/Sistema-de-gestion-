#pragma once
#include "Profesores.h"
#include "ArchivoProfesores.h"
#include "MateriaArchivo.h"

using namespace std;
class ProfesoresManager{
public:
    int  ValidarDNI();
    int IncrementarLegajo();
    int CargarProfesor();
    void ListarProfesoresActivos();
    void buscarProfesorPorLegajo(int legajo);
    void buscarProfesorPorDNI(int  dni);
    void buscarProfesorPorApellido(const char *apellido);
    bool modificarCantMaterias(int legajo);
    void modificarSueldo(int legajo);


private:
    ArchivoProfesores _archiProf;

};

#pragma once
#include "Profesores.h"
#include "ArchivoProfesores.h"
#include "MateriaArchivo.h"

class ProfesoresManager{
public:
    int  ValidarDNI();
    int IncrementarLegajo();
    int CargarProfesor();
    void ListarProfesoresActivos();
    void menuProfesores();
    void buscarProfesorPorLegajo(int legajo);
    void buscarProfesorPorDNI(int  dni);
    void buscarProfesorPorApellido(const char *apellido);

private:
    ArchivoProfesores _archiProf;

};

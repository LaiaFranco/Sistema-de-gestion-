#pragma once
#include "Profesores.h"
#include "ArchivoProfesores.h"

class ProfesoresManager{
public:
    bool ValidarDNI();
    int IncrementarLegajo();
    int CargarProfesor();
    void ListarProfesoresActivos();
    void buscarProfesorPorLegajo(int legajo);
    void buscarProfesorPorDNI(std::string dni);
    void buscarProfesorPorApellido(const char *apellido);

private:
    ArchivoProfesores _archiProf;

};

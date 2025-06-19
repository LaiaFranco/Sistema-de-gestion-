#include "MenuGestionesAcademicas.h"
#include "Materia.h"
#include "MateriaArchivo.h"
#include <iostream>
using namespace std;

void darAltaMateria() {
    Materia m;
    m.Cargar();
    MateriaArchivo arch;
    if (arch.guardar(m)) {
        cout << "Materia guardada correctamente." << endl;
    } else {
        cout << "Error al guardar la materia." << endl;
    }
}

void darBajaMateria() {
    int cod;
    cout << "Ingrese el codigo de la materia a dar de baja: ";
    cin >> cod;

    MateriaArchivo arch;
    for (int i = 0; i < arch.contar(); i++) {
        Materia m = arch.leer(i);
        if (m.getCodigo() == cod && m.getActivo()) {
            m.setActivo(false);
            arch.modificar(m, i);
            cout << "Materia dada de baja lógicamente." << endl;
            return;
        }
    }
    cout << "Materia no encontrada o ya inactiva." << endl;
}

void modificarMateria() {
    int cod;
    cout << "Ingrese el codigo de la materia a modificar: ";
    cin >> cod;

    MateriaArchivo arch;
    for (int i = 0; i < arch.contar(); i++) {
        Materia m = arch.leer(i);
        if (m.getCodigo() == cod && m.getActivo()) {
            cout << "Materia actual: " << endl;
            m.Mostrar();

            cout << "Ingrese nuevo nombre: ";
            string nuevoNombre;
            cin.ignore();
            getline(cin, nuevoNombre);
            m.setNombre(nuevoNombre.c_str());

            arch.modificar(m, i);
            cout << "Materia modificada con éxito." << endl;
            return;
        }
    }
    cout << "Materia no encontrada o inactiva." << endl;
}

void listarMaterias() {
    MateriaArchivo arch;
    arch.listar();
}

void emitirCertificadoEstudios() {
    cout << "Función en desarrollo: se emitirá un certificado de estudios por alumno." << endl;
    cout << "Este módulo necesita integrar inscripciones y cursos para mostrar materias cursadas." << endl;
}

void menuGestionesAcademicas() {
    int opcion;
    do {
        system("cls");
        cout << "==== MENU GESTIONES ACADEMICAS ====" << endl;
        cout << "1. Dar de alta materia" << endl;
        cout << "2. Dar de baja materia" << endl;
        cout << "3. Modificar materia" << endl;
        cout << "4. Listar materias activas" << endl;
        cout << "5. Emitir certificado de estudios" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            darAltaMateria();
            break;
        case 2:
            darBajaMateria();
            break;
        case 3:
            modificarMateria();
            break;
        case 4:
            listarMaterias();
            break;
        case 5:
            emitirCertificadoEstudios();  // por ahora solo placeholder
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida." << endl;
        }
        system("pause");
    } while(opcion != 0);
}

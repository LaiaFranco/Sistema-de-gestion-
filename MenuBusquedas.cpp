#include "MenuBusquedas.h"
#include <iostream>

using namespace std;
void MenuBusqueda::MenuBusquedas(){
    int opcion;

    do {
        system("cls");
        cout << "===================================" << endl;
        cout << "          MENU DE BUSQUEDAS        " << endl;
        cout << "===================================" << endl;
        cout << "1. Buscar alumno" << endl;
        cout << "2. Buscar docente" << endl;
        cout << "3. Buscar materia" << endl;
        cout << "4. Buscar curso" << endl;
        cout << "5. Buscar inscripci�n" << endl;
        cout << "6. Buscar tutor/responsable " << endl;
        cout << "0. Volver al men� principal" << endl;
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            MenuBusquedaAlumno menuAlu;
            menuAlu.menuBusquedaAlumno();
            break;
        case 2:
           // menuBusquedaDocente();
            break;
        case 3:
            //menuBusquedaMateria();
            break;
        case 4:
           // menuBusquedaCurso();
            break;
        case 5:
           // menuBusquedaInscripcion();
            break;
        case 6:
             //menuBusquedaTutor();
            break;
        case 0:
            cout << "Volviendo al men� principal..." << endl;
            break;
        default:
            cout << "Opci�n inv�lida. Intente nuevamente." << endl;
        }
        system("pause");
    } while (opcion != 0);
}


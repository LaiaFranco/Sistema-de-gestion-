#include "MenuBusquedaAlumno.h"
#include<iostream>
#include<cstdlib>

using namespace std;
void MenuBusquedaAlumno::menuBusquedaAlumno(){

     int opcion;
     AlumnoManager aluManager;
    do {
        system("cls");
        cout << "===================================" << endl;
        cout << "          MENU DE ALUMNOS       " << endl;
        cout << "===================================" << endl;
        cout << "1. Buscar alumno por legajo" << endl;
        cout << "2. Buscar alumno por DNI" << endl;
        cout << "3. Buscar alumno por apellido" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1: {
             system("cls");
            int legajo;
            cout << "INGRESE LEGAJO DEL ALUMNO: ";
            cin >> legajo;
            aluManager.buscarAlumnoPorLegajo(legajo);
            break;
        }
        case 2: {
              system("cls");
            int dni;
            cout << "INGRESE DNI DEL ALUMNO(SIN PUNTOS): ";
            cin >> dni;
            aluManager.buscarAlumnoPorDNI(dni);
            break;
        }
        case 3: {
              system("cls");
            char apellido[30];
            cout << "INGRESE APELLIDO DEL ALUMNO: ";
            cin.ignore();
            cin.getline(apellido, 30);
            aluManager.buscarAlumnoPorApellido(apellido);
            break;
        }
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }

        system("pause");

    } while (opcion != 0);

 }

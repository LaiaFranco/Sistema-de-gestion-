#include "MenuInscripciones.h"
#include "InscripcionesManager.h"
#include<iostream>
#include<string>

using namespace std;
void MenuInscripciones::menuInscripciones(){
     int opcion;
    do {
        system("cls");
        cout<<"==============================================="<<endl;
        cout << "             MENU DE INSCRIPCIONES          "<<endl;
        cout<<"==============================================="<<endl;
        cout << "1. Inscribir a un nuevo estudiante "<<endl;
        cout << "2. Reinscripcion de alumno antiguo "<<endl;
        cout << "3. Consultar estado de inscripcion "<<endl;
        cout << "4. Lista de inscriptos por curso   "<<endl;
        cout << "0. Volver al menu principal        "<<endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:{
                InscripcionesManager insMan;
                insMan.CargarInscripcion();
                break;
            }
            case 2:
               // reinscribirAlumnoAntiguo();
                break;
            case 3:
               // consultarEstadoInscripcion();
                break;
            case 4:
                //listarInscriptosPorCurso();
                break;
            case 0:
                cout << "Volviendo al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
        system("pause");
    } while (opcion != 0);
}


#include "MenuBusquedas.h"
#include "MenuInscripciones.h"
#include "ProfesoresManager.h"
#include "MenuReportes.h"
//#include "MenuGestionesAcademicas.h"
#include <iostream>
#include <cstring>

using namespace std;
int main() {

    cout << "================================================================================="<<endl;
    cout<<"                     BIENVENIDOS AL SISTEMA DE GESTION ESCOLAR       "<<endl;
    cout << "================================================================================="<<endl;
     system("pause");
     system("cls");
    int opcion;

    do {
        cout << "===================================" << endl;
        cout << "           MENU PRINCIPAL          " << endl;
        cout << "===================================" << endl;
        cout << "1. INSCRIPCIONES" << endl;
        cout << "2. GESTIONES ACADEMICAS" << endl;
        cout << "3. PERSONAL ACADEMICO" << endl;
        cout << "4. BUSQUEDAS" << endl;
        cout << "5. REPORTES" << endl;
        cout << "6. CONFIGURACION" << endl;
        cout << "0. SALIR" << endl;
        cout<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:{
            MenuInscripciones menIns;
            menIns.menuInscripciones();
            break;
        }
        case 2:{
            // Menú Gestiones Académicas (materias/cursos)
            cout << "Menu de Gestiones Academicas (en desarrollo)" << endl;
            system("pause");
            break;
        }
        case 3:{
            // Personal Académico (cargar profesores)
            ProfesoresManager pm;
            pm.menuProfesores();  // si lo implementaste así
            break;
        }
        case 4: {
            MenuBusqueda menBusq;
            menBusq.MenuBusquedas();
            break;
        }
        case 5:{
            menuReportes();
            break;
        }
        case 6:{
            cout << "Configuracion del sistema (en desarrollo)" << endl;
            system("pause");
            break;
        }
        case 0:{
            cout << "Gracias por usar el sistema<3." << endl;
            break;
        }
        default:{
            cout << "Opción inválida." << endl;
        }


        system("pause");
        system("cls");
        }
    } while (opcion != 0);

    return 0;
}

#include "MenuBusquedas.h"
#include "MenuInscripciones.h"
#include "Menus.h"
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
            system("cls");
            Menus menuGestion;
            menuGestion.MenuGestionesAcademicas();
            break;
        }
        case 3:{

            Menus menu;
            menu.MenuPersonalAcademico();
            break;
        }
        case 4:{
           MenuBusqueda menBusq;
           menBusq.MenuBusquedas();
            break;
        }
        case 5:
            break;
        case 6:
            break;
        case 0:
            cout << "Gracias por usar el sistema<3." << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
        }

        system("pause");
        system("cls");

    } while (opcion != 0);

    return 0;
}

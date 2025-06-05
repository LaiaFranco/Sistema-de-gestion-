#include <iostream>
#include <cstring>
#include "Alumno.h"
using namespace std;

void menuInscripciones();

int main() {
    int opcion;

    do {
        cout << "===================================" << endl;
        cout << "     SISTEMA DE GESTION ESCOLAR    " << endl;
        cout << "===================================" << endl;
        cout << "1. Inscripciones" << endl;
        cout << "2. Gestiones académicas" << endl;
        cout << "3. Personal académico" << endl;
        cout << "4. Búsquedas" << endl;
        cout << "5. Reportes" << endl;
        cout << "6. Configuración" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
        case 1:
            menuInscripciones(); 
            break;
        // demás casos omitidos por simplicidad
        case 0:
            cout << "Gracias por usar el sistema." << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
        }

        system("pause");
        system("cls");

    } while (opcion != 0);

    return 0;
}
void menuInscripciones() {
    AlumnoArchivo arch;
    int opcion;

    do {
        cout << "--- SUBMENU DE INSCRIPCIONES ---" << endl;
        cout << "1. Registrar nuevo estudiante" << endl;
        cout << "2. Reinscripción de alumno antiguo" << endl;
        cout << "3. Consultar estado de inscripción" << endl;
        cout << "4. Lista de inscriptos por curso" << endl;
        cout << "0. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
        case 1: {
            Alumno nuevo;
            nuevo.cargar();
            arch.guardar(nuevo);
            break;
        }
        
        case 0:
            cout << "Volviendo al menú principal..." << endl;
            break;
        default:
            cout << "Opción inválida." << endl;
        }

        system("pause");
        system("cls");

    } while (opcion != 0);
}

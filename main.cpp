#include <iostream>
#include <cstring>
#include "Alumno.h"

using namespace std;

void menuInscripciones();

int main() {
    menuInscripciones();
    return 0;
}

void menuInscripciones() {
    int opcion;
    AlumnoArchivo arch;

    do {
        cout << "----- MENU INSCRIPCIONES -----" << endl;
        cout << "1. Registrar nuevo estudiante" << endl;
        cout << "2. Reinscripcion de alumno antiguo" << endl;
        cout << "3. Consultar estado de inscripcion" << endl;
        cout << "4. Lista de inscriptos por curso" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1: {
            Alumno nuevo;
            nuevo.cargar();  // heredaría carga desde Persona + propios campos de Alumno
            if (arch.guardar(nuevo)) {
                cout << "Alumno registrado correctamente." << endl;
            } else {
                cout << "Error al guardar el alumno." << endl;
            }
            break;
        }
        case 2: {
            int dni;
            cout << "Ingrese DNI del alumno a reinscribir: ";
            cin >> dni;
            int pos = arch.buscarPorDNI(dni);
            if (pos >= 0) {
                Alumno a = arch.leer(pos);
                cout << "Alumno encontrado:" << endl;
                a.mostrar();
                cout << "--- Ingrese nuevos datos para reinscripcion ---" << endl;
                a.cargar();  // se vuelve a cargar con nuevos datos
                if (arch.modificar(a, pos)) {
                    cout << "Reinscripcion exitosa." << endl;
                } else {
                    cout << "Error al reinscribir." << endl;
                }
            } else {
                cout << "Alumno no encontrado." << endl;
            }
            break;
        }
        case 3: {
            int dni;
            cout << "Ingrese DNI del alumno: ";
            cin >> dni;
            int pos = arch.buscarPorDNI(dni);
            if (pos >= 0) {
                Alumno a = arch.leer(pos);
                cout << "Estado de inscripcion: ";
                cout << (a.getEstado() ? "Activa" : "Inactiva") << endl;
            } else {
                cout << "Alumno no encontrado." << endl;
            }
            break;
        }
        case 4: {
            int curso;
            cout << "Ingrese codigo de curso: ";
            cin >> curso;

            int cantidad = arch.getCantidadRegistros();
            int contador = 0;

            for (int i = 0; i < cantidad; i++) {
                Alumno a = arch.leer(i);
                if (a.getCodigoCurso() == curso && a.getEstado()) {
                    a.mostrar();
                    cout << "------------------------" << endl;
                    contador++;
                }
            }

            cout << "Total de inscriptos en el curso " << curso << ": " << contador << endl;
            break;
        }
        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }

        system("pause");
        system("cls");

    } while (opcion != 0);
}

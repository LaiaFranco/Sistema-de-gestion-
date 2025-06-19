#include "MenuReportes.h"
#include "ArchivoCuota.h"
#include <iostream>
using namespace std;

void menuReportes() {
    ArchivoCuota arch;
    int opcion;

    do {
        system("cls");
        cout << "===== MENU DE REPORTES =====" << endl;
        cout << "1. Listar cuotas impagas" << endl;
        cout << "2. Recaudacion mensual" << endl;
        cout << "3. Recaudacion anual" << endl;
        cout << "4. Buscar cuotas por DNI" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                arch.listarImpagas();
                break;
            case 2: {
                int m, a;
                cout << "MES: "; cin >> m;
                cout << "AÑO: "; cin >> a;
                float total = arch.recaudacionDelMes(m, a);
                cout << "TOTAL RECAUDADO: $" << total << endl;
                break;
            }
            case 3: {
                int a;
                cout << "AÑO: "; cin >> a;
                float total = arch.recaudacionAnual(a);
                cout << "TOTAL RECAUDADO EN " << a << ": $" << total << endl;
                break;
            }
            case 4: {
                char dni[12];
                cout << "DNI: ";
                cin.ignore();
                cin.getline(dni, 12);
                arch.listarPorDNI(dni);
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

        system("pause");

    } while (opcion != 0);
}

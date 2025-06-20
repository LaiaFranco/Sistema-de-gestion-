#include "Menus.h"
#include<iostream>
#include<cstdlib>

using namespace std;
void Menus::MenuGestionesAcademicas(){
    int opcion;
    do{
            cout << "===================================" << endl;
            cout << "       GESTIONES ACADEMICAS        " << endl;
            cout << "===================================" << endl;
            cout << "1. GESTION DE MATERIAS" << endl;
            cout << "2. MODIFICACION DE MATERIAS" << endl;
            cout << "3. CARGA DE CURSOS" << endl;
            cout << "4. MODIFICACION DE CURSO" << endl;
            cout << "5.EMISION DE CERTIFICADOS DE ESTUDIO"<<endl;
            cout << "0.VOLVER AL MENU PRINCIPAL" << endl<<endl;
            cout << "Seleccione una opcion: ";
            cin >> opcion;
            cout<<endl;
            switch (opcion) {
                case 1:{
                    system("cls");
                    MateriaArchivo matArch;
                    cout << ">> Gestion/carga de Materias"<<endl;
                    matArch.CargarMateria();
                    break;
                }
                case 2:{
                    Materia mat;
                    MateriaArchivo matArchi;
                    int opcion2;
                    system("cls");
                    cout << ">> Modificacion de Materias"<<endl;
                    cout<<"MODIFICACION DE: "<<endl;
                    cout<<"1.ESTADO"<<endl;
                    cout<<"2.CARGA HORARIA"<<endl;
                    cout<<"OPCION: ";
                    cin>> opcion2;
                    system("cls");
                        char nombre[30];
                        bool nivel;
                        int anio;
                        cout<<"INGRESE NOMBRE DE LA MATERIA: ";
                        cin.ignore();
                        cin.getline(nombre,30,'\n');
                        cout<<"NIVEL ACADEMICO(0-Primaria,1-Secundario): ";
                        cin>>nivel;
                        cout<<"ANIO EN QUE SE DICTA LA MATERIA: ";
                        cin>>anio;
                        system("cls");
                    if(opcion2==1){
                        matArchi.ModificarEstado(nombre,nivel,anio);
                    }if(opcion2 ==2){
                        matArchi.ModificarCargaHoraria(nombre,nivel,anio);
                    }else {
                        cout<<"ERROR, MIRE BIEN LAS OPCIONES DEL MENU"<<endl;
                    }
                    break;
                }
                case 3:{
                    CursoArchivo archiCur;
                    system("cls");
                    cout << ">> Carga de Cursos"<<endl;
                    archiCur.CargarCurso();
                    break;
                }
                case 4:{
                    CursoArchivo archiCur;
                    int opcion2;
                    system("cls");
                    bool nivel;
                    int numAula, NumCurso;
                    cout << ">> Modificacion Curso"<<endl;
                    cout<<"MODIFICACION DE: "<<endl;
                    cout<<"1.ESTADO"<<endl;
                    cout<<"2.CANTIDAD MAXIMA DE ALUMNOS"<<endl;
                    cout<<"OPCION: ";
                    cin>> opcion2;
                    system("cls");

                    cout<<"NIVEL ACADEMICO: ";
                    cin>>nivel;
                    cout<<"NUMERO DE AULA: ";
                    cin>>numAula;
                    cout<<"NUMERO DE CURSO: ";
                    cin>>NumCurso;
                    if(opcion ==1){
                        archiCur.ModificarEstado(nivel,numAula,NumCurso);
                    }if (opcion2==2){
                        archiCur.ModificarCantAlumnos(nivel,numAula,NumCurso);
                    }else{
                         cout<<"ERROR, MIRE BIEN LAS OPCIONES DEL MENU"<<endl;
                    }
                    break;
                }
                case 5:
                    system("cls");
                     int opcion;
                     cout << ">> Emision de Certificado de Estudio"<<endl;
                     cout<<"---CERTIFIADOS A EMITIR----"<<endl;
                     cout<<"1.CERT.ALUMNO REGULAR"<<endl;
                     cout<<"2.CERT.ANALITICO PARCIAL"<<endl;
                     cout<<"3.CERT.FINALIZACION DE ESTUDIOS" <<endl;
                     cout<<"OPCION: ";
                     cin>>opcion;
                     system("cls");
                     int dni;
                     cout<<"INGRESE DNI DEL ALUMNO: ";
                     cin>>dni;
                     switch(opcion){
                     case 1:{
                         Alumno alu;
                         ArchivoAlumno archi;
                         AlumnoManager aluMan;
                         alu = archi.buscarAlumnoXDni(dni);
                         aluMan.emisionCertificadoRegular(alu);
                        break;
                     }
                     case 2:{
                         Alumno alu;
                         ArchivoAlumno archi;
                         InscripcionesManager insMan;
                         alu = archi.buscarAlumnoXDni(dni);
                         insMan.emisionCertificadoParcial(alu);

                        break;
                     }
                     case 3:{
                         Alumno alu;
                         ArchivoAlumno archi;
                         InscripcionesManager insMan;
                         alu = archi.buscarAlumnoXDni(dni);
                         insMan.emisionCertificadoFinal(alu);
                        break;
                     }
                    case 0:
                    cout << "Volviendo al menu principal...";
                        break;
                    default:
                    cout << "Opcion invalida. Intente nuevamente.";

                     }

                    break;
                case 0:
                    cout << "Volviendo al menu principal...";
                    break;
                default:
                    cout << "Opcion invalida. Intente nuevamente.";
                }
                system("pause");
                system("cls");
        } while (opcion != 0);
}

void Menus::MenuPersonalAcademico(){
     int opcion;
    do {
            system("cls");
        cout << "====== MENU PERSONAL ACADEMICO ======" << endl;
        cout << "1. Alta/Carga Profesor" << endl;
        cout << "2. Baja de Profesor" << endl;
        cout << "3. Modificacion" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:{
                ProfesoresManager profMan;
                profMan.CargarProfesor();
                break;
            }
            case 2:{
                int dni;
                bool ok;
                cout<<"INGRESE DNI: ";
                cin>>dni;

                ArchivoProfesores archiProf;
                ok =archiProf.bajaLogica(dni);
                if(ok){
                    cout<<"SE GUARDO CORRECTAMENTE EL CAMBIO "<<endl;
                }else {
                    cout<<"NO SE PUDO MODIFICAR"<<endl;
                }
                break;
            }
            case 3:
                {
                    ProfesoresManager profMan;
                    Profesores prof;
                    system("cls");
                    int opcion;
                    int legajo;
                    cout<<"|| MODIFICACION ||"<<endl;
                    cout<<"1.Sueldo   "<<endl;
                    cout<<"2.Cantidad de materias a dar"<<endl<<endl;
                    cout<<"OPCION: ";
                    cin>>opcion;

                    cout<<"INGRESE LEGAJO DEL PROFESOR: ";
                    cin>>legajo;

                    if(opcion==1){
                            profMan.modificarSueldo(legajo);
                    }if(opcion==2){
                        if(profMan.modificarCantMaterias(legajo)){
                             cout<<"SE MODIFICO CORRECTAMENTE"<<endl;
                        }
                    }
                break;
                }
            case 0:{
                    cout << "Volviendo al menu principal...";
                    break;
            }
            default:{
                    cout << "Opcion invalida. Intente nuevamente.";
                }
        }
    } while(opcion != 0);


}

void Menus::MenuReportes(){

    int opcion;

    do {
        system("cls");
        cout << "===== MENU DE REPORTES =====" << endl;
        cout << "1. Reporte de inscripciones" << endl;
        cout << "2. Reporte financiero" << endl;
        cout << "3. Reporte historial academico" << endl;
        cout << "0. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {/*{
            case 1:
                arch.listarImpagas();*/
                break;
            case 2: /*{
                int m, a;
                cout << "MES: "; cin >> m;
                cout << "AÑO: "; cin >> a;
                float total = arch.recaudacionDelMes(m, a);
                cout << "TOTAL RECAUDADO: $" << total << endl;*/
                break;
            case 3: /*{
                int a;
                cout << "AÑO: "; cin >> a;
                float total = arch.recaudacionAnual(a);
                cout << "TOTAL RECAUDADO EN " << a << ": $" << total << endl;*/
                break;
            case 0:
                break;
            default:{
                cout << "Opcion invalida." << endl;
        }
        }
        system("pause");

    } while (opcion != 0);

}

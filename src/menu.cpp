#include "../include/menu.h"
#include "../include/utils.h"
#include "../include/agenda.h"

#include <iostream>

using namespace std;

void ejecutarMenu(){
    Agenda agenda;
    
    int opcion;
    bool ejecutar = true;

    while(ejecutar){
        try{
            cout << "\n\n\t##### AGENDA CONTACTOS #####\n\n";
            cout << "1) Agregar nuevo contacto" << "\n"
                << "2) Buscar contacto por nombre" << "\n"
                << "3) Eliminar contacto por nombre o telefono" << "\n"
                << "4) Mostrar todos los contactos." << "\n"
                << "5) Salir." << "\n"
                << "Opcion: ";
            cin >> opcion; validarInput();

            switch(opcion){
                case 1: // agregar contacto
                    limpiarConsola();
                    agenda.agregarContacto();
                    break;
                case 2:{ // buscar por nombre
                    limpiarConsola();
                    string nombre;
                    cout << "BUSCAR CONTACTO POR NOMBRE" << endl;
                    cout << "Nombre: "; cin >> nombre;
                    Contacto& cont = agenda.obtenerContactoPorNombre(nombre);
                    cont.getInfoContacto();
                    break;
                }
                case 3:{ // eliminar contacto por nombre o telefono
                    limpiarConsola();
                    bool regresarMenu = false;
                    do{
                        int res;
                        cout << "\n\tELIMINAR POR:\n\n"
                            << "1) Nombre\n"
                            << "2) Telefono\n"
                            << "3) Regresar al menu anterior\n\n"
                            << "Opcion: ";
                        cin >> res; validarInput();
                        switch (res){
                            case 1:{
                                string nombre;
                                cout << "\nNombre: "; cin >> nombre; // TODO: Validar case sensitive
                                agenda.eliminarContactoPorNombre(nombre);
                                cout << "Contacto eliminado." << endl;
                                break;
                            }
                            case 2:{
                                string telefono;
                                cout << "\nTelefono: "; cin >> telefono;
                                agenda.eliminarContactoPorTelefono(telefono);
                                cout << "Contacto eliminado." << endl;
                                break;
                            }           
                            case 3:
                                regresarMenu = true;
                                break;                
                            default:
                                cout << "\n*** Opcion incorrecta. Intenta de nuevo ***\n";
                                break;
                        }
                    } while(!regresarMenu);
                    break;
                }
                case 4: // mostrar todos los contactos
                    limpiarConsola();
                    agenda.mostrarCotactos();
                    break;
                case 5: // salir
                    limpiarConsola();
                    char res;
                    cout << "Seguro que quieres salir? (y): "; cin >> res;
                    if(tolower(res) == 'y'){
                        cout << "\n\n *** FIN DEL PROGRAMA ***\n\n";
                        ejecutar = false;
                    }
                    break;
                default:
                    limpiarConsola();
                    cout << "\n*** Opcion incorrecta. Intenta de nuevo ***\n";
                    break;
            }
        } catch (const runtime_error& e){
            cerr << "\nError: " << e.what() << endl;
        } catch (const exception& e){
            cerr << "\nError inesperado: " << e.what() << endl;
        }
    }
}
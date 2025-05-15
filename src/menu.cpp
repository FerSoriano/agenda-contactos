#include "../include/menu.h"
#include "../include/utils.h"
#include "../include/agenda.h"
#include "../include/csv_manager.h"

#include <iostream>
#include <stdexcept>

using namespace std;

//TODO: Agregar escape de las opciones. Ejemplo: Pular '*' para regresar.

void ejecutarMenuPrincipal(){
    Agenda agenda;
    
    int opcion;
    bool ejecutar = true;
    
    string contactosCSV = "../output/data/contactosCSV.csv"; // esta al mismo nivel que output.

    try{
        CSVManager archivoCSV(contactosCSV);
        if(archivoCSV.crearArchivo()){
            cout << "\nArchivo inicial creado con exito: " << contactosCSV << endl;
        } else{
            archivoCSV.actualizarContactosVector(agenda);
            cout << "\nSe actualizaron correctamente los contactos!" << endl;
        }
        while(ejecutar){
            try{
                cout << "\n\n\t##### AGENDA CONTACTOS #####\n\n";
                cout << "1) Agregar nuevo contacto" << "\n"
                    << "2) Buscar contacto por nombre" << "\n"
                    << "3) Editar contacto" << "\n"
                    << "4) Eliminar contacto" << "\n"
                    << "5) Mostrar todos los contactos." << "\n"
                    << "6) Salir." << "\n"
                    << "Opcion: ";
                cin >> opcion; validarInput();

                switch(opcion){
                    case 1: // agregar
                        limpiarConsola();
                        agenda.agregarContacto(archivoCSV);
                        break;
                    case 2:{ // buscar
                        limpiarConsola();
                        string nombre;
                        cout << "BUSCAR CONTACTO POR NOMBRE" << endl;
                        cout << "Nombre: "; cin >> nombre;
                        Contacto& cont = agenda.obtenerContactoPorNombre(nombre);
                        cont.getInfoContacto();
                        break;
                    }
                    case 3:{ // editar
                        limpiarConsola();
                        bool regresarMenu = false;
                        do{
                            try{
                                int res;
                                cout << "\n\tEDITAR CONTACTO:\n\n"
                                    << "1) Buscar por nombre\n"
                                    << "2) Buscar por numero de telefono\n"
                                    << "3) Regresar al menu anterior\n\n"
                                    << "Opcion: ";
                                cin >> res; validarInput();
                                switch (res){
                                    case 1:{
                                        string nombre;
                                        cout << "\nNombre: "; cin >> nombre;
                                        Contacto& c = agenda.obtenerContactoPorNombre(nombre);
                                        c.getInfoContacto();
                                        agenda.editarContacto(c,archivoCSV);
                                        break;
                                    }
                                    case 2:{
                                        string numeroTelefono;
                                        cout << "\nNumero Tel: "; cin >> numeroTelefono;
                                        Contacto& c = agenda.obtenerContactoPorTelefono(numeroTelefono);
                                        c.getInfoContacto();
                                        agenda.editarContacto(c,archivoCSV);
                                        break;
                                    }           
                                    case 3:
                                        regresarMenu = true;
                                        break;                
                                    default:
                                        cout << "\n*** Opcion incorrecta. Intenta de nuevo ***\n";
                                        break;
                                }
                            } catch (const runtime_error& e){
                                cerr << "\nError: " << e.what() << endl;
                            } catch (const exception& e){
                                cerr << "\nError inesperado: " << e.what() << endl;
                            }
                        } while(!regresarMenu);
                        break;
                    }
                    case 4:{ // eliminar
                        limpiarConsola();
                        bool regresarMenu = false;
                        do{
                            try{
                                int res;
                                cout << "\n\tELIMINAR CONTACTO POR:\n\n"
                                    << "1) Nombre\n"
                                    << "2) Telefono\n"
                                    << "3) Regresar al menu anterior\n\n"
                                    << "Opcion: ";
                                cin >> res; validarInput();
                                switch (res){
                                    case 1:{
                                        string nombre;
                                        cout << "\nNombre: "; cin >> nombre;
                                        agenda.eliminarContactoPorNombre(nombre, archivoCSV);
                                        cout << "Contacto eliminado." << endl;
                                        break;
                                    }
                                    case 2:{
                                        string numeroTelefono;
                                        cout << "\nTelefono: "; cin >> numeroTelefono;
                                        agenda.eliminarContactoPorTelefono(numeroTelefono, archivoCSV);
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
                            } catch (const runtime_error& e){
                                cerr << "\nError: " << e.what() << endl;
                            } catch (const exception& e){
                                cerr << "\nError inesperado: " << e.what() << endl;
                            } 
                        } while(!regresarMenu);
                        break;
                    }
                    case 5: // mostrar
                        limpiarConsola();
                        agenda.mostrarCotactos();
                        break;
                    case 6: // salir
                        char res;
                        cout << "\n\nSeguro que quieres salir? (y): "; cin >> res;
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
    } catch(const invalid_argument& e){
        cerr << "\nError: " << e.what() << endl;
    } catch (const runtime_error& e){
        cerr << "\nError: " << e.what() << endl;
    } catch (const exception& e){
        cerr << "\nError inesperado: " << e.what() << endl;
    }
}
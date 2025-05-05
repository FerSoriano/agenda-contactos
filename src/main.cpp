#include "../include/contacto.h"
#include "../include/menu.h"
#include "../include/agenda.h"
#include "../include/utils.h"

#include <iostream>

using namespace std;

int main(){

    bool run = true;

    while(run){
        cout << "\n\t##### AGENDA CONTACTOS #####\n\n";

        Agenda agenda;

        int opcion;
        while(true){
            mostrarMenu(); 
            cin >> opcion;
            if(opcion >= 1 && opcion <= 5) break; 
            limpiarConsola();
            cout << "*** Opcion incorrecta. Intenta de nuevo ***\n";
        }

        try{
            // TODO: VALIDAR PORQUE NO DEJA AGREGAR CONTACTOS
            if(opcion == 1){ // Agregar nuevo contacto
                limpiarConsola();
                agenda.agregarContacto();
            }
            if(opcion == 2){ // Buscar contacto por nombre
                limpiarConsola();
                string nombre;
                cout << "BUSCAR CONTACTO POR NOMBRE" << endl;
                cout << "Nombre: "; cin >> nombre;
                agenda.buscarContactoPorNombre(nombre);
            }
            if(opcion == 3){ // Eliminar contacto por nombre o telefono
                limpiarConsola();
                do{
                    int res;
                    cout << "ELIMINAR POR: \n1) Nombre\n2)Telefono\nOpcion: "; cin >> res;
                    validarInput();
                    if(res == 0) {cout << "Opcion incorrecta\n\n"; continue;}
                    if(res == 1) {
                        string nombre;
                        cout << "Nombre: "; cin >> nombre;
                        agenda.eliminarContactoPorNombre(nombre);
                        break;
                    }
                    if(res == 2) {
                        string telefono;
                        cout << "Telefono: "; cin >> telefono;
                        agenda.eliminarContactoPorTelefono(telefono);
                        break;
                    }
                } while(true);
            }
            if(opcion == 4){ // Mostrar contactos
                limpiarConsola();
                agenda.mostrarCotactos();
            }
            if(opcion == 5){ // Mostrar contactos
                cout << "\n\n *** FIN DEL PROGRAMA ***\n\n";
                run = false;
            }

        } catch (const runtime_error& e){
            cerr << "Runtime error: " << e.what() << endl;

        } catch (const exception& e){
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
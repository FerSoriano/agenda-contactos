#include "../include/menu.h"

#include <iostream>

using namespace std;

void mostrarMenu(){
    cout << "\n1) Agregar nuevo contacto" << "\n"
        << "2) Buscar contacto por nombre" << "\n"
        << "3) Eliminar contacto por nombre o telefono" << "\n"
        << "4) Mostrar todos los contactos." << "\n"
        << "5) Salir." << "\n"
        << "Opcion: ";
}
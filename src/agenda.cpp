#include "../include/contacto.h"
#include "../include/agenda.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//TODO: Agregar logica de CSV.

void Agenda::agregarContacto(){
    string nombre, telefono;
    cout << "AGREGAR CONTACTO" << endl;
    cout << "Nombre: "; cin >> nombre;
    cout << "Telefono: "; cin >> telefono;
    Contacto nuevoContacto(nombre, telefono);
    char agregarCorreo;
    cout << "Agregar correo? (y o cualquiera para omitir): "; cin >> agregarCorreo;
    if(tolower(agregarCorreo) == 'y'){
        string correo;
        cout << "Correo: "; cin >> correo;
        nuevoContacto.actualizarCorreo(correo);
    }
    contactos_.push_back(nuevoContacto);
}

Contacto Agenda::buscarContactoPorNombre(string nombre){
    for(auto& contacto : contactos_){
        if(contacto.getNombre() == nombre) return contacto;
    }
    throw runtime_error("Contacto no encontrado");
}

void Agenda::eliminarContactoPorNombre(string nombre){
    for(auto it = contactos_.begin(); it != contactos_.end(); it++){
        if(it->getNombre() == nombre){
            contactos_.erase(it);
            return;
        }
    }
    throw runtime_error("Contacto no encontrado");
}
    
void Agenda::eliminarContactoPorTelefono(std::string telefono){
    for(auto it = contactos_.begin(); it != contactos_.end(); it++){
        if(it->getNombre() == telefono){
            contactos_.erase(it);
            return;
        }
    }
    throw runtime_error("Contacto no encontrado");
}

void Agenda::mostrarCotactos(){
    cout << "\n### CONTACTOS ###\n\n";
    for(auto& contacto : contactos_){
        contacto.getInfoContacto();
        cout << '\n';
    }
}

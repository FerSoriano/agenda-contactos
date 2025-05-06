#include "../include/contacto.h"
#include "../include/agenda.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//TODO: Agregar logica de CSV.

void Agenda::agregarContacto(){
    string nombre, telefono;
    do{
        cout << "AGREGAR CONTACTO" << endl;

        cout << "Nombre: "; cin >> nombre;
        if(buscarContactoPorNombre(nombre)){ cout << "\n*** El contacto \"" << nombre << "\" ya existe. Intenta de nuevo. ***\n\n"; continue; }

        cout << "Telefono: "; cin >> telefono;
        if(buscarContactoPorTelefono(telefono)){ cout << "\n*** El telefono \"" << telefono << "\" ya existe. Intenta de nuevo. ***\n\n"; continue; }

        break;
    } while(true);

    Contacto nuevoContacto(nombre, telefono);

    char agregarCorreo;
    cout << "Agregar correo? (y o cualquiera para omitir): "; cin >> agregarCorreo;
    if(tolower(agregarCorreo) == 'y'){
        string correo;
        cout << "Correo: "; cin >> correo;
        nuevoContacto.actualizarCorreo(correo);
    }

    contactos_.push_back(nuevoContacto);
    cout << "\n" << nuevoContacto.getNombre() << " se agrego correctamente." << endl;   
}

bool Agenda::buscarContactoPorNombre(const string& nombre){
    // TODO: validar case sensitive
    for(auto& contacto : contactos_){
        if(contacto.getNombre() == nombre) return true;
    }
    return false;
}

bool Agenda::buscarContactoPorTelefono(const string& telefono){
    for(auto& contacto : contactos_){
        if(contacto.getTelefono() == telefono) return true;
    }
    return false;
}

Contacto& Agenda::obtenerContactoPorNombre(const string& nombre) {
    // TODO: validar case sensitive
    for(auto& contacto : contactos_) {  // Iterar por referencia
        if (contacto.getNombre() == nombre) return contacto;  // Retorna referencia al objeto original
    }
    throw runtime_error("Contacto no encontrado");
}

void Agenda::eliminarContactoPorNombre(const string& nombre){
    for(auto it = contactos_.begin(); it != contactos_.end(); it++){
        if(it->getNombre() == nombre){
            contactos_.erase(it);
            return;
        }
    }
    throw runtime_error("Contacto no encontrado");
}
    
void Agenda::eliminarContactoPorTelefono(const string& telefono){
    for(auto it = contactos_.begin(); it != contactos_.end(); it++){
        if(it->getTelefono() == telefono){
            contactos_.erase(it);
            return;
        }
    }
    throw runtime_error("Contacto no encontrado");
}

void Agenda::mostrarCotactos(){
    cout << "\n\t### CONTACTOS ###\n\n";
    for(size_t i=0; i < contactos_.size(); i++){
        contactos_[i].getInfoContacto();
    }
}

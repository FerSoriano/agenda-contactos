#include "../include/contacto.h"
#include "../include/agenda.h"
#include "../include/utils.h"

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
        nuevoContacto.setCorreo(correo);
    }

    contactos_.push_back(nuevoContacto);
    cout << "\n" << nuevoContacto.getNombre() << " se agrego correctamente." << endl;   
}

bool Agenda::buscarContactoPorNombre(const string& nombre){
    for(auto& contacto : contactos_){
        if(convertirMinus(contacto.getNombre()) == convertirMinus(nombre)) return true;
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
    for(auto& contacto : contactos_) {
        if(convertirMinus(contacto.getNombre()) == convertirMinus(nombre)) return contacto;
        
    }
    throw runtime_error("Contacto no encontrado");
}

Contacto& Agenda::obtenerContactoPorTelefono(const string& telefono) {
    for(auto& contacto : contactos_) {
        if (contacto.getTelefono() == telefono) return contacto;
    }
    throw runtime_error("Contacto no encontrado");
}

void Agenda::eliminarContactoPorNombre(const string& nombre){
    for(auto it = contactos_.begin(); it != contactos_.end(); it++){
        if(convertirMinus(it->getNombre()) == convertirMinus(nombre)){
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

void Agenda::editarContacto(Contacto& contacto){
    int res;
    bool ejecutar = true;
    while(ejecutar){
        cout << "\n1) Editar nombre" << "\n"
            << "2) Editar numero" << "\n"
            << "3) Editar correo" << "\n"
            << "4) Regresar" << "\n"
            << "Opcion: ";
            cin >> res; validarInput();
            switch (res){
                case 1:{
                    string nombre;
                    cout << "\nNuevo nombre: "; cin >> nombre;
                    contacto.setNombre(nombre);
                    cout << "\nNombre actualizado\n";
                    contacto.getInfoContacto();
                    break;
                }
                case 2:{
                    string numeroTelefono;
                    cout << "\nNuevo numero: "; cin >> numeroTelefono;
                    contacto.setTelefono(numeroTelefono);
                    cout << "\nNumero actualizado\n";
                    contacto.getInfoContacto();
                    break;
                }
                case 3:{
                    string correo;
                    cout << "\nNuevo correo: "; cin >> correo;
                    contacto.setCorreo(correo);
                    cout << "\nCorreo actualizado\n";
                    contacto.getInfoContacto();
                    break;
                }           
                case 4:
                    ejecutar = false;
                    break;                
                default:
                    cout << "\n*** Opcion incorrecta. Intenta de nuevo ***\n";
                    break;
            }
    }
}

void Agenda::mostrarCotactos(){
    cout << "\n\t### CONTACTOS ###\n";
    for(size_t i=0; i < contactos_.size(); i++){
        contactos_[i].getInfoContacto();
    }
}

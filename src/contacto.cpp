#include "../include/contacto.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

Contacto::Contacto(const string& nombre, const string& telefono){
    if(nombre.empty()) { throw invalid_argument("El nombre no puede estar vacio."); }
    if(telefono.empty()) { throw invalid_argument("El telefono no puede estar vacio."); }
    nombre_ = nombre;
    telefono_ = telefono;
}

Contacto::~Contacto(){};

string Contacto::getNombre(){ return nombre_; }
string Contacto::getTelefono(){ return telefono_; }
string Contacto::getCorreo(){ return correo_; }
void Contacto::getInfoContacto(){
    cout << "\nNombre: " << nombre_ << "\n"
        << "Telefono: " << telefono_ << "\n"
        << "Correo: " << correo_ << "\n";
}

void Contacto::actualizarNombre(string nombre){
    if(nombre.empty()) { throw invalid_argument("El nombre no puede estar vacio."); }
    nombre_ = nombre;
}
void Contacto::actualizarTelefono(string telefono){
    if(telefono.empty()) { throw invalid_argument("El telefono no puede estar vacio."); }
    telefono_ = telefono;
}
void Contacto::actualizarCorreo(string correo){
    if(correo.empty()) { throw invalid_argument("El correo no puede estar vacio."); }
    correo_ = correo;
}

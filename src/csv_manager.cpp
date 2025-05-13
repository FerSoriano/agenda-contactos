#include "../include/csv_manager.h"
#include "../include/contacto.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <filesystem>

using namespace std;

CSVManager::CSVManager(const string& nombreArchivo){
    if(nombreArchivo.empty()) throw invalid_argument("El nombre del archivo no puede estar vacio");
    nombreArchivo_ = nombreArchivo;
}

// setters
void CSVManager::setNombreArchivo(string nombreArchivo){
    if(nombreArchivo.empty()) throw invalid_argument("Nombre del archivo vacio");
    nombreArchivo_ = nombreArchivo;
}
// getters
string CSVManager::getNombreArchivo(){
    if(nombreArchivo_.empty()) throw runtime_error("Nombre del archivo vacio");
    return nombreArchivo_;
}

bool CSVManager::crearArchivo(){
    if(filesystem::exists(nombreArchivo_)){ return false; }
    ofstream archivo(nombreArchivo_,ios::out);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    archivo << "Nombre,Telefono,Correo\n"; // agregamos encabezados
    return true;
}

void CSVManager::agregarRegistro(Contacto& contacto){
    ofstream archivo(nombreArchivo_,ios::app);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }
    archivo << formatearContactoComoFilaCSV(contacto);
}

string CSVManager::formatearContactoComoFilaCSV(Contacto& contacto){
    ostringstream fila;
    fila << contacto.getNombre() << "," << contacto.getTelefono() << "," << contacto.getCorreo() << endl;
    return fila.str();
}

void CSVManager::sobreEscribirArchivo(std::vector<Contacto>& contactos){
    if(crearArchivo()){
        for(size_t i=0; i<contactos.size(); i++){
            agregarRegistro(contactos[i]);
        }
    }
}

void CSVManager::actualizarContactosVector(std::vector<Contacto>& contactos){
    contactos.clear();
    ifstream archivo(nombreArchivo_);
    
    if(!archivo.is_open()){
        throw runtime_error("\n\n *** Error actualizando el vector. No se pudo abrir el archivo \"" + filesystem::absolute(nombreArchivo_).string() + "\". ***\n\n");
    }
    
    string fila;
    bool esEncabezado = true;
    while(getline(archivo, fila)){
        if (esEncabezado){
            esEncabezado = false;
            continue; // saltamos header
        }

        stringstream ss(fila);
        string nombre, telefono, correo;

        getline(ss,nombre,',');
        getline(ss,telefono,',');
        getline(ss,correo,',');
        
        Contacto c(nombre,telefono);
        c.setCorreo(correo);
        contactos.push_back(c);
    }
}

//TODO: Aplicar metodos en el main
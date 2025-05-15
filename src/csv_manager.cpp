#include "../include/csv_manager.h"
#include "../include/contacto.h"
#include "../include/agenda.h"

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
    if(filesystem::exists(nombreArchivo_)) return false; // si existe

    // Crear directorio si no existe
    filesystem::path dir = filesystem::path(nombreArchivo_).parent_path();
    if (!dir.empty() && !filesystem::exists(dir)) {
        filesystem::create_directories(dir);  // Crea toda la jerarquía de directorios
    }

    ofstream archivo(nombreArchivo_,ios::out);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo crear el archivo en: " + filesystem::absolute(nombreArchivo_).string());
    }
    archivo << "Nombre,Telefono,Correo\n"; // agregamos encabezados
    return true;
}

void CSVManager::agregarContacto(Contacto& contacto){
    ofstream archivo(nombreArchivo_,ios::app);
    if (!archivo.is_open()) {
        throw runtime_error("Error al agregar contacto al CSV. No se pudo abrir el archivo");
    }
    archivo << '\n' << formatearContactoComoFilaCSV(contacto);
}

string CSVManager::formatearContactoComoFilaCSV(Contacto& contacto){
    ostringstream fila;
    fila << contacto.getNombre() << "," << contacto.getTelefono() << "," << contacto.getCorreo();
    return fila.str();
}

void CSVManager::sobreEscribirArchivoCSV(std::vector<Contacto>& contactos){
    ofstream archivo(nombreArchivo_,ios::out); // sobreescribe el archivo
    if (!archivo.is_open()) throw runtime_error("No se pudo sobreescribir el archivo");

    archivo << "Nombre,Telefono,Correo"; // agregamos encabezados
    for(size_t i=0; i<contactos.size(); i++){
        archivo << "\n" << formatearContactoComoFilaCSV(contactos[i]);
    }
}

void CSVManager::actualizarContactosVector(Agenda& agenda){
    // Agenda agenda;
    agenda.eliminarElementosVector();

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

        agenda.agregarContactosDesdeCSV(c);
    }
}

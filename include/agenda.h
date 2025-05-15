#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"
#include <vector>

class CSVManager; // Forward declaration

class Agenda{
private:
    std::vector<Contacto> contactos_;
public:
    void agregarContacto(CSVManager& archivoCSV);
    void agregarContactosDesdeCSV(Contacto& c);
    void eliminarElementosVector();
    Contacto& obtenerContactoPorNombre(const std::string& nombre);
    Contacto& obtenerContactoPorTelefono(const std::string& telefono);
    bool buscarContactoPorNombre(const std::string& nombre);
    bool buscarContactoPorTelefono(const std::string& telefono);
    void eliminarContactoPorNombre(const std::string& nombre, CSVManager& archivoCSV);
    void eliminarContactoPorTelefono(const std::string& telefono, CSVManager& archivoCSV);
    void editarContacto(Contacto& contacto, CSVManager& archivoCSV);
    void mostrarCotactos();
};


#endif
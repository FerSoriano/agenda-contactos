#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"
#include <vector>

class Agenda{
private:
    std::vector<Contacto> contactos_;
public:
    void agregarContacto();
    Contacto& obtenerContactoPorNombre(const std::string& nombre);
    bool buscarContactoPorNombre(const std::string& nombre);
    bool buscarContactoPorTelefono(const std::string& telefono);
    void eliminarContactoPorNombre(const std::string& nombre);
    void eliminarContactoPorTelefono(const std::string& telefono);
    void mostrarCotactos();
};


#endif
#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"
#include <vector>

class Agenda{
private:
    std::vector<Contacto> contactos_;
public:
    void agregarContacto();
    Contacto buscarContactoPorNombre(std::string nombre);
    void eliminarContactoPorNombre(std::string nombre);
    void eliminarContactoPorTelefono(std::string telefono);
    void mostrarCotactos();
};


#endif
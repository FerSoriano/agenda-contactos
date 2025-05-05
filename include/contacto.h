#ifndef CONTACTOS_H
#define CONTACTOS_H

#include <string>

class Contacto{
private:
    std::string nombre_;
    std::string telefono_;
    std::string correo_;

public:
    Contacto(const std::string& nombre, const std::string& telefono);
    ~Contacto();

    // getters
    std::string getNombre();
    std::string getTelefono();
    std::string getCorreo();
    void getInfoContacto();

    void actualizarNombre(std::string nombre);
    void actualizarTelefono(std::string telefono);
    void actualizarCorreo(std::string correo);
};

#endif
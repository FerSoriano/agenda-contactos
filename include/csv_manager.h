#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H

#include "contacto.h"
#include <string>
#include <vector>
#include <fstream>

class Agenda; // Forward declaration

class CSVManager{
private:
    std::string nombreArchivo_;
    std::string formatearContactoComoFilaCSV(Contacto& contacto);

public:
    explicit CSVManager(const std::string& nombreArchivo);

    // setters
    void setNombreArchivo(std::string nombreArchivo);
    // getters
    std::string getNombreArchivo();

    bool crearArchivo(); // true si se creo, false si ya existe
    void agregarContacto(Contacto& contacto);
    void sobreEscribirArchivoCSV(std::vector<Contacto>& contactos);


    void actualizarContactosVector(Agenda& agenda);
    /*
        Leer el CSV linea por linea
        mandar llamar a funcion para crear el objeto Contacto
        hacer push back al vector
        seguir con la siguiente linea
    */

};

#endif
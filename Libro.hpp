#pragma once
#include "Volumen.hpp"

class Libro : public Volumen {
private:
    int numLibro;
public:
    Libro();                        // Construye un libro con numero 0
    virtual ~Libro();
    Libro(std::string, int, int);   // Construye un Libro, con Numero de Volumen y Numero de Libro
    std::string mostrar();          // Muestra todos los datos de un Libro
};
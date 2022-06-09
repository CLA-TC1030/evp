#pragma once
#include "Volumen.hpp"

class Libro : public Volumen {
private:
    int numLibro;
public:
    Libro();
    virtual ~Libro();
    Libro(std::string, int, int);
    std::string mostrar();    
};
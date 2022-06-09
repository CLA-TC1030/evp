#pragma once
#include "Volumen.hpp"

class Revista : public Volumen {
private:
    int numRevista;
public:
    Revista();
    virtual ~Revista();
    Revista(std::string, int, int);
    std::string mostrar();    
};
#pragma once
#include "Volumen.hpp"

class Revista : public Volumen {
private:
    int numRevista;
public:
    Revista();                      // Construye una Revista con Volumen X y Num de Revista 0 
    virtual ~Revista();
    Revista(std::string, int, int); // Construye una Revista con Nombre, Numero de Volumen y Numero de Revista
    std::string mostrar();          // Muestra todos los datos de una Revista : Volumen, Nombre de la Revista y Numero de la Revista
};
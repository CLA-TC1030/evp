#pragma once
#include <string>

class Volumen {
protected:
    std::string nombre;
    int numVol;
public:
    Volumen();                      // Crea un volumen X, con un numero 0
    virtual ~Volumen();
    Volumen(std::string, int);      // Construye un volumen con un nombre y numero de volumen
    virtual std::string mostrar()=0;
    void print();                   // Muestra el volumen de cualquier Libro o Revista
};
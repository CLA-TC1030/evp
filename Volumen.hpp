#pragma once
#include <string>

class Volumen {
protected:
    std::string nombre;
    int numVol;
public:
    Volumen();
    virtual ~Volumen();
    Volumen(std::string, int);
    virtual std::string mostrar()=0;
    void print();
};
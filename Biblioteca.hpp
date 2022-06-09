#pragma once
#include "Volumen.hpp"
#include <iostream>
#include <vector>

class Biblioteca {
private:
    std::vector<Volumen *> v;
public:
    Biblioteca();
    ~Biblioteca();
    void print();
    std::string mostrarBiblioteca();
    void incluir(Volumen&);
    Biblioteca operator+(Volumen&);
};
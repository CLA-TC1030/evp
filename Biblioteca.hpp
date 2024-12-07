#pragma once
#include "Volumen.hpp"
#include <iostream>
#include <vector>

class Biblioteca {
private:
    std::vector<Volumen *> v;
public:
    Biblioteca();                       // Constructor por default de la Biblioteca
    ~Biblioteca();
    void incluir(Volumen&);             // Incluye un Volumen cualquiera en la Biblioteca 
    Biblioteca operator+(Volumen&);     // Incluye un Volumen cualquiera en la Biblioteca con el operador + sobrecargado
    std::string mostrarBiblioteca();    // Muestra todos los volumenes de la biblioteca (Libros, Revistas)
    void print();                       // Otra forma de mostrar todos los volumenes de la biblioteca (sin repetir programación de Biblioteca::mostrarBiblioteca)
};
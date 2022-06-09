#include "Volumen.hpp"
#include "Libro.hpp"
#include "Revista.hpp"
#include "Biblioteca.hpp"
#include <iostream>

int main()
{

// Libros individuales -----------------------    
    
    std::cout << "Libros individuales:\n";
    Libro l0;
    Libro l1("OOP in C++",1,1);

    l0.print();
    l1.print();

    Volumen *l=new Libro("OOD in C++",1,2);

    l->print();

// Revistas individuales -----------------------

    std::cout << "\nRevistas individuales:\n";    
    Revista r0;
    Revista r1("Now on OOP in C++",2,3);

    r0.print();
    r1.print();

    Volumen *r=new Revista("Now on OOD in C++",4,5);

    r->print();

// Biblioteca -------------------------------------

    std::cout << "\nBiblioteca:\n";    
    Biblioteca b;

    b.incluir(l0);
    b.incluir(r0);
    b.incluir(l1);
    b.incluir(r1);
    b.incluir(*l);
    b.incluir(*r);

    b.print();

// Sobrecarga de operador en Biblioteca ---------------

    std::cout << "\nBiblioteca con operador + sobrecargado :\n";    
    Biblioteca b2;

    b2 = b2 + l0;
    b2 = b2 + r0;
    b2 = b2 + l1;
    b2 = b2 + r1;
    b2 = b2 + *l;
    b2 = b2 + *r;

    b.print();

    delete l;
    delete r;
}
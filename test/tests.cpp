// Test definitions. Do NOT edit this file!

#include <tuple>

#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch_amalgamated.hpp"

#include "../Libro.hpp"
#include "../Revista.hpp"
#include "../Biblioteca.hpp"

// =====================
// tests for exercises
// ---------------------

TEST_CASE("ex0", "[Libros concretos]")
{
    Libro l0;
    Libro l1("OOP in C++",1,1);

    REQUIRE(l0.mostrar() == "Volumen:0 Libro:Volumen X No. Libro:0");
    REQUIRE(l1.mostrar() == "Volumen:1 Libro:OOP in C++ No. Libro:1");
}

TEST_CASE("ex1", "[Libro polimorfico]")
{
    Volumen *l=new Libro("OOD in C++",1,2);

    REQUIRE(l->mostrar() == "Volumen:1 Libro:OOD in C++ No. Libro:2");

    delete l;
}

TEST_CASE("ex2", "[Revistas concretas]")
{
    Revista r0;
    Revista r1("Now on OOP in C++",2,3);

    REQUIRE(r0.mostrar() == "Volumen:0 Revista:Volumen X No. Revista:0");
    REQUIRE(r1.mostrar() == "Volumen:2 Revista:Now on OOP in C++ No. Revista:3");
}

TEST_CASE("ex3", "[Revistas polimórficas]")
{
    Volumen *r=new Revista("Now on OOD in C++",4,5);

    REQUIRE(r->mostrar() == "Volumen:4 Revista:Now on OOD in C++ No. Revista:5");

    delete r;
}

TEST_CASE("ex4", "[Biblioteca]")
{
    Libro l0;
    Libro l1("OOP in C++",1,1);
    Volumen *l=new Libro("OOD in C++",1,2);

    Revista r0;
    Revista r1("Now on OOP in C++",2,3);
    Volumen *r=new Revista("Now on OOD in C++",4,5);

    Biblioteca b;

    std::string all_v{""};

    b.incluir(l0);
    b.incluir(l1);
    b.incluir(*l);

    b.incluir(r0);
    b.incluir(r1);
    b.incluir(*r);

    all_v += l0.mostrar() + "\n" + l1.mostrar() + "\n" + l->mostrar() + "\n";
    all_v += r0.mostrar() + "\n" + r1.mostrar() + "\n" + r->mostrar() + "\n";


    REQUIRE(b.mostrarBiblioteca() == all_v);

    delete l;
    delete r;
}

TEST_CASE("ex5", "[Biblioteca con operador sobrecargado]")
{
    Libro l0;
    Libro l1("OOP in C++",1,1);
    Volumen *l=new Libro("OOD in C++",1,2);

    Revista r0;
    Revista r1("Now on OOP in C++",2,3);
    Volumen *r=new Revista("Now on OOD in C++",4,5);

    Biblioteca b;

    std::string all_v{""};

    b = b + l0;
    b = b + l1;
    b = b + *l;

    b = b + r0;
    b = b + r1;
    b = b + *r;

    all_v += l0.mostrar() + "\n" + l1.mostrar() + "\n" + l->mostrar() + "\n";
    all_v += r0.mostrar() + "\n" + r1.mostrar() + "\n" + r->mostrar() + "\n";


    REQUIRE(b.mostrarBiblioteca() == all_v);

    delete l;
    delete r;
}
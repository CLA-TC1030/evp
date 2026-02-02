#define CATCH_CONFIG_MAIN // defines main() automatically
#include <catch2/catch.hpp>

#include "../Libro.hpp"
#include "../Revista.hpp"
#include "../Biblioteca.hpp"

// =====================
// tests for exercises
// ---------------------

TEST_CASE("ex0", "[Libros concretos]")
{
    INFO("FUNCIONALIDAD ESPERADA: La clase Libro debe heredar de Volumen y sobrescribir el metodo mostrar() para retornar una cadena con el formato 'Volumen:X Libro:nombre No. Libro:Y'");
    INFO("SUGERENCIA DE PROGRAMACION: Implementa el constructor por defecto inicializando numLibro en 0, el constructor parametrizado recibiendo nombre, numVol y numLibro, y el metodo mostrar() usando std::to_string() para convertir los numeros a cadena");
    
    Libro l0;
    Libro l1("OOP in C++",1,1);

    REQUIRE(l0.mostrar() == "Volumen:0 Libro:Volumen X No. Libro:0");
    REQUIRE(l1.mostrar() == "Volumen:1 Libro:OOP in C++ No. Libro:1");
}

TEST_CASE("ex1", "[Libro polimorfico]")
{
    INFO("FUNCIONALIDAD ESPERADA: El metodo mostrar() de Libro debe funcionar correctamente mediante polimorfismo cuando se accede a traves de un apuntador de tipo Volumen");
    INFO("SUGERENCIA DE PROGRAMACION: Asegurate que el metodo mostrar() en la clase base Volumen sea virtual puro (=0) y que Libro lo sobrescriba. Usa memoria dinamica con new y libera con delete");
    
    Volumen *l=new Libro("OOD in C++",1,2);

    REQUIRE(l->mostrar() == "Volumen:1 Libro:OOD in C++ No. Libro:2");

    delete l;
}

TEST_CASE("ex2", "[Revistas concretas]")
{
    INFO("FUNCIONALIDAD ESPERADA: La clase Revista debe heredar de Volumen y sobrescribir el metodo mostrar() para retornar una cadena con el formato 'Volumen:X Revista:nombre No. Revista:Y'");
    INFO("SUGERENCIA DE PROGRAMACION: Implementa el constructor por defecto inicializando numRevista en 0, el constructor parametrizado recibiendo nombre, numVol y numRevista, y el metodo mostrar() concatenando las cadenas con operador +");
    
    Revista r0;
    Revista r1("Now on OOP in C++",2,3);

    REQUIRE(r0.mostrar() == "Volumen:0 Revista:Volumen X No. Revista:0");
    REQUIRE(r1.mostrar() == "Volumen:2 Revista:Now on OOP in C++ No. Revista:3");
}

TEST_CASE("ex3", "[Revistas polimórficas]")
{
    INFO("FUNCIONALIDAD ESPERADA: El metodo mostrar() de Revista debe funcionar correctamente mediante polimorfismo cuando se accede a traves de un apuntador de tipo Volumen");
    INFO("SUGERENCIA DE PROGRAMACION: El metodo mostrar() debe estar sobrescrito en Revista. Utiliza el destructor virtual en la clase base para garantizar la liberacion correcta de memoria");
    
    Volumen *r=new Revista("Now on OOD in C++",4,5);

    REQUIRE(r->mostrar() == "Volumen:4 Revista:Now on OOD in C++ No. Revista:5");

    delete r;
}

TEST_CASE("ex4", "[Biblioteca]")
{
    INFO("FUNCIONALIDAD ESPERADA: La clase Biblioteca debe almacenar volumenes (Libros y Revistas) en un vector de apuntadores y el metodo mostrarBiblioteca() debe retornar todas las descripciones concatenadas con salto de linea");
    INFO("SUGERENCIA DE PROGRAMACION: Usa std::vector<Volumen*> para almacenar los volumenes. El metodo incluir() debe recibir una referencia y guardar su direccion. En mostrarBiblioteca() itera con un ciclo for y concatena llamando mostrar() de cada volumen");
    
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
    INFO("FUNCIONALIDAD ESPERADA: El operador + debe permitir agregar volumenes a la biblioteca retornando una referencia a la biblioteca modificada para permitir encadenamiento de operaciones");
    INFO("SUGERENCIA DE PROGRAMACION: Sobrecarga el operador + como metodo miembro que recibe Volumen& por referencia, agrega el apuntador al vector con push_back(&vnew) y retorna *this para permitir b = b + vol");
    
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
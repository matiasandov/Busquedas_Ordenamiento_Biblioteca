//
//  Libro.hpp
//  BusqBiblio
//
//  Created by Matías Méndez on 08/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef Libro_hpp
#define Libro_hpp
#include <iostream>
#include <stdio.h>

using namespace std;

class Libro{
private:
    int año;
    
    string nombre;
    
    string autor;
    
    int edicion;
    
    string editorial;
public:
    Libro();
    
    Libro(int, string, string, int, string);
    
    //sobrecargar operador << cout
    friend ostream & operator<<(std::ostream & os, const Libro & li);
    
    int getAño();
    
    string getAutor();
    
    string getEditorial();
    
    string getNombre();
    
    /*comparacion para ordenar ascendete o descendetemente los libros por atributo
     en asc se indicará que eMenor < eMayor
     en desc se indicará que eMenor > eMayor
     */
    
    static bool año_asc(Libro, Libro);
    
    static bool año_desc(Libro, Libro);
    
    static bool aut_asc(Libro, Libro);
    
    static bool aut_desc(Libro, Libro);
    
    static bool edit_asc(Libro, Libro);
    
    static bool edit_desc(Libro, Libro);
    
    static bool edic_asc(Libro, Libro);
    
    static bool edic_desc(Libro, Libro);
    
    static bool nom_asc(Libro, Libro);
    
    static bool nom_desc(Libro, Libro);
    
};



#endif /* Libro_hpp */

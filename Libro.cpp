//
//  Libro.cpp
//  BusqBiblio
//
//  Created by Matías Méndez on 08/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include <stdio.h>
#include "Libro.hpp"


Libro::Libro(){
    año = 0;
    
    nombre = " ";
    
    autor = " ";
    
    edicion = 0;
    
    editorial = " ";
}

Libro::Libro(int a, string n, string au, int _edicion, string _editorial ){
    año = a;
    
    nombre = n;
    
    autor = au;
    
    edicion = _edicion;
    
    editorial = _editorial;
}

ostream & operator<<(ostream & os, const Libro & li)
{
    os << li.año << " " << li.nombre << " " << li.autor << " "  << li.edicion << " " << li.editorial << " " << ::endl;
    
    return os;
}

int Libro::getAño(){
    return año;
}

string Libro::getAutor(){
    return autor;
}

string Libro::getEditorial(){
    return editorial;
}

string Libro::getNombre(){
    return nombre;
}
/*
 static bool año_asc(Libro, Libro);
 
 static bool año_desc(Libro, Libro);
 
 static bool aut_asc(Libro, Libro);
 
 static bool aut_desc(Libro, Libro);
 
 static bool edit_asc(Libro, Libro);
 
 static bool edit_desc(Libro, Libro);
 
 static bool edic_asc(Libro, Libro);
 
 static bool edic_desc(Libro, Libro);
 */

bool Libro::año_asc(Libro co, Libro b){
    return co.año < b.año;
}

bool Libro::año_desc(Libro co, Libro b){
    return co.año > b.año;
}


bool Libro::nom_asc(Libro a, Libro b){
    return a.nombre < b.nombre;
}

bool Libro::nom_desc(Libro a, Libro b){
    return a.nombre > b.nombre;
}

bool Libro::aut_asc(Libro a, Libro b){
    return a.autor < b.autor;
}

bool Libro::aut_desc(Libro a, Libro b){
    return a.autor > b.autor;
}



bool Libro::edic_asc(Libro a, Libro b){
    return a.edicion < b.edicion;
}

bool Libro::edic_desc(Libro a, Libro b){
    return a.edicion > b.edicion;
}



bool Libro::edit_asc(Libro a, Libro b){
    return a.editorial < b.editorial;
}

bool Libro::edit_desc(Libro a, Libro b){
    return a.editorial > b.editorial;
}

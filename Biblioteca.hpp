//
//  Biblioteca.hpp
//  BusqBiblio
//
//  Created by Matías Méndez on 08/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef Biblioteca_hpp
#define Biblioteca_hpp

#include <stdio.h>
#include "Libro.hpp"
#include "Ordenamiento.hpp"
#include <iostream>
#include <vector>

using namespace std;


class Biblioteca{
private:
    //debo de tener un atributo privado de libros
    vector<Libro> libros;
    
public:
    
    //constructor prederteminado falta
    Biblioteca();
    //destrcutor: elimina todo el vector para no almacenar
    
    //los métodos se harán template para que sean reutilizables
    
    //con static creo que ya no es necesario hacer un constructor
    void adicionar();
    
    void eliminar(string);
    
    //para estos métodos, desde añoAntes hasta debemos sobrecargar el operador de << para libro para poder imprimirlos libros que cumplan la condicion con un formato generico
    void añoAntes(int);
    
    void añoDespues(int);
    
    void añoRango(int, int);
    
    void busAutor(string);
    
    void busEditorial(string);
    
    void ordena1();
    
    //______desde burbuja() hasta compara() es todo lo que se necesita para la función ordena, el parametro de funcion booleana que se les pasa es el de compara()
    
        //el tercer parametro int será el numero de opcion para getAtributo(opcion)
    /*static vector<T> burbuja(vector<T>, bool(*)(T,T), int);
    
    static vector<T> insercion(vector<T>, bool(*)(T,T), int);
    
    static vector<T> seleccion(vector<T>, bool(*)(T,T), int );
    
    static vector<T> quicksort(vector<T>, int, int, bool(*)(T,T), int);
    
    
    
    static vector<T> merge(vector<T>, int, int, int, bool (*) (T, T), int);
    
    static vector<T> mergesort(vector<T>, int, int, bool(*)(T,T), int);
    
    
    
    static bool asc(T,T);
    
    static bool desc(T,T);*/
    
    //funcion para getAtributo que se quiera elegir en la funcion de ordena
   
    //_______________

    void ordena(int, int, int);
    //se indica que se debe pasar una funcion de un algoritmo cuyo parametros es un vector y la funcion de sobrescrita de compara, el algoritmo de busqeda devuelve un vector que se imprimirá aquí
 
    
 
    

};
//___________________________________________________________





#endif /* Biblioteca_hpp */

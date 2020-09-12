//
//  main.cpp
//  BusqBiblio
//
//  Created by Matías Méndez on 08/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//
#include "Biblioteca.hpp"
#include "Libro.hpp"
#include <iostream>
#include <vector>
using namespace std;



/*
hice la clase libro template y cre que por eso no funciona, lo hice para lo de getAtributo(op)
 

*/

void menu( Biblioteca Bib ){
    
    //Imprime las opciones que va a tener el sistema
    cout << "\nMenu de opciones: \n";
    cout << "1. Adicionar libros. \n";
    cout << "2. Eliminar libros \n\n";
    cout << "3. Mostrar los libros que se hayan publicado antes de un año dado \n";
    cout << "4. Mostrar los libros que se hayan publicado después de un año dado. \n";
    cout << "5. Mostrar los libros que se hayan publicado en un período de tiempo determinado (entre un rango de años) \n";
    cout << "6.Mostrar los libros escritos por un autor \n";
    cout << "7. Mostrar los libros publicados por una editorial\n";
    cout << "8. Mostrar los libros ordenados por el criterio (título, año o edición), algoritmo de ordenamiento y dirección (ascendente o descendente) seleccionados por el usuario\n";
    cout << "9. Salir";
    
    
    
    
    int opcion = 0;
       
       //Ciclo para que el sistema siga corriendo mientras no elija la opcion salir.
       while(opcion < 9 && opcion > -1){
           
           //Leer indice que selecciona la opcion del menu
           cout << "\n Ingresa opción deseada: " ;
           cin >>opcion;
           
           //Switch donde dependiendo la eleccion efectua un diferente procedimiento
           switch(opcion){
                   
                   
               case 1:{
                   
                   Bib.adicionar();
                   
                   break;
               }
                   
               case 2:{
                   string nombre;
                   cout << " ingresa nombre del libro a eliminar ";
                   cin >> nombre;
                   Bib.eliminar(nombre);
                   break;
               }
                   
               case 3:{
                   int añoA ;
                   cout << " ingresa año a partir del cual se buscara el objeto  :";
                   cin >> añoA;
                   Bib.añoAntes(añoA);
                break;
               }
               
                   
               case 4:{
                   int añoD;
                   cout << " ingresa año a partir del cual se buscara el objeto  :";
                   cin >> añoD;
                   Bib.añoDespues(añoD);
                   break;
               }
                   
               case 5:{
                   int añoA5, añoD5;
                   cout << "\n ingresa primer año del rango ";
                   cin >> añoA5;
                   cout << "\n ingresa último año del rango ";
                   cin >> añoD5;
                   Bib.añoRango(añoA5, añoD5);
                   break;}
                   
                case 6:{
                    string autor;
                    cout << " \n ingresa autor ";
                    cin >> autor;
                   Bib.busAutor(autor);
                   break;}
                   
               case 7:{
                    string edi;
                    cout << " \n ingresa editorial ";
                    cin >> edi;
                   Bib.busEditorial( edi);
                   break;}
                   
               case 8: {
                 /* Invocar al método ordenar */
                 int criterio = 1;
                 int algoritmo = 1;
                 int orden = 1;
                 
                 do {
                     std::cout << "Selecciona el atributo de ordenamiento: " << std::endl;
                     std::cout << "1 - Nombre del libro" << std::endl;
                     std::cout << "2 - Año" << std::endl;
                     std::cout << "3 - Edicion" << std::endl;
                     std::cin >> criterio;
                 }while (criterio < 1 || criterio > 3);
                     
                 do {
                     std::cout << "Selecciona el algoritmo de ordenamiento: " << std::endl;
                     std::cout << "1 - Burbuja" << std::endl;
                     std::cout << "2 - Selección" << std::endl;
                     std::cout << "3 - Inserción" << std::endl;
                     std::cout << "4 - QuickSort" << std::endl;
                     std::cout << "5 - MergeSort" << std::endl;
                     std::cin >> algoritmo;
                 }while (algoritmo < 1 || algoritmo > 5);
                 
                 do {
                     std::cout << "Selecciona el orden: " << std::endl;
                     std::cout << "1 - Ascendente" << std::endl;
                     std::cout << "2 - Descendente" << std::endl;
                     std::cin >> orden;
                 }while (orden < 1 || orden > 2);
                 
                
                Bib.ordena(criterio, algoritmo, orden);
                break;
                    
                }
                
                   
                   
           }//switch
    
        }//while
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
  
    
    


    //libros.push_back(l6);
    Biblioteca bib;
    menu(bib);
    
    return 0;

    
}

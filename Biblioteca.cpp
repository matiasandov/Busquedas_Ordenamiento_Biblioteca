//
//  Biblioteca.cpp
//  BusqBiblio
//
//  Created by Matías Méndez on 10/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#include <stdio.h>
#include "Biblioteca.hpp"

Biblioteca::Biblioteca(){
    
    Libro l1(1990, "greg", "john doe", 1, "nose");
    Libro l2(1993, "bob esponja", "matias", 1, "nose1");
    Libro l3(1992, "bob esponja2", "matias", 2, "nose");
    Libro l4(1992,"greg2", "john doe", 2, "nose1" );
    Libro l5(1995,"greg3", "john doe", 3, "nose");

    libros.push_back(l1);
    libros.push_back(l2);
    libros.push_back(l3);
    libros.push_back(l4);
    libros.push_back(l5);
    
    
}








void Biblioteca::adicionar(  ){
    int a;
    string n;
    string au;
    int _edicion;
    string _editorial;
    
    cout << "\n Ingresar año del libro: ";
    cin >> a;
    
    cout << "\n Ingresar nombre del libro: ";
    cin >> n;
    
    cout << "\n Ingresar autor del libro: \n";
    cin >> au;
    
    cout << "\n Ingresar numero de edicion del libro: \n";
    cin >> _edicion;
    
    cout << "\n Ingresar editorial del libro: \n";
    cin >> _editorial;
    
    Libro lib(a, n, au, _edicion,  _editorial);
    libros.push_back(lib);
    //creo que chance aqui debo hacer sobrecarga de <<
    cout << " Objeto agregado: " << lib;
}



//buscado con busqueda binaria

void Biblioteca::eliminar( string nombre){
    long int size = libros.size();
    
    int i = 0;
    int encontrado = -1;
     
    while (encontrado == -1 && i< size ) {
        if ( libros[i].getNombre() == nombre) {
            
            encontrado = i;
            libros.erase(libros.begin() + encontrado);
            cout << "Libro encontrado y eliminado";
            
            ++i;

         }
         ++i;
     }//while
    if (encontrado == -1){
        cout << "nada encontrado";
    }
}

//Opcion 3
void Biblioteca::añoAntes(int año){
    long int size = libros.size();
    
    int i = 0;
    int cont = 0;
     
    while ( i < size) {
        if ( libros[i].getAño() < año) {
            cout << libros[i];
            cont = cont +1;
         }//if
         ++i;
     }//while
    cout << "Objetos encontrados: " << cont << endl;
}



void Biblioteca::añoDespues( int año){
    int cont = 0;
    int i = 0;
    long int size = libros.size();
    while ( i< size ) {
        if ( libros[i].getAño() > año) {
             
            cout << libros[i];
            cont = cont +1;
         }
         ++i;
     }//while
    cout << "Objetos encontrados: " << cont << endl;
}


void Biblioteca::añoRango( int año1, int año2){
    long int size = libros.size();
    int i = 0;
    int cont = 0;
    
    while ( i< size ) {
        if ( (libros[i].getAño() > año1) && (libros[i].getAño() < año2) ) {
            cout << libros[i];
            cont = cont +1;
         }
         ++i;
        cout << "Objetos encontrados: " << cont << endl;
     }//while
  

}


void Biblioteca::busAutor( string autor){
    int cont = 0;
    int i = 0;
    while ( i< libros.size() ) {
        if ( libros[i].getAutor() == autor) {
            cout << libros[i];
             cont = cont +1;
         }
         ++i;
     }//while
    cout << "Objetos encontrados: " << cont << endl;
}


void Biblioteca::busEditorial( string editorial){
    int cont = 0;
    int i = 0;
    long int size = libros.size();
     
    while ( i< size ) {
        if ( libros[i].getEditorial() == editorial) {
            cout << libros[i];
            cont = cont +1;
         }//if
         ++i;
     }//while
    cout << "Objetos encontrados: " << cont << endl;
}


/*static bool aut_asc(Libro, Libro);

static bool aut_desc(Libro, Libro);

static bool edit_asc(Libro, Libro);

static bool edit_desc(Libro, Libro);

static bool edic_asc(Libro, Libro);

static bool edic_desc(Libro, Libro);

static bool nom_asc(Libro, Libro);

static bool nom_desc(Libro, Libro);*/


void Biblioteca::ordena(int criterio, int algoritmo, int orden){
    int tam = (int) libros.size()-1;
        switch (algoritmo) {
                
            //__________________________________________
            case 1:{ /* Burbuja */
                switch (criterio) {
                    case 1:{ /* Nombre */
                        if (orden == 1) {
                          libros =  Ordenamiento<Libro>::burbuja(libros, Libro::nom_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }//if
                        else {
                          libros = Ordenamiento<Libro>::burbuja(libros, Libro::nom_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }//else
                        break;}
                        
                    case 2:{ /* Autor */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::burbuja(libros, Libro::año_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }//if
                        else {
                          libros = Ordenamiento<Libro>::burbuja(libros, Libro::año_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }//else
                        break;}
                        
                        
                    case 3:{ /* Año */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::burbuja(libros, Libro::edic_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                          libros = Ordenamiento<Libro>::burbuja(libros, Libro::edic_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;}
                }//switch case 1
                break;
            
                
            //__________________________________________
            case 3:{ /* Burbuja */
                switch (criterio) {
                    case 1: /* Nombre */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::insercion(libros, Libro::nom_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                           libros = Ordenamiento<Libro>::insercion(libros, Libro::nom_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                        
                    case 2: /* Autor */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::insercion(libros, Libro::año_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                          libros = Ordenamiento<Libro>::insercion(libros, Libro::año_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                    case 3: /* Año */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::insercion(libros, Libro::edic_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                          libros = Ordenamiento<Libro>::insercion(libros, Libro::edic_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                }
                break;
            }//____________Burbuja
            
            //__________________________________________
            case 2:{ /* Burbuja */
                switch (criterio) {
                    case 1: /* Nombre */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::seleccion(libros, Libro::nom_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        else {
                           libros = Ordenamiento<Libro>::seleccion(libros, Libro::nom_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        break;
                        
                    case 2: /* Autor */
                        if (orden == 1) {
                            libros = Ordenamiento<Libro>::seleccion(libros, Libro::año_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        else {
                          libros = Ordenamiento<Libro>::seleccion(libros, Libro::año_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                    case 3: /* Año */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::seleccion(libros, Libro::edic_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        else {
                          libros = Ordenamiento<Libro>::seleccion(libros, Libro::edic_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        break;
                }
                break;
            }//____________Burbuja
                
            //__________________________________________
            case 4:{ /* quicksort*/
                switch (criterio) {
                    case 1: /* Nombre */
                        if (orden == 1) {
                            libros = Ordenamiento<Libro>::quicksort(libros,0, tam, Libro::nom_asc);
                            
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        else {
                           libros = Ordenamiento<Libro>::quicksort(libros,0, tam, Libro::nom_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                        
                    case 2: /* Autor */
                        if (orden == 1) {
                           libros =  Ordenamiento<Libro>::quicksort(libros,0, tam, Libro::año_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                          libros = Ordenamiento<Libro>::quicksort(libros,0, tam, Libro::año_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                    case 3: /* Año */
                        if (orden == 1) {
                           libros = Ordenamiento<Libro>::quicksort(libros,0, tam, Libro::edic_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                           libros = Ordenamiento<Libro>::quicksort(libros,0, tam, Libro::edic_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                }
                break;
            }//____________Burbuja
                
            case 5:{ /* Burbuja */
                switch (criterio) {
                    case 1: /* Nombre */
                        if (orden == 1) {
                            libros = Ordenamiento<Libro>::mergesort(libros,0, tam, Libro::nom_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                            
                        }
                        else {
                           libros = Ordenamiento<Libro>::mergesort(libros,0, tam, Libro::nom_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                        
                    case 2: /* Autor */
                        if (orden == 1) {
                            libros = Ordenamiento<Libro>::mergesort(libros,0, tam, Libro::año_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                          libros = Ordenamiento<Libro>::mergesort(libros,0, tam, Libro::año_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                    case 3: /* Año */
                        if (orden == 1) {
                            libros = Ordenamiento<Libro>::mergesort(libros,0, tam, Libro::edic_asc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        else {
                           libros = Ordenamiento<Libro>::mergesort(libros,0, tam, Libro::edic_desc);
                            copy(libros.begin(), libros.end(), std::ostream_iterator<Libro>(std::cout, " "));
                        }
                        break;
                }
                break;
                

                        
                
            
                
            default:
                break;
        }

        
    }
       
        }
}

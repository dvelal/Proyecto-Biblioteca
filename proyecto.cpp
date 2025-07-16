#include <iostream>
#include <string>
#include <ctime>
#include "struclibro.h"
#include "struccliente.h"
#include "utilidades.h"
#include "libros.h"
using namespace std;

int main() {
    // Libreria Ctime
    srand(time(0));  
    Libro libros[1000];
    Cliente cliente[1000];
    int contadorLibros = 0;
    int contadorcliente = 0;
    int op, dni, edad, subop, codigo;
    char op1;
    string titulo, autor, nombre, cate, subcate;
    int edicion, anio;

    cargarLibrosPredefinidos(libros, contadorLibros);

    do {
        limpiarPantalla();

        cout << magenta << "===============================\n" << reset;
        cout << azul << "     BIBLIOTECA VIRTUAL\n" << reset;
        cout << magenta << "===============================\n" << reset;

        cout << rojo << "  [1] " <<  reset << "Buscar libro\n";
        cout << rojo << "  [2] "<< reset << "Agregar un libro\n";
        cout << rojo << "  [3] " << reset << "Mostrar libros\n";
        cout << rojo << "  [4] " << reset << "Prestar un libro\n";
        cout << rojo << "  [5] " << reset << "Devolver un libro\n";
        cout << rojo << "  [6] " << reset << "Libros Alquilados\n";
        cout << rojo << "  [0] " << reset << "Salir\n";

        cout << amarillo << "\nSeleccione una opcion: " << reset; cin >> op;
        cin.ignore(); 
        
        limpiarPantalla();

        switch (op) {
            case 1: {
                cout << rojo << "\n1. " << azul << "Buscar por titulo y autor\n" << reset;
                cout << rojo << "2. " <<  azul << "Buscar por categoria y subcategoria\n" << reset;
                cout << "||" << amarillo << "Seleccione una opcion: " << reset << "||"<< endl; cin >> subop;
                cin.ignore();
                switch (subop){
                    case 1:{
                        cout <<  verde << "Ingrese el titulo del libro a buscar: " << reset; getline(cin, titulo);  
                        cout << verde << "Ingrese el autor del libro a buscar: " << reset; getline(cin, autor);

                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor);

                        pausar();
                        break;
                    }

                    case 2:{
                        mostrarCategorias(libros, contadorLibros);
                        cout << verde << "\nIngrese la CATEGORIA exacta: " << reset; getline(cin, cate);
                        mostrarSubcategorias(libros, contadorLibros, cate);
                        cout << verde << "\nIngrese la SUBCATEGORIA exacta: " << reset; getline(cin, subcate);

                        limpiarPantalla();

                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor); 

                        pausar();  
                        break; 
                    }
                    default:
                        cout << rojo << "No existe la opcion elegida"<< reset << endl;
                        pausar();
                        break;
                }
                break;
            }

            case 2: {
                cout << magenta << "Titulo del libro: " << reset; getline(cin, titulo);
                cout << cian << "Autor: " << reset; getline(cin, autor);
                cout << magenta << "Edicion: " << reset; cin >> edicion;
                cin.ignore();
                cout << cian << "Anio: " << reset; cin >> anio;
                cin.ignore();
                cout << magenta << "Categoria: " << reset; cin >> cate;
                cin.ignore();
                cout << cian << "Subcategoria: " << reset; cin >> subcate;

                leerLibro(libros[contadorLibros], titulo, autor, edicion, anio, cate, subcate);

                contadorLibros++;
                cout << verde << "Libro agregado con exito.\n" << reset;

                pausar();
                break;
            }

            case 3: {
                mostrarLibros(libros, contadorLibros);

                pausar();
                break;
            }

            case 4: {
                mostrarLibros(libros,contadorLibros); 
                cout << amarillo << " || Ingresa los datos del libro ||" << reset << endl;
                cout << azul << "Titulo: " << reset; getline(cin, titulo);
                cout << azul << "Autor: " << reset; getline(cin, autor);
                cout << amarillo << " || Ingresa tus datos personales|| " << reset << endl;
                cout << azul << "Ingresa tu nombre (Primer nombre y apellido): " << reset; getline(cin, nombre);
                cout << azul << "Ingresa tu edad: " << reset; cin >> edad;
                cin.ignore();
                cout << azul << "Ingresa tu DNI: " << reset; cin >> dni;
                cin.ignore();

                leercliente(cliente[contadorcliente], nombre, edad, dni);

                contadorcliente++;

                prestarLibro(libros, contadorLibros, titulo, autor, dni);

                pausar();
                break;
            }
            case 5: {
                cout << "----------------------------------------------" << endl;
                cout << amarillo << "Datos del libro a devolver\n" << reset;
                cout << "----------------------------------------------" << endl;
                cout << azul << "Titulo del libro: " << reset; getline(cin, titulo);
                cout << azul << "Autor del libro: " << reset; getline(cin, autor);
                cout << azul << "DNI del cliente: " << reset; cin >> dni;
                cout << verde << "Codigo de seguridad del prestamo: " << reset; cin >> codigo;

                devolverLibro(libros, contadorLibros, titulo, autor, dni, codigo);

                pausar();
                break;
            }

            case 6: {
                mostrarClientes(cliente, libros, contadorcliente);
                pausar();
                break;
            }
            case 0:
                cout << rojo << "¿Seguro que desea salir (S/N)? " << reset; cin >> op1;
                switch (op1){
                    case 'S':
                    cout << verde << "Saliendo del programa...\n" << reset;
                    pausar();
                    break;
                    case 'N':
                    op++;
                    break;       
                }
                break;

            default:
                cout << rojo << "Opcion invalida." << reset << endl;

                pausar();
        }

        limpiarPantalla();

    } while (op != 0);

    return 0;
}

#include <iostream>
#include <string>
#include <ctime>
#include "struclibro.h"
#include "struccliente.h"
#include "utilidades.h"
#include "libros.h"
using namespace std;

int main() {
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
        cout << rojo << "  [0] " << reset << "Salir\n";

        cout << "\nSeleccione una opcion: "; cin >> op;
        cin.ignore(); 
        
        limpiarPantalla();

        switch (op) {
            case 1: {
                cout << "\n1. Buscar por titulo y autor\n";
                cout << "2. Buscar por categoria y subcategoria\n";
                cout << "Seleccione una opcion: "; cin >> subop;
                cin.ignore();
                switch (subop){
                    case 1:{
                        cout << "Ingrese el titulo del libro a buscar: "; getline(cin, titulo);  
                        cout << "Ingrese el autor del libro a buscar: "; getline(cin, autor);

                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor);

                        pausar();
                        break;
                    }

                    case 2:{
                        mostrarCategorias(libros, contadorLibros);
                        cout << "\nIngrese la CATEGORIA exacta: "; getline(cin, cate);
                        mostrarSubcategorias(libros, contadorLibros, cate);
                        cout << "\nIngrese la SUBCATEGORIA exacta: "; getline(cin, subcate);

                        limpiarPantalla();

                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor); 

                        pausar();  
                        break; 
                    }
                    default:
                        cout << "No existe la opcion elegida"<< endl;
                        pausar();
                        break;
                }
                break;
            }

            case 2: {
                cout << "Titulo del libro: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "Edicion: "; cin >> edicion;
                cin.ignore();
                cout << "Anio: "; cin >> anio;
                cin.ignore();
                cout << "Categoria: "; cin >> cate;
                cin.ignore();
                cout << "Subcategoria: "; cin >> subcate;

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
                cout << "-------------------------------------Ingresa los datos del libro----------------------------------------------" << endl;
                cout << "Titulo del libro a prestar: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "----------------------------------------Ingresa tus datos personales----------------------------------------- " << endl;
                cout << "Ingresa tu nombre (Primer nombre y apellido): "; getline(cin, nombre);
                cout << "Ingresa tu edad: "; cin >> edad;
                cin.ignore();
                cout << "Ingresa tu DNI: "; cin >> dni;
                cin.ignore();

                leercliente(cliente[contadorcliente], nombre, edad, dni);

                contadorcliente++;

                prestarLibro(libros, contadorLibros, titulo, autor, dni);

                pausar();
                break;
            }
            case 5: {
                cout << "-------------------------------------Datos del libro a devolver----------------------------------------------\n";
                cout << "Titulo del libro: "; getline(cin, titulo);
                cout << "Autor del libro: "; getline(cin, autor);
                cout << "DNI del cliente: "; cin >> dni;
                cout << "Codigo de seguridad del prestamo: "; cin >> codigo;

                devolverLibro(libros, contadorLibros, titulo, autor, dni, codigo);

                pausar();
                break;
            }
            case 0:
                cout << "¿Seguro que desea salir (S/N)? "; cin >> op1;
                switch (op1){
                    case 'S':
                    cout << "Saliendo del programa...\n";
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

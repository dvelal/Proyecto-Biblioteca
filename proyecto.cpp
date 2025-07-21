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
    int op, dni, edad, subop, codigo, id;
    char op1;
    string titulo, autor, nombre, cate, subcate;
    int edicion, anio;

    cargarLibrosPredefinidos(libros, contadorLibros);

    do {
        limpiarPantalla();

        cout << magenta << "===============================\n" << reset;
        cout << azul << "     BIBLIOTECA VIRTUAL\n" << reset;
        cout << magenta << "===============================\n" << reset;

        cout << rojo << "  [1] " << reset << "Buscar libro\n";
        cout << rojo << "  [2] " << reset << "Agregar un libro\n";
        cout << rojo << "  [3] " << reset << "Mostrar libros\n";
        cout << rojo << "  [4] " << reset << "Prestar un libro\n";
        cout << rojo << "  [5] " << reset << "Devolver un libro\n";
        cout << rojo << "  [6] " << reset << "Libros Prestados\n";
        cout << rojo << "  [0] " << reset << "Salir\n";

        cout << amarillo << "\nSeleccione una opcion: " << reset;
        cin >> op;
        if (!validarEntradaNumerica()) {
            cout << rojo << "Entrada invalida. Ingrese un numero.\n" << reset;
            pausar();
            continue;
        }
        cin.ignore();

        limpiarPantalla();

        switch (op) {
            case 1: {
                cout << rojo << "\n1. " << azul << "Buscar por titulo y autor\n" << reset;
                cout << rojo << "2. " << azul << "Buscar por categoria y subcategoria\n" << reset;
                cout << amarillo << "Seleccione una opcion: " << reset;
                cin >> subop;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "Entrada invalida.\n" << reset;
                    pausar();
                    break;
                }
                cin.ignore();
                switch (subop) {
                    case 1:
                        solicitarDato(verde + string("Ingrese el titulo del libro: ") + reset, titulo);
                        solicitarDato(verde + string("Ingrese el autor del libro: ") + reset, autor);
                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor);
                        break;
                    case 2:
                        mostrarCategorias(libros, contadorLibros);
                        solicitarDato(verde + string("\nIngrese la CATEGORIA exacta: ") + reset, cate);
                        mostrarSubcategorias(libros, contadorLibros, cate);
                        solicitarDato(verde + string("\nIngrese la SUBCATEGORIA exacta: ") + reset, subcate);
                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor);
                        break;
                    default:
                        cout << rojo << "No existe la opcion elegida\n" << reset;
                        break;
                }
                pausar();
                break;
            }

            case 2: {
                solicitarDato(magenta + string("Titulo del libro: ") + reset, titulo);
                solicitarDato(cian + string("Autor: ") + reset, autor);

                cout << magenta << "Edicion: " << reset;
                cin >> edicion;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "Entrada invalida.\n" << reset;
                    pausar(); break;
                }
                cin.ignore();

                cout << cian << "Anio: " << reset;
                cin >> anio;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "Entrada invalida.\n" << reset;
                    pausar(); break;
                }
                cin.ignore();

                solicitarDato(magenta + string("Categoria: ") + reset, cate);
                solicitarDato(cian + string("Subcategoria: ") + reset, subcate);

                leerLibro(libros[contadorLibros], contadorLibros + 1, titulo, autor, edicion, anio, cate, subcate);
                contadorLibros++;

                cout << verde << "Libro agregado con exito.\n" << reset;
                pausar();
                break;
            }

            case 3:
                mostrarLibros(libros, contadorLibros);
                pausar();
                break;

            case 4:  {
                mostrarLibros(libros, contadorLibros);
    
                cout << azul << "Ingrese el ID del libro a prestar: " << reset;
                cin >> id;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "ID invalido.\n" << reset;
                    pausar(); break;
                }
                cin.ignore();

                int idx = buscarLibroPorID(libros, contadorLibros, id);
                if (idx == -1) {
                    cout << rojo << "No se encontro un libro con ese ID.\n" << reset;
                    pausar(); break;
                }

                if (libros[idx].estado != "disponible") {
                    cout << rojo << "Ese libro ya fue prestado.\n" << reset;
                    pausar(); break;
                }

                solicitarDato(azul + string("Nombre del cliente: ") + reset, nombre);

                cout << azul << "Edad: " << reset;
                cin >> edad;
                if (!validarEntradaNumerica() || edad <= 0) {
                    cout << rojo << "Edad invalida.\n" << reset;
                    pausar(); break;
                }
                cin.ignore();

                cout << azul << "DNI: " << reset;
                cin >> dni;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "DNI invalido.\n" << reset;
                    pausar(); break;
                }
                cin.ignore();

                if (leercliente(cliente[contadorcliente], cliente, nombre, edad, dni, contadorcliente)){
                    contadorcliente++;
                    prestarLibro(libros, contadorLibros, libros[idx].titulo, libros[idx].autor, dni);
                }
                pausar();
                break;
                }
            case 5: {
                mostrarLibrosPrestados(libros, contadorLibros);
                cout << azul << "\nIngrese el ID del libro a devolver: " << reset;
                cin >> id;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "ID invalido.\n" << reset;
                    pausar();
                    break;
                }
                cout << azul << "DNI del cliente: " << reset;
                cin >> dni;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "DNI invalido.\n" << reset;
                    pausar();
                    break;
                }
                cout << azul << "Codigo de seguridad: " << reset;
                cin >> codigo;
                if (!validarEntradaNumerica()) {
                    cout << rojo << "Codigo invalido.\n" << reset;
                    pausar();
                    break;
                }
                if (devolverLibro(libros, contadorLibros, id, dni, codigo)) {
                    cout << verde << "Libro devuelto correctamente.\n" << reset;
                } else {
                    cout << rojo << "No se pudo devolver el libro. Verifique los datos.\n" << reset;
                }
                pausar();
                break;
                }
            case 6: {
                mostrarClientes(cliente, libros, contadorcliente, contadorLibros);
                pausar();
                break;
                }
            case 0: {
                cout << rojo << "¿Seguro que desea salir (S/N)? " << reset;
                cin >> op1;
                op1 = toupper(op1);
                if (op1 == 'S') {
                    cout << verde << "Saliendo del programa...\n" << reset;
                    pausar();
                } else if (op1 == 'N') {
                    op = -1;
                } else {
                    cout << rojo << "Opcion invalida. Regresando al menu.\n" << reset;
                    op = -1;
                    pausar();
                }
                break;
                }
            default:{
                cout << rojo << "Opcion invalida." << reset << endl;
                pausar();
                }
        }

        limpiarPantalla();
    } while (op != 0);

    return 0;
}
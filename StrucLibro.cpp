#include "struclibro.h"
#include "utilidades.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void mostrarCategorias(Libro libros[], int cantidad) {
    bool encontrado = false;
    cout << amarillo << "\n|| Categorias disponibles:||\n" << reset;
    for (int i = 0; i < cantidad; i++) {
        bool repetido = false;
        for (int j = 0; j < i; j++) {
            if (libros[i].categoria == libros[j].categoria) {
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            cout << "- " << libros[i].categoria << endl;
        }
    }
}

void mostrarSubcategorias(Libro libros[], int cantidad, string categoria) {
    bool encontrado = false;
    cout << amarillo << "\n|| Subcategorias en " << categoria << ": ||\n" << reset;
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].categoria == categoria) {
            bool repetido = false;
            for (int j = 0; j < i; j++) {
                if (libros[i].subcategoria == libros[j].subcategoria &&
                    libros[i].categoria == libros[j].categoria) {
                    repetido = true;
                    break;
                }
            }
            if (!repetido) {
                cout << "- " << libros[i].subcategoria << endl;
            }
        }
    }
}

void mostrarLibros(Libro libros[], int cantidad) {
    cout << amarillo << "\n || Lista de libros registrados: || \n" << reset;
    cout << endl;
    // El texto se alinea a la izquierda 
    cout << left
        << setw(60) << "Titulo"        // imprime "Titulo" con 60 espacios de ancho
        << setw(30) << "Autor"         // imprime "Autor" con 30 espacios
        << setw(10) << "Edicion"       // imprime "Edicion" con 10 espacios
        << setw(10) << "Anio"          // "Anio" con 10 espacios
        << setw(12) << "Categoria"     // "Categoria" con 12 espacios
        << setw(23) << "Subcategoria"  // "Subcategoria" con 23 espacios
        << setw(15) << "Estado" << endl; // "Estado" con 15 espacios

    cout << string(157, '-') << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << left
             << setw(60) << libros[i].titulo 
             << setw(30) << libros[i].autor
             << setw(10) << libros[i].edicion
             << setw(10) << libros[i].anio
             << setw(12) << libros[i].categoria
             << setw(15) << libros[i].subcategoria;
            if (libros[i].estado == "disponible")
                cout << left << setw(15) << azul << libros[i].estado << reset << endl;
            else
                cout << left << setw(15) << rojo << libros[i].estado << reset << endl;
    }
}


void buscarLibro(Libro libros[], int cant, int elegir , string categoria, string subcategoria, string titulo, string autor) {
    bool encontra = false;
    if (elegir == 1){
        for (int i = 0; i < cant; i++){
            if (libros[i].titulo == titulo && libros[i].autor == autor){
                cout << verde << "\nLibro encontrado:\n" << reset;
                imprimelibro(libros[i]);
                encontra=true;
            }
        }
        if (!encontra){
            cout << rojo << "No existe el libro" << reset << endl;
        }
    }

    if (elegir == 2){
        cout << amarillo << "\n|| Libros encontrados: ||\n" << reset;
        for (int i = 0; i < cant; i++) {
            if (libros[i].categoria == categoria && libros[i].subcategoria == subcategoria) {
                imprimelibro(libros[i]);
                cout << endl;
                encontra = true;
            }
        }
        if (!encontra) {
            cout << rojo << "No hay libros encontrados" << reset;
        }
    }
}

void leerLibro(Libro &l, string titulo, string autor, int edicion, int anio, string cate, string subcate) {
    l.titulo = titulo;
    l.autor = autor;
    l.edicion = edicion;
    l.anio = anio;
    l.categoria = cate;
    l.subcategoria = subcate;
}

void imprimelibro(Libro &l){
    cout << "Libro: " << l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "Edicion: " << l.edicion << endl;
    cout << "Anio: " << l.anio << endl;
    if (l.estado == "disponible")
        cout << "Estado: " << azul << l.estado << reset << endl;
    else
        cout << "Estado: " << rojo << l.estado << reset << endl;
        cout << "Categoria: " << l.categoria << endl;
        cout << "Subcategoria: " << l.subcategoria << endl; 
}

void prestarLibro(Libro libros[], int cant, string titulo, string autor, int dni) {
    for (int i = 0; i < cant; i++) {
        if (libros[i].titulo == titulo && libros[i].autor == autor) {
            if (libros[i].estado == "prestado") {
                cout << amarillo << "Este libro ya está prestado.\n" << reset;
            } 
            else {
                libros[i].estado = "prestado";
                libros[i].dni_cliente = dni;
                libros[i].codigo_seguridad = rand() % 9999 + 1000; 
                cout << verde << "Libro prestado con exito al cliente con DNI: " << dni << reset << endl;
                cout << cian << "Codigo de seguridad del prestamo: " << reset << libros[i].codigo_seguridad << endl;
            }
            return;
        }
    }
    cout << rojo << "Libro no encontrado.\n" << reset;
}

void devolverLibro(Libro libros[], int cant, string titulo, string autor, int dni, int codigo_input) {
    for (int i = 0; i < cant; i++) {
        if (libros[i].titulo == titulo && libros[i].autor == autor) {
            if (libros[i].estado == "disponible") {
                cout << amarillo << "Ese libro ya esta disponible.\n" << reset;
            } 
            else if (libros[i].dni_cliente != dni) {
                cout << rojo << "DNI incorrecto. No puedes devolver un libro que no has prestado.\n" << reset;
            } 
            else {
                if (libros[i].codigo_seguridad == codigo_input) {
                    libros[i].estado = "disponible";
                    libros[i].codigo_seguridad = 0; 
                    cout << verde << "Libro devuelto con exito.\n" << reset;
                }
                else {
                    cout << rojo << "Codigo de seguridad incorrecto. No se puede devolver el libro.\n" << reset;
                }
            }
            return;
        }
    }
    cout << rojo << "Libro no encontrado.\n" << reset;
}

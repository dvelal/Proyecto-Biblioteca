#ifndef STRUCLIBRO_H
#define STRUCLIBRO_H

#include <string>
using namespace std;

// Estructura del libro
struct Libro {
    int id;                 // ID unico del libro
    string titulo;
    string autor;
    int edicion;
    int anio;
    string categoria;
    string subcategoria;
    string estado = "disponible";  // disponible o prestado
    int dni_cliente = 0;           // DNI del cliente si esta prestado
    int codigo_seguridad = 0;      // codigo aleatorio de prestamo
};

// Funciones
void leerLibro(Libro &, int, string, string, int, int, string, string);
void imprimelibro(Libro &);
void mostrarLibros(Libro [], int);
void mostrarCategorias(Libro [], int);
void mostrarSubcategorias(Libro [], int, string);
void buscarLibro(Libro [], int, int, string, string, string, string);
void prestarLibro(Libro [], int, string, string, int);
bool devolverLibro(Libro [], int , int, int, int);
int buscarLibroPorID(Libro [], int , int);
void mostrarLibrosPrestados(Libro libros[], int cantidad);

#endif

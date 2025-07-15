#ifndef STRUCLIBRO_H
#define STRUCLIBRO_H

#include <string>
#include <iostream>
#include <iomanip>
#include "utilidades.h"
using namespace std;

// Estructura Libro
struct Libro {
    string titulo;
    string autor;
    int edicion;
    int anio;
    string categoria;
    string subcategoria;
    string estado = "disponible"; 
    int dni_cliente; 
    int codigo_seguridad = 0;
};

// Funciones
void mostrarCategorias(Libro [], int);
void mostrarSubcategorias(Libro [], int, string);
void mostrarLibros(Libro[], int);
void buscarLibro(Libro[], int, int, string, string, string, string);
void leerLibro(Libro &, string, string, int, int, string, string);
void imprimelibro(Libro &);
void prestarLibro(Libro[], int, string, string, int);
void devolverLibro(Libro[], int, string, string, int, int);

#endif
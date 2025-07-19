#ifndef STRUCCLIENTE_H
#define STRUCCLIENTE_H

#include <string>
#include "struclibro.h"
using namespace std;

// Estructura del cliente
struct Cliente {
    string nombre;
    int edad;
    int dni;
};

bool leercliente(Cliente &, Cliente [], string, int, int, int);
void imprimecliente(const Cliente &);
void mostrarClientes(Cliente [], Libro [], int, int);

#endif
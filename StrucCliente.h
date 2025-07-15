#ifndef STRUCCLIENTE_H
#define STRUCCLIENTE_H

#include <string>
using namespace std;

// Estructura Cliente
struct Cliente{
    string nombre;
    int edad;
    int dni;
};

void leercliente(Cliente &, string, int, int);

void imprimecliente(Cliente &);

#endif
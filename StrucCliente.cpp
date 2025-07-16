#include "struccliente.h"
#include "utilidades.h"
#include "struclibro.h"
#include <iostream>
using namespace std;

void imprimecliente(Cliente &c){
    cout << "Nombre: " << c.nombre << endl;
    cout << "Edad: " << c.edad << endl;
    cout << "DNI: " << c.dni << endl;
}

void leercliente(Cliente &c, string nombre, int edad, int dni){
    c.nombre = nombre;
    c.edad = edad;
    c.dni = dni;
}

void mostrarClientes(Cliente c[], Libro l[], int cantidad) {
    cout << amarillo << "\n|| Libros alquilados ||\n" << reset;
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < cantidad; j++) {
            if (l[i].dni_cliente == c[j].dni) {
                imprimecliente(c[j]);
                imprimelibro(l[i]);
            }
        }
        cout << endl;
    }
}
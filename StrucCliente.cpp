#include "struccliente.h"
#include "utilidades.h"
#include "struclibro.h"
#include <iostream>
#include <iomanip>
using namespace std;

void imprimecliente(Cliente &c) {
    cout << azul << "\n>> Cliente <<" << reset << endl;
    cout << "Nombre: " << c.nombre << endl;
    cout << "Edad: " << c.edad << endl;
    cout << "DNI: " << c.dni << endl;
}

bool leercliente(Cliente &c, Cliente clientes[], string nombre, int edad, int dni, int cantidad) {
    c.nombre = nombre;
    c.edad = edad;
    c.dni = dni;
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i].dni == c.dni) {
            if (clientes[i].nombre != c.nombre) {
                cout << rojo << "\nYa existe un cliente con el mismo DNI. Intente con otro.\n" << reset;
                c.nombre = "";
                c.dni = -1;
                return false;
            }
        }
    }
    return true;
}

void mostrarClientes(Cliente c[], Libro l[], int clientes, int libros) {
    bool hayPrestamos = false;

    cout << amarillo << "\n|| Libros alquilados ||\n" << reset;

    for (int i = 0; i < clientes; i++) {
        bool clienteYaMostrado = false;
        for (int k = 0; k < i; k++) {
            if (c[k].dni == c[i].dni) {
                clienteYaMostrado = true;
                break;
            }
        }

        if (!clienteYaMostrado) {
            bool clienteTieneLibros = false;

            for (int j = 0; j < libros; j++) {
                if (l[j].dni_cliente == c[i].dni) {
                    clienteTieneLibros = true;
                    break;
                }
            }

            if (clienteTieneLibros) {
                hayPrestamos = true;

                imprimecliente(c[i]);

                cout << azul << left
                    << setw(5)  << "ID"
                    << setw(25) << "TITULO"
                    << setw(20) << "AUTOR"
                    << setw(6)  << "ANIO"
                    << setw(12) << "ESTADO"
                    << setw(20) << "CODIGO SEGURIDAD"
                    << reset << endl;

                cout << magenta << string(90, '-') << reset << endl;

                for (int j = 0; j < libros; j++) {
                    if (l[j].dni_cliente == c[i].dni) {
                        cout << left
                            << setw(5)  << l[j].id
                            << setw(25) << l[j].titulo
                            << setw(20) << l[j].autor
                            << setw(6)  << l[j].anio;

                        if (l[j].estado == "disponible")
                            cout << azul << setw(12) << l[j].estado << reset;
                        else
                            cout << rojo << setw(12) << l[j].estado << reset;

                        cout << setw(20) << l[j].codigo_seguridad << endl;
                    }
                }

                cout << endl;
            }
        }
    }
    if (!hayPrestamos)
        cout << rojo << "No hay libros prestados actualmente.\n" << reset;
}
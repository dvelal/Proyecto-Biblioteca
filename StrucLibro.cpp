#include "struclibro.h"
#include "utilidades.h"
#include <iostream>
#include <iomanip>
using namespace std;

void leerLibro(Libro &l, int id, string titulo, string autor, int edicion, int anio, string categoria, string subcategoria) {
    l.id = id;
    l.titulo = titulo;
    l.autor = autor;
    l.edicion = edicion;
    l.anio = anio;
    l.categoria = categoria;
    l.subcategoria = subcategoria;
    l.estado = "disponible";
    l.dni_cliente = 0;
    l.codigo_seguridad = 0;
}

void imprimelibro(Libro &l) {
    cout << "\n-----------------------------\n";
    cout << "ID: " << l.id << endl;
    cout << "Titulo: " << l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "Edicion: " << l.edicion << endl;
    cout << "Anio: " << l.anio << endl;
    cout << "Categoria: " << l.categoria << endl;
    cout << "Subcategoria: " << l.subcategoria << endl;
    if (l.estado == "disponible")
        cout << azul << l.estado << reset << endl;
    else
        cout << rojo << l.estado << reset << endl;
    if (l.estado == "prestado") {
        cout << "DNI del cliente: " << l.dni_cliente << endl;
        cout << "Codigo de seguridad: " << l.codigo_seguridad << endl;
    }
    cout << "-----------------------------\n";
}

void mostrarCategorias(Libro libros[], int cantidad) {
    cout << verde << "Categorias disponibles:\n" << reset;
    for (int i = 0; i < cantidad; i++) {
        bool repetido = false;
        for (int j = 0; j < i; j++) {
            if (libros[j].categoria == libros[i].categoria) {
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
    cout << cian << "Subcategorias de '" << categoria << "':\n" << reset;
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].categoria == categoria) {
            bool repetido = false;
            for (int j = 0; j < i; j++) {
                if (libros[j].subcategoria == libros[i].subcategoria && libros[j].categoria == categoria) {
                    repetido = true;
                    break;
                }
            }
            if (!repetido) {
                cout << "- " << libros[i].subcategoria << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << rojo << "No se encontraron subcategorias para esa categoria.\n" << reset;
    }
}

void buscarLibro(Libro libros[], int cantidad, int modo, string cate, string subcate, string titulo, string autor) {
    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if ((modo == 1 && libros[i].autor == autor) ||
            (modo == 2 && libros[i].titulo == titulo) ||
            (modo == 3 && libros[i].categoria == cate && libros[i].subcategoria == subcate)) {
            imprimelibro(libros[i]);
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << rojo << "No se encontraron libros con esos datos.\n" << reset;
    }
}

void prestarLibro(Libro libros[], int cantidad, string titulo, string autor, int dni) {
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].titulo == titulo && libros[i].autor == autor) {
            if (libros[i].estado == "disponible") {
                libros[i].estado = "prestado";
                libros[i].dni_cliente = dni;
                libros[i].codigo_seguridad = rand() % 9000 + 1000;
                cout << verde << "Libro prestado con exito.\n" << reset;
                cout << amarillo << "Codigo de seguridad: " << libros[i].codigo_seguridad << reset << endl;
                return;
            } else {
                cout << rojo << "El libro ya esta prestado.\n" << reset;
                return;
            }
        }
    }

    cout << rojo << "Libro no encontrado.\n" << reset;
}

bool devolverLibro(Libro libros[], int cantidad, int id, int dni, int codigo) {
    int idx = buscarLibroPorID(libros, cantidad, id);
    if (idx == -1 || libros[idx].estado == "disponible") {
        return false;
    }
    if (libros[idx].dni_cliente == dni && libros[idx].codigo_seguridad == codigo) {
        libros[idx].estado = "disponible";
        libros[idx].dni_cliente = 0;
        libros[idx].codigo_seguridad = 0;
        return true;
    }

    return false;
}

void mostrarLibros(Libro libros[], int cantidad) {
    if (cantidad == 0) {
        cout << rojo << "No hay libros registrados.\n" << reset;
        return;
    }
    cout << azul << left
         << setw(5)  << "ID"
         << setw(25) << "TITULO"
         << setw(20) << "AUTOR"
         << setw(8)  << "EDIC."
         << setw(6)  << "ANIO"
         << setw(15) << "CATEGORIA"
         << setw(18) << "SUBCATEGORIA"
         << setw(12) << "ESTADO"
         << reset << endl;

    cout << magenta << string(120, '-') << reset << endl;
    
    for (int i = 0; i < cantidad; i++) {
        cout << left
             << setw(5)  << libros[i].id
             << setw(25) << libros[i].titulo
             << setw(20) << libros[i].autor
             << setw(8)  << libros[i].edicion
             << setw(6)  << libros[i].anio
             << setw(15) << libros[i].categoria
             << setw(18) << libros[i].subcategoria;
            if (libros[i].estado == "disponible")
                cout << left << setw(12) << azul << libros[i].estado << reset << endl;
            else
                cout << left << setw(12) << rojo << libros[i].estado << reset << endl;
    }
}

int buscarLibroPorID(Libro libros[], int cantidad, int id) {
    for (int i = 0; i < cantidad; i++) {
        if (libros[i].id == id) {
            return i;
        }
    }
    return -1;
}

void mostrarLibrosPrestados(Libro libros[], int cantidad) {
    bool hayPrestados = false;

    cout << left
         << setw(5)  << "ID"
         << setw(25) << "TITULO"
         << setw(20) << "AUTOR"
         << setw(8)  << "ANIO"
         << setw(12) << "ESTADO"
         << setw(20) << "CODIGO SEGURIDAD"
         << endl;

    cout << magenta << string(90, '-') << reset << endl;

    for (int i = 0; i < cantidad; i++) {
        if (libros[i].estado == "prestado") {
            hayPrestados = true;

            cout << left
                 << setw(5)  << libros[i].id
                 << setw(25) << libros[i].titulo
                 << setw(20) << libros[i].autor
                 << setw(8)  << libros[i].anio;

            cout << rojo << setw(12) << libros[i].estado << reset;

            cout << setw(20) << libros[i].codigo_seguridad << endl;
        }
    }

    if (!hayPrestados) {
        cout << rojo << "No hay libros prestados actualmente.\n" << reset;
    }
}

#include <iostream>
#include <string>
#include <ctime> 
#include <windows.h>
#include "utilidades.h"
using namespace std;

string amarillo = "\033[1;33m";
string verde = "\033[0;32m";
string rojo = "\033[0;31m";
string reset = "\033[0m";

struct Cliente{
    string nombre;
    int edad;
    int dni;
};

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

void buscarLibro(Libro[], int, int, string, string, string, string);

void leerLibro(Libro &, string, string, int, int, string, string);

void leercliente(Cliente &, string, int, int);

void imprimecliente(Cliente &);

void imprimelibro(Libro &);

void prestarLibro(Libro[], int, string, string, int);

void devolverLibro(Libro[], int, string, string, int);

int main() {
    Libro libros[1000];
    Cliente cliente[1000];
    int contadorLibros = 0;
    int contadorcliente = 0;
    int op, dni, edad, subop;
    char op1;
    string titulo, autor, nombre, cate, subcate;
    int edicion, anio;

    do {
        cout << "\n--- Biblioteca Virtual ---\n";
        cout << "1. Buscar libro\n";
        cout << "2. Agregar un libro\n";
        cout << "3. Mostrar libros\n";
        cout << "4. Prestar un libro\n";
        cout << "5. Devolver un libro\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> op;
        cin.ignore(); 
        
        limpiarPantalla();

        switch (op) {
            case 1: {
                cout << "\n1. Buscar por titulo y autor\n";
                cout << "2. Buscar por categoria y subcategoria\n";
                cout << "Seleccione una opcion: ";
                cin >> subop;
                cin.ignore();
                if (subop == 1){
                cout << "Ingrese el titulo del libro a buscar: ";
                getline(cin, titulo);  
                cout << "Ingrese el autor del libro a buscar: ";
                getline(cin, autor);
                buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor);
                pausar();
                }
                else if (subop == 2){
                cout << "\nSeleccione una Categoria: ";
                getline(cin, cate);
                cout << "\nSeleccione una Subcategoria: ";
                getline(cin, subcate);
                buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor); 
                pausar();   
                }
                break;
            }

            case 2: {
                cout << "Titulo del libro: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "Edicion: ";
                cin >> edicion;
                cin.ignore();
                cout << "Anio: ";
                cin >> anio;
                cin.ignore();
                cout << "Categoria: ";
                cin >> cate;
                cin.ignore();
                cout << "Subcategoria: ";
                cin >> subcate;

                leerLibro(libros[contadorLibros], titulo, autor, edicion, anio, cate, subcate);
                contadorLibros++;
                cout << verde << "Libro agregado con exito.\n" << reset;
                pausar();
                break;
            }

            case 3: {
                cout << "\nLibros registrados:\n";
                for (int i = 0; i < contadorLibros; i++) {
                    cout<<"Libro #"<<i+1<<endl;
                    imprimelibro(libros[i]);
                    cout << endl;
                }
                pausar();
                break;
            }

            case 4: {
                cout << "-------------------------------------Ingresa los datos del libro----------------------------------------------" << endl;
                cout << "Titulo del libro a prestar: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "----------------------------------------Ingresa tus datos personales----------------------------------------- " << endl;
                cout << "Ingresa tu nombre (Primer nombre y apellido): ";
                getline(cin, nombre);
                cout << "Ingresa tu edad: ";
                cin >> edad;
                cin.ignore();
                cout << "Ingresa tu DNI: ";
                cin >> dni;
                cin.ignore();
                leercliente(cliente[contadorcliente], nombre, edad, dni);
                contadorcliente++;
                prestarLibro(libros, contadorLibros, titulo, autor, dni);
                pausar();
                break;
            }
            case 5: {
                cout << "-------------------------------------Datos del libro a devolver----------------------------------------------\n";
                cout << "Titulo del libro: ";
                getline(cin, titulo);
                cout << "Autor: ";
                getline(cin, autor);

                cout << "Ingresa tu DNI: ";
                cin >> dni;
                cin.ignore();
                devolverLibro(libros, contadorLibros, titulo, autor, dni);
                pausar();
                break;
            }
            case 0:
                cout << "¿Seguro que desea salir (S/N)? ";
                cin >> op1;
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
        cout << "\nLibros encontrados:\n";
        for (int i = 0; i < cant; i++) {
            if (libros[i].categoria == categoria && libros[i].subcategoria == subcategoria) {
                imprimelibro(libros[i]);
                cout << endl;
                encontra = true;
            }
        }
        if (!encontra) {
            cout << "No hay libros encontrados";
        }
    }
}

void imprimelibro(Libro &l){
    cout << "Libro: " << l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "Edicion: " << l.edicion << endl;
    cout << "Anio: " << l.anio << endl;
    cout << "Estado: " << l.estado << endl;
    cout << "Categoria: " << l.categoria << endl;
    cout << "Subcategoria: " << l.subcategoria << endl; 
}

void imprimecliente(Cliente &c){
    cout << "Nombre: " << c.nombre << endl;
    cout << "Edad: " << c.edad << endl;
    cout << "DNI: " << c.dni << endl;
}

void leerLibro(Libro &l, string titulo, string autor, int edicion, int anio, string cate, string subcate) {
    l.titulo = titulo;
    l.autor = autor;
    l.edicion = edicion;
    l.anio = anio;
    l.categoria = cate;
    l.subcategoria = subcate;
}

void leercliente(Cliente &c, string nombre, int edad, int dni){
    c.nombre = nombre;
    c.edad = edad;
    c.dni = dni;
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
                libros[i].codigo_seguridad = rand() % 9000 + 1000; 
                cout << verde << "Libro prestado con exito al cliente con DNI: " << dni << reset << endl;
                cout << "Codigo de seguridad del prestamo: " << libros[i].codigo_seguridad << endl;
            }
            return;
        }
    }
    cout << rojo << "Libro no encontrado.\n" << reset;
}

void devolverLibro(Libro libros[], int cant, string titulo, string autor, int dni) {
    int codigo_input;

    for (int i = 0; i < cant; i++) {
        if (libros[i].titulo == titulo && libros[i].autor == autor) {
            if (libros[i].estado == "disponible") {
                cout << amarillo << "Ese libro ya está disponible.\n" << reset;
            } 
            else if (libros[i].dni_cliente != dni) {
                cout << rojo << "DNI incorrecto. No puedes devolver un libro que no has prestado.\n" << reset;
            } 
            else {
                cout << "Ingresa el codigo de seguridad del prestamo: ";
                cin >> codigo_input;

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
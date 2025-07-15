// Para entrada y salida estándar (cout, cin)
#include <iostream>
// Para trabajar con cadenas de texto 
#include <string>
// Generar números aleatorios
#include <ctime> 
// Colocar colores
#include <windows.h>
#include <iomanip>
#include <set>
#include "utilidades.h"
using namespace std;

// Códigos para utilizar los colores de la libreria windows.h
string amarillo = "\033[1;33m";
string verde = "\033[0;32m";
string rojo = "\033[0;31m";
string azul = "\033[0;34m";
string magenta = "\033[0;35m";
string cian = "\033[1;36m";
string reset = "\033[0m";

// Estructura Cliente
struct Cliente{
    string nombre;
    int edad;
    int dni;
};

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

// Función para mostrar las categorias y subcategorias de los libros 
void mostrarCategoriasYSubcategorias(Libro[], int);

// Función para mostrar los libros 
void mostrarLibros(Libro[], int);

// Función para buscar un libro en la biblioteca 
void buscarLibro(Libro[], int, int, string, string, string, string);

void leerLibro(Libro &, string, string, int, int, string, string);

void leercliente(Cliente &, string, int, int);

void imprimecliente(Cliente &);

void imprimelibro(Libro &);

void prestarLibro(Libro[], int, string, string, int);

void devolverLibro(Libro[], int, string, string, int);

void cargarLibrosPredefinidos(Libro[], int &);

int main() {
    srand(time(0));  
    Libro libros[1000];
    Cliente cliente[1000];
    int contadorLibros = 0;
    int contadorcliente = 0;
    int op, dni, edad, subop;
    char op1;
    string titulo, autor, nombre, cate, subcate;
    int edicion, anio;

    cargarLibrosPredefinidos(libros, contadorLibros);

    do {
        cout << magenta << "===============================\n" << reset;
        cout << azul << "     BIBLIOTECA VIRTUAL\n" << reset;
        cout << magenta << "===============================\n" << reset;

        cout << rojo << "  [1] " <<  reset << "Buscar libro\n";
        cout << rojo << "  [2] "<< reset << "Agregar un libro\n";
        cout << rojo << "  [3] " << reset << "Mostrar libros\n";
        cout << rojo << "  [4] " << reset << "Prestar un libro\n";
        cout << rojo << "  [5] " << reset << "Devolver un libro\n";
        cout << rojo << "  [0] " << reset << "Salir\n";

        cout << "\nSeleccione una opcion: "; cin >> op;
        cin.ignore(); 
        
        limpiarPantalla();

        switch (op) {
            case 1: {
                cout << "\n1. Buscar por titulo y autor\n";
                cout << "2. Buscar por categoria y subcategoria\n";
                cout << "Seleccione una opcion: "; cin >> subop;
                cin.ignore();
                switch (subop){
                    case 1:{
                        cout << "Ingrese el titulo del libro a buscar: "; getline(cin, titulo);  
                        cout << "Ingrese el autor del libro a buscar: "; getline(cin, autor);

                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor);

                        pausar();
                        break;
                    }

                    case 2:{
                        mostrarCategoriasYSubcategorias(libros, contadorLibros);
    
                        cout << "\nIngrese la CATEGORIA exacta: "; getline(cin, cate);
                        cout << "Ingrese la SUBCATEGORIA exacta: "; getline(cin, subcate);

                        limpiarPantalla();

                        buscarLibro(libros, contadorLibros, subop, cate, subcate, titulo, autor); 

                        pausar();  
                        break; 
                    }
                    default:
                        cout << "No existe la opcion elegida"<< endl;
                        pausar();
                        break;
                }
                break;
            }

            case 2: {
                cout << "Titulo del libro: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "Edicion: "; cin >> edicion;
                cin.ignore();
                cout << "Anio: "; cin >> anio;
                cin.ignore();
                cout << "Categoria: "; cin >> cate;
                cin.ignore();
                cout << "Subcategoria: "; cin >> subcate;

                leerLibro(libros[contadorLibros], titulo, autor, edicion, anio, cate, subcate);

                contadorLibros++;
                cout << verde << "Libro agregado con exito.\n" << reset;

                pausar();
                break;
            }

            case 3: {
                mostrarLibros(libros, contadorLibros);

                pausar();
                break;
            }

            case 4: {
                cout << "-------------------------------------Ingresa los datos del libro----------------------------------------------" << endl;
                cout << "Titulo del libro a prestar: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "----------------------------------------Ingresa tus datos personales----------------------------------------- " << endl;
                cout << "Ingresa tu nombre (Primer nombre y apellido): "; getline(cin, nombre);
                cout << "Ingresa tu edad: "; cin >> edad;
                cin.ignore();
                cout << "Ingresa tu DNI: "; cin >> dni;
                cin.ignore();

                leercliente(cliente[contadorcliente], nombre, edad, dni);

                contadorcliente++;

                prestarLibro(libros, contadorLibros, titulo, autor, dni);

                pausar();
                break;
            }
            case 5: {
                cout << "-------------------------------------Datos del libro a devolver----------------------------------------------\n";
                cout << "Titulo del libro: "; getline(cin, titulo);
                cout << "Autor: "; getline(cin, autor);
                cout << "Ingresa tu DNI: "; cin >> dni;
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

void mostrarLibros(Libro libros[], int cantidad) {
    cout << "\nLista de libros registrados:\n";
    cout << left
         << setw(60) << "Titulo"
         << setw(30) << "Autor"
         << setw(10) << "Edicion"
         << setw(10) << "Anio"
         << setw(12) << "Categoria"
         << setw(23) << "Subcategoria" 
         << setw(15) << "Estado" << endl;

    cout << string(167, '-') << endl;

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

void mostrarCategoriasYSubcategorias(Libro libros[], int cantidad) {
    cout << "Categorias y Subcategorias disponibles:\n";

    set<string> mostradas;

    for (int i = 0; i < cantidad; i++) {
        string clave = libros[i].categoria + " > " + libros[i].subcategoria;
        if (mostradas.find(clave) == mostradas.end()) {

            // Color por categoría
            string color;
            if (libros[i].categoria == "Matematica")
                color = azul;
            else if (libros[i].categoria == "Ciencias")
                color = rojo;
            else if (libros[i].categoria == "Literatura")
                color = verde;
            else if (libros[i].categoria == "Historia")
                color = magenta;
            else if (libros[i].categoria == "Filosofia")
                color = amarillo;
            else if (libros[i].categoria == "Computacion")
                color = azul;
            else if (libros[i].categoria == "Economia")
                color = rojo;
            else if (libros[i].categoria == "Ingenieria")
                color = verde;
            else if (libros[i].categoria == "Medicina")
                color = magenta;
            else 
                color = azul;

            cout << " - " << color << libros[i].categoria << reset << " > " << cian << libros[i].subcategoria << reset << endl;
            mostradas.insert(clave);
        }
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
    cout << "Estado: " << azul << l.estado << reset << endl;
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
                libros[i].codigo_seguridad = rand() % 9999 + 1000; 
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

void cargarLibrosPredefinidos(Libro libros[], int &contador) {

    // Matematica - Calculo
    libros[contador++] = {"Calculo", "James Stewart", 8, 2020, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo I", "Luis Arana", 2, 2019, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo Diferencial", "Julio Rios", 3, 2016, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo Integral", "Pedro Poma", 4, 2018, "Matematica", "Calculo"};
    libros[contador++] = {"Curso de Calculo", "Carlos Zavala", 1, 2015, "Matematica", "Calculo"};
    libros[contador++] = {"Introduccion al Calculo", "Manuel Ventura", 1, 2014, "Matematica", "Calculo"};
    libros[contador++] = {"Fundamentos de Calculo", "Walter Apaza", 2, 2021, "Matematica", "Calculo"};
    libros[contador++] = {"Problemas de Calculo", "Jose Rojas", 2, 2020, "Matematica", "Calculo"};
    libros[contador++] = {"Matematica Avanzada", "Lucho Herrera", 1, 2017, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo Multivariable", "Enrique Torres", 1, 2022, "Matematica", "Calculo"};

    // Matematica - Algebra
    libros[contador++] = {"Algebra Lineal", "David Lay", 5, 2016, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra I", "Luis Arana", 3, 2020, "Matematica", "Algebra"};
    libros[contador++] = {"Problemas de Algebra", "Walter Apaza", 2, 2019, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra Elemental", "Cesar Delgado", 1, 2015, "Matematica", "Algebra"};
    libros[contador++] = {"Curso de Algebra", "Pedro Poma", 4, 2017, "Matematica", "Algebra"};
    libros[contador++] = {"Teoria y Practica de Algebra", "Jose Rojas", 2, 2018, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra Basica", "Jorge Pineda", 1, 2016, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra Moderna", "Maria Diaz", 2, 2020, "Matematica", "Algebra"};
    libros[contador++] = {"Estructuras Algebraicas", "Ana Lopez", 1, 2014, "Matematica", "Algebra"};
    libros[contador++] = {"Matrices y Determinantes", "Carlos Meneses", 1, 2023, "Matematica", "Algebra"};

    // Matematica - Geometria
    libros[contador++] = {"Geometria Euclidiana", "Fernando Cardenas", 1, 2015, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria Analitica", "Maria Romero", 2, 2017, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria Plana", "Luis Suarez", 3, 2016, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria en el Espacio", "Pedro Diaz", 2, 2014, "Matematica", "Geometria"};
    libros[contador++] = {"Figuras Geometricas", "Juan Vega", 1, 2013, "Matematica", "Geometria"};
    libros[contador++] = {"Vectores y Geometria", "Carlos Inga", 1, 2021, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria Diferencial", "Oscar Garcia", 1, 2020, "Matematica", "Geometria"};
    libros[contador++] = {"Introduccion a la Geometria", "Carmen Valdez", 1, 2019, "Matematica", "Geometria"};
    libros[contador++] = {"Problemas de Geometria", "Antonio Luna", 2, 2018, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria para Pre", "Lucia Reyes", 1, 2016, "Matematica", "Geometria"};

    // Matematica - Aritmetica
    libros[contador++] = {"Aritmetica I", "Luis Arana", 2, 2015, "Matematica", "Aritmetica"};
    libros[contador++] = {"Aritmetica Basica", "Carmen Flores", 1, 2016, "Matematica", "Aritmetica"};
    libros[contador++] = {"Curso de Aritmetica", "Pedro Poma", 2, 2017, "Matematica", "Aritmetica"};
    libros[contador++] = {"Aritmetica para Pre", "Walter Apaza", 1, 2014, "Matematica", "Aritmetica"};
    libros[contador++] = {"Teoria de Numeros", "Carlos Rojas", 2, 2020, "Matematica", "Aritmetica"};
    libros[contador++] = {"Aritmetica Moderna", "Laura Ruiz", 1, 2019, "Matematica", "Aritmetica"};
    libros[contador++] = {"Aritmetica Elemental", "Enrique Torres", 1, 2013, "Matematica", "Aritmetica"};
    libros[contador++] = {"Operaciones Basicas", "Jose Luis", 1, 2022, "Matematica", "Aritmetica"};
    libros[contador++] = {"Numeros Enteros", "Raul Caceres", 1, 2021, "Matematica", "Aritmetica"};
    libros[contador++] = {"Potencias y Raices", "Antonio Chambi", 1, 2018, "Matematica", "Aritmetica"};

    // Matematica - Estadistica
    libros[contador++] = {"Estadistica Matematica", "John Freund", 8, 2010, "Matematica", "Estadistica"};
    libros[contador++] = {"Probabilidad y Estadistica", "Ronald Walpole", 9, 2012, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Aplicada", "Richard Levin", 7, 1999, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Inferencial", "Mario Triola", 13, 2018, "Matematica", "Estadistica"};
    libros[contador++] = {"Introduccion a la Estadistica", "Sheldon Ross", 3, 2010, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Descriptiva", "Douglas Lind", 17, 2019, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica para Economia", "Paul Newbold", 6, 2006, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica con Excel", "Guillermo Ramirez", 1, 2013, "Matematica", "Estadistica"};
    libros[contador++] = {"Metodos Estadisticos", "Victor Mendoza", 2, 2018, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Computacional", "Maria Luque", 1, 2021, "Matematica", "Estadistica"};

    // Matematica - Trigonometria
    libros[contador++] = {"Trigonometria", "Luis Arana", 1, 2015, "Matematica", "Trigonometria"};
    libros[contador++] = {"Curso de Trigonometria", "Pedro Poma", 2, 2017, "Matematica", "Trigonometria"};
    libros[contador++] = {"Trigonometria Plana", "Maria Castro", 1, 2016, "Matematica", "Trigonometria"};
    libros[contador++] = {"Identidades Trigonometricas", "Jose Rojas", 2, 2019, "Matematica", "Trigonometria"};
    libros[contador++] = {"Funciones Trigonometricas", "Walter Apaza", 1, 2021, "Matematica", "Trigonometria"};
    libros[contador++] = {"Trigonometria para Pre", "Ana Salas", 1, 2020, "Matematica", "Trigonometria"};
    libros[contador++] = {"Triangulos y Angulos", "Oscar Bravo", 1, 2018, "Matematica", "Trigonometria"};
    libros[contador++] = {"Trigonometria Basica", "Carmen Rios", 1, 2014, "Matematica", "Trigonometria"};
    libros[contador++] = {"Problemas de Trigonometria", "Enrique Torres", 1, 2019, "Matematica", "Trigonometria"};
    libros[contador++] = {"Trigonometria Aplicada", "Antonio Lima", 1, 2023, "Matematica", "Trigonometria"};
    
    // Ciencias - Fisica
    libros[contador++] = {"Fisica Universitaria", "Hugh D. Young", 13, 2012, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica Conceptual", "Paul G. Hewitt", 12, 2010, "Ciencias", "Fisica"};
    libros[contador++] = {"Fundamentos de Fisica", "David Halliday", 10, 2014, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica para la Ciencia y la Tecnologia", "Paul Tipler", 6, 2008, "Ciencias", "Fisica"};
    libros[contador++] = {"Problemas de Fisica General", "I.E. Irodov", 1, 2001, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica General", "Pedro Poma", 3, 2016, "Ciencias", "Fisica"};
    libros[contador++] = {"Mecanica", "Landau y Lifshitz", 4, 1976, "Ciencias", "Fisica"};
    libros[contador++] = {"Electricidad y Magnetismo", "Edward Purcell", 2, 2013, "Ciencias", "Fisica"};
    libros[contador++] = {"Termodinamica", "Mark W. Zemansky", 7, 1997, "Ciencias", "Fisica"};
    libros[contador++] = {"Ondas y Oscilaciones", "Walter Apaza", 1, 2020, "Ciencias", "Fisica"};

    // Ciencias - Quimica
    libros[contador++] = {"Quimica", "Raymond Chang", 12, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica General", "Ralph H. Petrucci", 11, 2011, "Ciencias", "Quimica"};
    libros[contador++] = {"Principios de Quimica", "Paula Yurkanis Bruice", 7, 2014, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica Organica", "John McMurry", 9, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica Inorganica", "Gary L. Miessler", 5, 2014, "Ciencias", "Quimica"};
    libros[contador++] = {"Problemas Resueltos de Quimica", "Luis Arana", 2, 2015, "Ciencias", "Quimica"};
    libros[contador++] = {"Laboratorio de Quimica", "Ana Paredes", 1, 2018, "Ciencias", "Quimica"};
    libros[contador++] = {"Fisicoquimica", "Peter Atkins", 10, 2018, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica Analitica", "Douglas Skoog", 9, 2013, "Ciencias", "Quimica"};
    libros[contador++] = {"Bioquimica", "Jeremy M. Berg", 8, 2016, "Ciencias", "Quimica"};

    // Ciencias - Biologia
    libros[contador++] = {"Biologia", "Neil A. Campbell", 9, 2012, "Ciencias", "Biologia"};
    libros[contador++] = {"Fundamentos de Biologia", "Solomon Berg", 7, 2010, "Ciencias", "Biologia"};
    libros[contador++] = {"Biologia Celular y Molecular", "Gerald Karp", 8, 2016, "Ciencias", "Biologia"};
    libros[contador++] = {"Anatomia y Fisiologia", "Elaine N. Marieb", 10, 2015, "Ciencias", "Biologia"};
    libros[contador++] = {"Microbiologia", "Tortora", 11, 2014, "Ciencias", "Biologia"};
    libros[contador++] = {"Biologia Humana", "Sylvia S. Mader", 9, 2011, "Ciencias", "Biologia"};
    libros[contador++] = {"Genetica", "William S. Klug", 12, 2015, "Ciencias", "Biologia"};
    libros[contador++] = {"Botanica", "James D. Mauseth", 5, 2012, "Ciencias", "Biologia"};
    libros[contador++] = {"Zoologia", "Stephen A. Miller", 9, 2009, "Ciencias", "Biologia"};
    libros[contador++] = {"Ecologia de Poblaciones", "Walter Apaza", 1, 2020, "Ciencias", "Biologia"};

    // Ciencias - Astronomia
    libros[contador++] = {"Astronomia: Una Guia", "Ian Ridpath", 3, 2015, "Ciencias", "Astronomia"};
    libros[contador++] = {"Cosmos", "Carl Sagan", 1, 1980, "Ciencias", "Astronomia"};
    libros[contador++] = {"Astrofisica para Gente con Prisa", "Neil deGrasse Tyson", 1, 2017, "Ciencias", "Astronomia"};
    libros[contador++] = {"Introduccion a la Astronomia", "Pedro Poma", 2, 2016, "Ciencias", "Astronomia"};
    libros[contador++] = {"El Universo en una Cascara de Nuez", "Stephen Hawking", 1, 2001, "Ciencias", "Astronomia"};
    libros[contador++] = {"El Gran Diseño", "Stephen Hawking", 1, 2010, "Ciencias", "Astronomia"};
    libros[contador++] = {"Astronomia Moderna", "Michael Zeilik", 10, 2002, "Ciencias", "Astronomia"};
    libros[contador++] = {"Observacion Astronomica", "Walter Apaza", 1, 2020, "Ciencias", "Astronomia"};
    libros[contador++] = {"Guia del Cielo", "Guillermo Abramson", 1, 2018, "Ciencias", "Astronomia"};
    libros[contador++] = {"Astronomia General", "Luis Arana", 1, 2019, "Ciencias", "Astronomia"};

    // Ciencias - Ecologia
    libros[contador++] = {"Ecologia", "Cain, Bowman y Hacker", 3, 2014, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia: De Individuos a Ecosistemas", "Begon, Townsend, Harper", 4, 2006, "Ciencias", "Ecologia"};
    libros[contador++] = {"Principios de Ecologia", "Walter Apaza", 1, 2019, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Aplicada", "S. R. Carpenter", 1, 2012, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Humana", "Paul Shepard", 2, 2001, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Urbana", "Luis Arana", 1, 2018, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecosistemas y Medio Ambiente", "Carlos Zavala", 2, 2020, "Ciencias", "Ecologia"};
    libros[contador++] = {"Conservacion de la Naturaleza", "Pedro Poma", 1, 2016, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Marina", "James Nybakken", 2, 2001, "Ciencias", "Ecologia"};
    libros[contador++] = {"Biologia de la Conservacion", "Richard Primack", 3, 2012, "Ciencias", "Ecologia"};

    // Literatura - Peruana
    libros[contador++] = {"Los Heraldos Negros", "Cesar Vallejo", 1, 1919, "Literatura", "Peruana"};
    libros[contador++] = {"La Casa de Carton", "Martin Adan", 1, 1928, "Literatura", "Peruana"};
    libros[contador++] = {"Redoble por Rancas", "Manuel Scorza", 1, 1970, "Literatura", "Peruana"};
    libros[contador++] = {"Un Mundo para Julius", "Alfredo Bryce Echenique", 1, 1970, "Literatura", "Peruana"};
    libros[contador++] = {"La Tia Julia y el Escribidor", "Mario Vargas Llosa", 1, 1977, "Literatura", "Peruana"};
    libros[contador++] = {"Todas las Sangres", "Jose Maria Arguedas", 1, 1964, "Literatura", "Peruana"};
    libros[contador++] = {"No me esperen en Abril", "Alfredo Bryce Echenique", 1, 1995, "Literatura", "Peruana"};
    libros[contador++] = {"El Pez de Oro", "Gamaleon Churata", 1, 1957, "Literatura", "Peruana"};
    libros[contador++] = {"El Sexto", "Jose Maria Arguedas", 1, 1961, "Literatura", "Peruana"};
    libros[contador++] = {"Conversacion en La Catedral", "Mario Vargas Llosa", 1, 1969, "Literatura", "Peruana"};

    // Literatura - Latinoamericana
    libros[contador++] = {"Cien Anos de Soledad", "Gabriel Garcia Marquez", 1, 1967, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Rayuela", "Julio Cortazar", 1, 1963, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Pedro Paramo", "Juan Rulfo", 1, 1955, "Literatura", "Latinoamericana"};
    libros[contador++] = {"La Ciudad y los Perros", "Mario Vargas Llosa", 1, 1963, "Literatura", "Latinoamericana"};
    libros[contador++] = {"El Tunel", "Ernesto Sabato", 1, 1948, "Literatura", "Latinoamericana"};
    libros[contador++] = {"La Muerte de Artemio Cruz", "Carlos Fuentes", 1, 1962, "Literatura", "Latinoamericana"};
    libros[contador++] = {"La Fiesta del Chivo", "Mario Vargas Llosa", 1, 2000, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Aura", "Carlos Fuentes", 1, 1962, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Sobre Heroes y Tumbas", "Ernesto Sabato", 1, 1961, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Doce Cuentos Peregrinos", "Gabriel Garcia Marquez", 1, 1992, "Literatura", "Latinoamericana"};

    // Literatura - Universal
    libros[contador++] = {"1984", "George Orwell", 1, 1949, "Literatura", "Universal"};
    libros[contador++] = {"Matar a un Ruisenor", "Harper Lee", 1, 1960, "Literatura", "Universal"};
    libros[contador++] = {"Crimen y Castigo", "Fiodor Dostoievski", 1, 1866, "Literatura", "Universal"};
    libros[contador++] = {"Orgullo y Prejuicio", "Jane Austen", 1, 1813, "Literatura", "Universal"};
    libros[contador++] = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1, 1605, "Literatura", "Universal"};
    libros[contador++] = {"La Metamorfosis", "Franz Kafka", 1, 1915, "Literatura", "Universal"};
    libros[contador++] = {"El Principito", "Antoine de Saint-Exupery", 1, 1943, "Literatura", "Universal"};
    libros[contador++] = {"Fahrenheit 451", "Ray Bradbury", 1, 1953, "Literatura", "Universal"};
    libros[contador++] = {"Ensayo sobre la Ceguera", "Jose Saramago", 1, 1995, "Literatura", "Universal"};
    libros[contador++] = {"La Divina Comedia", "Dante Alighieri", 1, 1320, "Literatura", "Universal"};

    // Literatura - Clasica
    libros[contador++] = {"La Iliada", "Homero", 1, -750, "Literatura", "Clasica"};
    libros[contador++] = {"La Odisea", "Homero", 1, -700, "Literatura", "Clasica"};
    libros[contador++] = {"La Eneida", "Virgilio", 1, -19, "Literatura", "Clasica"};
    libros[contador++] = {"Edipo Rey", "Sofocles", 1, -429, "Literatura", "Clasica"};
    libros[contador++] = {"Las Metamorfosis", "Ovidio", 1, 8, "Literatura", "Clasica"};
    libros[contador++] = {"Antigona", "Sofocles", 1, -441, "Literatura", "Clasica"};
    libros[contador++] = {"Las Nubes", "Aristofanes", 1, -423, "Literatura", "Clasica"};
    libros[contador++] = {"Prometeo Encadenado", "Esquilo", 1, -460, "Literatura", "Clasica"};
    libros[contador++] = {"Electra", "Euripides", 1, -413, "Literatura", "Clasica"};
    libros[contador++] = {"Las Ranas", "Aristofanes", 1, -405, "Literatura", "Clasica"};

    // Literatura - Contemporanea
    libros[contador++] = {"Kafka en la Orilla", "Haruki Murakami", 1, 2002, "Literatura", "Contemporanea"};
    libros[contador++] = {"Nunca Me Abandones", "Kazuo Ishiguro", 1, 2005, "Literatura", "Contemporanea"};
    libros[contador++] = {"Los Detectives Salvajes", "Roberto Bolaño", 1, 1998, "Literatura", "Contemporanea"};
    libros[contador++] = {"El Nino con el Pijama de Rayas", "John Boyne", 1, 2006, "Literatura", "Contemporanea"};
    libros[contador++] = {"El Nombre del Viento", "Patrick Rothfuss", 1, 2007, "Literatura", "Contemporanea"};
    libros[contador++] = {"La Carretera", "Cormac McCarthy", 1, 2006, "Literatura", "Contemporanea"};
    libros[contador++] = {"El Juego de Ender", "Orson Scott Card", 1, 1985, "Literatura", "Contemporanea"};
    libros[contador++] = {"La Sombra del Viento", "Carlos Ruiz Zafon", 1, 2001, "Literatura", "Contemporanea"};
    libros[contador++] = {"El Codigo Da Vinci", "Dan Brown", 1, 2003, "Literatura", "Contemporanea"};
    libros[contador++] = {"La Ladrona de Libros", "Markus Zusak", 1, 2005, "Literatura", "Contemporanea"};

    //Historia - Peruana
    libros[contador++] = {"Breve Historia del Peru", "Franklin Pease G.Y.", 1, 1995, "Historia", "Peruana"};
    libros[contador++] = {"Los Incas: Reyes del Sol", "Victor W. von Hagen", 1, 1961, "Historia", "Peruana"};
    libros[contador++] = {"La Guerra del Pacifico", "Jorge Basadre Grohmann", 1, 1946, "Historia", "Peruana"};
    libros[contador++] = {"Historia de la Republica del Peru", "Jorge Basadre Grohmann", 11, 2005, "Historia", "Peruana"};
    libros[contador++] = {"El Conflicto Armado Interno en Peru", "CVR", 1, 2003, "Historia", "Peruana"};

    //Historia - Universal
    libros[contador++] = {"Sapiens: De Animales a Dioses", "Yuval Noah Harari", 1, 2014, "Historia", "Universal"};
    libros[contador++] = {"Una Breve Historia del Mundo", "Ernst Gombrich", 1, 1935, "Historia", "Universal"};
    libros[contador++] = {"Armas, Germenes y Acero", "Jared Diamond", 1, 1997, "Historia", "Universal"};
    libros[contador++] = {"Historia Universal", "H.G. Wells", 1, 1920, "Historia", "Universal"};
    libros[contador++] = {"La Historia del Mundo en Cien Objetos", "Neil MacGregor", 1, 2010, "Historia", "Universal"};

    //Historia - Antigua
    libros[contador++] = {"Historia de Roma", "Mary Beard", 1, 2015, "Historia", "Antigua"};
    libros[contador++] = {"El Antiguo Egipto", "Toby Wilkinson", 1, 2010, "Historia", "Antigua"};
    libros[contador++] = {"Los Griegos", "H.D.F. Kitto", 1, 1951, "Historia", "Antigua"};
    libros[contador++] = {"El Cercano Oriente Antiguo", "Marc Van De Mieroop", 2, 2016, "Historia", "Antigua"};
    libros[contador++] = {"La Guerra del Peloponeso", "Tucidides", 1, -431, "Historia", "Antigua"};

    //Historia - Moderna
    libros[contador++] = {"El Siglo de las Luces", "Alejo Carpentier", 1, 1962, "Historia", "Moderna"};
    libros[contador++] = {"La Revolucion Francesa", "Michel Vovelle", 1, 1993, "Historia", "Moderna"};
    libros[contador++] = {"Historia de la Revolucion Rusa", "Leon Trotsky", 1, 1930, "Historia", "Moderna"};
    libros[contador++] = {"La Era de las Revoluciones", "Eric Hobsbawm", 1, 1962, "Historia", "Moderna"};
    libros[contador++] = {"El Mundo de Ayer", "Stefan Zweig", 1, 1942, "Historia", "Moderna"};

    //Historia - Contemporanea
    libros[contador++] = {"El Fin de la Historia y el Ultimo Hombre", "Francis Fukuyama", 1, 1992, "Historia", "Contemporanea"};
    libros[contador++] = {"La Era de los Extremos", "Eric Hobsbawm", 1, 1994, "Historia", "Contemporanea"};
    libros[contador++] = {"Los Origenes de la Segunda Guerra Mundial", "A.J.P. Taylor", 1, 1961, "Historia", "Contemporanea"};
    libros[contador++] = {"Guerra y Paz", "Leon Tolstoi", 1, 1869, "Historia", "Contemporanea"};
    libros[contador++] = {"Un Mundo Feliz", "Aldous Huxley", 1, 1932, "Historia", "Contemporanea"};

    //Filosofia - Etica
    libros[contador++] = {"Etica a Nicomaco", "Aristoteles", 1, -340, "Filosofia", "Etica"};
    libros[contador++] = {"Fundamentacion de la Metafisica de las Costumbres", "Immanuel Kant", 1, 1785, "Filosofia", "Etica"};
    libros[contador++] = {"Utilitarismo", "John Stuart Mill", 1, 1861, "Filosofia", "Etica"};
    libros[contador++] = {"Asi Hablo Zaratustra", "Friedrich Nietzsche", 1, 1883, "Filosofia", "Etica"};
    libros[contador++] = {"Sobre la Libertad", "John Stuart Mill", 1, 1859, "Filosofia", "Etica"};

    //Filosofia - Logica
    libros[contador++] = {"Logica", "Irving M. Copi", 14, 2011, "Filosofia", "Logica"};
    libros[contador++] = {"Introduccion a la Logica", "Alfred Tarski", 1, 1941, "Filosofia", "Logica"};
    libros[contador++] = {"Principia Mathematica", "Bertrand Russell", 1, 1910, "Filosofia", "Logica"};
    libros[contador++] = {"Investigaciones Filosoficas", "Ludwig Wittgenstein", 1, 1953, "Filosofia", "Logica"};
    libros[contador++] = {"El Organon", "Aristoteles", 1, -350, "Filosofia", "Logica"};

    //Filosofia - Metafisica
    libros[contador++] = {"Metafisica", "Aristoteles", 1, -350, "Filosofia", "Metafisica"};
    libros[contador++] = {"Critica de la Razon Pura", "Immanuel Kant", 1, 1781, "Filosofia", "Metafisica"};
    libros[contador++] = {"Ser y Tiempo", "Martin Heidegger", 1, 1927, "Filosofia", "Metafisica"};
    libros[contador++] = {"El Mundo como Voluntad y Representacion", "Arthur Schopenhauer", 1, 1818, "Filosofia", "Metafisica"};
    libros[contador++] = {"Discurso del Metodo", "Rene Descartes", 1, 1637, "Filosofia", "Metafisica"};

    //Filosofia - Epistemologia
    libros[contador++] = {"Investigacion sobre el Entendimiento Humano", "David Hume", 1, 1748, "Filosofia", "Epistemologia"};
    libros[contador++] = {"El Conocimiento Humano", "Bertrand Russell", 1, 1948, "Filosofia", "Epistemologia"};
    libros[contador++] = {"Logica de la Investigacion Cientifica", "Karl Popper", 1, 1934, "Filosofia", "Epistemologia"};
    libros[contador++] = {"Estructura de las Revoluciones Cientificas", "Thomas S. Kuhn", 1, 1962, "Filosofia", "Epistemologia"};
    libros[contador++] = {"Teoria del Conocimiento", "Johannes Hessen", 1, 1926, "Filosofia", "Epistemologia"};

    //Computacion - Programacion
    libros[contador++] = {"Principios de Programacion con C++", "Bjarne Stroustrup", 2, 2014, "Computacion", "Programacion"};
    libros[contador++] = {"Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", 1, 2008, "Computacion", "Programacion"};
    libros[contador++] = {"Code Complete", "Steve McConnell", 2, 2004, "Computacion", "Programacion"};
    libros[contador++] = {"Python Crash Course", "Eric Matthes", 2, 2019, "Computacion", "Programacion"};
    libros[contador++] = {"Refactoring: Improving the Design of Existing Code", "Martin Fowler", 2, 2018, "Computacion", "Programacion"};

    //Computacion - Algoritmos
    libros[contador++] = {"Introduccion a los Algoritmos", "Thomas H. Cormen", 4, 2022, "Computacion", "Algoritmos"};
    libros[contador++] = {"Algoritmos", "Robert Sedgewick", 4, 2011, "Computacion", "Algoritmos"};
    libros[contador++] = {"La Estructura y la Interpretacion de los Programas de Computadora", "Harold Abelson", 2, 1996, "Computacion", "Algoritmos"};
    libros[contador++] = {"The Art of Computer Programming, Vol. 1: Fundamental Algorithms", "Donald Knuth", 3, 1997, "Computacion", "Algoritmos"};
    libros[contador++] = {"Algoritmos y Estructuras de Datos", "Niklaus Wirth", 1, 1986, "Computacion", "Algoritmos"};

    //Computacion - Redes
    libros[contador++] = {"Redes de Computadoras", "Andrew S. Tanenbaum", 5, 2011, "Computacion", "Redes"};
    libros[contador++] = {"TCP/IP Illustrated, Vol. 1: The Protocols", "W. Richard Stevens", 1, 1993, "Computacion", "Redes"};
    libros[contador++] = {"CompTIA Network+ Study Guide", "Todd Lammle", 5, 2021, "Computacion", "Redes"};
    libros[contador++] = {"Interconexiones de Redes con TCP/IP Volumen 1", "Douglas E. Comer", 6, 2013, "Computacion", "Redes"};
    libros[contador++] = {"Cisco CCNA Routing and Switching Official Cert Guide", "Wendell Odom", 2, 2013, "Computacion", "Redes"};

    //Computacion - IA
    libros[contador++] = {"Inteligencia Artificial: Un Enfoque Moderno", "Stuart Russell", 4, 2020, "Computacion", "IA"};
    libros[contador++] = {"Aprendizaje Automatico", "Tom M. Mitchell", 1, 1997, "Computacion", "IA"};
    libros[contador++] = {"Deep Learning", "Ian Goodfellow", 1, 2016, "Computacion", "IA"};
    libros[contador++] = {"Programacion de la Inteligencia Artificial en Python", "Peter Norvig", 3, 2009, "Computacion", "IA"};
    libros[contador++] = {"Redes Neuronales y Aprendizaje Profundo", "Michael Nielsen", 1, 2015, "Computacion", "IA"};

    //Computacion - Bases de Datos
    libros[contador++] = {"Fundamentos de Sistemas de Bases de Datos", "Elmasri & Navathe", 7, 2015, "Computacion", "Bases de Datos"};
    libros[contador++] = {"SQL para Dummies", "Allen G. Taylor", 9, 2017, "Computacion", "Bases de Datos"};
    libros[contador++] = {"Database System Concepts", "Abraham Silberschatz", 7, 2019, "Computacion", "Bases de Datos"};
    libros[contador++] = {"Diseño de Bases de Datos Relacionales", "C.J. Date", 4, 2000, "Computacion", "Bases de Datos"};
    libros[contador++] = {"NoSQL Distilled: A Brief Guide to the Emerging World of Polyglot Persistence", "Pramod J. Sadalage", 1, 2012, "Computacion", "Bases de Datos"};

    // Economia - Microeconomia
    libros[contador++] = {"Principios de microeconomia", "Rosa Salazar", 1, 2018, "Economia", "Microeconomia"};
    libros[contador++] = {"Microeconomia intermedia", "Luis Camargo", 2, 2019, "Economia", "Microeconomia"};
    libros[contador++] = {"Teoria del consumidor", "Claudia Poma", 1, 2020, "Economia", "Microeconomia"};
    libros[contador++] = {"Analisis de oferta y demanda", "Carlos Huamani", 2, 2021, "Economia", "Microeconomia"};
    libros[contador++] = {"Estructura de mercados", "Elena Quispe", 1, 2022, "Economia", "Microeconomia"};
    libros[contador++] = {"Microeconomia aplicada", "Oscar Nina", 3, 2023, "Economia", "Microeconomia"};
    libros[contador++] = {"Costos de produccion", "Ana Ludeña", 1, 2020, "Economia", "Microeconomia"};
    libros[contador++] = {"Teoria de juegos", "Pedro Mamani", 1, 2021, "Economia", "Microeconomia"};
    libros[contador++] = {"Externalidades y bienes publicos", "Flor Caceres", 2, 2022, "Economia", "Microeconomia"};
    libros[contador++] = {"Mercados imperfectos", "Julio Paredes", 1, 2023, "Economia", "Microeconomia"};

    // Economia - Macroeconomia
    libros[contador++] = {"Fundamentos de macroeconomia", "Sofia Ramos", 1, 2018, "Economia", "Macroeconomia"};
    libros[contador++] = {"Macroeconomia intermedia", "Ricardo Calla", 2, 2019, "Economia", "Macroeconomia"};
    libros[contador++] = {"Inflacion y desempleo", "Carmen Huanca", 1, 2020, "Economia", "Macroeconomia"};
    libros[contador++] = {"Cuentas nacionales", "Javier Ticona", 2, 2021, "Economia", "Macroeconomia"};
    libros[contador++] = {"Politica monetaria", "Tatiana Chahuares", 1, 2022, "Economia", "Macroeconomia"};
    libros[contador++] = {"Crecimiento economico", "Renato Apaza", 3, 2023, "Economia", "Macroeconomia"};
    libros[contador++] = {"Ciclo economico", "Nataly Vizcarra", 1, 2020, "Economia", "Macroeconomia"};
    libros[contador++] = {"Modelo IS-LM", "Edgar Quispe", 2, 2021, "Economia", "Macroeconomia"};
    libros[contador++] = {"Balanza de pagos", "Lucia Nina", 1, 2022, "Economia", "Macroeconomia"};
    libros[contador++] = {"Mercado de trabajo", "Angelica Mendoza", 1, 2023, "Economia", "Macroeconomia"};

    // Economia - Finanzas
    libros[contador++] = {"Introduccion a las finanzas", "Hugo Poma", 1, 2018, "Economia", "Finanzas"};
    libros[contador++] = {"Finanzas corporativas", "Lorena Huamani", 2, 2019, "Economia", "Finanzas"};
    libros[contador++] = {"Mercado de capitales", "Jaime Chura", 1, 2020, "Economia", "Finanzas"};
    libros[contador++] = {"Inversiones financieras", "Lucero Lazo", 2, 2021, "Economia", "Finanzas"};
    libros[contador++] = {"Riesgo y rendimiento", "Victor Caceres", 1, 2022, "Economia", "Finanzas"};
    libros[contador++] = {"Analisis financiero", "Noemi Ramos", 3, 2023, "Economia", "Finanzas"};
    libros[contador++] = {"Valuacion de activos", "Carlos Apaza", 1, 2020, "Economia", "Finanzas"};
    libros[contador++] = {"Gestion financiera", "Evelyn Ticona", 2, 2021, "Economia", "Finanzas"};
    libros[contador++] = {"Presupuestos empresariales", "Fernando Quispe", 1, 2022, "Economia", "Finanzas"};
    libros[contador++] = {"Finanzas personales", "Diana Salas", 1, 2023, "Economia", "Finanzas"};

    // Economia - Contabilidad
    libros[contador++] = {"Contabilidad general", "Roxana Nina", 1, 2018, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad financiera", "Luis Huayta", 2, 2019, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad de costos", "Paola Rojas", 1, 2020, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad gerencial", "Juliana Chambi", 2, 2021, "Economia", "Contabilidad"};
    libros[contador++] = {"Estados financieros", "Erick Mamani", 1, 2022, "Economia", "Contabilidad"};
    libros[contador++] = {"Analisis contable", "Camila Vilca", 3, 2023, "Economia", "Contabilidad"};
    libros[contador++] = {"Normas contables", "Walter Calla", 1, 2020, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad tributaria", "Vanessa Nina", 2, 2021, "Economia", "Contabilidad"};
    libros[contador++] = {"Auditoria financiera", "Elmer Quispe", 1, 2022, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad para pymes", "Sandra Huamani", 1, 2023, "Economia", "Contabilidad"};

    // Ingenieria - Civil
    libros[contador++] = {"Fundamentos de ingenieria civil", "Luis Cardenas", 1, 2018, "Ingenieria", "Civil"};
    libros[contador++] = {"Diseño estructural basico", "Ana Rojas", 2, 2019, "Ingenieria", "Civil"};
    libros[contador++] = {"Construccion de carreteras", "Julio Pacheco", 1, 2020, "Ingenieria", "Civil"};
    libros[contador++] = {"Mecanica de suelos", "Rosa Luyo", 3, 2021, "Ingenieria", "Civil"};
    libros[contador++] = {"Hormigon armado", "Carlos Ninanya", 1, 2022, "Ingenieria", "Civil"};
    libros[contador++] = {"Gestion de proyectos civiles", "Esteban Quispe", 2, 2023, "Ingenieria", "Civil"};
    libros[contador++] = {"Topografia moderna", "Luz Mendoza", 1, 2021, "Ingenieria", "Civil"};
    libros[contador++] = {"Ingenieria hidraulica", "Victor Poma", 1, 2020, "Ingenieria", "Civil"};
    libros[contador++] = {"Patologia de estructuras", "Gladys Ramos", 2, 2022, "Ingenieria", "Civil"};
    libros[contador++] = {"Puentes y estructuras especiales", "Jose Ticona", 1, 2023, "Ingenieria", "Civil"};

    // Ingenieria - Mecanica
    libros[contador++] = {"Termodinamica basica", "Oscar Mamani", 1, 2019, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Resistencia de materiales", "Lucia Vargas", 2, 2020, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Mecanica de fluidos", "Pedro Nina", 3, 2021, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Maquinas termicas", "Diana Quispe", 1, 2022, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Diseño de maquinas", "Hector Ancco", 2, 2023, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Instrumentacion mecanica", "Ruth Apaza", 1, 2020, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Tecnicas de manufactura", "Marco Salazar", 2, 2021, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Vibraciones mecanicas", "Evelyn Paredes", 1, 2022, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Elementos de maquinas", "Arturo Ludeña", 1, 2023, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Analisis de mecanismos", "Sandra Flores", 2, 2019, "Ingenieria", "Mecanica"};

    // Ingenieria - Electrica
    libros[contador++] = {"Circuitos electricos", "Cesar Ramos", 1, 2018, "Ingenieria", "Electrica"};
    libros[contador++] = {"Maquinas electricas", "Natalia Huamani", 2, 2020, "Ingenieria", "Electrica"};
    libros[contador++] = {"Electrotecnia basica", "Luis Chahuares", 1, 2019, "Ingenieria", "Electrica"};
    libros[contador++] = {"Instalaciones electricas", "Veronica Salas", 3, 2021, "Ingenieria", "Electrica"};
    libros[contador++] = {"Transformadores", "Hugo Quispe", 2, 2022, "Ingenieria", "Electrica"};
    libros[contador++] = {"Proteccion de sistemas electricos", "Martha Apaza", 1, 2023, "Ingenieria", "Electrica"};
    libros[contador++] = {"Control automatico", "Ivan Chambi", 2, 2020, "Ingenieria", "Electrica"};
    libros[contador++] = {"Energia renovable", "Clara Lazo", 1, 2022, "Ingenieria", "Electrica"};
    libros[contador++] = {"Sistemas de potencia", "Gustavo Rojas", 3, 2023, "Ingenieria", "Electrica"};
    libros[contador++] = {"Alumbrado y eficiencia energetica", "Elena Huayta", 1, 2021, "Ingenieria", "Electrica"};

    // Ingenieria - Sistemas
    libros[contador++] = {"Programacion en C++", "Fernando Quispe", 1, 2018, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Base de datos relacional", "Roxana Calla", 2, 2019, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Ingenieria de software", "Carlos Vizcarra", 3, 2020, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Sistemas operativos", "Isabel Nina", 1, 2021, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Redes de computadoras", "Jaime Chura", 2, 2022, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Algoritmos y estructuras de datos", "Nancy Ramos", 1, 2023, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Desarrollo web", "Alvaro Mendoza", 2, 2020, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Inteligencia artificial", "Carmen Poma", 1, 2021, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Ciberseguridad basica", "Renzo Gutierrez", 1, 2022, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Arquitectura de computadoras", "Liliana Salazar", 3, 2023, "Ingenieria", "Sistemas"};

    // Ingenieria - Industrial
    libros[contador++] = {"Gestion de calidad", "Erika Vilca", 1, 2018, "Ingenieria", "Industrial"};
    libros[contador++] = {"Logistica y produccion", "Jorge Caceres", 2, 2019, "Ingenieria", "Industrial"};
    libros[contador++] = {"Investigacion de operaciones", "Carla Ludeña", 3, 2020, "Ingenieria", "Industrial"};
    libros[contador++] = {"Seguridad industrial", "Walter Huamani", 1, 2021, "Ingenieria", "Industrial"};
    libros[contador++] = {"Gestion de procesos", "Ines Paredes", 2, 2022, "Ingenieria", "Industrial"};
    libros[contador++] = {"Productividad y eficiencia", "Hernan Salas", 1, 2023, "Ingenieria", "Industrial"};
    libros[contador++] = {"Gestion del mantenimiento", "Yessica Chambi", 2, 2020, "Ingenieria", "Industrial"};
    libros[contador++] = {"Analisis de costos", "Raul Quispe", 1, 2021, "Ingenieria", "Industrial"};
    libros[contador++] = {"Ingenieria de metodos", "Diana Ticona", 2, 2022, "Ingenieria", "Industrial"};
    libros[contador++] = {"Estadistica aplicada", "Martin Calla", 1, 2023, "Ingenieria", "Industrial"};

    // Medicina - Anatomia
    libros[contador++] = {"Anatomia humana basica", "Luis Huamani", 1, 2018, "Medicina", "Anatomia"};
    libros[contador++] = {"Atlas de anatomia", "Rosa Quispe", 2, 2020, "Medicina", "Anatomia"};
    libros[contador++] = {"Anatomia para estudiantes", "Jorge Apaza", 3, 2019, "Medicina", "Anatomia"};
    libros[contador++] = {"Sistema oseo", "Elena Paredes", 1, 2021, "Medicina", "Anatomia"};
    libros[contador++] = {"Anatomia del sistema nervioso", "Carmen Luyo", 2, 2022, "Medicina", "Anatomia"};
    libros[contador++] = {"Anatomia funcional", "Walter Chura", 1, 2020, "Medicina", "Anatomia"};
    libros[contador++] = {"Guia de diseccion", "Margarita Calla", 1, 2019, "Medicina", "Anatomia"};
    libros[contador++] = {"Musculos y huesos", "Julio Pari", 2, 2021, "Medicina", "Anatomia"};
    libros[contador++] = {"Anatomia clinica", "Ana Romero", 1, 2022, "Medicina", "Anatomia"};
    libros[contador++] = {"Introduccion a la anatomia", "Carlos Yupanqui", 1, 2023, "Medicina", "Anatomia"};

    // Medicina - Fisiologia
    libros[contador++] = {"Fisiologia humana", "Lucia Valverde", 1, 2018, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fundamentos de fisiologia", "Oscar Mamani", 2, 2020, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia del sistema digestivo", "Sandra Huayta", 1, 2021, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia cardiovascular", "Victor Ancco", 2, 2022, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia pulmonar", "Mercedes Chuquimia", 1, 2019, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia aplicada", "Raul Ticona", 2, 2020, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia endocrina", "Ester Nina", 1, 2022, "Medicina", "Fisiologia"};
    libros[contador++] = {"Control del sistema nervioso", "Hector Rojas", 1, 2023, "Medicina", "Fisiologia"};
    libros[contador++] = {"Regulacion y homeostasis", "Maria Ludeña", 3, 2021, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia del movimiento", "Alberto Salazar", 2, 2020, "Medicina", "Fisiologia"};

    // Medicina - Farmacologia
    libros[contador++] = {"Introduccion a la farmacologia", "Daniela Vizcarra", 1, 2020, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacos esenciales", "Andres Ramos", 2, 2021, "Medicina", "Farmacologia"};
    libros[contador++] = {"Manual de farmacologia", "Veronica Zevallos", 1, 2022, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacologia clinica", "Ernesto Guzman", 1, 2019, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacocinetica basica", "Milagros Poma", 2, 2020, "Medicina", "Farmacologia"};
    libros[contador++] = {"Medicamentos del sistema nervioso", "Bruno Medina", 1, 2021, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacologia de urgencias", "Patricia Caceres", 1, 2023, "Medicina", "Farmacologia"};
    libros[contador++] = {"Interacciones farmacologicas", "Cesar Rivera", 2, 2022, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacos antimicrobianos", "Nora Galvez", 1, 2020, "Medicina", "Farmacologia"};
    libros[contador++] = {"Guia de medicamentos", "Jaime Loayza", 2, 2021, "Medicina", "Farmacologia"};

    // Medicina - General
    libros[contador++] = {"Principios de medicina general", "Isabel Flores", 1, 2018, "Medicina", "General"};
    libros[contador++] = {"Diagnostico clinico", "Felix Paredes", 2, 2019, "Medicina", "General"};
    libros[contador++] = {"Tratamiento ambulatorio", "Ruben Chambi", 1, 2020, "Medicina", "General"};
    libros[contador++] = {"Medicina preventiva", "Cecilia Asto", 2, 2021, "Medicina", "General"};
    libros[contador++] = {"Salud publica", "Norma Chahuares", 1, 2022, "Medicina", "General"};
    libros[contador++] = {"Manual del medico rural", "Hugo Ninanya", 1, 2023, "Medicina", "General"};
    libros[contador++] = {"Atencion primaria", "Paola Rojas", 2, 2020, "Medicina", "General"};
    libros[contador++] = {"Medicina basada en evidencia", "Renzo Torres", 1, 2022, "Medicina", "General"};
    libros[contador++] = {"Urgencias medicas", "Silvia Pacco", 2, 2021, "Medicina", "General"};
    libros[contador++] = {"Cuidados integrales", "Jesus Chumpitaz", 3, 2023, "Medicina", "General"};

    // Idioma - Ingles
    libros[contador++] = {"Guia de Ingles", "Maria Lopez", 1, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"Manual de Ingles", "Maria Lopez", 2, 2021, "Idioma", "Ingles"};
    libros[contador++] = {"Aprende Ingles", "Maria Lopez", 1, 2022, "Idioma", "Ingles"};
    libros[contador++] = {"Curso basico de Ingles", "Maria Lopez", 3, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"Introduccion a Ingles", "Maria Lopez", 1, 2021, "Idioma", "Ingles"};
    libros[contador++] = {"Domina Ingles", "Maria Lopez", 2, 2023, "Idioma", "Ingles"};
    libros[contador++] = {"Diccionario de Ingles", "Maria Lopez", 1, 2022, "Idioma", "Ingles"};
    libros[contador++] = {"Frases utiles en Ingles", "Maria Lopez", 2, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"Conversaciones en Ingles", "Maria Lopez", 1, 2023, "Idioma", "Ingles"};
    libros[contador++] = {"Gramatica de Ingles", "Maria Lopez", 3, 2021, "Idioma", "Ingles"};

    // Idioma - Frances
    libros[contador++] = {"Guia de Frances", "Jean Dupont", 1, 2020, "Idioma", "Frances"};
    libros[contador++] = {"Manual de Frances", "Jean Dupont", 2, 2021, "Idioma", "Frances"};
    libros[contador++] = {"Aprende Frances", "Jean Dupont", 1, 2022, "Idioma", "Frances"};
    libros[contador++] = {"Curso basico de Frances", "Jean Dupont", 3, 2020, "Idioma", "Frances"};
    libros[contador++] = {"Introduccion a Frances", "Jean Dupont", 1, 2021, "Idioma", "Frances"};
    libros[contador++] = {"Domina Frances", "Jean Dupont", 2, 2023, "Idioma", "Frances"};
    libros[contador++] = {"Diccionario de Frances", "Jean Dupont", 1, 2022, "Idioma", "Frances"};
    libros[contador++] = {"Frases utiles en Frances", "Jean Dupont", 2, 2020, "Idioma", "Frances"};
    libros[contador++] = {"Conversaciones en Frances", "Jean Dupont", 1, 2023, "Idioma", "Frances"};
    libros[contador++] = {"Gramatica de Frances", "Jean Dupont", 3, 2021, "Idioma", "Frances"};

    // Idioma - Quechua
    libros[contador++] = {"Guia de Quechua", "Rumi Huaman", 1, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"Manual de Quechua", "Rumi Huaman", 2, 2021, "Idioma", "Quechua"};
    libros[contador++] = {"Aprende Quechua", "Rumi Huaman", 1, 2022, "Idioma", "Quechua"};
    libros[contador++] = {"Curso basico de Quechua", "Rumi Huaman", 3, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"Introduccion a Quechua", "Rumi Huaman", 1, 2021, "Idioma", "Quechua"};
    libros[contador++] = {"Domina Quechua", "Rumi Huaman", 2, 2023, "Idioma", "Quechua"};
    libros[contador++] = {"Diccionario de Quechua", "Rumi Huaman", 1, 2022, "Idioma", "Quechua"};
    libros[contador++] = {"Frases utiles en Quechua", "Rumi Huaman", 2, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"Conversaciones en Quechua", "Rumi Huaman", 1, 2023, "Idioma", "Quechua"};
    libros[contador++] = {"Gramatica de Quechua", "Rumi Huaman", 3, 2021, "Idioma", "Quechua"};

    // Idioma - Aleman
    libros[contador++] = {"Guia de Aleman", "Hans Becker", 1, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"Manual de Aleman", "Hans Becker", 2, 2021, "Idioma", "Aleman"};
    libros[contador++] = {"Aprende Aleman", "Hans Becker", 1, 2022, "Idioma", "Aleman"};
    libros[contador++] = {"Curso basico de Aleman", "Hans Becker", 3, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"Introduccion a Aleman", "Hans Becker", 1, 2021, "Idioma", "Aleman"};
    libros[contador++] = {"Domina Aleman", "Hans Becker", 2, 2023, "Idioma", "Aleman"};
    libros[contador++] = {"Diccionario de Aleman", "Hans Becker", 1, 2022, "Idioma", "Aleman"};
    libros[contador++] = {"Frases utiles en Aleman", "Hans Becker", 2, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"Conversaciones en Aleman", "Hans Becker", 1, 2023, "Idioma", "Aleman"};
    libros[contador++] = {"Gramatica de Aleman", "Hans Becker", 3, 2021, "Idioma", "Aleman"};

    // Idioma - Chino
    libros[contador++] = {"Guia de Chino", "Li Zhang", 1, 2020, "Idioma", "Chino"};
    libros[contador++] = {"Manual de Chino", "Li Zhang", 2, 2021, "Idioma", "Chino"};
    libros[contador++] = {"Aprende Chino", "Li Zhang", 1, 2022, "Idioma", "Chino"};
    libros[contador++] = {"Curso basico de Chino", "Li Zhang", 3, 2020, "Idioma", "Chino"};
    libros[contador++] = {"Introduccion a Chino", "Li Zhang", 1, 2021, "Idioma", "Chino"};
    libros[contador++] = {"Domina Chino", "Li Zhang", 2, 2023, "Idioma", "Chino"};
    libros[contador++] = {"Diccionario de Chino", "Li Zhang", 1, 2022, "Idioma", "Chino"};
    libros[contador++] = {"Frases utiles en Chino", "Li Zhang", 2, 2020, "Idioma", "Chino"};
    libros[contador++] = {"Conversaciones en Chino", "Li Zhang", 1, 2023, "Idioma", "Chino"};
    libros[contador++] = {"Gramatica de Chino", "Li Zhang", 3, 2021, "Idioma", "Chino"};

}

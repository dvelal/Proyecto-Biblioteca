#include <iostream>
#include <string>
#include <ctime> 
#include <windows.h>
#include <iomanip>
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

void mostrarLibros(Libro[], int);

void buscarLibro(Libro[], int, int, string, string, string, string);

void leerLibro(Libro &, string, string, int, int, string, string);

void leercliente(Cliente &, string, int, int);

void imprimecliente(Cliente &);

void imprimelibro(Libro &);

void prestarLibro(Libro[], int, string, string, int);

void devolverLibro(Libro[], int, string, string, int);

void cargarLibrosPredefinidos(Libro[], int &);

int main() {
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
                mostrarLibros(libros, contadorLibros);
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

void mostrarLibros(Libro libros[], int cantidad) {
    cout << "\nLista de libros registrados:\n";
    cout << left
         << setw(60) << "Titulo"
         << setw(30) << "Autor"
         << setw(10) << "Edicion"
         << setw(10) << "Anio"
         << setw(12) << "Categoria"
         << setw(25) << "Subcategoria" 
         << setw(15) << "Estado" << endl;

    cout << string(132, '-') << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << left
             << setw(60) << libros[i].titulo
             << setw(30) << libros[i].autor
             << setw(10) << libros[i].edicion
             << setw(10) << libros[i].anio
             << setw(12) << libros[i].categoria
             << setw(25) << libros[i].subcategoria 
             << setw(15) << libros[i].estado << endl;
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

void cargarLibrosPredefinidos(Libro libros[], int &contador) {

    //Matematica - Calculo
    libros[contador++] = {"Calculo", "James Stewart", 8, 2020, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo I", "Luis Antonio Arana", 2, 2019, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo Diferencial", "Julio Rios", 3, 2016, "Matematica", "Calculo"};
    libros[contador++] = {"Matematica para Ingenieria", "Carlos Zavala", 1, 2015, "Matematica", "Calculo"};
    libros[contador++] = {"Curso de Calculo", "Pedro Poma", 4, 2018, "Matematica", "Calculo"};
    libros[contador++] = {"Introduccion al Calculo", "Manuel Ventura", 1, 2014, "Matematica", "Calculo"};
    libros[contador++] = {"Fundamentos de Matematica", "Walter Apaza", 2, 2021, "Matematica", "Calculo"};

    //Matematica - Algebra
    libros[contador++] = {"Algebra Lineal", "David Lay", 5, 2016, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra I", "Luis Antonio Arana", 3, 2020, "Matematica", "Algebra"};
    libros[contador++] = {"Problemas de Algebra", "Walter Apaza", 2, 2019, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra Elemental", "Cesar Delgado", 1, 2015, "Matematica", "Algebra"};
    libros[contador++] = {"Curso de Algebra", "Pedro Poma", 4, 2017, "Matematica", "Algebra"};
    libros[contador++] = {"Teoria y Practica de Algebra", "Jose Rojas", 2, 2018, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra Basica para pre", "Jorge Pineda", 1, 2016, "Matematica", "Algebra"};

    //Matematica - Ecuaciones Diferenciales
    libros[contador++] = {"Ecuaciones Diferenciales con Aplicaciones de Modelado", "Dennis G. Zill", 11, 2018, "Matematica", "Ecuaciones Diferenciales"};
    libros[contador++] = {"Curso de Ecuaciones Diferenciales", "Richard C. DiPrima", 7, 2012, "Matematica", "Ecuaciones Diferenciales"};
    libros[contador++] = {"Introduccion a las Ecuaciones Diferenciales", "Serge Lang", 1, 1990, "Matematica", "Ecuaciones Diferenciales"};
    libros[contador++] = {"Ecuaciones Diferenciales Aplicadas", "Murray R. Spiegel", 3, 2004, "Matematica", "Ecuaciones Diferenciales"};
    libros[contador++] = {"Metodos Matematicos para Ingenieros y Cientificos", "George B. Arfken", 7, 2012, "Matematica", "Ecuaciones Diferenciales"};
    libros[contador++] = {"Ecuaciones Diferenciales Parciales", "L.C. Evans", 2, 2010, "Matematica", "Ecuaciones Diferenciales"};

    //Matematica - Estadistica
    libros[contador++] = {"Estadistica Matematica con Aplicaciones", "John E. Freund", 8, 2010, "Matematica", "Estadistica"};
    libros[contador++] = {"Probabilidad y Estadistica para Ingenieria y Ciencias", "Ronald E. Walpole", 9, 2012, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica para Administracion y Economia", "Richard I. Levin", 7, 1999, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Descriptiva e Inferencial", "Mario F. Triola", 13, 2018, "Matematica", "Estadistica"};
    libros[contador++] = {"Introduccion a la Estadistica", "Sheldon M. Ross", 3, 2010, "Matematica", "Estadistica"};
    libros[contador++] = {"Principios de Estadistica", "W.C. Scheaffer", 3, 2009, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Aplicada a los Negocios y la Economia", "Douglas A. Lind", 17, 2019, "Matematica", "Estadistica"};

    //Matematica - Geometria Diferencial
    libros[contador++] = {"Geometria Diferencial de Curvas y Superficies", "Manfredo P. do Carmo", 2, 2016, "Matematica", "Geometria Diferencial"};
    libros[contador++] = {"Introduccion a la Geometria Diferencial", "Andrew Pressley", 2, 2010, "Matematica", "Geometria Diferencial"};
    libros[contador++] = {"Geometria Diferencial", "Michael Spivak", 3, 1999, "Matematica", "Geometria Diferencial"};
    libros[contador++] = {"Notas de Geometria Diferencial", "Oscar Garcia-Prada", 1, 2005, "Matematica", "Geometria Diferencial"};
    libros[contador++] = {"Fundamentos de Geometria Diferencial", "Sigurdur Helgason", 2, 2001, "Matematica", "Geometria Diferencial"};
    libros[contador++] = {"Un Curso en Geometria Diferencial", "W.P. Ziemer", 1, 2009, "Matematica", "Geometria Diferencial"};
    libros[contador++] = {"Geometria Diferencial: Curvas y Superficies", "Antonio Fernandez", 1, 2010, "Matematica", "Geometria Diferencial"};

    //Matematica - Teoria de Numeros
    libros[contador++] = {"Introduccion a la Teoria de Numeros", "David M. Burton", 7, 2012, "Matematica", "Teoria de Numeros"};
    libros[contador++] = {"Teoria de Numeros", "G.H. Hardy", 6, 2008, "Matematica", "Teoria de Numeros"};
    libros[contador++] = {"Una Introduccion a la Teoria de Numeros", "Ivan Niven", 5, 1991, "Matematica", "Teoria de Numeros"};
    libros[contador++] = {"Problemas de Teoria de Numeros", "D. M. Burton", 1, 2006, "Matematica", "Teoria de Numeros"};
    libros[contador++] = {"Fundamentos de Teoria de Numeros", "William J. LeVeque", 1, 1977, "Matematica", "Teoria de Numeros"};
    libros[contador++] = {"Teoria de Numeros Elementales", "Joseph H. Silverman", 1, 2018, "Matematica", "Teoria de Numeros"};
    libros[contador++] = {"Teoria de Numeros para Principiantes", "Kim S. Kwong", 1, 2019, "Matematica", "Teoria de Numeros"};

    //Matematica - Topologia
    libros[contador++] = {"Topologia", "James R. Munkres", 2, 2000, "Matematica", "Topologia"};
    libros[contador++] = {"Elementos de Topologia General", "S. W. Davis", 1, 2005, "Matematica", "Topologia"};
    libros[contador++] = {"Topologia General", "Stephen Willard", 1, 2004, "Matematica", "Topologia"};
    libros[contador++] = {"Una Introduccion a la Topologia", "Bert Mendelson", 3, 1990, "Matematica", "Topologia"};
    libros[contador++] = {"Topologia en Contexto", "Paul L. Shick", 1, 2007, "Matematica", "Topologia"};
    libros[contador++] = {"Conceptos Basicos de Topologia", "Mark A. Armstrong", 1, 1983, "Matematica", "Topologia"};
    libros[contador++] = {"Topologia y Geometria", "Glen E. Bredon", 1, 1993, "Matematica", "Topologia"};
    
    //Ciencias - Fisica
    libros[contador++] = {"Fisica Universitaria", "Sears", 13, 2021, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica I", "Luis Antonio Arana", 2, 2019, "Ciencias", "Fisica"};
    libros[contador++] = {"Problemas de Fisica", "Walter Apaza", 3, 2020, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica General", "Julio Silva", 2, 2017, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica para Ingenieria", "Carlos Zavala", 1, 2016, "Ciencias", "Fisica"};
    libros[contador++] = {"Fundamentos de Fisica", "Manuel Ventura", 1, 2015, "Ciencias", "Fisica"};
    libros[contador++] = {"Ejercicios de Fisica Universitaria", "Jose Cardenas", 1, 2021, "Ciencias", "Fisica"};

    //Ciencias - Quimica
    libros[contador++] = {"Quimica General", "Zumdahl", 7, 2012, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica I", "Luis Antonio Arana", 2, 2018, "Ciencias", "Quimica"};
    libros[contador++] = {"Problemas de Quimica", "Walter Apaza", 3, 2019, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica General", "Julio Silva", 2, 2015, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica para Ingenieria", "Carlos Zavala", 1, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"Fundamentos de Quimica", "Manuel Ventura", 1, 2017, "Ciencias", "Quimica"};
    libros[contador++] = {"Ejercicios de Quimica Basica", "Jose Cardenas", 1, 2021, "Ciencias", "Quimica"};

    //Ciencias - Astronomia
    libros[contador++] = {"Cosmos", "Carl Sagan", 1, 1980, "Ciencias", "Astronomia"};
    libros[contador++] = {"Astrophysics for People in a Hurry", "Neil deGrasse Tyson", 1, 2017, "Ciencias", "Astronomia"};
    libros[contador++] = {"Una Breve Historia de Casi Todo", "Bill Bryson", 1, 2003, "Ciencias", "Astronomia"};
    libros[contador++] = {"El Universo en una Cascara de Nuez", "Stephen Hawking", 1, 2001, "Ciencias", "Astronomia"};
    libros[contador++] = {"Pale Blue Dot", "Carl Sagan", 1, 1994, "Ciencias", "Astronomia"};
    libros[contador++] = {"Los Pilares de la Creacion", "Alan Hirshfeld", 1, 2002, "Ciencias", "Astronomia"};
    libros[contador++] = {"Historia del Tiempo", "Stephen Hawking", 1, 1988, "Ciencias", "Astronomia"};

    //Ciencias - Biologia
    libros[contador++] = {"Biologia", "Neil A. Campbell", 11, 2017, "Ciencias", "Biologia"};
    libros[contador++] = {"Biologia Celular y Molecular", "Gerald Karp", 8, 2016, "Ciencias", "Biologia"};
    libros[contador++] = {"El Origen de las Especies", "Charles Darwin", 1, 1859, "Ciencias", "Biologia"};
    libros[contador++] = {"Genes, Desarrollo y Genomas", "Nancy Hopkins", 1, 2002, "Ciencias", "Biologia"};
    libros[contador++] = {"Principios de Bioquimica", "Albert L. Lehninger", 7, 2017, "Ciencias", "Biologia"};
    libros[contador++] = {"La Doble Helice", "James D. Watson", 1, 1968, "Ciencias", "Biologia"};
    libros[contador++] = {"Microbiologia", "Prescott's", 11, 2020, "Ciencias", "Biologia"};

    //Ciencias - Geologia
    libros[contador++] = {"Fundamentos de Geologia Fisica", "Arthur N. Strahler", 5, 2011, "Ciencias", "Geologia"};
    libros[contador++] = {"Geologia Ambiental", "Edward A. Keller", 11, 2019, "Ciencias", "Geologia"};
    libros[contador++] = {"Geologia General", "Richard Foster Flint", 3, 1983, "Ciencias", "Geologia"};
    libros[contador++] = {"La Historia de la Tierra", "Robert M. Hazen", 2, 2012, "Ciencias", "Geologia"};
    libros[contador++] = {"Geologia de Campo", "F.J. Grout", 1, 1971, "Ciencias", "Geologia"};
    libros[contador++] = {"Introduccion a la Geologia", "Frederick K. Lutgens", 13, 2016, "Ciencias", "Geologia"};
    libros[contador++] = {"Vulcanologia", "Hans-Ulrich Schmincke", 2, 2004, "Ciencias", "Geologia"};

    //Ciencias - Ecologia
    libros[contador++] = {"Ecologia: Principios y Aplicaciones", "Manuel C. Molles Jr.", 8, 2018, "Ciencias", "Ecologia"};
    libros[contador++] = {"Fundamentos de Ecologia", "Eugene P. Odum", 5, 2005, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Humana", "Gerald G. Marten", 1, 2001, "Ciencias", "Ecologia"};
    libros[contador++] = {"Conservacion de la Biodiversidad", "Richard B. Primack", 8, 2018, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Urbana", "Marina Alberti", 1, 2008, "Ciencias", "Ecologia"};
    libros[contador++] = {"Los Limites del Crecimiento", "Donella H. Meadows", 1, 1972, "Ciencias", "Ecologia"};
    libros[contador++] = {"Principios de Ecologia de Poblaciones", "Thomas M. Smith", 1, 2009, "Ciencias", "Ecologia"};

    //Ciencias - Neurociencia
    libros[contador++] = {"Principios de Neurociencia", "Eric R. Kandel", 5, 2013, "Ciencias", "Neurociencia"};
    libros[contador++] = {"Neurociencia Cognitiva", "Michael S. Gazzaniga", 5, 2018, "Ciencias", "Neurociencia"};
    libros[contador++] = {"Fundamentos de Neurociencia", "Dale Purves", 4, 2012, "Ciencias", "Neurociencia"};
    libros[contador++] = {"La Mente de la Mente", "Oliver Sacks", 1, 2010, "Ciencias", "Neurociencia"};
    libros[contador++] = {"El Cerebro: La Historia de Usted", "David Eagleman", 1, 2015, "Ciencias", "Neurociencia"};
    libros[contador++] = {"Neurociencia del Comportamiento", "Marc Breedlove", 8, 2016, "Ciencias", "Neurociencia"};
    libros[contador++] = {"Introduccion a la Neurociencia", "Dale Purves", 1, 2000, "Ciencias", "Neurociencia"};
    
    //Literatura - Peruana
    libros[contador++] = {"Los rios profundos", "Jose Arguedas", 1, 1958, "Literatura", "Peruana"};
    libros[contador++] = {"Los rios profundos", "Jose Maria Arguedas", 1, 1958, "Literatura", "Peruana"};
    libros[contador++] = {"El zorro de arriba y el zorro de abajo", "Jose Maria Arguedas", 1, 1971, "Literatura", "Peruana"};
    libros[contador++] = {"La ciudad y los perros", "Mario Vargas Llosa", 1, 1963, "Literatura", "Peruana"};
    libros[contador++] = {"Conversacion en La Catedral", "Mario Vargas Llosa", 1, 1969, "Literatura", "Peruana"};
    libros[contador++] = {"Aves sin nido", "Clorinda Matto de Turner", 1, 1889, "Literatura", "Peruana"};
    libros[contador++] = {"El tungsteno", "Cesar Vallejo", 1, 1931, "Literatura", "Peruana"};

    // Literatura - Argentina
    libros[contador++] = {"Ficciones", "Jorge Luis Borges", 1, 1944, "Literatura", "Argentina"};
    libros[contador++] = {"Rayuela", "Julio Cortazar", 1, 1963, "Literatura", "Argentina"};
    libros[contador++] = {"El Tunel", "Ernesto Sabato", 1, 1948, "Literatura", "Argentina"};
    libros[contador++] = {"Martin Fierro", "Jose Hernandez", 1, 1872, "Literatura", "Argentina"};
    libros[contador++] = {"Adan Buenosayres", "Leopoldo Marechal", 1, 1948, "Literatura", "Argentina"};
    libros[contador++] = {"Boquitas Pintadas", "Manuel Puig", 1, 1969, "Literatura", "Argentina"};

    // Literatura - Espana
    libros[contador++] = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1, 1605, "Literatura", "Espana"};
    libros[contador++] = {"La Sombra del Viento", "Carlos Ruiz Zafon", 1, 2001, "Literatura", "Espana"};
    libros[contador++] = {"La Casa de Bernarda Alba", "Federico Garcia Lorca", 1, 1936, "Literatura", "Espana"};
    libros[contador++] = {"Nada", "Carmen Laforet", 1, 1945, "Literatura", "Espana"};
    libros[contador++] = {"Platero y Yo", "Juan Ramon Jimenez", 1, 1914, "Literatura", "Espana"};
    libros[contador++] = {"El Lazarillo de Tormes", "Anonimo", 1, 1554, "Literatura", "Espana"};

    // Literatura - Mexico
    libros[contador++] = {"Pedro Paramo", "Juan Rulfo", 1, 1955, "Literatura", "Mexico"};
    libros[contador++] = {"Como Agua para Chocolate", "Laura Esquivel", 1, 1989, "Literatura", "Mexico"};
    libros[contador++] = {"Aura", "Carlos Fuentes", 1, 1962, "Literatura", "Mexico"};
    libros[contador++] = {"El Laberinto de la Soledad", "Octavio Paz", 1, 1950, "Literatura", "Mexico"};
    libros[contador++] = {"Los de Abajo", "Mariano Azuela", 1, 1915, "Literatura", "Mexico"};
    libros[contador++] = {"Balun Canan", "Rosario Castellanos", 1, 1957, "Literatura", "Mexico"};

    // Literatura - Colombia
    libros[contador++] = {"Cien Anos de Soledad", "Gabriel Garcia Marquez", 1, 1967, "Literatura", "Colombia"};
    libros[contador++] = {"El Amor en los Tiempos del Colera", "Gabriel Garcia Marquez", 1, 1985, "Literatura", "Colombia"};
    libros[contador++] = {"La Voragine", "Jose Eustasio Rivera", 1, 1924, "Literatura", "Colombia"};
    libros[contador++] = {"Cronica de una Muerte Anunciada", "Gabriel Garcia Marquez", 1, 1981, "Literatura", "Colombia"};
    libros[contador++] = {"Maria", "Jorge Isaacs", 1, 1867, "Literatura", "Colombia"};
    libros[contador++] = {"El Coronel no tiene quien le escriba", "Gabriel Garcia Marquez", 1, 1961, "Literatura", "Colombia"};
    libros[contador++] = {"Del Amor y Otros Demonios", "Gabriel Garcia Marquez", 1, 1994, "Literatura", "Colombia"};

    // Literatura - Chile
    libros[contador++] = {"Veinte Poemas de Amor y una Cancion Desesperada", "Pablo Neruda", 1, 1924, "Literatura", "Chile"};
    libros[contador++] = {"La Casa de los Espiritus", "Isabel Allende", 1, 1982, "Literatura", "Chile"};
    libros[contador++] = {"Canto General", "Pablo Neruda", 1, 1950, "Literatura", "Chile"};
    libros[contador++] = {"El Cartero de Neruda (Ardiente Paciencia)", "Antonio Skarmeta", 1, 1985, "Literatura", "Chile"};
    libros[contador++] = {"Hijo de Ladron", "Manuel Rojas", 1, 1951, "Literatura", "Chile"};
    libros[contador++] = {"Nocturno de Chile", "Roberto Bolano", 1, 2000, "Literatura", "Chile"};

    // Literatura - Cuba
    libros[contador++] = {"El Reino de Este Mundo", "Alejo Carpentier", 1, 1949, "Literatura", "Cuba"};
    libros[contador++] = {"Tres Tristes Tigres", "Guillermo Cabrera Infante", 1, 1967, "Literatura", "Cuba"};
    libros[contador++] = {"Paradiso", "Jose Lezama Lima", 1, 1966, "Literatura", "Cuba"};
    libros[contador++] = {"Cecilia Valdes", "Cirilo Villaverde", 1, 1882, "Literatura", "Cuba"};
    libros[contador++] = {"La Edad de Oro", "Jose Marti", 1, 1889, "Literatura", "Cuba"};
    libros[contador++] = {"Memorias del Subdesarrollo", "Edmundo Desnoes", 1, 1965, "Literatura", "Cuba"};
    libros[contador++] = {"Antes que Anochezca", "Reinaldo Arenas", 1, 1992, "Literatura", "Cuba"};

}

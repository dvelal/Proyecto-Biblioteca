#include <iostream>
#include <string>
using namespace std;

// Definición completa de la estructura Libro
struct Libro {
    string nombreLibro;
    string autor;
    int edicion;
};

void leerLibro(Libro &libro, string nombre, string autor, int edicion) {
    libro.nombreLibro = nombre;
    libro.autor = autor;
    libro.edicion = edicion;
}

int main() {
    Libro libros[1000];
    int contadorLibros = 0;
    int op;
    char op1;

    do {
        cout << "\n--- Biblioteca Virtual ---\n";
        cout << "1. Añadir un libro\n";
        cout << "2. Mostrar libros\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> op;
        cin.ignore(); 
        system("cls");

        switch (op) {
            case 1: {
                string nombre, autor;
                int edicion;
                cout << "Nombre del libro: ";
                getline(cin, nombre);
                cout << "Autor: ";
                getline(cin, autor);
                cout << "Edicion: ";
                cin >> edicion;
                cin.ignore();

                leerLibro(libros[contadorLibros], nombre, autor, edicion);
                contadorLibros++;
                cout << "Libro añadido con exito.\n";
                system("pause");
                break;
            }

            case 2: {
                cout << "\nLibros registrados:\n";
                for (int i = 0; i < contadorLibros; i++) {
                    cout << i+1 << ". " << libros[i].nombreLibro
                         << " - " << libros[i].autor
                         << " (Edicion " << libros[i].edicion << ")\n";
                }
                system("pause");
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
                cout << "Opción inválida.\n";
        }
        system("cls");
    } while (op != 0);

    return 0;
}
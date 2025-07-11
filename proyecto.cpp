#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int edicion;
    int anio;
};

void buscarLibro(Libro[], int, string, string);

void leerLibro(Libro &, string, string, int, int);

void imprimelibro(Libro &);

int main() {
    Libro libros[1000];
    int contadorLibros = 0;
    int op;
    char op1;
    string titulo, autor;
    int edicion, anio;

    do {
        cout << "\n--- Biblioteca Virtual ---\n";
        cout << "1. Buscar libro\n";
        cout << "2. Agregar un libro\n";
        cout << "3. Mostrar libros\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> op;
        cin.ignore(); 
        system("pause");
        system("cls");

        switch (op) {
            case 1: {
                cout << "Ingrese el titulo del libro a buscar: ";
                getline(cin, titulo);  
                cout << "Ingrese el autor del libro a buscar: ";
                getline(cin, autor);
                buscarLibro(libros, contadorLibros, titulo, autor);
                system("pause");
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

                leerLibro(libros[contadorLibros], titulo, autor, edicion, anio);
                contadorLibros++;
                cout << "Libro agregado con exito.\n";
                system("pause");
                break;
            }

            case 3: {
                cout << "\nLibros registrados:\n";
                for (int i = 0; i < contadorLibros; i++) {
                    cout<<"Libro #"<<i+1<<endl;
                    imprimelibro(libros[i]);
                    cout << endl;
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
                cout << "Opcion invalida.\n";
        }
        system("cls");
    } while (op != 0);

    return 0;
}

void buscarLibro(Libro libros[], int cant, string titulo, string autor) {
    int encontra = 0;
    for (int i = 0; i < cant; i++){
        if (libros[i].titulo == titulo && libros[i].autor == autor){
            cout << "\nLibro encontrado:\n";
            imprimelibro(libros[i]);
            encontra=i+1;
        }
    }
    if (encontra == 0){
        cout << "No existe el libro"<<endl;
    }
}

void imprimelibro(Libro &l){
    cout << "Libro: "<< l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "Edicion: " << l.edicion << endl;
    cout << "Anio: " << l.anio << endl;
}

void leerLibro(Libro &l, string titulo, string autor, int edicion, int anio) {
    l.titulo = titulo;
    l.autor = autor;
    l.edicion = edicion;
    l.anio = anio;
}

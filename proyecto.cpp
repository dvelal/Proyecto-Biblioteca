#include <iostream>
using namespace std;

struct Cliente;
string nom;
int edad;

struct Libro;
string noml;
string autor;
int edic;

void leerlibro(Libro &, string,string,int);

int main() {
    Cli Cliente[100];
    Li Libro[1000];
    int op,edad,edic;
    string autor,nom, noml;
    char op1;
    do {
        cout<<"Bienvenido a la biblioteca virtual"<<endl;
        cout<<"Menu de opciones----------------------------------------------------------------"<<endl;
        cout<<"1. Buscar un libro"<<endl;
        cout<<"2. Añadir un libro"<<endl;
        cout<<"3. Mostrar libros"<<endl;
        cout<<"4. Alquilar un libro"<<endl;
        cout<<"5. Devolver un libro"<<endl;
        cout<<"0. Salir"<<endl;
        switch (op){
            case 0:
                cout<<"¿Seguro que desea salir (S/N)?"<<endl;
                cin>>op1;
                switch (op1){
                    case 'S':
                        cout<<"Fin del programa"<<endl;
                        system("pause");
                        break;
                    case 'N':
                        op++;
                        break;
                }         
                break;
            case 2:
                cout<<"Ingrese la información del libro"<<endl;
                cin.ignore();
                cout<<"Nombre del libro"<<getline(Li,noml);
                cout<<"Nombre del autor ";
                cin>>nom;
                cout<<"N° de edición ";
                cin>>edic;
                leerlibro(Li,noml,nom,edic);
            case 3:
                cout<<"Ingrese la información del libro"<<endl;
                cout<<"Nombre del libro"<<getline(Li,noml);
                cout<<"Nombre del autor "<<nom;
                cout<<"N° de edición "<<edic;
        }
    }while!=0
    return 0;
}

void leerlibro(Libro &, string nom,string a,int e){
    libro.noml=nom;
    libro.autor=a;
    libro.edic=e;
}
#include "utilidades.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

string amarillo = "\033[1;33m";
string verde = "\033[0;32m";
string rojo = "\033[0;31m";
string azul = "\033[0;34m";
string magenta = "\033[0;35m";
string cian = "\033[1;36m";
string reset = "\033[0m";

void limpiarPantalla() {
    system("cls");
}

void pausar() {
    system("pause");
}

bool validarEntradaNumerica() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        return false;
    }
    return true;
}

void solicitarDato(const string& mensaje, string& variable) {
    do {
        cout << mensaje;
        getline(cin, variable);
        if (variable.empty()) {
            cout << rojo << "Entrada no puede estar vacia. Intente nuevamente.\n" << reset;
        }
    } while (variable.empty());
}

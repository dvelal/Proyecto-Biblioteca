#include "utilidades.h"
#include <cstdlib>
#include <string>
using namespace std;

// Códigos para utilizar los colores de la libreria windows.h
string amarillo = "\033[1;33m";
string verde = "\033[0;32m";
string rojo = "\033[0;31m";
string azul = "\033[0;34m";
string magenta = "\033[0;35m";
string cian = "\033[1;36m";
string reset = "\033[0m";

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    system("pause");
}

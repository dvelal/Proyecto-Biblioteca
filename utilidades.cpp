#include "utilidades.h"
#include <cstdlib>

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

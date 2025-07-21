#include "libros.h"
#include "struclibro.h"
// Permite usar la lista de inicialización {} para llenar los campos de una estructura en el mismo orden en que fueron definidos.
void cargarLibrosPredefinidos(Libro libros[], int &contador) {
    
    libros[contador++] = {1, "Calculo", "James Stewart", 8, 2020, "Matematica", "Calculo"};
    libros[contador++] = {2, "Calculo I", "Luis Arana", 2, 2019, "Matematica", "Calculo"};
    libros[contador++] = {3, "Dif. Calculo", "Julio Rios", 3, 2016, "Matematica", "Calculo"};
    libros[contador++] = {4, "Int. Calculo", "Pedro Poma", 4, 2018, "Matematica", "Calculo"};
    libros[contador++] = {5, "Curso Calculo", "Carlos Zavala", 1, 2015, "Matematica", "Calculo"};
    libros[contador++] = {6, "Algebra I", "Luis Cardozo", 1, 2018, "Matematica", "Algebra"};
    libros[contador++] = {7, "Algebra Lineal", "Gilbert Strang", 4, 2016, "Matematica", "Algebra"};
    libros[contador++] = {8, "Curso Algebra", "Carlos Cieza", 2, 2020, "Matematica", "Algebra"};
    libros[contador++] = {9, "Problemas Algebra", "Julio Ruiz", 3, 2017, "Matematica", "Algebra"};
    libros[contador++] = {10, "Fund. Algebra", "Marco Medina", 2, 2019, "Matematica", "Algebra"};
    libros[contador++] = {11, "Geometria I", "Ana Castillo", 1, 2018, "Matematica", "Geometria"};
    libros[contador++] = {12, "Geometria Analitica", "Santiago Gomez", 2, 2017, "Matematica", "Geometria"};
    libros[contador++] = {13, "Curso Geometria", "Felipe Ramos", 1, 2020, "Matematica", "Geometria"};
    libros[contador++] = {14, "Geometria Descriptiva", "Rosa Medina", 2, 2016, "Matematica", "Geometria"};
    libros[contador++] = {15, "Ejercicios Geometria", "Julia Sosa", 2, 2018, "Matematica", "Geometria"};
    libros[contador++] = {16, "Aritmetica Basica", "Luis Ramos", 1, 2015, "Matematica", "Aritmetica"};
    libros[contador++] = {17, "Curso Aritmetica", "Diana Quispe", 2, 2017, "Matematica", "Aritmetica"};
    libros[contador++] = {18, "Problemas Aritmetica", "Carlos Mena", 3, 2016, "Matematica", "Aritmetica"};
    libros[contador++] = {19, "Fund. Aritmetica", "Paola Vega", 1, 2019, "Matematica", "Aritmetica"};
    libros[contador++] = {20, "Aritmetica Rapida", "Juan Castro", 2, 2018, "Matematica", "Aritmetica"};
    libros[contador++] = {21, "Estadistica I", "Juan Vargas", 1, 2018, "Matematica", "Estadistica"};
    libros[contador++] = {22, "Curso Estadistica", "Andrea Solis", 2, 2020, "Matematica", "Estadistica"};
    libros[contador++] = {23, "Prob. y Estadistica", "Luis Cano", 3, 2019, "Matematica", "Estadistica"};
    libros[contador++] = {24, "Estadistica Aplicada", "Miguel Rios", 1, 2021, "Matematica", "Estadistica"};
    libros[contador++] = {25, "Ejercicios Estadistica", "Laura Moreno", 2, 2017, "Matematica", "Estadistica"};
    libros[contador++] = {26, "Trigonometria I", "David Ramos", 1, 2018, "Matematica", "Trigonometria"};
    libros[contador++] = {27, "Curso Trigonometria", "Ana Rojas", 2, 2019, "Matematica", "Trigonometria"};
    libros[contador++] = {28, "Fund. Trigonometria", "Marco Leon", 1, 2020, "Matematica", "Trigonometria"};
    libros[contador++] = {29, "Trigonometria y Func.", "Nelly Diaz", 3, 2016, "Matematica", "Trigonometria"};
    libros[contador++] = {30, "Problemas Trigonom.", "Esteban Ruiz", 1, 2017, "Matematica", "Trigonometria"};
    libros[contador++] = {31, "Quimica I", "Chang Raymond", 5, 2015, "Ciencias", "Quimica"};
    libros[contador++] = {32, "Curso Quimica", "Pedro Lopez", 2, 2017, "Ciencias", "Quimica"};
    libros[contador++] = {33, "Quimica General", "Julia Ramos", 4, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {34, "Ejercicios Quimica", "Luis Huaman", 3, 2019, "Ciencias", "Quimica"};
    libros[contador++] = {35, "Fund. Quimica", "Carmen Diaz", 1, 2020, "Ciencias", "Quimica"};
    libros[contador++] = {36, "Fisica I", "Giancoli", 6, 2014, "Ciencias", "Fisica"};
    libros[contador++] = {37, "Curso Fisica", "Carlos Diaz", 3, 2017, "Ciencias", "Fisica"};
    libros[contador++] = {38, "Fisica Universitaria", "Sears Zemansky", 13, 2016, "Ciencias", "Fisica"};
    libros[contador++] = {39, "Fund. Fisica", "Maria Huerta", 2, 2019, "Ciencias", "Fisica"};
    libros[contador++] = {40, "Problemas Fisica", "Fernando Rojas", 1, 2021, "Ciencias", "Fisica"};
    libros[contador++] = {41, "Biologia I", "Neil Campbell", 9, 2013, "Ciencias", "Biologia"};
    libros[contador++] = {42, "Curso Biologia", "Rosa Salas", 2, 2017, "Ciencias", "Biologia"};
    libros[contador++] = {43, "Biologia Celular", "Carlos Torres", 4, 2015, "Ciencias", "Biologia"};
    libros[contador++] = {44, "Fund. Biologia", "Teresa Poma", 1, 2019, "Ciencias", "Biologia"};
    libros[contador++] = {45, "Problemas Biologia", "Victor Z.", 3, 2016, "Ciencias", "Biologia"};
}










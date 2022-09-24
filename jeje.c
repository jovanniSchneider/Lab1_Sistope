#include <stdio.h>
#include <string.h>
#include "padre.c"
int main() {
    TDAlista  ** hash = leerCSV("datos_juegos_1000.csv");
    int cont = crearArchivo(hash,"out.txt");
    //printf("%d\n",cont);
    return 0;
}

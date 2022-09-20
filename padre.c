#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
//lee archivo y ordenar con la tabla
void leerCSV(char* nombreArchivo){
    FILE* fp;
    fp= fopen(nombreArchivo,"r");
    char* string;
    fscanf("%s",string);
    char string[150];
    while(NULL!= fgets(string,150,fp)){
        printf("siguiente dato %s\n",string);
        //LLAMADO
    }
    //980830,Spirit Hunter: Death Mark,18,50.0,False,2019,False,Yes,No,No

}
//crear el archivo intermedio

//Capturar el puntero posicion del archivo

//crear hijos (1 por year)

void procesarDatos(){

}
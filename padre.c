#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "hash.h"


//Entradas Char* del nombre del archivo
//Salidas TdaLista ** que trabaja como una tabla hash
//Descripcion se lee el archivo solicitado por el usuario, el contenido de este csv se almacena en una tabla hash segun
//            el year del juego en cuestion
TDAlista ** leerCSV(char* nombreArchivo){
    FILE* fp;
    fp= fopen(nombreArchivo,"r");
    TDAlista** hash=crearHash();
    char string[150];
    while(fgets(string,150,fp)!=NULL){
        agregarDatoHash(string, hash);
    }
    fclose(fp);
    return hash;
}
//crear el archivo intermedio

//Capturar el puntero posicion del archivo

//crear hijos (1 por year)

void procesarDatos(){

}
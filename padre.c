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
//Entradas TDALista** que simula una tabla hash,char* para el nombre del archivo
//Salidas int que representa la cantidad de years que si tienen juegos
//Descripcion crea un archivo que contiene la info de la tabla hash con el nombre ingresado, ademas de calcular
//             los years con juegos, tambien dejando constancia de donde comienza cada year mediante ftell
int crearArchivo(TDAlista** hash, char * nombreSalida){
    int largoHash = getActualYear()-1985;
    FILE * fp;
    fp = fopen(nombreSalida, "w");
    int cont = 0;
    for(int i=0;i<(2022-1985);i++){
        if(!esListaVacia(hash[i])) {
            cont++;
            printf("ftell: %d\n",ftell(fp));//esto deja en cola del pipe la actual posicion del puntero
            recorrerLista(hash[i], fp);
        }
        liberarLista(hash[i]);
    }
    fclose(fp);
    return cont;
}
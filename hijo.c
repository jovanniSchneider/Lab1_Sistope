//
// Created by jovan on 9/13/2022.
//
#include <stdio.h>
#include <string.h>//para armar la entrega
#include "gameList.h"



//Entradas: puntero del archivo intermedio creado por el padre y el puntero (long) para saber donde comenzar a leer
//Salidas: void
//Descripcion: lee los juegos correspondientes y los almacena
void leerArchivo(FILE * fp,long puntero,gamelist * lista){
    fseek(fp,puntero,SEEK_SET);//posicionamiento del puntero en la posicion correspondiente
    char string[150];
    game juego;
    fgets(string,150,fp);
    int year = getYear(string);
    printf("Me corresponden los siguientes juegos del year %d:\n",year);
    do {
        //38400,Fallout: A Post Nuclear Role Playing Game,16,6.88,False,2015,False,Yes,No,No
        juego.ID = atoi(getGenerico(string,0));
        strcpy(juego.name,getGenerico(string,1));
        juego.ageRest = atoi(getGenerico(string,2));
        juego.price = getPrice(string);
        juego.comSoon = convertirBool(getGenerico(string,4));
        juego.year = getYear(string);
        juego.free = convertirBool(getGenerico(string,6));
        juego.win = convertirBool(getGenerico(string,7));
        juego.mac = convertirBool(getGenerico(string,8));
        juego.lix = convertirBool(getGenerico(string,9));
        //printf("%d,%s,%d,%f,%d,%d,%d,%d,%d,%d\n",juego.ID,juego.name,juego.ageRest,juego.price,juego.comSoon,juego.year,juego.free,juego.win,juego.mac,juego.lix);
        insertarIniciogame(lista,juego);
    }while(fgets(string,150,fp)!=NULL && getYear(string) ==year);
    
}
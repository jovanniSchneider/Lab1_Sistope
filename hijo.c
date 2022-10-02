//
// Created by jovan on 9/13/2022.
//
#include <stdio.h>
#include "functions.h"
#include <string.h>//para armar la entrega
#include "game.h"
#include "TDAlista.h"



//Entradas: puntero del archivo intermedio creado por el padre y el puntero (long) para saber donde comenzar a leer
//Salidas: void
//Descripcion: lee los juegos correspondientes y los almacena
void leerArchivo(FILE * fp,long puntero,TDAlista* lista){
    fseek(fp,puntero,SEEK_SET);//posicionamiento del puntero en la posicion correspondiente
    char string[150];
    char * pronto;
    char * free;
    char * wi;
    char * ios;
    char * lin;
    int yearSon;
    game juego;
    fscanf(fp,"%d,%s,%d,%f,%s,%d,%s,%s,%s,%s\n",&juego.ID,juego.name,&juego.ageRest,&juego.price,pronto,&juego.year,free,wi,ios,lin);//primera lectura
    
    yearSon=juego.year;
    //con esto tenemos el primer juego
    //"980830,Spirit Hunter: Death Mark,18,50.0,False,2019,False,Yes,No,No"
    
    do {//se hacen las lecturas correspondientes hasta encontrar un juego que no corresponda al year de este hijo
        juego.comSoon=convertirBool(pronto);
        juego.free=convertirBool(free);
        juego.win=convertirBool(wi);
        juego.mac=convertirBool(ios);
        juego.lix=convertirBool(lin);
        insertarIniciogame(lista,juego);
    }while((fscanf(fp,"%d,%s,%d,%f,%s,%d,%s,%s,%s,%s\n",&juego.ID,juego.name,&juego.ageRest,&juego.price,pronto,&juego.year,free,wi,ios,lin)!=EOF)&&(juego.year==yearSon));
    //ARRAY de juegos 
    
}
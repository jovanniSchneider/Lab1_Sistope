//
// Created by jovan on 9/13/2022.
//
#include <stdio.h>
#include "functions.h"

void leerArchivo(FILE * fp,long puntero){
    fseek(fp,puntero,SEEK_SET);
    char string[150];
    fgets(string,150,fp);
    int year = getYear(string);
    printf("Me corresponden los siguientes juegos del year %d:\n",year);
    do {
        printf("%s\n",string);
    }while(getYear(string)==year && fgets(string,150,fp)!=NULL);
}
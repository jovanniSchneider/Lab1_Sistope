#ifndef LAB_1_HASH_H
#define LAB_1_HASH_H

#endif //LAB_1_HASH_H
#include "TDAlista.h"
#include <time.h>
#include "functions.h"
//Entradas: Un entero que representa el año del game
//Salidas: Un entero correspondiente a la casilla de la tabla hash
//Descripcion: Calcula la casilla de la tabla
int hashFunction(int number){
    return number - 1990;
}
//Entradas: void
//Salidas: Un arreglo de listas enlazadas que corresponde a la tabla hash
//Descripcion: genera una tabla hash
TDAlista ** crearHash(){
    time_t t;
    struct tm *tm;
    char y[100];
    int year;
    t=time(NULL);
    tm=localtime(&t);
    strftime(y, 100, "%Y", tm);
    year = atoi(y);
    TDAlista** M=(TDAlista**)malloc(sizeof(TDAlista*)*(year-1985));
    for (int i = 0; i < year-1985; ++i) {
        M[i] = crearListaVacia();
    }
    return M;
}

void agregarDatoHash(char * datos, TDAlista ** hash){
    int year = getYear(datos);
    insertarInicio(hash[hashFunction(year)],datos);
}
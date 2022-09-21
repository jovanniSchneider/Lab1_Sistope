#ifndef LAB_1_HASH_H
#define LAB_1_HASH_H

#endif //LAB_1_HASH_H
#include "TDAlista.h"
#include <time.h>
#include "functions.c"

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
    int year = getActualYear();
    TDAlista** M=(TDAlista**)malloc(sizeof(TDAlista*)*(37));// 37 espacios
    for (int i = 0; i < year-1985; ++i) {
        M[i] = crearListaVacia();
    }
    return M;
}

void agregarDatoHash(char * datos, TDAlista ** hash){
    int year = getYear(datos);
    insertarInicio(hash[hashFunction(year)],datos);
}
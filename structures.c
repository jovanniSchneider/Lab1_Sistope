#include <string.h>
#include <stdlib.h>
typedef struct juego{
    int ID;
    char * name;
    int ageRest;
    float price;
    int comSoon;
    int year;
    int free;
    int win;
    int mac;
    int linux;
}juego;

// Entradas: se reciben los datos que conforman la estructura de un juego
// Salidas: se retorna un juego*
// Descripción: se asigna memoria a un juego* y se asignan los valores correspondientes
juego* buildJuego(int ID, char * name, int ageRest, float price, int comSoon, int year, int free, int win,int mac,int linux){
    juego* nuevo= (juego*)malloc(sizeof (juego));
    nuevo->ID=ID;
    nuevo->ageRest=ageRest;
    nuevo->price=price;
    nuevo->comSoon=comSoon;
    nuevo->year=year;
    nuevo->free=free;
    nuevo->win=win;
    nuevo->mac=mac;
    nuevo->linux=linux;
    strcpy(nuevo->name,name);
    return nuevo;
}
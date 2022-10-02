#include <string.h>
#include <stdlib.h>
typedef struct game{
    int ID;
    char * name;
    int ageRest;
    float price;
    int comSoon;
    int year;
    int free;
    int win;
    int mac;
    int lix;
}game;

// Entradas: se reciben los datos que conforman la estructura de un game
// Salidas: se retorna un game*
// Descripción: se asigna memoria a un game* y se asignan los valores correspondientes
//"980830,Spirit Hunter: Death Mark,18,50.0,False,2019,False,Yes,No,No"
game * buildJuego(int ID, char * name, int ageRest, float price, char* comSoon, int year, char* free, char* win,char* mac,char* lix){
    game* nuevo= (game*)malloc(sizeof (game));
    nuevo->ID=ID;
    nuevo->ageRest=ageRest;
    nuevo->price=price;
    nuevo->comSoon=comSoon;
    nuevo->year=year;
    nuevo->free=free;
    nuevo->win=win;
    nuevo->mac=mac;
    nuevo->lix=lix;
    strcpy(nuevo->name,name);
    return nuevo;
}
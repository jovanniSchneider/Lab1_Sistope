#include <stdio.h>
#include <string.h>
#include "hash.h"
void main() {
    FILE* fp;
    fp= fopen("datos_juegos_1000.csv","r");
    TDAlista** hash=crearHash();
    char string[150];
    while(fgets(string,150,fp)!=NULL){
        agregarDatoHash(string, hash);
    }
    fclose(fp);
    for(int i=0;i<(2022-1985);i++){
        printf("h[%d]\n",i);
        recorrerLista(hash[i]);
    }
}

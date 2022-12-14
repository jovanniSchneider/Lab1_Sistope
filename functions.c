#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
// Entradas: char*
// Salidas: int
// Descripción: separa un string hasta obtener el dato que representa el year
int getYear(char * string) {
    char string2[150];
    strcpy(string2,string);
    char separacion[2] = ",";
    char * pedacito;
    int year;
    pedacito = strtok(string2,separacion);//980830,Spirit Hunter: Death Mark,18,50.0,False,2019,False,Yes,No,No
    for (int i = 0; i<5;i++){
        pedacito = strtok(NULL,separacion);
    }
    year = atoi(pedacito);
    return year;
}

char * getGenerico(char * string, int posicion){
    char string2[150];
    strcpy(string2,string);
    char separacion[2] = ",";
    char * pedacito;
    pedacito = strtok(string2,separacion);//980830,Spirit Hunter: Death Mark,18,50.0,False,2019,False,Yes,No,No
    for (int i = 0; i<posicion;i++){
        pedacito = strtok(NULL,separacion);
    }
    return pedacito;
}

// Entradas: char*
// Salidas: int
// Descripción: transforma un char* a bool(int 0 o 1)
int convertirBool(char string[10]) {
    //True,False,Yes,No
    if((strcmp(string,"True")==0)||(strcmp(string,"Yes")==0)||(strcmp(string,"Yes\n")==0)){
        return 1;
    }if((strcmp(string,"False")==0)||(strcmp(string,"No")==0)||(strcmp(string,"No\n")==0)){
        return 0;
    }
    return -1;
}

//Entradas: string
//Salidas: float
//Descripcion: separa un string hasta obtener el dato que representa el precio
float getPrice(char * string){
    char string2[150];
    strcpy(string2,string);
    char separacion[2] = ",";
    char * pedacito;
    float price;
    pedacito = strtok(string2,separacion);//980830,Spirit Hunter: Death Mark,18,50.0,False,2019,False,Yes,No,No
    for (int i = 0; i<3;i++){
        pedacito = strtok(NULL,separacion);
    }
    price = atof(pedacito);
    return price;
}

// Entradas: entra un char*
// Salidas: un int 0 o 1
// Descripción: verifica que el string de entrada este conformado solo por digitos
int digitValidate(char * string) {
    for (int i = 0; i < strlen(string); ++i) {
        if (!isdigit(string[i])) {
            if ('.' == string[i]) {
                continue;
            } else
                return 0;
        }
    }
    return 1;
}

// Entradas: parametros ingresados por consola los cuales podrian variar segun la entrada del usuario
// Salidas: int 0 o 1
// Descripción: verifica los parametros ingresados por consola para corroborar que cumplan ciertos parametros para el
// correcto funcionamiento del codigo.
int validate(int argc, char * argv[], char input[], char output[], float * min_price, int * min_year, int * flag){
    int opt;
    while((opt = getopt(argc,argv,":bi:o:d:p: :h"))!= -1){
        switch (opt) {
            case 'i':
                strcpy(input,optarg);
                break;
            case 'o':
                strcpy(output,optarg);
                break;
            case 'd':
                if(digitValidate(optarg))
                    *min_year = atoi(optarg);
                else{
                    printf("Invalid argument for %c\n",optopt);
                    exit(0);
                }
                break;
            case 'p':
                if(digitValidate(optarg))
                    *min_price = atof(optarg);
                else{
                    printf("Invalid argument for %c\n",optopt);
                    exit(0);
                }
                break;
            case 'b':
                *flag = 1;
                break;
            case 'h':
                printf("-i: input file including extension\n"
                       "-o: output file including extension\n"
                       "-d: game start year, must be a number\n"
                       "-p: minimum game price, must be in dollars\n"
                       "-b: details flag (show additional information on console)\n"
                       "-h: help\n");
                exit(0);
                break;
            case '?':
                printf("Unknown option: %c\n",optopt);
                break;
            case ':':
                printf("Missing arg for %c\n",optopt);
        }
    }
    if(*min_year == -1) {
        return 0;
    }
    return 1;
}

//Entradas: void
//Salidas: Un entero que representa el year actual del SO
//Descripcion: Cmediante funciones de time.h obtiene el year
int getActualYear(){
    time_t t;
    struct tm *tm;
    char y[100];
    int year;
    t=time(NULL);
    tm=localtime(&t);
    strftime(y, 100, "%Y", tm);
    year = atoi(y);
    return year;
}
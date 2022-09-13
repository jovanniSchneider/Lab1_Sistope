#include <stdio.h>
#include "functions.c"

int main(int argc, char * argv[]) {
    char input[30] = "datos_juegos.csv";
    char output[30] = "output.txt";
    float min_price = 0;
    int min_year = -1;
    int flag = 0;
    if(validate(argc,argv,input,output,&min_price,&min_year,&flag)){
        if(flag){
            printf("Archivo de entrada: %s\n",input);
            printf("Archivo de salida : %s\n",output);
            printf("Ano de inicio: %d\n",min_year);
            printf("Precio minimo: %f\n",min_price);
            printf("Flag: %d\n",flag);
        }
    }else {
        printf("Por favor ingrese una entrada correcta\n");
        printf("Utilice -h para ver las indicaciones de ayuda\n");
    }
    return 0;
}

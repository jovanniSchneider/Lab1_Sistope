#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "game.h"
#include "padre.c"
#include <sys/wait.h>
#include <unistd.h>
#include "hijo.c"


int main(int argc, char * argv[]) {
    char input[30] = "datos_juegos_1000.csv";
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
        int fd[2];
        int pid;
        long buffer = 41;
        int totalYears;
        if(pipe(fd) == -1){
            printf("error\n");
            exit(-1);
        }
        TDAlista  ** hash = leerCSV(input,min_year,min_price);
        totalYears = crearArchivo(hash,output,fd,flag,min_year);
        for (int i = 0; i < totalYears; i++) {
            FILE * fp;
            fp = fopen(output,"r");
            pid = fork();
            if(pid>0){
                wait(NULL);
                fclose(fp);
            }
            if(pid == 0){
                close(fd[1]);
                //printf("%d\n",buffer);
                read(fd[0],&buffer,sizeof(buffer));
                leerArchivo(fp,buffer);
                break;
            }
        }
    }else {
        printf("Por favor ingrese una entrada correcta\n");
        printf("Utilice -h para ver las indicaciones de ayuda\n");
    }

    return 0;
}
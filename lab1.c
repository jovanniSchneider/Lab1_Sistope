#include <stdio.h>
#include "functions.h"
#include "game.h"


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
        int fd[2];
        int pid;
        int buffer = 0;
        int totalYears = 5; //Es solo de ejemplo, se debe calcular
        int stat;
        if(pipe(fd) == -1){
            printf("error\n");
            exit(-1);
        }
        for (int i = 0; i < totalYears; i++) {
            pid = fork();
            if(pid>0){
                buffer+=1;
                printf("buffer: %d\n", buffer);
                write(fd[1],&buffer, sizeof(buffer));
                wait(NULL);
            }
            if(pid == 0){
                close(fd[1]);
                read(fd[0],&buffer,sizeof(buffer));
                printf("soy el hijo %d pid: %d\n", buffer,getpid());
                exit(buffer);
            }
        }
    }else {
        printf("Por favor ingrese una entrada correcta\n");
        printf("Utilice -h para ver las indicaciones de ayuda\n");
    }

    return 0;
}
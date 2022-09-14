#include <stdio.h>
#include "functions.c"
#include "structures.c"

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
        int buffer;
        int totalYears = 5; //Es solo de ejemplo, se debe calcular
        buffer = 0;
        if(pipe(fd) == -1){
            printf("error\n");
            exit(-1);
        }
        for (int i = 0; i < totalYears; ++i) {
            if ((pid = fork()) == -1){
                printf("error\n");
                exit(-1);
            }
            if(pid > 0){
                close(fd[0]);
                buffer+=1;
                write(fd[1], &buffer,sizeof(buffer));
                exit(0);
            }else{
                close(fd[1]);
                read(fd[0],&buffer,sizeof(buffer));
                printf(" soy el hijo numero %d\n",buffer);
                break;
            }
        }
    }else {
        printf("Por favor ingrese una entrada correcta\n");
        printf("Utilice -h para ver las indicaciones de ayuda\n");
    }

    return 0;
}
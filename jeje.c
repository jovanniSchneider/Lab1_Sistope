#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {
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

    return 0;
}

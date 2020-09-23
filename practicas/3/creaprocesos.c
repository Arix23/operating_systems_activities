#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){

    unsigned pid = fork();
    if(pid==0){
        printf("Soy el proceso hijo\n");
        if(argc>=2){
            char *newev[] = {NULL};
            execve(argv[1],&argv[1],newev);
        }
        
    } else {
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        wait(&status);
        printf("terminando despues del hijo y estatus %d\n",status);
    }
    printf("Hola mundo \n");


    return 0;
}
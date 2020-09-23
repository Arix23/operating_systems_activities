#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void signalHandler(int signum){
    printf("nadie me echa del ciber, no puedes matarme");
}


int main(){
    signal(2,signalHandler);
    while(1){
        sleep(2);
        printf("en el ciber\n");
    }
    return 0;
}
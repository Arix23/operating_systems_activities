#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main(){
    char c;
    int numcaracteres = 0;
    int numpalabras = 0;
    int numlineas = 0;
    bool flag = true;

    while(read(STDIN_FILENO,&c,1) != 0) {
        //salto de linea
		if(c == '\n' && flag == false) {
            numcaracteres++;
            numpalabras++;
            numlineas++;
            flag = false;
        } else if(c == '\n' && flag == true){
            numcaracteres++;
            numlineas++;

        } else if(c != ' ') {
            numcaracteres++;
            flag = false;
        } else if(flag == false) {
            numcaracteres++;
            numpalabras++;
            flag = true;
        } else if (flag == true){
            numcaracteres++;
        } else{

        }
        }
        printf("Este es el numero de lineas %u\n", numlineas);
        printf("Este es el numero de palabras: %u\n", numpalabras);
        printf("Este es el numero de caracteres: %u\n", numcaracteres);
        return 0;
    }

    
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void screen_usm(int x, bool limpar);

int main(void)
{
    screen_usm(1, false);
    printf("\n\n\n\n");

    screen_usm(2, false);
    printf("\n\n\n\n");

    screen_usm(3, false);
    printf("\n\n\n\n");

    screen_usm(4, false);
    printf("\n\n\n\n");

    return 0;
}

void screen_usm(int x, bool clear)
{
    /*Função que atualiza a tela junto com o menu para o programa MRU*/
    /*Function that update the screen with the menu to Program USM*/

    if(clear == true){
        system("cls");
    }

    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
    printf("\n                UNIFORM STRAIGHT MOTION");
    printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");

    if(x == 1){
        printf("\n***                 SPACE TRAVELLED                      ***");
    }
    if(x == 2){
        printf("\n***                 STARTING POSITION                    ***");
    }
    if(x == 3){
        printf("\n***                      VELOCITY                        ***");
    }
    if(x == 4){
        printf("\n***                       TIME                           ***");
    }
}

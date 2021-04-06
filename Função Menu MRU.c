#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    void tela_mru(x) //funcção que atualiza a tela junto com o menu para o programa MRU
    {

        if(x == 0)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
        }
        if(x == 1)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                ESPAÇO PERCORRIDO                     ***");
        }
        if(x == 2)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                  POSIÇÃO INICIAL                     ***");
        }
        if(x == 3)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                     VELOCIDADE                       ***");
        }
        if(x == 4)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                       TEMPO                          ***");
        }
    }

    tela_mru(3);
}

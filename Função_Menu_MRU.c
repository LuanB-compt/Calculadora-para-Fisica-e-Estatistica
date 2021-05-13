#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(void)
{
    setlocale(LC_ALL, "portuguese");

    void tela_mru(x) //função que atualiza a tela junto com o menu para o programa MRU
    {
        system("cls");
        printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
        printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
        printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");

        if(x == 1)
        {
            printf("\n***                ESPAÇO PERCORRIDO                     ***");
        }
        if(x == 2)
        {
            printf("\n***                  POSIÇÃO INICIAL                     ***");
        }
        if(x == 3)
        {
            printf("\n***                     VELOCIDADE                       ***");
        }
        if(x == 4)
        {
            printf("\n***                       TEMPO                          ***");
        }
    }

    tela_mru(3);
}

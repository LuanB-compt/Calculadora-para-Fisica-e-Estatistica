#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    void tela_mru(x) //func��o que atualiza a tela junto com o menu para o programa MRU
    {
        system("cls");
        printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
        printf("\n              MOVIMENTO RET�LINEO UNIFORME");
        printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");

        if(x == 1)
        {
            printf("\n***                ESPA�O PERCORRIDO                     ***");
        }
        if(x == 2)
        {
            printf("\n***                  POSI��O INICIAL                     ***");
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

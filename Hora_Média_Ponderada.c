#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void titulo_ponderada()
    {
        system("cls");
        printf("------------------------------------------------------------------------------");
        printf("\n***                           M�DIA PONDERADA =)                           ***");
        printf("\n------------------------------------------------------------------------------");
        fflush(stdin);
    }

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    char continua;

    do{
        //t�tulo
        titulo_ponderada();    //atualiza a tela
        printf("\n\n\n");

        //pede os dados do usu�rio
        int tamanho;
        float media_ponderada = 0;

        printf("Quantos elementos? "); //pergunta com quantos elementos o usu�rio deseja fazer a m�dia
        scanf("%d", &tamanho);
        printf("\n\n");

        //conta dos pesos
        float pesos_total = 0;
        float pesos[tamanho];
        for(int i = 0; i < tamanho; i++)
        {
            printf("Qual o peso do %i� elemento: ", i + 1);
            scanf("%f", & pesos[i]); //recebe os pesos
            fflush(stdin);
            pesos_total += pesos[i]; //salva a soma de todos os pesos
        }

        //faz a propor��o dos pesos com a soma total
        for(int i = 0; i < tamanho; i++)
        {   //n�o importa se a soma dos pesos tem de 100% ou menos que 100% (assim a propor��o sempre � mantida)
            pesos[i] = pesos[i] / pesos_total;
        }

        //recebe os dados
        float elementos[tamanho];  //cria a lista com tamanho de elementos que o usu�rio deu
        printf("\nDigite os dados: \n");
        for (int i = 0; i < tamanho; i++)
        {        //for para coletar dado por dado e adiciona-lo em seu respectivo espa�o na lista
            printf("Digite o %d�: ", i + 1);
            scanf("%f", &elementos[i]);
        }

        titulo_ponderada();  //atualiza a tela
        printf("\n\n\n");

        //mostra os dados brutos inseridos pelo usu�rio
        printf("Os elementos brutos s�o: ");
        for (int i = 0; i < tamanho -1 ; i++)//colocado n-1 para n�o incluir o �ltimo elemento, pois o �ltimo elemento seja diferente
        {
            printf("%.2f; ", elementos[i]);    //printa os termos da lista
        }
        printf("%.2f.\n", elementos[tamanho-1]);   //formata��o do �ltimo elemento,

        //faz o calculo multiplicando cada elemento com seu devido peso
        for (int i = 0; i < tamanho; i++)
        {
            /*printf("listinha: %.2f\n", elementos[i]);
            printf("peso: %.2f\n", pesos[i]);*/
            elementos[i] = elementos[i] * pesos[i];
            //printf("%f", listinha[i]);
        }

        //pula linha
        printf("\n\n\n");

        //mostra os elementos j� tratados depois da multiplica��o
        printf("Os elementos com suas propor��es s�o: ");
        for (int i = 0; i < tamanho -1 ; i++)//colocado n-1 para n�o incluir o �ltimo elemento, pois o �ltimo elemento seja diferente
        {
            printf("%.2f; ", elementos[i]);    //printa os termos da lista
            media_ponderada += elementos[i];              //soma = soma + lista[indice]
        }
        media_ponderada += elementos[tamanho-1];              //soma do �ltimo elemento
        printf("%.2f.\n", elementos[tamanho-1]);   //formata��o do �ltimo elemento,
        // essas duas coisas foram necess�rias para que o �ltimo elemento fosse printado diferente

        //calcula e mostra o tamanho da lista com os dados brutos
        printf("S�o %d elementos.\n\n", tamanho);

        printf("\n- M�dia = %.2f\n\n", media_ponderada);

        //trava a tela para o usu�rio prosseguir a hora que ele quiser
        char termina;
        while (termina != 'c')
        {
            //system("cls");
            printf("\nDig�te C para continuar...\n");
            termina = getch();
        }
        system("cls");

        //termina ou come�a novamente o programa
        fflush(stdin);
        printf("Deseja fazer uma nova m�dia?(s/n) ");
        scanf("%c", & continua);

    }while (continua == 115);

    return 0;
}

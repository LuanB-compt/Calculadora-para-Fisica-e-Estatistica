#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void screen_wa(bool clear);

void recebe_pesos(int tamanho, float pesos, float pesos_total);

int main(void){
    setlocale(LC_ALL, "portuguese");
    char continua;
    int tamanho;
    float media_ponderada = 0;
    float pesos_total = 0;
    float pesos[tamanho];
    float elementos[tamanho];  //cria a lista com tamanho de elementos que o usuário deu
    char termina;

    do{
        screen_wa(true);
        printf("\n\n\n");

        //pede os dados do usuário
        printf("Quantos elementos? "); //pergunta com quantos elementos o usuário deseja fazer a média
        scanf("%d", &tamanho);
        printf("\n\n");

        recebe_pesos(tamanho, pesos, pesos_total);

        //recebe os dados
        printf("\nDigite os dados: \n");
        for (int i = 0; i < tamanho; i++)
        {        //for para coletar dado por dado e adiciona-lo em seu respectivo espaço na lista
            printf("Digite o %d°: ", i + 1);
            scanf("%f", &elementos[i]);
        }

        screen_wa(true);  //atualiza a tela
        printf("\n\n\n");

        //mostra os dados brutos inseridos pelo usuário
        printf("Os elementos brutos são: ");
        for (int i = 0; i < tamanho -1 ; i++)//colocado n-1 para não incluir o último elemento, pois o último elemento seja diferente
        {
            printf("%.2f; ", elementos[i]);    //printa os termos da lista
        }
        printf("%.2f.\n", elementos[tamanho-1]);   //formatação do último elemento,

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

        //mostra os elementos já tratados depois da multiplicação
        printf("Os elementos com suas proporções são: ");
        for (int i = 0; i < tamanho -1 ; i++)//colocado n-1 para não incluir o último elemento, pois o último elemento seja diferente
        {
            printf("%.2f; ", elementos[i]);    //printa os termos da lista
            media_ponderada += elementos[i];              //soma = soma + lista[indice]
        }
        media_ponderada += elementos[tamanho-1];              //soma do último elemento
        printf("%.2f.\n", elementos[tamanho-1]);   //formatação do último elemento,
        // essas duas coisas foram necessárias para que o último elemento fosse printado diferente

        //calcula e mostra o tamanho da lista com os dados brutos
        printf("São %d elementos.\n\n", tamanho);

        printf("\n- Média = %.2f\n\n", media_ponderada);

        //trava a tela para o usuário prosseguir a hora que ele quiser
        while (termina != 'c')
        {
            //system("cls");
            printf("\nDigíte C para continuar...\n");
            termina = getch();
        }
        system("cls");

        //termina ou começa novamente o programa
        fflush(stdin);
        printf("Deseja fazer uma nova média?(s/n) ");
        scanf("%c", & continua);

    }while (continua == 115);

    return 0;
}

void screen_wa(bool clear){
    /*Function that print the title on the screen*/

    if(clear == true){
        system("cls");
    }

    printf("------------------------------------------------------------------------------");
    printf("\n***                          WEIGHTED AVERAGE =)                           ***");
    printf("\n------------------------------------------------------------------------------");
    fflush(stdin);
}

void recebe_pesos(int tamanho, float pesos[], float pesos_total){
    pesos[tamanho];

    //conta dos pesos
    for(int i = 0; i < tamanho; i++){
        printf("Qual o peso do %i° elemento: ", i + 1);
        scanf("%f", & pesos[i]); //recebe os pesos
        fflush(stdin);
        pesos_total += pesos[i]; //salva a soma de todos os pesos
    }

    //faz a proporção dos pesos com a soma total
    for(int i = 0; i < tamanho; i++){
        //não importa se a soma dos pesos tem de 100% ou menos que 100% (assim a proporção sempre é mantida)
        pesos[i] = pesos[i] / pesos_total;
    }
}

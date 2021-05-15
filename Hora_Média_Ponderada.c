#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define ARRAYLEN(ar) sizeof(ar)/sizeof(ar[0])

void titulo_ponderada()
    {
        system("cls");
        printf("------------------------------------------------------------------------------");
        printf("\n***                           MÉDIA PONDERADA =)                           ***");
        printf("\n------------------------------------------------------------------------------");
        fflush(stdin);
    }

int main(void)
{
    char continua;

    do{
        system("cls");
        setlocale(LC_ALL, "portuguese");
        system("color 17");

        titulo_ponderada();


        //recebe quantos elementos
        //int num_elementos_dois;
        int num_elementos;
        printf("\n\n\nQuantos elementos terão: ");
        scanf("%i", & num_elementos);
        //num_elementos_dois = num_elementos;
        //printf("%i", num_elementos_dois);



        //Recebe os pesos de cada nota
        float pesos[num_elementos];
        int i;
        printf("\n\n");
        for(i = 0; i < num_elementos; i++)
        {
            printf("Qual o peso do %i° elemento: ", i + 1);
            scanf("%f", & pesos[i]);
            /*if(pesos[i] > 0)
            {
                pesos[i] = pesos[i] * 0.01;
            }*/
            fflush(stdin);
            //printf("%f\n", pesos[i]);
        }


        // transforma os pesos recebidos em decimal
        i = 0;
        for(i = 0; i < num_elementos; i++)
        {
            if(pesos[i] > 0)
            {
                pesos[i] = pesos[i] * 0.01;
            }
            printf("%f\n", pesos[i]);
        }
        system("pause");

        /*for(i = 0; i < num_elementos; i++)
        {
            printf("%f\n", pesos[i]);
        }*/



        titulo_ponderada();




        int tamanho = ARRAYLEN(pesos);
        //printf("%i", tamanho);


        //Recebe as notas (erro)
        float nota_peso[num_elementos];
        float notas[num_elementos];
        printf("\n\n");
        i = 0;
        for(i = 0; i < tamanho; i++)
        {
            fflush(stdin);
            printf("Qual o %i° elemento: ", i + 1);
            scanf("%f", & notas[i]);
            printf("\n\n%i", i);
            /*if(notas > 0)
            {
                nota_porcentagem[i] = notas[i] * pesos[i];
            }
            printf("\n%f", & nota_porcentagem[i]);*/
        }

        i = 0;
        for(i = 0; i < tamanho; i++)
        {
            if(notas > 0)
            {
                nota_peso[i] = notas[i] * pesos[i];
            }
            printf("\n%f", & nota_peso[i]);
        }


        //cálculo da média ponderada
        float media;
        float soma = 0;
        i = 0;
        for(i = 0; i < num_elementos; i++)
        {
            if(notas[i] >= 0)
            {
                soma = soma + nota_peso[i];
            }
        }
        printf("%f", soma);
        system("pause");

        if(notas[i] >= 0)
        {
            media = soma / num_elementos;
        }

        /*if(multi1 >= 0)
        {
            media = multi1 + multi2 + multi3 + multi4;
        }*/

        printf("\n\nSua MÉDIA é de: %.2f\n", media);

        char termina;
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

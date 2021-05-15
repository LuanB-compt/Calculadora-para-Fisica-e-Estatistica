#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

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

        //Recebe os pesos de cada nota
        int num_elementos;
        printf("\n\n\nQuantos elementos terão: ");
        scanf("%i", & num_elementos);

        float pesos[num_elementos];
        int i;
        printf("\n");
        for(i = 0; i < num_elementos; i++)
        {
            printf("Qual o peso do %i° elemento: ", i + 1);
            scanf("%f", & pesos[i]);
            if(pesos[i] > 0)
            {
                pesos[i] = pesos[i] * 0.01;
            }
            fflush(stdin);
            //printf("%f\n", pesos[i]);
        }

        /*for(i = 0; i < num_elementos; i++)
        {
            printf("%f\n", pesos[i]);
        }*/

        //float peso1, peso2, peso3, peso4;
        /*printf("\n\n\nQual o peso da 1° NOTA?");
        printf("\nDigite aqui: ");
        scanf("%f", & peso1);
        fflush(stdin);
        printf("Qual o peso da 2° NOTA?");
        printf("\nDigite aqui: ");
        scanf("%f", & peso2);
        fflush(stdin);
        printf("Qual o peso da 3° NOTA?");
        printf("\nDigite aqui: ");
        scanf("%f", & peso3);
        fflush(stdin);
        printf("Qual o peso da 4° NOTA?");
        printf("\nDigite aqui: ");
        scanf("%f", & peso4);*/

        //Faz o cálculo de cada peso
        /*if(peso1 > 0)
        {
            peso1 = peso1 * 0.01;
        }
        if(peso2 > 0)
        {
            peso2 = peso2 * 0.01;
        }
        if(peso3 > 0)
        {
            peso3 = peso3 * 0.01;
        }
        if(peso4 > 0)
        {
            peso4 = peso4 * 0.01;
        }*/

        //Teste para verificar se os cálculos dos pesos estão certos
        /*printf("%f\n", peso1);
        printf("%f\n", peso2);
        printf("%f\n", peso3);*/

        titulo_ponderada();

        //Recebe as notas do aluno
        float nota_porcentagem[num_elementos];
        float notas[num_elementos];
        printf("\n");
        for(i = 0; i < num_elementos; i++)
        {
            printf("Qual o %i° elemento: ", i + 1);
            scanf("%f", & notas[i]);
            fflush(stdin);
            if(notas > 0)
            {
                nota_porcentagem[i] = notas[i] * pesos[i];
            }
            printf("\n%f", & nota_porcentagem);
        }

        /*float nota1, nota2, nota3, nota4;
        printf("\n\n\n1° NOTA: ");
        scanf("%f", & nota1);
        fflush(stdin);
        printf("2° NOTA: ");
        scanf("%f", & nota2);
        fflush(stdin);
        printf("3° NOTA: ");
        scanf("%f", & nota3);
        printf("4° NOTA: ");
        scanf("%f", & nota4);*/

        /*// teste para ver se as variáveis estão recendo os valores
        printf("%f\n", nota1);
        printf("%f\n", nota2);
        printf("%f\n", nota3);
        printf("%f\n", nota4)*/

        //cálculo do peso de cada nota do aluno
        /*float multi1, multi2, multi3, multi4;
        if(nota1 >= 0)
        {
            multi1 = nota1 * peso1;
        }
        if(nota2 >= 0)
        {
            multi2 = nota2 * peso2;
        }
        if(nota3 >= 0)
        {
            multi3 = nota3 * peso3;
        }
        if(nota4 >= 0)
        {
            multi4 = nota4 * peso4;
        }*/

        /*printf("%f\n", multi1);
        printf("%f\n", multi2);
        printf("%f\n", multi3);
        printf("%f\n", multi4);*/

        //cálculo da média ponderada
        float media;
        float soma = 0;
        for(i = 0; i < num_elementos; i++)
        {
            if(notas[i] >= 0)
            {
                soma = soma + nota_porcentagem[i];
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

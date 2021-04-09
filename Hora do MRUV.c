#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    void menu_mruv(x)
    {
        system("cls");
        fflush(stdin);
        printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
        printf("\n   MOVIMENTO RETILÍNEO UNIFOEMEMENTE VARIADO");
        printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

        if(x == 1)
        {
            printf("\n***               ACELERAÇÃO               ***");
        }
        if(x == 2)
        {
            printf("\n*** VELOCIDADE FINAL ***");
        }
    }

    do{
    setlocale(LC_ALL, "portuguese");

    menu_mruv();

    char continua_mruv1;
    char continua_mruv2;

    int menu = -1;
    printf("\n\n\n\nPara encontrar a ACELERAÇÃO (a) de um corpo ----> DIGITE 1");
    printf("\nPara encontrar a VELOCIDADE FINAL (Vf) de um corpo ----> DIGITE 2");
    printf("\nPara encontrar a VELOCIDADE INICIAL (Vi) de um corpo ----> DIGITE 3");
    printf("\nPara encontrar a ******** () de um corpo ----> DIGITE 4");
    printf("\nPara sair ----> DIGITE 0");
    printf("\nDIGITE SUA ESCOLHA: ");
    scanf("%d", & menu);

    switch(menu)
    {
        case 1:
            do{
                menu_mruv(1);

                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                float tempo_final;
                printf("Insira o TEMPO FINAL (tf) em SEGUNDOS: ");
                scanf("%f", & tempo_final);

                float tempo_inicial;
                printf("Insira o TEMPO INICIAL (ti) em SEGUNDOS: ");
                scanf("%f", & tempo_inicial);

                float aceleracao;
                if(tempo_final != 0)
                {
                    aceleracao = (velocidade_final - velocidade_inicial) / (tempo_final - tempo_inicial);
                }

                printf("\n\nA ACELERAÇÃO foi de: %.3f", aceleracao);
                printf("\nFÓRMULA: a = (Vf - Vi) / (tf - ti)\n"); //         a = ∆V / ∆t\n

                fflush(stdin);
                printf("\nDeseja calcular uma nova ACELERAÇÃO?(s/n) ");
                scanf("%c", continua_mruv1);
            }while(continua_mruv1 == 115);
            break;

        case 2:
            menu_mruv(2);


            break;

        case 0:
            return 0;
    }


    }while(1);

    system("pause");
    return 0;
}

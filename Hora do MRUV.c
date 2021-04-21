#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

 void menu_mruv(x)
{
    system("cls");
    fflush(stdin);
    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf("\n   MOVIMENTO RETILÍNEO UNIFORMEMENTE VARIADO");
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

    if(x == 1)
    {
        printf("\n***               ACELERAÇÃO               ***");
    }
    if(x == 2)
    {
        printf("\n*** VELOCIDADE FINAL ***");
    }
    if(x == 3)
    {
        printf("\n*** VELOCIDADE INICIAL ***");
    }
    if(x == 4)
    {
        printf("\n*** POSIÇÃO FINAL ***");
    }
    if(x == 5)
    {
        printf("\n*** POSIÇÃO INICIAL ***");
    }
    if(x == 6)
    {
        printf("\n*** TEMPO ***");
    }
}

int main(void)
{
    do{
    setlocale(LC_ALL, "portuguese");

    menu_mruv();

    char continua_mruv1;
    char continua_mruv2;
    char continua_mruv3;
    char continua_mruv4;
    char continua_mruv5;
    char continua_mruv6;

    int menu = -1;
    printf("\n\n\n\nPara encontrar a ACELERAÇÃO (a) de um corpo ----> DIGITE 1");
    printf("\nPara encontrar a VELOCIDADE FINAL (Vf) de um corpo ----> DIGITE 2");
    printf("\nPara encontrar a VELOCIDADE INICIAL (Vi) de um corpo ----> DIGITE 3");
    printf("\nPara encontrar a POSIÇÃO FINAL (S) de um corpo ----> DIGITE 4");
    printf("\nPara encontrar a POSIÇÃO INICIAL (Si) de um corpo ----> DIGITE 5");
    printf("\nPara encontrar a TEMPO (t) de um corpo ----> DIGITE 6");
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

                printf("\n\nA ACELERAÇÃO foi de: %.3f m/s^2", aceleracao);
                printf("\nFÓRMULA: a = (Vf - Vi) / (tf - ti)\n"); //         a = ∆V / ∆t\n

                fflush(stdin);
                printf("\nDeseja calcular uma nova ACELERAÇÃO?(s/n) ");
                scanf("%c", & continua_mruv1);
            }while(continua_mruv1 == 115);
            break;

        case 2:
            do{
                menu_mruv(2);

                float velocidade_inicial;
                printf("\n\n\nInsira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                float velocidade_final;
                if(tempo > 0)
                {
                    velocidade_final = velocidade_inicial + (aceleracao * tempo);
                }

                printf("\n\nA VELOCIDADE FINAL foi de: %.3f m/s", velocidade_final);
                printf("\nFÓRMULA: Vf = Vi + a * t\n");

                fflush(stdin);
                printf("\nDeseja calcular uma nova VELOCIDADE FINAL?(s/n) ");
                scanf("%c", & continua_mruv2);
            }while(continua_mruv2 == 115);
            break;

        case 3:
            do{
                menu_mruv(3);

                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                float velocidade_inicial;
                if(tempo > 0)
                {
                    velocidade_inicial = velocidade_final - (aceleracao * tempo);
                }

                printf("\n\nA VELOCIDADE INICIAL foi de: %.3f m/s", velocidade_inicial);
                printf("\nFÓRMULA: Vi = Vf - a * t\n");

                fflush(stdin);
                printf("\nDeseja calcular uma nova VELOCIDADE FINAL?(s/n) ");
                scanf("%c", & continua_mruv3);
            }while(continua_mruv3 == 115);
            break;

        case 4:
            do{
                menu_mruv(4);

                float posicao_inicial;
                printf("\n\n\nInsira a POSICÃO INICIAL (Si) em METROS: ");
                scanf("%f", & posicao_inicial);

                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                float posicao_final;
                if(tempo > 0)
                {
                    float tempo_ao_quadrado;
                    tempo_ao_quadrado = pow(tempo, 2);

                    float aceleracao_2;
                    aceleracao_2 = aceleracao / 2;

                    posicao_final = posicao_inicial + (velocidade_inicial*tempo) + (aceleracao_2 * tempo_ao_quadrado);
                }
                else
                    printf("");

                printf("\n\nA POSIÇÃO FINAL foi de: %.3f m", posicao_final);    //conferir se o resultado está certo
                printf("\nFÓRMULA: S = Si + Vi * t + 1/2 * a * t^2\n");        //

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSIÇÃO FINAL?(s/n) ");
                scanf("%c", & continua_mruv4);
            }while(continua_mruv4 == 115);
            break;

        case 5:
            do{
                menu_mruv(5);

                //aparecendo o que não devia
                float posicao_final;
                printf("\n\n\nInsira a POSICÃO FINAL (S) em METROS: ");
                scanf("%f", & posicao_final);

                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                float posicao_inicial;
                if(tempo > 0)
                {
                    float tempo_ao_quadrado;
                    tempo_ao_quadrado = pow(tempo, 2);

                    float aceleracao_2;
                    aceleracao_2 = aceleracao / 2;

                    posicao_inicial = posicao_final - (velocidade_inicial * tempo) - (aceleracao_2 * tempo_ao_quadrado);
                }

                printf("\n\nA POSIÇÃO INICIAL foi de: %.3f m", posicao_inicial);//conferir se o resultado está certo
                printf("\nFÓRMULA: Si = S - Vi * t + 1/2 * a * t^2\n");

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSIÇÃO INICIAL (s/n) ");
                scanf("%c", & continua_mruv5);
            }while(continua_mruv5 == 115);
            break;

        case 6:
            do{
                menu_mruv(6);

                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                float tempo;
                tempo = (velocidade_final - velocidade_inicial) / aceleracao;

                printf("\n\nO TEMPO foi de: %.3f m", tempo);//conferir se o resultado está certo
                printf("\nFÓRMULA: t = (Vf - Vi) / a\n");

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSIÇÃO INICIAL (s/n) ");
                scanf("%c", & continua_mruv6);
            }while(continua_mruv6 == 115);
            break;

        case 0:
            return 0;
    }

    }while(1);

    system("pause");
    return 0;
}

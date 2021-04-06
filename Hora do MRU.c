#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    system("color 75");

    void tela_mru(x) //func��o que atualiza a tela junto com o menu
    {

        if(x == 0)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RET�LINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
        }
        if(x == 1)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RET�LINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                ESPA�O PERCORRIDO                     ***");
        }
        if(x == 2)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RET�LINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                  POSI��O INICIAL                     ***");
        }
        if(x == 3)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RET�LINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                     VELOCIDADE                       ***");
        }
        if(x == 4)
        {
            system("cls");
            printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n              MOVIMENTO RET�LINEO UNIFORME");
            printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
            printf("\n***                       TEMPO                          ***");
        }
    }

    //variavel de cada do while,  que est� em todos os cases do switch
    char continua_mru1;
    char continua_mru2;
    char continua_mru3;
    char continua_mru4;

    tela_mru(0);

    //mostra as op��es de vari�veis que o programa pode calcular, e qual o usu�rio pode usar
    int icognita;
    printf("\n\n\n\nSe deseja encontrar o ESPA�O PERCORRIDO (S) pelo corpo ----> DIGITE 1");
    printf("\nSe deseja encontrar a POSI��O INICIAL (S0) do corpo ----> DIGITE 2");
    printf("\nSe deseja encontrar a VELOCIDADE (V) do corpo ----> DIGITE 3");
    printf("\nSe deseja encontrar o TEMPO (t) do movimento ----> DIGITE 4");
    printf("\n\nINSIRA AQUI: ");
    scanf("%d", & icognita);

    //leva para cada c�lculo diferente
    switch(icognita)
    {
        case 1:
            do
            {
                tela_mru(1);

                //recebe a posi��o inicial para a conta
                float posicao_inicial;
                printf("\n\n\n\nInsira a POSI��O INICIAL (S0) METROS do corpo: ");
                scanf("%f", & posicao_inicial);

                //recebe a velocidade para a conta
                float velocidade;
                printf("Insira a VELOCIDADE (V) em METROS POR SEGUNDO do corpo: ");
                scanf("%f", & velocidade);

                //recebe o tempo para a conta
                float tempo;
                printf("Insira o TEMPO (t) em SEGUNDOS que durou o movimento: ");
                scanf("%f", & tempo);

                //calcula o espa�o percorrido se no m�nimo o tempo e a velocidade forem diferentes que zero
                float espaco_percorrido;
                if(tempo != 0 && velocidade != 0)
                {
                    espaco_percorrido = posicao_inicial + (velocidade * tempo);
                }
                else
                {
                    printf("\n\nAlgum valor deve ter sido colocado errado, tente novamente");
                }

                printf("\n\nO ESPA�O PERCORRIDO (S) foi: %.4f\n", espaco_percorrido); //printa na tela o resultado
                printf("F�RMULA: S = S0 + V * t\n"); //formula usada para o calculo

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru1);
            }while(continua_mru1 == 115);

        case 2:
            do
            {
                tela_mru(2);

                //recebe o espa�o percorrido para a conta
                float espaco_percorrido;
                printf("\n\n\n\nInsira ESPA�O PERCORRIDO (S) em METROS pelo corpo: ");
                scanf("%f", & espaco_percorrido);

                //recebe a velocidade para a conta
                float velocidade;
                printf("Insira a VELOCIDADE (V) em METROS POR SEGUNDO do corpo: ");
                scanf("%f", & velocidade);

                //recebe o tempo para a conta
                float tempo;
                printf("Insira o TEMPO (t) em SEGUNDOS que durou o movimento: ");
                scanf("%f", & tempo);

                //calcula a posi��o inicial se no m�nimo o tempo e a velocidade forem diferentes que zero
                float posicao_inicial;
                if(tempo != 0 && velocidade != 0)
                {
                    posicao_inicial = espaco_percorrido - (velocidade * tempo);
                }
                else
                {
                    printf("\n\nAlgum valor deve ter sido colocado errado, tente novamente");
                }

                printf("\n\nA POSI��O INICIAL (S0) �: %.4f\n", posicao_inicial); //printa na tela o resultado
                printf("F�RMULA: S0 = S - V * t\n"); //formula usada para o calculo

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru2);
            }while (continua_mru2 == 115);

        case 3:
            do
            {
                tela_mru(3);

                //recebe o espa�o percorrido para a conta
                float espaco_percorrido;
                printf("\n\n\n\nInsira ESPA�O PERCORRIDO (S) em METROS pelo corpo: ");
                scanf("%f", & espaco_percorrido);

                //recebe a posi��o inicial para a conta
                float posicao_inicial;
                printf("Insira a POSI��O INICIAL (S0) METROS do corpo: ");
                scanf("%f", & posicao_inicial);

                //recebe o tempo para a conta
                float tempo;
                printf("Insira o TEMPO (t) em SEGUNDOS que durou o movimento: ");
                scanf("%f", & tempo);

                //calcula a posi��o inicial se no m�nimo o tempo e a velocidade forem diferentes que zero
                float velocidade;
                if(tempo != 0 && espaco_percorrido != 0)
                {
                    velocidade = (espaco_percorrido - posicao_inicial) / tempo;
                }
                else
                {
                    printf("\n\nAlgum valor deve ter sido colocado errado, tente novamente");
                }

                printf("\n\nA VELOCIDADE (V) �: %.4f\n", velocidade); //printa na tela o resultado
                printf("F�RMULA: V = (S - S0) / t\n"); //formula usada para o calculo


                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru3);
            }while (continua_mru3 == 115);

    }


    system("pause");
    return 0;
}

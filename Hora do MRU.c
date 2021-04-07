#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    do{
    setlocale(LC_ALL, "portuguese");
    system("color 75");

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



    //variavel de cada do while,  que est� em todos os cases do switch
    char continua_mru1;
    char continua_mru2;
    char continua_mru3;
    char continua_mru4;

    tela_mru(0);//printa o menu usando a fun��o criada tela_mru

    //mostra as op��es de vari�veis que o programa pode calcular, e qual o usu�rio pode usar
    int menu = -1;
    printf("\n\n\n\nSe deseja encontrar o ESPA�O PERCORRIDO (S) pelo corpo ----> DIGITE 1");
    printf("\nSe deseja encontrar a POSI��O INICIAL (S0) do corpo ----> DIGITE 2");
    printf("\nSe deseja encontrar a VELOCIDADE (V) do corpo ----> DIGITE 3");
    printf("\nSe deseja encontrar o TEMPO (t) do movimento ----> DIGITE 4");
    printf("\nSe deseja sair ----> DIGITE 0");
    printf("\n\nINSIRA AQUI: ");
    scanf("%d", & menu);

    //leva para cada c�lculo diferente
    switch(menu)
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
                    printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
                    Sleep(5000);
                    break;
                }

                printf("\n\nO ESPA�O PERCORRIDO (S) foi: %.4f\n", espaco_percorrido); //printa na tela o resultado
                printf("F�RMULA: S = S0 + V * t\n"); //formula usada para o calculo

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru1);
            }while(continua_mru1 == 115);
            break;

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
                    printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
                    Sleep(5000);
                    break;
                }

                printf("\n\nA POSI��O INICIAL (S0) �: %.4f\n", posicao_inicial); //printa na tela o resultado
                printf("F�RMULA: S0 = S - V * t\n"); //formula usada para o calculo

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru2);
            }while (continua_mru2 == 115);
            break;

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
                    printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
                    Sleep(5000);
                    break;
                }

                printf("\n\nA VELOCIDADE (V) �: %.4f\n", velocidade); //printa na tela o resultado
                printf("F�RMULA: V = (S - S0) / t\n"); //formula usada para o calculo


                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru3);
            }while (continua_mru3 == 115);
            break;

        case 4:
            do
            {
                tela_mru(4);//printa o menu

                //recebe a posi��o inicial para a conta
                float posicao_inicial;
                printf("\n\n\n\nInsira a POSI��O INICIAL (S0) METROS do corpo: ");
                scanf("%f", & posicao_inicial);

                //recebe o espa�o percorrido para a conta
                float espaco_percorrido;
                printf("Insira ESPA�O PERCORRIDO (S) em METROS pelo corpo: ");
                scanf("%f", & espaco_percorrido);

                //recebe a velocidade para a conta
                float velocidade;
                printf("Insira a VELOCIDADE (V) em METROS POR SEGUNDO do corpo: ");
                scanf("%f", & velocidade);

                //calcula a posi��o inicial se no m�nimo o tempo e a velocidade forem diferentes que zero
                float tempo;
                if(velocidade != 0 && espaco_percorrido != 0)
                {
                    tempo = (posicao_inicial - espaco_percorrido) / velocidade;
                }
                else
                {
                    printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
                    Sleep(5000);
                    break;
                }

                printf("\n\nA TEMPO (t) foi de: %.4f\n", tempo); //printa o resultado
                printf("F�RMULA: t = (S0 - S) / V\n"); //formula usada para o calculo

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("Deseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_mru3);
            }while (continua_mru4== 115);
            break;

        case 0:
            return 0;
    }
    }while(1);

    system("pause");
    return 0;
}

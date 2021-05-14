#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

//cria o titulo e atualiza a tela, ainda limpa o buffer do teclado
 void titulo_mruv(x)
{
    system("cls");
    fflush(stdin);
    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
    printf("\n   MOVIMENTO RETIL�NEO UNIFORMEMENTE VARIADO");
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

    if(x == 1)// parametro passado personaliza o titulo para cada op��o que o usu�rio escolher
    {
        printf("\n***               ACELERA��O               ***");
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
        printf("\n*** POSI��O FINAL ***");
    }
    if(x == 5)
    {
        printf("\n*** POSI��O INICIAL ***");
    }
    if(x == 6)
    {
        printf("\n*** TEMPO ***");
    }
}

int main(void)
{
    setlocale(LC_ALL,"portuguese");//acentua��o da lingua portuguesa
    do{

    titulo_mruv();//chama a fun��o criada

    //variaveis que controlam se o usu�rio deseja fazer novamente a conta ou se deseja sair
    char continua_mruv1;
    char continua_mruv2;
    char continua_mruv3;
    char continua_mruv4;
    char continua_mruv5;
    char continua_mruv6;

    //menu do programa
    int menu = -1;//guarda na mem�ria a escolha do usu�rio
    printf("\n\n\n\nPara encontrar a ACELERA��O (a) de um corpo ----> DIGITE 1");
    printf("\nPara encontrar a VELOCIDADE FINAL (Vf) de um corpo ----> DIGITE 2");
    printf("\nPara encontrar a VELOCIDADE INICIAL (Vi) de um corpo ----> DIGITE 3");
    printf("\nPara encontrar a POSI��O FINAL (S) de um corpo ----> DIGITE 4");
    printf("\nPara encontrar a POSI��O INICIAL (Si) de um corpo ----> DIGITE 5");
    printf("\nPara encontrar a TEMPO (t) de um corpo ----> DIGITE 6");
    printf("\nPara sair ----> DIGITE 0");//acaba o programa
    printf("\nDIGITE SUA ESCOLHA: ");
    scanf("%d", & menu);

    switch(menu)
    {
        case 1://caso escolha a op��o 1
            do{
                titulo_mruv(1);//chama o titulo personalizado para op��o 1

                //vari�vel necess�ria para conta
                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                //vari�vel necess�ria para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //vari�vel necess�ria para conta
                float tempo_final;
                printf("Insira o TEMPO FINAL (tf) em SEGUNDOS: ");
                scanf("%f", & tempo_final);

                //vari�vel necess�ria para conta
                float tempo_inicial;
                printf("Insira o TEMPO INICIAL (ti) em SEGUNDOS: ");
                scanf("%f", & tempo_inicial);

                //conta
                float aceleracao;//onde o resultado vai ser guardado;
                if(tempo_final != 0)//condi��o para poder fazer a conta (tempo final diferente de 0)
                {
                    aceleracao = (velocidade_final - velocidade_inicial) / (tempo_final - tempo_inicial);//conta da acelera��o
                }

                printf("\n\nA ACELERA��O foi de: %.3f m/s^2", aceleracao); //mostra os resultados
                printf("\nF�RMULA: a = (Vf - Vi) / (tf - ti)\n"); //a = ∆V / ∆t\n      //mostra a f�rmula caso o usu�rio queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova ACELERA��O?(s/n) ");//usu�rio pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv1);//guarda a escolha
            }while(continua_mruv1 == 115);//testa a escolha do usu�rio
            break;//termina o switch

        case 2://caso escolha a op��o 2
            do{
                titulo_mruv(2);//chama o titulo personalizado para op��o 2

                //vari�vel necess�ria para conta
                float velocidade_inicial;
                printf("\n\n\nInsira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //vari�vel necess�ria para conta
                float aceleracao;
                printf("Insira a ACELERA��O (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //vari�vel necess�ria para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //conta
                float velocidade_final;//guarda o resultado da conta
                if(tempo > 0)//condi��o para come�ar a conta (tempo maior que 0)
                {
                    velocidade_final = velocidade_inicial + (aceleracao * tempo);//conta
                }

                printf("\n\nA VELOCIDADE FINAL foi de: %.3f m/s", velocidade_final);//mostra os resultados
                printf("\nF�RMULA: Vf = Vi + a * t\n");//mostra a f�rmula caso o usu�rio queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova VELOCIDADE FINAL?(s/n) ");//usu�rio pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv2);//guarda a escolha
            }while(continua_mruv2 == 115);//testa a escolha do usu�rio
            break;//termina o switch

        case 3://caso escolha a op��o 3
            do{
                titulo_mruv(3);//chama o titulo personalizado para op��o 3

                //vari�vel necess�ria para conta
                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                //vari�vel necess�ria para conta
                float aceleracao;
                printf("Insira a ACELERA��O (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //vari�vel necess�ria para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //conta
                float velocidade_inicial;//guarda o resultado da conta
                if(tempo > 0)//condi��o para come�ar a conta (tempo maior que 0)
                {
                    velocidade_inicial = velocidade_final - (aceleracao * tempo);//conta
                }

                printf("\n\nA VELOCIDADE INICIAL foi de: %.3f m/s", velocidade_inicial);//mosta os resultados
                printf("\nF�RMULA: Vi = Vf - a * t\n");//mostra a f�rmula caso o usu�rio queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova VELOCIDADE FINAL?(s/n) ");//usu�rio pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv3);//guarda a escolha
            }while(continua_mruv3 == 115);//testa a escolha do usu�rio
            break;//termina o switch

        case 4://caso escolha a op��o 4
            do{
                titulo_mruv(4);//chama o titulo personalizado para op��o 4

                //variavel necess�ria para conta
                float posicao_inicial;
                printf("\n\n\nInsira a POSI��O INICIAL (Si) em METROS: ");
                scanf("%f", & posicao_inicial);

                //variavel necess�ria para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variavel necess�ria para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //variavel necess�ria para conta
                float aceleracao;
                printf("Insira a ACELERA��O (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //conta
                float posicao_final;//guarda o resultado final da conta
                if(tempo > 0)//condi��o para come�ar a conta
                {
                    //conta doi separada em 3 partes
                    float tempo_ao_quadrado;
                    tempo_ao_quadrado = pow(tempo, 2);//parte 1

                    float aceleracao_2;
                    aceleracao_2 = aceleracao / 2;//parte 2

                    posicao_final = posicao_inicial + (velocidade_inicial*tempo) + (aceleracao_2 * tempo_ao_quadrado);//parte 3
                }

                printf("\n\nA POSI��O FINAL foi de: %.3f m", posicao_final);//mosta os resultados
                printf("\nF�RMULA: S = Si + Vi * t + 1/2 * a * t^2\n");//mostra a f�rmula caso o usu�rio queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSI��O FINAL?(s/n) ");//usu�rio pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv4);//guarda a escolha
            }while(continua_mruv4 == 115);//testa a escolha do usu�rio
            break;//termina o switch

        case 5://caso escolha a op��o 5
            do{
               titulo_mruv(5);//chama o titulo personalizado para op��o 5

                //variavel necess�ria para conta
                float posicao_final;
                printf("\n\n\nInsira a POSI��O FINAL (S) em METROS: ");
                scanf("%f", & posicao_final);

                //variavel necess�ria para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variavel necess�ria para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //variavel necess�ria para conta
                float aceleracao;
                printf("Insira a ACELERA��O (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //conta
                float posicao_inicial;//guarda o resultado final da conta
                if(tempo > 0)
                {
                    //conta foi separada em 3 partes
                    float tempo_ao_quadrado;
                    tempo_ao_quadrado = pow(tempo, 2);//parte 1

                    float aceleracao_2;
                    aceleracao_2 = aceleracao / 2;//parte 2

                    posicao_inicial = posicao_final - (velocidade_inicial * tempo) - (aceleracao_2 * tempo_ao_quadrado);//parte 3
                }

                printf("\n\nA POSI��O INICIAL foi de: %.3f m", posicao_inicial);//mosta os resultados
                printf("\nF�RMULA: Si = S - Vi * t + 1/2 * a * t^2\n");//mostra a f�rmula caso o usu�rio queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSI��O INICIAL (s/n) ");//usu�rio pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv5);//guarda a escolha
            }while(continua_mruv5 == 115);//testa a escolha do usu�rio
            break;//termina o switch

        case 6://caso escolha a op��o 6
            do{
                titulo_mruv(6);//chama o titulo personalizado para op��o 6

                //variavel necess�ria para conta
                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                //variavel necess�ria para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variavel necess�ria para conta
                float aceleracao;
                printf("Insira a ACELERA��O (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //conta
                float tempo;//guarda o resultado da conta
                tempo = (velocidade_final - velocidade_inicial) / aceleracao;//n�o necessita de condi��o para entrar no c�lculo

                printf("\n\nO TEMPO foi de: %.3f m", tempo);//conferir se o resultado está certo
                printf("\nF�RMULA: t = (Vf - Vi) / a\n");//

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSI��O INICIAL (s/n) ");//usu�rio pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv6);//guarda a escolha
            }while(continua_mruv6 == 115);//testa a escolha do usu�rio
            break;//termina o switch

        case 0://caso escolha op��o 0
            return 0;//finaliza o programa
    }//switch

    }while(1);//o doWhile s� � finalizado quando o usu�rio escolhe a op��o 0 no menu

    system("pause");//finalizando
    return 0;//sucesso
}

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
    printf("\n   MOVIMENTO RETILÍNEO UNIFORMEMENTE VARIADO");
    printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

    if(x == 1)// parametro passado personaliza o titulo para cada opção que o usuário escolher
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
    setlocale(LC_ALL,"portuguese");//acentuação da lingua portuguesa
    do{

    titulo_mruv();//chama a função criada

    //variaveis que controlam se o usuário deseja fazer novamente a conta ou se deseja sair
    char continua_mruv1;
    char continua_mruv2;
    char continua_mruv3;
    char continua_mruv4;
    char continua_mruv5;
    char continua_mruv6;

    //menu do programa
    int menu = -1;//guarda na memória a escolha do usuário
    printf("\n\n\n\nPara encontrar a ACELERAÇÃO (a) de um corpo ----> DIGITE 1");
    printf("\nPara encontrar a VELOCIDADE FINAL (Vf) de um corpo ----> DIGITE 2");
    printf("\nPara encontrar a VELOCIDADE INICIAL (Vi) de um corpo ----> DIGITE 3");
    printf("\nPara encontrar a POSIÇÃO FINAL (S) de um corpo ----> DIGITE 4");
    printf("\nPara encontrar a POSIÇÃO INICIAL (Si) de um corpo ----> DIGITE 5");
    printf("\nPara encontrar a TEMPO (t) de um corpo ----> DIGITE 6");
    printf("\nPara sair ----> DIGITE 0");//acaba o programa
    printf("\nDIGITE SUA ESCOLHA: ");
    scanf("%d", & menu);

    switch(menu)
    {
        case 1://caso escolha a opção 1
            do{
                titulo_mruv(1);//chama o titulo personalizado para opção 1

                //variável necessária para conta
                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                //variável necessária para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variável necessária para conta
                float tempo_final;
                printf("Insira o TEMPO FINAL (tf) em SEGUNDOS: ");
                scanf("%f", & tempo_final);

                //variável necessária para conta
                float tempo_inicial;
                printf("Insira o TEMPO INICIAL (ti) em SEGUNDOS: ");
                scanf("%f", & tempo_inicial);

                //conta
                float aceleracao;//onde o resultado vai ser guardado;
                if(tempo_final != 0)//condição para poder fazer a conta (tempo final diferente de 0)
                {
                    aceleracao = (velocidade_final - velocidade_inicial) / (tempo_final - tempo_inicial);//conta da aceleração
                }

                printf("\n\nA ACELERAÇÃO foi de: %.3f m/s^2", aceleracao); //mostra os resultados
                printf("\nFÓRMULA: a = (Vf - Vi) / (tf - ti)\n"); //a = âˆ†V / âˆ†t\n      //mostra a fórmula caso o usuário queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova ACELERAÇÃO?(s/n) ");//usuário pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv1);//guarda a escolha
            }while(continua_mruv1 == 115);//testa a escolha do usuário
            break;//termina o switch

        case 2://caso escolha a opção 2
            do{
                titulo_mruv(2);//chama o titulo personalizado para opção 2

                //variável necessária para conta
                float velocidade_inicial;
                printf("\n\n\nInsira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variável necessária para conta
                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //variável necessária para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //conta
                float velocidade_final;//guarda o resultado da conta
                if(tempo > 0)//condição para começar a conta (tempo maior que 0)
                {
                    velocidade_final = velocidade_inicial + (aceleracao * tempo);//conta
                }

                printf("\n\nA VELOCIDADE FINAL foi de: %.3f m/s", velocidade_final);//mostra os resultados
                printf("\nFÓRMULA: Vf = Vi + a * t\n");//mostra a fórmula caso o usuário queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova VELOCIDADE FINAL?(s/n) ");//usuário pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv2);//guarda a escolha
            }while(continua_mruv2 == 115);//testa a escolha do usuário
            break;//termina o switch

        case 3://caso escolha a opção 3
            do{
                titulo_mruv(3);//chama o titulo personalizado para opção 3

                //variável necessária para conta
                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                //variável necessária para conta
                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //variável necessária para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //conta
                float velocidade_inicial;//guarda o resultado da conta
                if(tempo > 0)//condição para começar a conta (tempo maior que 0)
                {
                    velocidade_inicial = velocidade_final - (aceleracao * tempo);//conta
                }

                printf("\n\nA VELOCIDADE INICIAL foi de: %.3f m/s", velocidade_inicial);//mosta os resultados
                printf("\nFÓRMULA: Vi = Vf - a * t\n");//mostra a fórmula caso o usuário queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova VELOCIDADE FINAL?(s/n) ");//usuário pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv3);//guarda a escolha
            }while(continua_mruv3 == 115);//testa a escolha do usuário
            break;//termina o switch

        case 4://caso escolha a opção 4
            do{
                titulo_mruv(4);//chama o titulo personalizado para opção 4

                //variavel necessária para conta
                float posicao_inicial;
                printf("\n\n\nInsira a POSIÇÃO INICIAL (Si) em METROS: ");
                scanf("%f", & posicao_inicial);

                //variavel necessária para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variavel necessária para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //variavel necessária para conta
                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //conta
                float posicao_final;//guarda o resultado final da conta
                if(tempo > 0)//condição para começar a conta
                {
                    //conta doi separada em 3 partes
                    float tempo_ao_quadrado;
                    tempo_ao_quadrado = pow(tempo, 2);//parte 1

                    float aceleracao_2;
                    aceleracao_2 = aceleracao / 2;//parte 2

                    posicao_final = posicao_inicial + (velocidade_inicial*tempo) + (aceleracao_2 * tempo_ao_quadrado);//parte 3
                }

                printf("\n\nA POSIÇÃO FINAL foi de: %.3f m", posicao_final);//mosta os resultados
                printf("\nFÓRMULA: S = Si + Vi * t + 1/2 * a * t^2\n");//mostra a fórmula caso o usuário queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSIÇÃO FINAL?(s/n) ");//usuário pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv4);//guarda a escolha
            }while(continua_mruv4 == 115);//testa a escolha do usuário
            break;//termina o switch

        case 5://caso escolha a opção 5
            do{
               titulo_mruv(5);//chama o titulo personalizado para opção 5

                //variavel necessária para conta
                float posicao_final;
                printf("\n\n\nInsira a POSIÇÃO FINAL (S) em METROS: ");
                scanf("%f", & posicao_final);

                //variavel necessária para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variavel necessária para conta
                float tempo;
                printf("Insira o TEMPO (t) que levou em SEGUNDOS: ");
                scanf("%f", & tempo);

                //variavel necessária para conta
                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
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

                printf("\n\nA POSIÇÃO INICIAL foi de: %.3f m", posicao_inicial);//mosta os resultados
                printf("\nFÓRMULA: Si = S - Vi * t + 1/2 * a * t^2\n");//mostra a fórmula caso o usuário queira conferir

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSIÇÃO INICIAL (s/n) ");//usuário pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv5);//guarda a escolha
            }while(continua_mruv5 == 115);//testa a escolha do usuário
            break;//termina o switch

        case 6://caso escolha a opção 6
            do{
                titulo_mruv(6);//chama o titulo personalizado para opção 6

                //variavel necessária para conta
                float velocidade_final;
                printf("\n\n\nInsira a VELOCIDADE FINAL (Vf) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_final);

                //variavel necessária para conta
                float velocidade_inicial;
                printf("Insira a VELOCIDADE INICIAL (Vi) em METROS POR SEGUNDO: ");
                scanf("%f", & velocidade_inicial);

                //variavel necessária para conta
                float aceleracao;
                printf("Insira a ACELERAÇÃO (a) em METROS POR SEGUNDO ao quadrado: ");
                scanf("%f", & aceleracao);

                //conta
                float tempo;//guarda o resultado da conta
                tempo = (velocidade_final - velocidade_inicial) / aceleracao;//não necessita de condição para entrar no cálculo

                printf("\n\nO TEMPO foi de: %.3f m", tempo);//conferir se o resultado estÃ¡ certo
                printf("\nFÓRMULA: t = (Vf - Vi) / a\n");//

                fflush(stdin);
                printf("\nDeseja calcular uma nova POSIÇÃO INICIAL (s/n) ");//usuário pode escolher entre fazer a conta novamente ou terminar
                scanf("%c", & continua_mruv6);//guarda a escolha
            }while(continua_mruv6 == 115);//testa a escolha do usuário
            break;//termina o switch

        case 0://caso escolha opção 0
            return 0;//finaliza o programa
    }//switch

    }while(1);//o doWhile só é finalizado quando o usuário escolhe a opção 0 no menu

    system("pause");//finalizando
    return 0;//sucesso
}

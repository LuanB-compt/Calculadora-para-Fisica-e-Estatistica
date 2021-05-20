#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define MAX 100
#define ARRAYLEN(ar) sizeof(ar)/sizeof(ar[0])

int main(void)
{
    system("color 0F");
    setlocale(LC_ALL, "portuguese");
    int menu_principal = -1;
    do{
        fflush(stdin);
        system("cls");
        system("color 0F");
        printf("1 --- Média, Moda e Mediana\n");
        printf("2 --- Movimento Retilíneo Uniformemente\n");
        printf("3 --- Movimento Retilíneo Uniformemente Variado\n");
        printf("4 --- Desvio e Variancia\n");
        printf("0 --- Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &menu_principal);
        switch(menu_principal) {
        case 1:
            MMM();
            break;
        case 2:
            MRU();
            break;
        case 3:
            MRUV();
            break;
        case 4:
            Desvio();
            break;
        case 0:
            return 0;
        }

    } while (1);
}

// #####################
// MÉDIA, MODA E MEDIANA
// #####################

int MMM(void)
{
    system("color 06");
    do{

    //variavel que finaliza ou recomeça o cada case
    char continua;
    char continua_moda;
    char continua_mediana;

    system("cls");
    printf("-------------------------------------------------------------------------------\n");
    printf("***                           MÉDIA, MODA OU MEDIANA =)                    ***\n");
    printf("-------------------------------------------------------------------------------");

    //alterna entre calculo de média, moda ou mediana
    int menuMMM = -1;
    printf("\n\n\nAperte 1 para calcular média aritmética");
    printf("\nAperte 2 para calcular moda");
    printf("\nAperte 3 para calcular mediana");
    printf("\nAperte 0 para sair");
    printf("\nInsira sua escolha aqui: ");
    scanf("%d", & menuMMM);

    fflush(stdin);

    //função que atualiza a tela para a tela da média
    void telaMedia()
    {
        system("cls");
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n                   MÉDIA ARITMÉTICA");
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n\n\n");
        fflush(stdin);
    }

    void telaMediana()
    {
        system("cls");
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n                          MEDIANA");
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n\n\n");
        fflush(stdin);
    }

    switch(menuMMM)
    {
        case 1:
            do{
                //título
                telaMedia();    //atualiza a tela

                 //pede os dados do usuário
                int n;
                float soma = 0;

                printf("Quantos elementos? "); //pergunta com quantos elementos o usuário deseja fazer a média
                scanf("%d", &n);

                float listinha[n];  //cria a lista baseada no valor de elementos do usuário

                printf("Digite os dados: \n");

                for (int i = 0; i < n; i++)
                {        //for para coletar dado por dado e adiciona-lo em seu respectivo espaço na lista
                  printf("Digite o %d°: ", i + 1);
                  scanf("%f", &listinha[i]);
                }

                telaMedia();                    //atualiza a tela
                printf("Os elementos são: ");

                for (int i = 0; i < n -1 ; i++)//coloquei n-1 para não incluir o último elemento, pois eu quero que o último elemento seja diferente
                {

                  printf("%.2f; ", listinha[i]);    //printa os termos da lista
                  soma += listinha[i];              //soma = soma + lista[indice]
                }
                soma += listinha[n-1];              //soma do último elemento
                printf("%.2f.\n", listinha[n-1]);   //formatação do último elemento,
                // essas duas coisas foram necessárias para que o último elemento fosse printado diferente

                //calcula e mostra o tamanho da lista com os dados brutos
                int tamanho_lista = ARRAYLEN(listinha);
                printf("\nSão %d elementos.\t\t A soma é: %.2f.\n\n", tamanho_lista, soma);

                //faz a média aritmetica dos dados da lista
                float media_aritmetica;
                if(tamanho_lista > 0)
                {
                    media_aritmetica = (float)soma / tamanho_lista;
                }
                printf("\n- Média aritmetica = %.2f\n\n", media_aritmetica);

                //termina ou começa novamente o programa
                fflush(stdin);
                printf("\n\n\nDeseja fazer uma nova média?(s/n) ");
                scanf("%c", & continua);
            }while (continua == 115);
            break;
        case 2:
            do{
                //título
                system("cls");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                printf("\n                          MODA");
                printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                printf("\n\n\n");
                fflush(stdin);

                //codigo de criação da lista inicial
                int n;
                printf("Quantos elementos? "); //pergunta com quantos elementos o usuário deseja encontrar a mediana
                scanf("%d", &n);
                float listinha[n];
                printf("Digite os dados: \n");

                //pega os dados do usuário
                for (int i = 0; i < n; i++)
                {        //for para coletar dado por dado e adiciona-lo em seu respectivo espaço na lista
                  printf("Digite o %d°: ", i + 1);
                  scanf("%f", &listinha[i]);
                }

                //codigo que utiliza variaveis para armazenar qual é a moda

                float moda;
                int aux2 = 0;
                for (int i = 0; i < n; i++){
                    int aux = 0;

                    for (int j = 0; j < n; j++){
                        if (listinha[i] == listinha[j]){
                            aux++;
                        }
                    }
                    if (aux >= aux2){
                        aux2 = aux;
                        moda = listinha[i];
                    }
                }
                printf("\n\n A moda é %.2f\nO elemento aparece %d vezes", moda, aux2);

                //termina ou começa novamente o programa
                fflush(stdin);
                printf("\n\n\nDeseja encontrar uma nova moda?(s/n) ");
                scanf("%c", & continua_moda);
            }while(continua_moda == 115);
            break;

        case 3:
            do{
                //título
                telaMediana();

                int n;

                printf("Quantos elementos? "); //pergunta com quantos elementos o usuário deseja encontrar a mediana
                scanf("%d", &n);

                float listinha[n];
                printf("Digite os dados: \n");

                for (int i = 0; i < n; i++)
                {        //for para coletar dado por dado e adiciona-lo em seu respectivo espaço na lista
                  printf("Digite o %d°: ", i + 1);
                  scanf("%f", &listinha[i]);
                }

                for (int i = 0; i < n; i++){            //esse aninhado de for testa número por número para saber a ordem entre eles... não me perguntem ao certo como funciona, ainda não entendi tbm KKKK
                    for (int j = i + 1; j < n; j++){    //se quiserem pesquisar, o nome disso é "selection sort"
                        if (listinha[i] > listinha[j]){
                            float a = listinha[i];
                            listinha[i] = listinha[j];
                            listinha[j] = a;
                        }
                    }
                }
                printf("\nO Rol dos números em ordem crescente é: \n");   //printa a nova lista com os números substituídos para a ordem correta
                for (int i = 0; i < n; ++i)
                    printf("|%.2f|   ", listinha[i]);

                float mediana = 0.0;
                int tamanho_lista = ARRAYLEN(listinha);

                if (tamanho_lista % 2 == 0)
                {
                    int a = tamanho_lista/2;
                    mediana = (listinha[a]+listinha[a - 1])/2;
                }
                else
                {
                    int a = tamanho_lista/2;
                    mediana = listinha[a];
                }

                printf("\n\nA mediana dos dados é: %.4f", mediana);

                //termina ou começa novamente o programa
                fflush(stdin);
                printf("\n\n\nDeseja fazer uma nova média?(s/n) ");
                scanf("%c", & continua_mediana);
            }while(continua_mediana == 115);
            break;

        case 0:
            return 0;
    }
    } while (1); //1 = true... loop para sempre
    system("pause");
    return 0;
}

// ############################
// MOVIMENTO RETILINEO UNIFORME
// ############################

void tela_mru(x) //função que atualiza a tela junto com o menu para o programa MRU
{
    system("cls");
    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
    printf("\n              MOVIMENTO RETÍLINEO UNIFORME");
    printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");

    if(x == 1)
    {
        printf("\n***                ESPAÇO PERCORRIDO                     ***");
    }
    if(x == 2)
    {
        printf("\n***                  POSIÇÃO INICIAL                     ***");
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

int MRU(void)
{
    do{
    setlocale(LC_ALL, "portuguese");
    system("color 75");

    //variavel de cada do while,  que está em todos os cases do switch
    char continua_mru1;
    char continua_mru2;
    char continua_mru3;
    char continua_mru4;

    tela_mru(0);//printa o menu usando a função criada tela_mru

    //mostra as opções de variáveis que o programa pode calcular, e qual o usuário pode usar
    int menuMRU = -1;
    printf("\n\n\n\nSe deseja encontrar o ESPAÇO PERCORRIDO (S) pelo corpo ----> DIGITE 1");
    printf("\nSe deseja encontrar a POSIÇÃO INICIAL (S0) do corpo ----> DIGITE 2");
    printf("\nSe deseja encontrar a VELOCIDADE (V) do corpo ----> DIGITE 3");
    printf("\nSe deseja encontrar o TEMPO (t) do movimento ----> DIGITE 4");
    printf("\nSe deseja sair ----> DIGITE 0");
    printf("\n\nINSIRA AQUI: ");
    scanf("%d", & menuMRU);

    //leva para cada cálculo diferente
    switch(menuMRU)
    {
        case 1:
            do
            {
                tela_mru(1);//printa o menu

                //recebe a posição inicial para a conta
                float posicao_inicial;
                printf("\n\n\n\nInsira a POSIÇÃO INICIAL (S0) METROS do corpo: ");
                scanf("%f", & posicao_inicial);

                //recebe a velocidade para a conta
                float velocidade;
                printf("Insira a VELOCIDADE (V) em METROS POR SEGUNDO do corpo: ");
                scanf("%f", & velocidade);

                //recebe o tempo para a conta
                float tempo;
                printf("Insira o TEMPO (t) em SEGUNDOS que durou o movimento: ");
                scanf("%f", & tempo);

                //calcula o espaço percorrido se o tempo e a velocidade forem diferentes que zero
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

                printf("\n\nO ESPAÇO PERCORRIDO (S) foi: %.4f metros\n", espaco_percorrido); //printa na tela o resultado
                printf("FÓRMULA: S = S0 + V * t\n"); //formula usada para o calculo

                //termina ou começa novamente o programa
                fflush(stdin);
                printf("Deseja fazer o cálculo novamente?(s/n) ");
                scanf("%c", & continua_mru1);
            }while(continua_mru1 == 115);
            break;

        case 2:
            do
            {
                tela_mru(2);//printa o menu

                //recebe o espaço percorrido para a conta
                float espaco_percorrido;
                printf("\n\n\n\nInsira ESPAÇO PERCORRIDO (S) em METROS pelo corpo: ");
                scanf("%f", & espaco_percorrido);

                //recebe a velocidade para a conta
                float velocidade;
                printf("Insira a VELOCIDADE (V) em METROS POR SEGUNDO do corpo: ");
                scanf("%f", & velocidade);

                //recebe o tempo para a conta
                float tempo;
                printf("Insira o TEMPO (t) em SEGUNDOS que durou o movimento: ");
                scanf("%f", & tempo);

                //calcula a posição inicial se o tempo e a velocidade forem diferentes que zero
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

                printf("\n\nA POSIÇÃO INICIAL (S0) é: %.4f metros\n", posicao_inicial); //printa na tela o resultado
                printf("FÓRMULA: S0 = S - V * t\n"); //formula usada para o calculo

                //termina ou comeÃ§a novamente o programa
                fflush(stdin);
                printf("Deseja fazer cálculo novamente?(s/n) ");
                scanf("%c", & continua_mru2);
            }while (continua_mru2 == 115);
            break;

        case 3:
            do
            {
                tela_mru(3);//printa o menu

                //recebe o espaço percorrido para a conta
                float espaco_percorrido;
                printf("\n\n\n\nInsira ESPAÇO PERCORRIDO (S) em METROS pelo corpo: ");
                scanf("%f", & espaco_percorrido);

                //recebe a posição inicial para a conta
                float posicao_inicial;
                printf("Insira a POSIÇÃO INICIAL (S0) METROS do corpo: ");
                scanf("%f", & posicao_inicial);

                //recebe o tempo para a conta
                float tempo;
                printf("Insira o TEMPO (t) em SEGUNDOS que durou o movimento: ");
                scanf("%f", & tempo);

                //calcula a posiÃ§Ã£o inicial se o tempo e a velocidade forem diferentes que zero
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

                printf("\n\nA VELOCIDADE (V) é: %.4f m/s\n", velocidade); //printa na tela o resultado
                printf("FÓRMULA: V = (S - S0) / t\n"); //formula usada para o calculo

                //termina ou comeÃ§a novamente o programa
                fflush(stdin);
                printf("Deseja fazer cálculo novamente?(s/n) ");
                scanf("%c", & continua_mru3);
            }while (continua_mru3 == 115);
            break;

        case 4:
            do
            {
                tela_mru(4);//printa o menu

                //recebe a posição inicial para a conta
                float posicao_inicial;
                printf("\n\n\n\nInsira a POSIÇÃO INICIAL (S0) METROS do corpo: ");
                scanf("%f", & posicao_inicial);

                //recebe o espaço percorrido para a conta
                float espaco_percorrido;
                printf("Insira ESPAÇO PERCORRIDO (S) em METROS pelo corpo: ");
                scanf("%f", & espaco_percorrido);

                //recebe a velocidade para a conta
                float velocidade;
                printf("Insira a VELOCIDADE (V) em METROS POR SEGUNDO do corpo: ");
                scanf("%f", & velocidade);

                //calcula a posição inicial se o tempo e a velocidade forem diferentes que zero
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

                printf("\n\nA TEMPO (t) foi de: %.4f segundos\n", tempo); //printa o resultado
                printf("FÓRMULA: t = (S0 - S) / V\n"); //formula usada para o calculo

                //termina ou começa novamente o programa
                fflush(stdin);
                printf("Deseja fazer cálculo novamente?(s/n) ");
                scanf("%c", & continua_mru4);
            }while(continua_mru4 == 115);
            break;

        case 0:
            return 0;
    }

    }while(1);

    system("pause");
    return 0;
}

// #########################################
// MOVIMENTO RETILINEO UNIFORMEMENTE VARIADO
// #########################################

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

int MRUV(void)
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
    int menuMRUV = -1;//guarda na memória a escolha do usuário
    printf("\n\n\n\nPara encontrar a ACELERAÇÃO (a) de um corpo ----> DIGITE 1");
    printf("\nPara encontrar a VELOCIDADE FINAL (Vf) de um corpo ----> DIGITE 2");
    printf("\nPara encontrar a VELOCIDADE INICIAL (Vi) de um corpo ----> DIGITE 3");
    printf("\nPara encontrar a POSIÇÃO FINAL (S) de um corpo ----> DIGITE 4");
    printf("\nPara encontrar a POSIÇÃO INICIAL (Si) de um corpo ----> DIGITE 5");
    printf("\nPara encontrar a TEMPO (t) de um corpo ----> DIGITE 6");
    printf("\nPara sair ----> DIGITE 0");//acaba o programa
    printf("\nDIGITE SUA ESCOLHA: ");
    scanf("%d", & menuMRUV);

    switch(menuMRUV)
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

// ##################
// Desvio e Variancia
// ##################

void titulo_desvio(x)
{
    system("cls");
    fflush(stdin);
    printf("9696969696969696969696969696969696969969696969696969696969696");
    printf("\n                        DESVIO PADRÃO");
    printf("\n9696969696969696969696969696969696969969696969696969696969696");
    if(x == 1)
    {
        printf("\n                          VARIÂNCIA");
    }
}

int Desvio(void)
{
    setlocale(LC_ALL, "portuguese");
    do{
        titulo_desvio();
        int menu_desvio;
        printf("\n\n\nDeseja calcular o DESVIO PADRÃO ---> 1");
        printf("\nDeseja calcular a VARIÂNCIA ---> 2");
        printf("\nDeseja SAIR ---> 0");
        printf("\nINSIRA aqui: ");
        scanf("%i", & menu_desvio);

        char continua_desvio;
        char continua_variancia;

        switch(menu_desvio)
        {
            case 1:
                do{
                    titulo_desvio();
                    int numero_elementos;
                    printf("\n\n\nQuantos elementos tem a base de dados? ");
                    scanf("%i", & numero_elementos);

                    float base_dados[numero_elementos];
                    printf("\n");

                    int i = 0;
                    for(i = 0; i < numero_elementos; i++)
                    {
                        fflush(stdin);
                        printf("Insira o %d° elemento: ", i+1);
                        scanf("%f", & base_dados[i]);
                    }

                    float desvio_padrao_amostral, desvio_padrao_populacional;
                    float variancia_amostral, variancia_populacional;
                    float variancia_quadrado, variancia;
                    float media;
                    float soma = 0;
                    float soma_variancia = 0;
                    int n = 0;
                    if(ARRAYLEN(base_dados) > 1)
                    {
                        for(i = 0; i < numero_elementos; i++)
                        {
                            soma += base_dados[i];//soma os elementos
                        }

                        media = soma / numero_elementos;//média dos elementos

                        for(i = 0; i < numero_elementos; i++)
                        {
                            variancia = media - base_dados[i];//variancia
                            variancia_quadrado = pow(variancia, 2);//variancia ao quadrado
                            soma_variancia += variancia_quadrado;
                        }
                        variancia_amostral = soma_variancia / (numero_elementos - 1);//variancia ao quadrado por "n-1"
                        variancia_populacional = soma_variancia / numero_elementos;//variancia ao quadrado por "n"

                        desvio_padrao_amostral = sqrt(variancia_amostral);//raiz da variancia = desvio
                        desvio_padrao_populacional = sqrt(variancia_populacional);
                    } else {
                        desvio_padrao_amostral = 0;
                        desvio_padrao_populacional = 0;
                    }
                    printf("\n\nO desvio padrão amostral é: %f\n", desvio_padrao_amostral);
                    printf("O desvio padrão populacional é: %f\n", desvio_padrao_populacional);
                    system("pause");
                    fflush(stdin);
                    printf("\n\nDeseja calcular outros desvios? (s/n)\n");
                    scanf("%c", &continua_desvio);
                }while(continua_desvio == 's');
                break;

            case 2:
                do{
                    titulo_desvio(1);
                    int numero_elementos;
                    printf("\n\n\nQuantos elementos tem a base de dados? ");
                    scanf("%i", & numero_elementos);

                    float base_dados[numero_elementos];
                    printf("\n");

                    int i = 0;
                    for(i = 0; i < numero_elementos; i++)
                    {
                        fflush(stdin);
                        printf("Insira o %d° elemento: ", i+1);
                        scanf("%f", & base_dados[i]);
                    }
                    float variancia_amostral, variancia_populacional;
                    float variancia_quadrado, variancia;
                    float media;
                    float soma = 0;
                    float soma_variancia = 0;
                    int n = 0;
                    if(ARRAYLEN(base_dados) > 1)
                    {
                        for(i = 0; i < numero_elementos; i++)
                        {
                            soma += base_dados[i];//soma os elementos
                        }

                        media = soma / numero_elementos;//média dos elementos

                        for(i = 0; i < numero_elementos; i++)
                        {
                            variancia = media - base_dados[i];//variancia
                            variancia_quadrado = pow(variancia, 2);//variancia ao quadrado
                            soma_variancia += variancia_quadrado;
                        }
                        variancia_amostral = soma_variancia / (numero_elementos - 1);//variancia ao quadrado por "n-1"
                        variancia_populacional = soma_variancia / numero_elementos;//variancia ao quadrado por "n"

                    } else {
                        variancia_amostral = 0;
                        variancia_populacional = 0;
                    }
                    printf("\n\nA variância amostral é: %f\n", variancia_amostral);
                    printf("A variância populacional é: %f\n", variancia_populacional);
                    system("pause");
                    fflush(stdin);
                    printf("\n\nDeseja calcular outras variâncias?? (s/n)\n");
                    scanf("%c", &continua_variancia);
                }while(continua_variancia == 's');
                break;
            case 0:
                return 0;
        }

    }while(1);
    system("pause");
    return 0;
}

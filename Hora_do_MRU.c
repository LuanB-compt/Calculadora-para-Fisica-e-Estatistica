#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void screen_usm(int x, bool limpar);
void screen_menu(int *num_choose);

void space_travelled(char *continue_);
void starting_position(char *continue_);
void velocity(char *continue_);
void time(char *continue_);

int main(void)
{
    do{
        setlocale(LC_ALL, "portuguese");
        system("color 75");

        // Variable of each while, that is in all the switch cases
        char continue_usm;
        screen_usm(0, true);

        // Show the options of variables that the program can calculate, and which the user can choose
        int menu = -1;
        screen_menu(&menu);

        //leva para cada cálculo diferente
        // Take the user to each different calculus
        switch(menu){
            case 1:
                do{
                    screen_usm(1, true);
                    space_travelled(&continue_usm);

                }while(continue_usm == 121);
                break;

            case 2:
                do{
                    screen_usm(2, true);
                    starting_position(&continue_usm);

                }while (continue_usm == 115);
                break;

            case 3:
                do{
                    screen_usm(3, true);
                    velocity(&continue_usm);

                }while (continue_usm == 115);
                break;

            case 4:
                do{
                    screen_usm(4, true);
                    time(&continue_usm);

                }while(continue_usm == 115);
                break;

            case 0:
                return 0;
        }
    }while(1);

    system("pause");
    return 0;
}

void screen_usm(int x, bool clear)
{
    /*Função que atualiza a tela junto com o menu para o programa MRU*/
    /*Function that update the screen with the menu to Program USM*/

    if(clear == true){
        system("cls");
    }

    printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");
    printf("\n                UNIFORM STRAIGHT MOTION");
    printf("\n_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-");

    if(x == 1){
        printf("\n***                 SPACE TRAVELLED                      ***");
    }
    if(x == 2){
        printf("\n***                 STARTING POSITION                    ***");
    }
    if(x == 3){
        printf("\n***                      VELOCITY                        ***");
    }
    if(x == 4){
        printf("\n***                       TIME                           ***");
    }
}

void screen_menu(int *num_choose){
    printf("\n\n\n\nIf you want to find the SPACE TRAVELLED (S) by the body     -----> PRESS 1");
    printf("\nIf you want to find the STARTING POSITION (S0) by the body  -----> PRESS 2");
    printf("\nIf you want to find the VELOCITY (V) by the body            -----> PRESS 3");
    printf("\nIf you want to find the TIME (t) of movement                -----> PRESS 4");
    printf("\nIf you want to exit                                         -----> PRESS 0");
    printf("\n\nINSERT HERE: ");
    scanf("%d", num_choose);
}

void space_travelled(char *continue_){
    // Receives the starting position to the calculus
    float posicao_inicial;
    printf("\n\n\n\nInsert the STARTING POSITION (S0) in METERS of the body: ");
    scanf("%f", & posicao_inicial);

    // Receives the velocity to the calculus
    float velocidade;
    printf("Insert the VELOCITY (V) in METERS PER SECOND of the body: ");
    scanf("%f", & velocidade);

    // Receives the time to the calculus
    float tempo;
    printf("Insert the TIME (t) in SECONDS that the movement lasted: ");
    scanf("%f", & tempo);

    // Calculates the space travelled
    float espaco_percorrido;
    espaco_percorrido = posicao_inicial + (velocidade * tempo);

    printf("\n\nTHE SPACE TRAVELLED (S) was: %.4f meters\n", espaco_percorrido);
    printf("FORMULA: S = S0 + V * t\n"); // Formula used for calculation

    if(tempo == 0){
        printf("\nOBSERVATION:");
        printf("\nYou insert the time=0, therefore, don't exist moviment and the body is in the same position\n\n\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("Do you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void starting_position(char *continue_){
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
    if(tempo != 0 && velocidade != 0){
        posicao_inicial = espaco_percorrido - (velocidade * tempo);
    }
    else{
        printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
        Sleep(5000);
        //break;
    }

    printf("\n\nA POSIÇÃO INICIAL (S0) é: %.4f metros\n", posicao_inicial); //printa na tela o resultado
    printf("FÓRMULA: S0 = S - V * t\n"); //formula usada para o calculo

    //termina ou comeÃ§a novamente o programa
    fflush(stdin);
    printf("Deseja fazer cálculo novamente?(s/n) ");
    scanf("%c", continue_);
}

void velocity(char *continue_){
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
    if(tempo != 0 && espaco_percorrido != 0){
        velocidade = (espaco_percorrido - posicao_inicial) / tempo;
    }
    else{
        printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
        Sleep(5000);
        //break;
    }

    printf("\n\nA VELOCIDADE (V) é: %.4f m/s\n", velocidade); //printa na tela o resultado
    printf("FÓRMULA: V = (S - S0) / t\n"); //formula usada para o calculo

    //termina ou comeÃ§a novamente o programa
    fflush(stdin);
    printf("Deseja fazer cálculo novamente?(s/n) ");
    scanf("%c", continue_);
}

void time(char *continue_){
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
    if(velocidade != 0 && espaco_percorrido != 0){
        tempo = (posicao_inicial - espaco_percorrido) / velocidade;
    }
    else{
        printf("\n\nALGUM VALOR DEVE TER SIDO INSIRIDO ERRADO, ESPERE 5 SEGUNDOS E TENTE NOVAMENTE...");
        Sleep(5000);
        //break;
    }

    printf("\n\nA TEMPO (t) foi de: %.4f segundos\n", tempo); //printa o resultado
    printf("FÓRMULA: t = (S0 - S) / V\n"); //formula usada para o calculo

    //termina ou começa novamente o programa
    fflush(stdin);
    printf("Deseja fazer cálculo novamente?(s/n) ");
    scanf("%c", continue_);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void screen_usm(int x, bool limpar);
void screen_menu(int *num_choose);

void final_position(char *continue_);
void starting_position(char *continue_);
void velocity(char *continue_);
void time(char *continue_);

int main(void)
{
    do{
        system("color 75");

        // Variable of each while, that is in all the switch cases
        char continue_usm;
        screen_usm(0, true);

        // Show the options of variables that the program can calculate, and which the user can choose
        int menu = -1;
        screen_menu(&menu);

        // Take the user to each different calculus
        switch(menu){
            case 1:
                do{
                    screen_usm(1, true);
                    final_position(&continue_usm);

                }while(continue_usm == 121);
                break;

            case 2:
                do{
                    screen_usm(2, true);
                    starting_position(&continue_usm);

                }while (continue_usm == 121);
                break;

            case 3:
                do{
                    screen_usm(3, true);
                    velocity(&continue_usm);

                }while (continue_usm == 121);
                break;

            case 4:
                do{
                    screen_usm(4, true);
                    time(&continue_usm);

                }while(continue_usm == 121);
                break;

            case 0:
                return false;
        }
    }while(true);

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
    printf("\n\n\n\nIf you want to find the FINAL POSITION (S) by the body      -----> PRESS 1");
    printf("\nIf you want to find the STARTING POSITION (S0) by the body  -----> PRESS 2");
    printf("\nIf you want to find the VELOCITY (V) by the body            -----> PRESS 3");
    printf("\nIf you want to find the TIME (t) of movement                -----> PRESS 4");
    printf("\nIf you want to exit                                         -----> PRESS 0");
    printf("\n\nINSERT HERE: ");
    scanf("%d", num_choose);
}

void final_position(char *continue_){
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

    printf("\n\nTHE FINAL POSITION (S) was: %.4f meters\n", espaco_percorrido);
    printf("FORMULA: S = S0 + V * t\n"); // Formula used for calculation

    // Observations to help the user interpret the account result
    if(tempo == 0 && velocidade == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(tempo < 0 && velocidade < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the movement happen before the t=0");
        printf("\nYou entered the velocity<0, therefore, the body is returning with respect to the zero position (S=0)\n");
    }
    else if(velocidade == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(tempo == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(velocidade < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity<0, therefore, the body is returning with respect to the zero position (S=0)\n");
    }
    else if(time < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the movement happen before the t=0\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void starting_position(char *continue_){
    // Receives the space travalled to the calculus
    float espaco_percorrido;
    printf("\n\n\n\nInsert the FINAL POSITION (S) in METERS of the body: ");
    scanf("%f", & espaco_percorrido);

    // Receives the velocity to the calculus
    float velocidade;
    printf("Insert the VELOCITY (V) in METERS PER SECOND of the body: ");
    scanf("%f", & velocidade);

    // Receives the time to the calculus
    float tempo;
    printf("Insert the TIME (t) in SECONDS that the movement lasted: ");
    scanf("%f", & tempo);

    // Calculates the starting position
    float posicao_inicial;
    posicao_inicial = espaco_percorrido - (velocidade * tempo);

    printf("\n\nTHE STARTING POSITION (S0) is: %.4f meters\n", posicao_inicial);
    printf("FÓRMULA: S0 = S - V * t\n"); // Formula used to calculation

    // Observations to help the user interpret the account result
    if(tempo == 0 && velocidade == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(tempo < 0 && velocidade < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the movement happen before the t=0");
        printf("\nYou entered the velocity<0, therefore, the body is going to foward\n");
    }
    else if(velocidade == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(tempo == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(velocidade < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity<0, therefore, the body start in front and turn back\n");
    }
    else if(tempo < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the body is going to back\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void velocity(char *continue_){
    // Receives the space travelled to the calculus
    float espaco_percorrido;
    printf("\n\n\n\nInsert the FINAL POSITION (S) in METERS of the body: ");
    scanf("%f", & espaco_percorrido);

    // Receives the starting position to the calculus
    float posicao_inicial;
    printf("Insert the STARTING POSITION (S0) in METERS of the body: ");
    scanf("%f", & posicao_inicial);

    // Receives the time to the calculus
    float tempo;
    printf("Insert the TIME (t) in SECONDS that the movement lasted: ");
    scanf("%f", & tempo);

    // Calculates the velocity
    float velocidade;
    velocidade = (espaco_percorrido - posicao_inicial) / tempo;

    printf("\n\nTHE VELOCITY (V) is: %.4f m/s\n", velocidade);
    printf("FORMULA: V = (S - S0) / t\n"); // Formula used to calculation

    // Observations to help the user interpret the account result
    if(tempo == 0 && posicao_inicial == espaco_percorrido){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0 and S=S0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(tempo == 0 && posicao_inicial != espaco_percorrido){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, and to exist velocity is necessary a time!=0\n");
    }
    else if(tempo < 0 && espaco_percorrido > posicao_inicial){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0 and S>S0, therefore, you are considering that the body is going to back\n");
    }
    else if(tempo > 0 && posicao_inicial > espaco_percorrido){
        printf("\nOBSERVATION:");
        printf("\nYou entered S0>S, therefore, the velocity is negative (the body is going back)\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void time(char *continue_){
    // Receives the starting position to the calculus
    float posicao_inicial;
    printf("\n\n\n\nInsert the STARTING POSITION (S0) in METERS of the body: ");
    scanf("%f", & posicao_inicial);

    // Receives the space travelled to the calculus
    float espaco_percorrido;
    printf("Insert the FINAL POSITION (S) in METERS of the body: ");
    scanf("%f", & espaco_percorrido);

    // Receives the velocity to the calculus
    float velocidade;
    printf("Insert the VELOCITY (V) in METERS PER SECOND of the body: ");
    scanf("%f", & velocidade);

    // Calculate the time
    float tempo;
    tempo = (posicao_inicial - espaco_percorrido) / velocidade;

    printf("\n\nTHE TIME (t) was: %.4f seconds\n", tempo);
    printf("FORMULA: t = (S0 - S) / V\n"); // Formula used to calculation

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

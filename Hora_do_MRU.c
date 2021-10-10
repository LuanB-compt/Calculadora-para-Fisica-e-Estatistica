#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void screen_usm(int x, bool limpar);
void screen_menu(int *num_choose);

void calc_final_position(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_);
void calc_starting_position(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_);
void calc_velocity(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_);
void calc_time(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_);

int main(void)
{
    float start_position, final_position, velocity, time; // Variables that gonna be used in the calculus
    char continue_usm; // Variable of each while, that is in all the switch cases
    int menu = -1; // Variable used on menu

    do{
        system("color 75");

        screen_usm(0, true);

        screen_menu(&menu);

        // Take the user to each different calculus
        switch(menu){
            case 1:
                do{
                    screen_usm(1, true);
                    calc_final_position(&continue_usm, &start_position, &final_position, &velocity, &time);
                }while(continue_usm == 121);
                break;

            case 2:
                do{
                    screen_usm(2, true);
                    calc_starting_position(&continue_usm, &start_position, &final_position, &velocity, &time);
                }while (continue_usm == 121);
                break;

            case 3:
                do{
                    screen_usm(3, true);
                    calc_velocity(&continue_usm, &start_position, &final_position, &velocity, &time);
                }while (continue_usm == 121);
                break;

            case 4:
                do{
                    screen_usm(4, true);
                    calc_time(&continue_usm, &start_position, &final_position, &velocity, &time);
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
    /*Show the options of variables that the program can calculate, and which the user can choose*/

    printf("\n\n\n\nIf you want to find the FINAL POSITION (S) by the body      -----> PRESS 1");
    printf("\nIf you want to find the STARTING POSITION (S0) by the body  -----> PRESS 2");
    printf("\nIf you want to find the VELOCITY (V) by the body            -----> PRESS 3");
    printf("\nIf you want to find the TIME (t) of movement                -----> PRESS 4");
    printf("\nIf you want to exit                                         -----> PRESS 0");
    printf("\n\nINSERT HERE: ");
    scanf("%d", num_choose);
}


void calc_final_position(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_){
    // Receives the starting position to the calculus
    printf("\n\n\n\nInsert the STARTING POSITION (S0) in METERS of the body: ");
    scanf("%f", start_position_);

    // Receives the velocity to the calculus
    printf("Insert the VELOCITY (V) in METERS PER SECOND of the body: ");
    scanf("%f", velocity_);

    // Receives the time to the calculus
    printf("Insert the TIME (t) in SECONDS that the movement lasted: ");
    scanf("%f", time_);

    // Calculates the space travelled
    *final_position_ = *start_position_ + ((*velocity_) * (*time_));

    printf("\n\nTHE FINAL POSITION (S) was: %.4f meters\n", *final_position_);
    printf("FORMULA: S = S0 + V * t\n"); // Formula used for calculation

    // Observations to help the user interpret the account result
    if(*time_ == 0 && *velocity_ == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*time_ < 0 && *velocity_ < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the movement happen before the t=0");
        printf("\nYou entered the velocity<0, therefore, the body is returning with respect to the zero position (S=0)\n");
    }
    else if(*velocity_ == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*time_ == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*velocity_ < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity<0, therefore, the body is returning with respect to the zero position (S=0)\n");
    }
    else if(*time_ < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the movement happen before the t=0\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void calc_starting_position(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_){
    // Receives the space travalled to the calculus
    printf("\n\n\n\nInsert the FINAL POSITION (S) in METERS of the body: ");
    scanf("%f", final_position_);

    // Receives the velocity to the calculus
    printf("Insert the VELOCITY (V) in METERS PER SECOND of the body: ");
    scanf("%f", velocity_);

    // Receives the time to the calculus
    printf("Insert the TIME (t) in SECONDS that the movement lasted: ");
    scanf("%f", time_);

    // Calculates the starting position
    *start_position_ = *final_position_ - ((*velocity_) * (*time_));

    printf("\n\nTHE STARTING POSITION (S0) is: %.4f meters\n", *start_position_);
    printf("FÓRMULA: S0 = S - V * t\n"); // Formula used to calculation

    // Observations to help the user interpret the account result
    if(*time_ == 0 && *velocity_ == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*time_ < 0 && *velocity_ < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the movement happen before the t=0");
        printf("\nYou entered the velocity<0, therefore, the body is going to foward\n");
    }
    else if(*velocity_ == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*time_ == 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*velocity_ < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the velocity<0, therefore, the body start in front and turn back\n");
    }
    else if(*time_ < 0){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0, therefore, you are considering that the body is going to back\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void calc_velocity(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_){
    // Receives the space travelled to the calculus
    printf("\n\n\n\nInsert the FINAL POSITION (S) in METERS of the body: ");
    scanf("%f", final_position_);

    // Receives the starting position to the calculus
    printf("Insert the STARTING POSITION (S0) in METERS of the body: ");
    scanf("%f", start_position_);

    // Receives the time to the calculus
    printf("Insert the TIME (t) in SECONDS that the movement lasted: ");
    scanf("%f", time_);

    // Calculates the velocity
    *velocity_ = ((*final_position_) - (*start_position_)) / *time_;

    printf("\n\nTHE VELOCITY (V) is: %.4f m/s\n", *velocity_);
    printf("FORMULA: V = (S - S0) / t\n"); // Formula used to calculation

    // Observations to help the user interpret the account result
    if(*time_ == 0 && *start_position_ == *final_position_){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0 and S=S0, therefore, don't exist movement and the body is in the same position\n");
    }
    else if(*time_ == 0 && *start_position_ != *final_position_){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time=0, and to exist velocity is necessary a time!=0\n");
    }
    else if(*time_ < 0 && *final_position_ > *start_position_){
        printf("\nOBSERVATION:");
        printf("\nYou entered the time<0 and S>S0, therefore, you are considering that the body is going to back\n");
    }
    else if(*time_ > 0 && *start_position_ > *final_position_){
        printf("\nOBSERVATION:");
        printf("\nYou entered S0>S, therefore, the velocity is negative (the body is going back)\n");
    }

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

void calc_time(char *continue_, float *start_position_, float *final_position_, float *velocity_, float *time_){
    // Receives the starting position to the calculus
    printf("\n\n\n\nInsert the STARTING POSITION (S0) in METERS of the body: ");
    scanf("%f", start_position_);

    // Receives the space travelled to the calculus
    printf("Insert the FINAL POSITION (S) in METERS of the body: ");
    scanf("%f", final_position_);

    // Receives the velocity to the calculus
    printf("Insert the VELOCITY (V) in METERS PER SECOND of the body: ");
    scanf("%f", velocity_);

    // Calculate the time
    *time_ = ((*final_position_) - (*start_position_)) / *velocity_;

    printf("\n\nTHE TIME (t) was: %.4f seconds\n", *time_);
    printf("FORMULA: t = (S0 - S) / V\n"); // Formula used to calculation

    // Finish or start the program again
    fflush(stdin);
    printf("\n\nDo you want do the calculus again?(y/n) ");
    scanf("%c", continue_);
}

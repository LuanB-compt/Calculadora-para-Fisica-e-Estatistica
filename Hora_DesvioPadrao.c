#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ARRAYLEN(ar) sizeof(ar)/sizeof(ar[0])

void titulo_desvio(x)
{
    system("cls");
    fflush(stdin);
    printf("96969696969696969696969696969696969696969696");
    printf("\n                DESVIO PADRÃO");
    printf("\n96969696969696969696969696969696969696969696");
    if(x == 1)
    {
        printf("\n                VARIÂNCIA");
    }
}

int main(void)
{
    setlocale(LC_ALL, "portuguese");
    titulo_desvio();
    do{
        int menu_desvio;
        printf("\n\n\nDeseja calcular o DESVIO PADRÃO ---> 1");
        printf("\nDeseja calcular a VARIÂNCIA ---> 2");
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
                        printf("Insira o %d° elemento: ", i+1);
                        scanf("%f", & base_dados[i]);
                    }

                    float desvio_padrao;
                    float variancia;

                    if(ARRAYLEN(base_dados) > 1)
                    {
                        variancia =

                        desvio_padrao = sqrt(variancia);
                    }

                }while(continua_desvio == 's');
                break;
            //case 2:
        }




    }while(1);
    system("pause");
    return 0;
}

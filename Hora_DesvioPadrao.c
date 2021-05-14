#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ARRAYLEN(ar) sizeof(ar)/sizeof(ar[0])

void titulo_desvio(x)
{
    system("cls");
    fflush(stdin);
    printf("9696969696969696969696969696969696969696969696969696969696969696");
    printf("\n                       DESVIO PADRÃO");
    printf("\n9696969696969696969696969696969696969696969696969696969696969696");
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
                    float variancia_quadrado;
                    float media;
                    float soma;
                    float divisao_variancia;
                    int n = 0;
                    if(ARRAYLEN(base_dados) > 1)
                    {
                        for(i = 0; i < numero_elementos - 1; i++)
                        {
                            soma += base_dados[i];//soma os elementos
                        }
                        soma += base_dados[i - 1];//soma último elemento

                        media = soma / numero_elementos;//média dos elementos

                        for(i = 0; i < numero_elementos; i++)
                        {
                            variancia = media - base_dados[i];//variancia
                        }
                        variancia_quadrado = pow(variancia, 2);//variancia ao quadrado

                        divisao_variancia = variancia_quadrado / numero_elementos;//variancia ao quadrado por "n"

                        desvio_padrao = sqrt(divisao_variancia);//raiz do resultado
                    }

                }while(continua_desvio == 's');
                break;
            //case 2:
        }




    }while(1);
    system("pause");
    return 0;
}

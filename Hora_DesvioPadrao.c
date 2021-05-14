#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ARRAYLEN(ar) sizeof(ar)/sizeof(ar[0])

void titulo_desvio(x)
{
    system("cls");
    fflush(stdin);
    printf("9696969696969696969696969696969696969969696969696969696969696");
    printf("\n                        DESVIO PADRÃO");
    printf("\n9696969696969696969696969696969696969969696969696969696969696");
    if(x == 1)
    {
        printf("\n                VARIÂNCIA");
    }
}

int main(void)
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

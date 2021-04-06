#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ARRAYLEN(ar) sizeof(ar)/sizeof(ar[0])


int main(void)
{
    do{
    setlocale(LC_ALL, "portuguese");
    system("color 06");

    //variavel que finaliza ou recome�a o cada case
    char continua;
    char continua_moda;
    char continua_mediana;

    system("cls");
    printf("------------------------------------------------------------------------------");
    printf("\n***                           M�DIA, MODA OU MEDIANA =)                    ***");
    printf("\n------------------------------------------------------------------------------");

    //alterna entre calculo de m�dia, moda ou mediana
    int menu = -1;
    printf("\n\n\nAperte 1 para calcular m�dia aritm�tica");
    printf("\nAperte 2 para calcular moda");
    printf("\nAperte 3 para calcular mediana");
    printf("\nAperte 0 para sair");
    printf("\nInsira sua escolha aqui: ");
    scanf("%d", & menu);

    fflush(stdin);


    //fun��o que atualiza a tela para a tela da m�dia
    void telaMedia(){
        system("cls");
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n                   M�DIA ARITM�TICA");
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n\n\n");
    }

    void telaMediana(){
        system("cls");
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n                          MEDIANA");
        printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
        printf("\n\n\n");
    }

    switch(menu)
    {
        case 1:
            do{
                //t�tulo
                telaMedia();    //atualiza a tela


                 //pede os dados do usu�rio
                int n;
                float soma = 0;

                printf("Quantos elementos? "); //pergunta com quantos elementos o usu�rio deseja fazer a m�dia
                scanf("%d", &n);

                float listinha[n];  //cria a lista baseada no valor de elementos do usu�rio

                printf("Digite os dados: \n");

                for (int i = 0; i < n; i++){        //for para coletar dado por dado e adiciona-lo em seu respectivo espa�o na lista
                  printf("Digite o %d�: ", i + 1);
                  scanf("%f", &listinha[i]);
                }

                telaMedia();                    //atualiza a tela
                printf("Os elementos s�o: ");

                for (int i = 0; i < n -1 ; i++){    //coloquei n-1 para n�o incluir o �ltimo elemento, pois eu quero que o �ltimo elemento seja diferente

                  printf("%.2f; ", listinha[i]);    //printa os termos da lista
                  soma += listinha[i];              //soma = soma + lista[indice]
                }
                soma += listinha[n-1];              //soma do �ltimo elemento
                printf("%.2f.\n", listinha[n-1]);   //formata��o do �ltimo elemento,
                // essas duas coisas foram necess�rias para que o �ltimo elemento fosse printado diferente

                //calcuka e mostra o tamanho da lista com os dados brutos
                int tamanho_lista = ARRAYLEN(listinha);
                printf("\nS�o %d elementos.\t\t A soma �: %.2f.\n\n", tamanho_lista, soma);


                //faz a m�dia aritmetica dos dados da lista
                float media_aritmetica;
                if(tamanho_lista > 0)
                {
                    media_aritmetica = (float)soma / tamanho_lista;
                }
                printf("\n- M�dia aritmetica = %.2f\n\n", media_aritmetica);

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("\n\n\nDeseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua);
            }while (continua == 115);
            break;
        case 2:
            do{
                //t�tulo
                system("cls");
                printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                printf("\n                          MODA");
                printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
                printf("\n\n\n");
                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("\n\n\nDeseja fazer uma nova m�dia?(s/n) ");
                scanf("%c", & continua_moda);
            }while(continua_moda == 115);

        case 3:
            do{
                //t�tulo
                telaMediana();




                int n;

                printf("Quantos elementos? "); //pergunta com quantos elementos o usu�rio deseja encontrar a mediana
                scanf("%d", &n);
                float listinha[n];
                printf("Digite os dados: \n");

                for (int i = 0; i < n; i++){        //for para coletar dado por dado e adiciona-lo em seu respectivo espa�o na lista
                  printf("Digite o %d�: ", i + 1);
                  scanf("%f", &listinha[i]);
                }
                for (int i = 0; i < n; i++){            //esse aninhado de for testa n�mero por n�mero para saber a ordem entre eles... n�o me perguntem ao certo como funciona, ainda n�o entendi tbm KKKK
                    for (int j = i + 1; j < n; j++){    //se quiserem pesquisar, o nome disso � "selection sort"
                        if (listinha[i] > listinha[j]){
                            float a = listinha[i];
                            listinha[i] = listinha[j];
                            listinha[j] = a;
                        }
                    }
                }
                printf("\nO Rol dos n�meros em ordem crescente �: \n");   //printa a nova lista com os n�meros substitu�dos para a ordem correta
                for (int i = 0; i < n; ++i)
                    printf("|%.2f|   ", listinha[i]);

                float mediana = 0.0;
                int tamanho_lista = ARRAYLEN(listinha);

                if (tamanho_lista % 2 == 0){
                    int a = tamanho_lista/2;
                    mediana = (listinha[a]+listinha[a - 1])/2;
                }
                else {
                    int a = tamanho_lista/2;
                    mediana = listinha[a];
                }

                printf("\n\nA mediana dos dados �: %.4f", mediana);

                //termina ou come�a novamente o programa
                fflush(stdin);
                printf("\n\n\nDeseja fazer uma nova m�dia?(s/n) ");
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

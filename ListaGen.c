#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"

char menu()
{
    system("cls");
    printf("## MENU ##\n");
    printf("[1] Inserir\n");
    printf("[2] Remover\n");
    printf("[3] Imprimir Lista\n");
    printf("[4] Destruir Lista\n");
    printf("[ESC] SAIR\n");
    printf("OPCAO: ");
    
    return getchar();
}

int main()
{
    char op, aux[8];
    ListaGen *L = NULL; 

    do {
        op = menu();
        system("cls");
        switch (op) {
            case '1':
                printf("Insira na lista: ");
                fflush(stdin);
                gets(aux);
                if (L == NULL) {
                    L = CriaT(aux);
                } else {
                    printf("Lista ja existe. Nao e possivel criar outra.\n");
                }
                fflush(stdin);
                getchar();
                break;

            case '2':
               
                break;

            case '3':
                printf("Conteudo da lista:\n");
                exibeConteudo(L);
                fflush(stdin);
                getchar();
                break;

            case '4':
                if (L != NULL) {
                    destroiLista(&L); 
                    printf("Lista destruida.\n");
                } else {
                    printf("Nao ha lista para destruir.\n");
                }
                fflush(stdin);
                getchar();
                break;
        }
    } while (op != 27);

  
    if (L != NULL) {
        destroiLista(&L);
    }

    return 0;
}

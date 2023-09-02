#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include "tad.h"

char menu()
{
    system("cls");
    printf("## MENU ##\n");
    printf("[1] Inserir\n");
    printf("[2] Remover\n");
    printf("[3] Imprimir Lista\n");
    printf("[4] Destruir Lista\n");
    printf("[5] Duplicar Lista\n");
    printf("[ESC] SAIR\n");
    printf("OPCAO: ");
    
    return getche();
}

int main()
{
    char op;
    ListaGen *L = NULL, *L2 = NULL; 

    do {
        op = menu();
        system("cls");
        switch (op) {
            case '1':
                printf("Insira na lista");
                if (L == NULL) {
                    L = Cons(CriaT("a"),Cons(Cons(CriaT("b"),Cons(Cons(CriaT("c"),NULL),NULL)),NULL));
                } else {
                    printf("Lista ja existe. Nao e possivel criar outra.\n");
                }       
                break;

            case '2':
               
                break;

            case '3':
                printf("Conteudo da lista:\n");
                exibeConteudo(L);
                printf("\n");
                exibe(L);
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
            case '5':
                if (L != NULL) {
                     L2 = duplicarListaGen(L);
                    printf("Lista duplioada.\n");
                    exibe(L2);
                } else {
                    printf("Nao ha lista para duplicar.\n");
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

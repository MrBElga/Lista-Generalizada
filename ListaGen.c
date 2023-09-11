#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include "tad.h"

char menu2()
{
    system("cls");
    printf("## MENU ##\n");
    printf("[1] [a,[b,[c]]]\n");
    printf("[2] [[a,[f,[c]]]\n");
    printf("[3] [a,[]]\n");
    printf("[4] [[a,b],c]\n");
    printf("[5] [[a],C]\n");
    printf("OPCAO: ");

    return getche();
}

char menu()
{
    system("cls");
    printf("## MENU ##\n");
    printf("[1] Inserir Lista 1\n");
    printf("[2] Inserir Lista 2\n");
    printf("[3] Imprimir Lista\n");
    printf("[4] Destruir Lista\n");
    printf("[5] Duplicar Lista\n");
    printf("[6] Compara Lista\n");
    printf("[7] Nivel da Lista\n");
    printf("[8] Concatenar Lista\n");
    printf("[ESC] SAIR\n");
    printf("OPCAO: ");

    return getche();
}

int main()
{
    int maior=0;
    char op, op2,op3;
    ListaGen *L = NULL, *L2 = NULL, *aux = NULL;
    //

    do
    {
        op = menu();
        system("cls");
        switch (op)
        {
        case '1':
         
            if (L == NULL)
            {
                op2 = menu2();
                switch (op2)
                {
                case '1':
                    L = Cons(CriaT("a"), Cons(Cons(CriaT("b"), Cons(Cons(CriaT("c"), NULL), NULL)), NULL));
                    break;

                case '2':
                    L = Cons(CriaT("a"), Cons(Cons(CriaT("f"), Cons(Cons(CriaT("c"), NULL), NULL)), NULL));
                    break;

                case '3':
                    L = Cons(CriaT("a"), Cons(NULL,NULL));
                    break;
                case '4':
                    L = Cons(Cons(CriaT("a"), Cons(CriaT("b"), NULL)), Cons(CriaT("c"), NULL));
                    break;
                case '5':
                    L = Cons(Cons(CriaT("a"),NULL), Cons(CriaT("c"), NULL));
                    break;
                }
            }
            else
            {
                printf("Lista ja existe. Destrua para criar outra.\n");
            }
            break;

        case '2':
      
            if (L2 == NULL)
            {
                op2 = menu2();
                switch (op2)
                {
                case '1':
                    L2 = Cons(CriaT("a"), Cons(Cons(CriaT("b"), Cons(Cons(CriaT("c"), NULL), NULL)), NULL));
                    break;

                case '2':
                    L2 = Cons(CriaT("a"), Cons(Cons(CriaT("f"), Cons(Cons(CriaT("c"), NULL), NULL)), NULL));
                    break;

                case '3':
                    L2 =  Cons(CriaT("a"), Cons(NULL,NULL));
                    break;
                case '4':
                    L2 = Cons(Cons(CriaT("a"), Cons(CriaT("b"), NULL)), Cons(CriaT("c"), NULL));
                    break;
                case '5':
                    L = Cons(Cons(CriaT("a"),NULL), Cons(CriaT("c"), NULL));
                    break;
                }
            }
            else
            {
                printf("Lista ja existe. Destrua para criar outra.\n");
            }
            break;

        case '3':
            printf("Conteudo da lista 1:\n");
            exibeConteudo(L);
            printf("\n");
            exibe(L);
            
            printf("\n");
            printf("Conteudo da lista 2:\n");
            exibeConteudo(L2);
            printf("\n");
            exibe(L2);
            fflush(stdin);
            getchar();
            break;

        case '4':
            if (L != NULL)
            {
                destroiLista(&L);
                printf("Lista destruida.\n");
            }
            else
            {
                printf("Nao ha lista para destruir.\n");
            }
            printf("Deseja destruir a Lista 2? [S/n]\n");
            op2 = getche();
            if ('S' == toupper(op2))
            {
                if (L2 != NULL)
                {
                    destroiLista(&L2);
                    printf("\nLista destruida.\n");
                }
                else
                {
                    printf("Nao ha lista para destruir.\n");
                }
            }
            fflush(stdin);
            getchar();
            break;
        case '5':
            if (L != NULL && L2 == NULL)
            {
                L2 = duplicarListaGen(L);
                printf("Lista duplioada.\n");
                exibe(L2);
            }
            else if(L2 != NULL)
            {
            	exibe(L2);
            	printf("\nA Lista 2 esta ocupada deseja destrui-la [S/n]");
            	op3=getchar();
            	if(toupper(op3) == 'S'){
            		destroiLista(&L2);
            		L2 = duplicarListaGen(L);
                	printf("Lista duplioada.\n");
                	exibe(L2);
            	}
										
            }
            else
            {
                printf("Nao ha lista para duplicar.\n");
            }
            fflush(stdin);
            getchar();
            break;
        case '6':
            if (L != NULL && L2 != NULL)
            {
                if (comparaListaGen(L, L2))
                    printf("Listas Iguais.\n");
                else
                    printf("Listas Diferentes.\n");
                printf("Lista 1: ");
                exibe(L);
                printf("\nLista 2: ");
                exibe(L2);
            }
            else
            {
                printf("Nao ha lista para comparar.\n");
            }
            fflush(stdin);
            getchar();
            break;
        case '7':
            if(L != NULL)
            {
                 maior=0;
                 deph(L,1,&maior);
                 printf("Lista: ");
                 exibe(L);
                 printf("\nniveis: %d\n",maior);
            }
            else
            {
                printf("Lista L vazia\n");
            }

            if(L2 != NULL)
            {
                 maior=0;
                 deph(L2,1,&maior);
                 printf("Lista: ");
                 exibe(L2);
                 printf("\nniveis: %d\n",maior);
            }
            else
            {
                printf("Lista L2 vazia\n");
            }
            getchar();
            break;
        case '8':
            if(L != NULL && L2 != NULL)
            {
                exibe(L);
                aux = L;
                while (!Nula(Tail(aux)))
                    aux = Tail(aux);
                aux->no.lista.cauda = L2;
                printf(" + ");
                exibe(L2);
                printf(" = ");
                exibe(L);
                printf("\n## Lista concatenada ##\n");
            }
            else
            {
                if(L == NULL)
                {
                    printf("Lista 1 nao pode ser nula\n");
                }
                else
                {
                    printf("Lista 2 nao pode ser nula\n");
                }
            }
            getchar();
            break;
        }
    } while (op != 27);

    if (L != NULL)
    {
        destroiLista(&L);
    }

    return 0;
}

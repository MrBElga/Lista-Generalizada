#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tad.h"

char menu()
{
	system("cls");
	printf("## MENU ##");
	printf("\n [1] Inserir");
	printf("\n [2] Remover");
	printf("\n [3] printar Lista");
	printf("\n [4] Destruir");
	printf("\n [ESC] SAIR");
	printf("\n OPCAO: ");
	
	return getche();
}

int main()
{
    char op, aux,aux2;
  	ListaGen *L;

    do{
        op = menu();
        system("cls");
        switch(op){
            case '1':
                printf("insira na lista: ");
				scanf("%c",&aux);
	        	L = CriarT(aux);

            break;           
            case '2':
                exibe(L);
            break;
            case '3':

            break;
            case '4':

            break;
        }
    }while(op != 27);




    return 0;
}

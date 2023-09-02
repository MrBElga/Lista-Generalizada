#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


struct reg_lista
{
	struct listagen *cabeca;
	struct listagen *cauda;
};
union info_lista
{
	char info[8]; //se for 1
	struct reg_lista lista;//se for 0
};
struct listagen
{
	char terminal;
	union info_lista no;
};
typedef struct listagen ListaGen;

ListaGen* CriaT(char *info)
{
	ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
	L->terminal = 1;
	strcpy((L->no.info), info);
	return L;
}

char Nula(ListaGen* L)
{
	return L==NULL;
}

char Atomo(ListaGen *L)
{
	return !Nula(L) && L->terminal;
}


void exibeConteudo(ListaGen *L)
{
    if(!Nula(L))
    {
        if(Atomo(L))
        {
            printf("%s", L->no.info);
        }
        else
        {
            exibeConteudo(Head(L));
            exibeConteudo(Tail(L));
        }
    }
}

void destroiLista(ListaGen **L)
{
    if(!Nula(*L))
    {
        if(Atomo(*L))
        {
            free(*L);
        }
        else
        {
            destroiLista(&(*L) -> no.lista.cabeca);
            destroiLista(&(*L) -> no.lista.cauda);
            free(*L);
            *L = NULL;
        }
    }
}

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

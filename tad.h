
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


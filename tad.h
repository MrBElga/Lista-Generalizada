struct Fila{
    int info;
    struct Fila *prox;
};
typedef struct Fila fila;

struct reg_lista
{
    struct listagen *cabeca;
    struct listagen *cauda;
};
union info_lista
{
    char info[8];           // se for 1
    struct reg_lista lista; // se for 0
};
struct listagen
{
    char terminal;
    union info_lista no;
};
typedef struct listagen ListaGen;

ListaGen *CriaT(char info[])
{
    ListaGen *L = (ListaGen *)malloc(sizeof(ListaGen));
    L->terminal = 1;
    strcpy((L->no.info), info);
    return L;
}

char Nula(ListaGen *L)
{
    return L == NULL;
}

char Atomo(ListaGen *L)
{
    return !Nula(L) && L->terminal;
}

ListaGen *Cons(ListaGen *H, ListaGen *T)
{
    if (Atomo(T))
    {
        printf("Cons: Segundo arqumento nao pode ser Atomo!");
        return NULL;
    }
    else
    {
        ListaGen *L = (ListaGen *)malloc(sizeof(ListaGen));
        L->terminal = 0;
        L->no.lista.cabeca = H;
        L->no.lista.cauda = T;
        return L;
    }
}

ListaGen *Head(ListaGen *L)
{
    if (Nula(L) || Atomo(L))
    {
        printf("Head: argumento deve ser lista não vazia!");
        return NULL;
    }
    else
        return L->no.lista.cabeca;
}

ListaGen *Tail(ListaGen *L)
{
    if (Nula(L) || Atomo(L))
    {
        printf("Tail: argumento deve ser lista não vazia!");
        return NULL;
    }
    else
        return L->no.lista.cauda;
}

void exibeConteudo(ListaGen *L)
{
    if (!Nula(L))
    {
        if (Atomo(L))
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

void exibe(ListaGen *L)
{
    if (Atomo(L))
        printf("%s", L->no.info);
    else
    {
        printf("[");
        while (!Nula(L))
        {
            exibe(Head(L));
            L = Tail(L);
            if (!Nula(L))
                printf(",");
        }
        printf("]");
    }
}

void destroiLista(ListaGen **L)
{
    if (!Nula(*L))
    {
        if (Atomo(*L))
        {
            free(*L);
        }
        else
        {
            destroiLista(&(*L)->no.lista.cabeca);
            destroiLista(&(*L)->no.lista.cauda);
            free(*L);
            *L = NULL;
        }
    }
}

ListaGen *duplicarListaGen(ListaGen *L)
{
    if(Nula(L))
        return NULL;
    if(Atomo(L))
        return CriaT(L->no.info);
    return Cons(duplicarListaGen(Head(L)),duplicarListaGen(Tail(L)));
}

char comparaListaGen(ListaGen *L, ListaGen *L2)
{
    if(Nula(L) && Nula(L2))
         return 1;
    if(Nula(L) || Nula(L2))
         return 0;
    if(Atomo(L) && Atomo(L2))
         return !strcmp(L->no.info, L2->no.info);  //1
    if(Atomo(L) || Atomo(L2))
         return 0; //0
    return comparaListaGen(Head(L), Head(L2)) && comparaListaGen(Tail(L), Tail(L2));
}


void init(fila **inicio){
        *inicio = NULL;
}

char QisEmpety(fila *inicio){
	return inicio == NULL;
}

void Enqueue(fila **inicio, int info){
    fila *nova = (fila*) malloc(sizeof(fila)), *aux = *inicio;
    nova->info = info;
    nova->prox = NULL;
    if(!QisEmpety(*inicio)){
       while(aux->prox !=NULL)
        {
            aux = aux -> prox;
        }
        aux->prox = nova;
    }
    else
    {
    	 *inicio = nova;
        
    }
}

void Dequeue(fila **inicio, int *info ){
    fila *aux = *inicio;
    if(!QisEmpety(*inicio)){      
		*info = (*inicio)->info;
		*inicio = (*inicio)->prox;
		free(aux);	
	}
	else{
		*info = -1;
	}
}
 
int top(fila *inicio){
    return inicio->info;    
}

void exibe(fila *inicio){
    system("cls");
    if(inicio == NULL){
    	printf("FILA: vazia");
	}
	else{
		printf("FILA: ");
	    while(inicio != NULL){
	        printf("%d ", inicio->info);
	        inicio=inicio->prox;
	    }
	}
	printf("\n");
}

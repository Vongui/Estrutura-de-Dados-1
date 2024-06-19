#include <stdio.h>
#include <stdlib.h>

typedef struct sLista
{
    int info;
    struct sLista *esq, *dir;
} Lista;


void inicializar(Lista **l){
    *l = NULL;
}

Lista* getnode(){
    return (Lista *) malloc(sizeof(Lista));
}

void freenode(Lista *l){
    free(l);
}

int vazia(Lista *l){
    if (l == NULL)
    {
        return 1;
    }
    return 0;
    
}

void inserir_inicio(Lista **l, int elem){
    Lista *q;
    q = getnode();
    if (q != NULL)
    {
        q->info = elem;
        q->esq = NULL;
        q->dir = NULL;
        if (!vazia(*l))
        {
            (*l)->esq = q;
            q->dir = *l;
        }
        *l = q;
    }
    else
    {
        printf("\nErro");
    }
}

void inserir_fim(Lista **l, int elem){
    Lista *q, *aux;
    q = getnode();
    if (q != NULL)
    {
        q->info = elem;
        q->esq = NULL;
        q->dir = NULL;

        if (vazia(*l))
        {
            *l = q;
        }
        else
        {
            aux = *l;
            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }
            q->esq = aux;
            aux->dir = q;
        }
    }
    else
    {
        printf("\nErro");
    }
}

void remover_inicio(Lista **l){
    Lista *q;

    if (!vazia(*l))
    {
        q = *l;
        *l = (*l)->dir;
        if (!(*l == NULL))
        {
            (*l)->esq = NULL;
        }
        freenode(q);
    }
    else
    {
        printf("\nLista vazia");
    }
}

void remover_fim(Lista **l){
    Lista *q, *aux;

    if (!vazia(*l))
    {
        if ((*l)->dir == NULL)
        {
            *l = NULL;
        }
        else
        {
            aux = *l;
            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }
            q = aux;
            (aux->esq)->dir = NULL;
        }
        freenode(q);
    }
    else
    {
        printf("\nLista vazia");
    }
}

void exibir(Lista *l){
    if (!vazia(l))
    {
        while (l != NULL)
        {
            printf("[%d] ", l->info);
            l = l->dir;
        }
    }
    else
    {
        printf("\nLista vazia");
    }
}

int pesquisa(Lista *l, int elem){
    int retorno;

    if (!vazia(l))
    {
        while (l != NULL)
        {
            if (l->info == elem)
            {
                retorno = l->info;
                return retorno;
            }
            l = l->dir;
        }
        return NULL;
    }
    else
    {
        printf("\nLista vazia");
    }
}

int ler_elemento(){
    int elem;
    printf("\nDigite o valor: ");
    scanf("%d", &elem);
    return elem;
}

int Menu()
{
    int op;
    printf("\n------------Menu-------------");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 - Inserir valor no Inicio da Lista");
    printf("\n2 - Inserir valor no Fim da Lista");
    printf("\n3 - Remover valor do Inicio da Lista");
    printf("\n4 - Remover valor do Fim da Lista");
    printf("\n5 - Apresentar a Lista");
    printf("\n6 - Buscar ");
    printf("\n0 - Encerrar\n");

    do
    {
        printf("Escolha: ");
        scanf("%d", &op);
    } while (op < 0 || op > 6);
    return op;
}

void main(){
    int escolha, retorno;
    Lista *lista;
    inicializar(&lista);

    do
    {
        escolha = Menu();
        switch (escolha)
        {
        case 0:
            printf("\nSaindoo......");
            break;
        case 1:
            inserir_inicio(&lista, ler_elemento());
            break;
        case 2:
            inserir_fim(&lista, ler_elemento());
            break;
        case 3:
            remover_inicio(&lista);
            break;
        case 4:
            remover_fim(&lista);
            break;
        case 5:
            exibir(lista);
            break;
        case 6:
            retorno = pesquisa(lista, ler_elemento());
            if (retorno != NULL)
            {
                printf("Valor encontrado: [%d]", retorno);
            }
            else
            {
                printf("\nValor nao encontrado!");
            }
            break;
        default:
            printf("\nEscolha uma opcao valida!!");
            break;
        }
    } while (escolha != 0);
    
}
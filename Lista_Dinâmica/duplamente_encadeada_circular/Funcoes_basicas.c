#include <stdio.h>
#include <stdlib.h>

typedef struct sLista
{
    int info;
    struct sLista *next;
    struct sLista *back;
} Lista;

void inicializar(Lista **l){
    *l = NULL;
}

Lista* getnode(){
    return (Lista *) malloc(sizeof(Lista));
}

int vazia(Lista *l){
    if (l == NULL)
    {
        return 1;
    }
    return 0;
}

void freenode(Lista *l){
    free(l);
}

void inserir_inicio(Lista **l, int elem){
    Lista *q;
    q = getnode();
    if (q != NULL)
    {
        q->info = elem;
        if (vazia(*l))
        {
            q->next = q;
            q->back = q;
        }
        else
        {
            q->next = *l;
            q->back = (*l)->back;
            (*l)->back->next = q;
            (*l)->back = q;
        }
        *l = q;
    }
    else
    {
        printf("\nErro");
    }
}

void inserir_final(Lista **l, int elem){
    Lista *q;
    q = getnode();
    if (q != NULL)
    {
        q->info = elem;
        if (vazia(*l))
        {
            q->next = q;
            q->back = q;
            *l = q;
        }
        else
        {
            q->next = *l;
            q->back = (*l)->back;
            (*l)->back->next = q;
            (*l)->back = q;
        }
    }
    else
    {
        printf("\nErro");
    }  
}

void remover_inicio(Lista **l){
    Lista *q;
    q = *l;

    if (!vazia(*l))
    {
        if ((*l)->next == *l)
        {
            freenode(q);
            *l = NULL;
        }
        else
        {
            (*l)->back->next = (*l)->next;
            (*l)->next->back = (*l)->back;
            (*l) = (*l)->next;
            freenode(q);
        }
    }
    else
    {
        printf("\nLista vazia");
    }
}

void remover_fim(Lista **l){
    Lista *q;

    q = *l;
    if (!vazia(*l))
    {
        if ((*l)->next == *l)
        {
            freenode(q);
            *l = NULL;
        }
        else
        {
            q = (*l)->back;
            (*l)->back->back->next = *l;
            (*l)->back = (*l)->back->back;
            freenode(q);
        }  
    }
    else
    {
        printf("\nLista vazia");
    }
}

Lista* pesquisa(Lista *l, int elem){
    Lista *aux;
    aux = l;

    if (!vazia(l))
    {
        do
        {
            if (aux->info == elem)
            {
                return aux;
            }
            aux = aux->next;
        } while (aux != l);
    }
    return NULL;
}

void remover_valor(Lista **l, int elem){
    Lista *aux, *aux2;

    aux2 = *l;
    aux = pesquisa(*l, elem);
    if (aux != NULL)
    {
        if (aux == *l)
        {
            remover_inicio(l);
        }
        else{
            while (aux2 != aux)
            {
                aux2 = aux2->next;
            }
            aux2->back->next = aux2->next;
            aux2->next->back = aux2->back;
            freenode(aux);
        }
    }
    else
    {
        printf("\nElemento nao existe na lista\n");
    }
}

void exibir(Lista *l){
    Lista *aux;

    if (vazia(l))
    {
        printf("\nLista vazia");
    }
    else
    {
        aux = l;
        do
        {
            printf("[%d] ", aux->info);
            aux = aux->next;
        } while (aux != l);
            
    } 
}

int ler_elemento(){
    int elem;
    printf("\nDigite o valor: ");
    scanf("%d", &elem);
    return elem;
}

int menu(){
    int escolha;

    printf("\n====  Menu  ====");
    printf("\n0 - Sair");
    printf("\n1 - Inserir inicio");
    printf("\n2 - Inserir fim");
    printf("\n3 - Remover inicio");
    printf("\n4 - Remover fim");
    printf("\n5 - Remover valor");
    printf("\n6 - Exibir");
    printf("\nDigite a sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int main(){
    int escolha;
    Lista *l;
    inicializar(&l);

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("\nSaindooo......");
            break;
        case 1:
            inserir_inicio(&l, ler_elemento());
            break;
        case 2:
            inserir_final(&l, ler_elemento());
            break;
        case 3:
            remover_inicio(&l);
            break;
        case 4:
            remover_fim(&l);
            break;
        case 5:
            remover_valor(&l, ler_elemento());
            break;
        case 6:
            exibir(l);
            break;
        default:
            break;
        }
    } while (escolha != 0);
    
}

#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
    int info; 
    struct cell *next;
} Lista;


Lista* getnode(){
    return (Lista*) malloc(sizeof(Lista));

}

void freenode(Lista *q){
    free(q);
}

void inicializa(Lista **lista){
    *lista = NULL;
}

int empty(Lista *lista){
    if (lista == NULL) {
        return 1;
    }
    return 0;
}

void exibe_lista(Lista **lista){
    Lista *aux;

    aux = *lista;
    if (empty(lista))
    {
        printf("\nErro - lista vazia");
    }
    
    while (aux != NULL) {
        printf("[%d] ", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

void insere_inicio(Lista **lista, int x) {
  Lista *q;

  q = getnode();
  if (q != NULL) {
        q->info = x;
        q->next = lista;
        *lista = q;
    
  } else {
        printf("\nErro");
  }
}

void insere_fim(Lista **lista, int x)
{
    Lista *q;
    Lista *aux;

    q = getnode();
    if (q != NULL)
    {
        q->info = x;
        q->next = NULL;

        if (empty(lista))
        {
            *lista = q;
        }
        else
        {
            aux = *lista;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = q;
        }
    }

    else
    {
        printf("\nErro na alocação");
    }
}

void insere_posicao(Lista **lista, int x, int pos) {
    Lista *q;
    Lista *aux;
    Lista *ant;
    int i = 1;

    q = getnode();
    if (q != NULL) {
        q->info = x;
        if (pos == 1) {
            q->next = *lista;
            *lista = q;
        }
        else {
            aux = *lista;
            while (aux != NULL && i < pos) {
                ant = aux;
                aux = aux->next;
                i++;
            }
            if (aux != NULL) {
                q->next = aux;
                ant->next = q;
            }
            else {
                printf("Posicao invalida...");
            }
        }
    }
}

void remove_inicio(Lista **lista){
    Lista *q;

    q = *lista;
    if (!empty(lista)) {
        *lista = q->next;
        freenode(q);
    }
    else {
        printf("\nErro - lista vazia");
    }
}

void remover_fim(Lista **L) {
    Lista *aux;
    aux = *L;

    if(empty(L)) {
        printf("Erro! - Lista vazia");
    }

    if(empty(aux->next)) {
        freenode(aux);
        *L = NULL;
    } else {
        while(!empty(aux->next->next)) {
            aux = aux->next;
        }
        freenode(aux->next);
        aux->next = NULL;
    }
}

Lista* pesquisa(Lista *lista, int x){
    Lista *q;

    if (!empty(lista)) {
        q = lista;
        while (q != NULL) {
            if (q->info == x) {
                return q;
            }
            q = q->next;
        }
    }
    return NULL;
}

void remove_valor(Lista **lista, int x){
    Lista *q;
    Lista *aux;

    if ((q = pesquisa(lista, x)) != NULL) {
        aux = *lista;
        if (aux == q) {
            remove_inicio(lista);
        }
        else {
            while (aux->next != q) {
                aux = aux->next;
            }
            aux->next = q->next;
            freenode(q);
        }
    } 
}

int ler_inteiro(){
    int valor;

    printf("\nDigite o valor: ");
    scanf("%d", &valor);

    return valor;
}

int ler_posicao(){
    int valor;

    printf("\nDigite a posicao: ");
    scanf("%d", &valor);

    return valor;
}

int menu(){
    int escolha;

    printf("\n========MENU========");
    printf("\n0 - Sair");
    printf("\n1 - Inserir no início");
    printf("\n2 - Inserir no fim");
    printf("\n3 - Inserir na posição X");
    printf("\n4 - Remover início");
    printf("\n5 - Remover fim");
    printf("\n6 - Remover elemento X");
    printf("\n7 - Pesquisar elemento X");
    printf("\n8 - Exibir lista");
    printf("\nEscolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void main(){
    Lista *lista;
    Lista *retorno;
    int escolha;

    inicializa(&lista);

    do {
        escolha = menu();

        switch (escolha) {
        case 0:
            printf("Saindo...");
            break;
        case 1:
            insere_inicio(&lista, ler_inteiro());
            break;
        case 2:
            insere_fim(&lista, ler_inteiro());
            break;
        case 3:
            insere_posicao(&lista, ler_inteiro(), ler_posicao());
            break;
        case 4:
            remove_inicio(&lista);
            break;
        case 5:
            remover_fim(&lista);
            break;
        case 6:
            remove_valor(&lista, ler_inteiro());
            break;
        // case 7:
        //     retorno = inicializa(retorno);
        //     retorno = pesquisa(lista, ler_inteiro());
        //     if(retorno != NULL){
        //         printf("\nValor encontrado: %d\n", retorno->info);
        //     }
        //     else
        //     {
        //         printf("\nValor não está na lista");
        //     }
            
        //     break;
        case 8:
            exibe_lista(&lista);
            break;
        default:
            printf("\nOpcao invalida!!!");
            break;
        }
        
    }while (escolha != 0);


}
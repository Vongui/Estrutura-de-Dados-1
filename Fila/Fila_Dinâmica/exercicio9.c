#include <stdio.h>
#include <stdlib.h>

typedef struct sFila {
    int info;
    struct sFila *next;
}fila;

void inicializar(fila **inicio, fila **fim) {
    *inicio = NULL;
    *fim = NULL;
}

fila* getnode()  {
    return (fila*) malloc (sizeof(fila));
}

void freenode(fila *F) {
    free(F);
}

int vazia(fila *F) {
    if(F == NULL)
        return 1;
    return 0;
}

void enfileirar(fila **inicio, fila **fim, int elem) {
    fila *f;

    f = getnode();
    if(f != NULL) {
        f->info = elem;
        f->next = NULL;
        if(vazia(*inicio)) {
            *inicio = f;
            *fim = f;
        } else {
            (*fim)->next = f;
            *fim = f; // *fim = (*fim)->next;
        }
    } else {
        printf("Erro na alocacao do no\n");
    }
}

int desenfileirar(fila **inicio, fila **fim) {
    int elem;
    fila *q = *inicio;

    if(vazia(*inicio)) {
        printf("Erro! - Fila vazia\n");
    } else {
        elem = (*inicio)->info;

        if(*inicio == *fim) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            *inicio = (*inicio)->next;
        }
        freenode(q);
        return elem;
    }
}

void exibir_fila(fila **inicio, fila **fim) {
    if(vazia(*inicio)) {
        printf("Erro! - Fila vazia\n");
        return;
    }
    while(!vazia(*inicio)) {
        printf("[%d] ", desenfileirar(inicio, fim));
    }
}

void exibir_filaA(fila *inicio, fila *fim){

    if(vazia(inicio)) {
        printf("Erro! - Fila vazia\n");
        return;
    }
    while(!vazia(inicio)) {
        printf("[%c] ", desenfileirar(&inicio, &fim));
    }
}

int ler_elemento(){
    int elem;
    printf("\nDigite o elemento: ");
    scanf("%d", &elem);

    return elem;
}

int menu(){
    int escolha;

    printf("\nMenu de opcoes");
    printf("\n0 - Sair");
    printf("\n1 - Inserir elemento");
    printf("\n2 - Remover elemento");
    printf("\n3 - Exibir elementos");
    printf("\nEscolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void main(){
    fila *inicio, *fim;

    inicializar(&inicio, &fim);
    int escolha;
    do{
        escolha = menu();
        switch(escolha){
        case 0:
            printf("\nSaindo.....");
            break;
        case 1:
            enfileirar(&inicio, &fim, ler_elemento());
            break;
        case 2:
            desenfileirar(&inicio, &fim);
            break;
        case 3:
            exibir_fila(&inicio, &fim);
            break;
        default:
            printf("\nDigite uma opção válida!!!");
            break;
        }
    }while(escolha != 0);
}

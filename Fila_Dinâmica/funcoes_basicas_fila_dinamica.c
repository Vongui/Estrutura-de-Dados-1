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
    }
    while(!vazia(*inicio)) {
        printf("[%d] ", desenfileirar(inicio, fim));
    }
}


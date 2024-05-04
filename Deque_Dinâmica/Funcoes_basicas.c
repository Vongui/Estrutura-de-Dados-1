#include <stdio.h>
#include <stdlib.h>

typedef struct sDeque {
    int info;
    struct sDeque *next;
    struct sDeque *back;
}deque;

void inicializar(deque **inicio, deque **fim) {
    *inicio = NULL;
    *fim = NULL;
}

deque* getnode() {
    return (deque*) malloc (sizeof(deque));
}

void freenode(deque *D) {
    free(D);
}

int vazia(deque *d) {
    if(d == NULL)
        return 1;
    return 0;
}

void inserir_inicio(deque **inicio, deque **fim, int elem) {
    deque *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->back = NULL;
        if(vazia(*inicio)) {
            q->next = NULL;
            *fim = q;
        } else {
            (*inicio)->back = q;
            q->next = *inicio;
        }
        *inicio = q;
    } else {
        printf("Erro na alocacao de no\n");
    }
}

void inserir_fim(deque **inicio, deque **fim, int elem) {
    deque *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        q->next = NULL;

        if(vazia(*inicio)) {
            q->back = NULL;
            *inicio = q;
            *fim = q;
        } else {
            (*fim)->next = q;
            q->back = *fim;
            *fim = q;
        }
    } else {
        printf("Erro na alocao do no");
    }
}

int remover_inicio(deque **inicio, deque **fim) {
    int elem;
    deque *q;

    if(vazia(*inicio)) {
        printf("Erro! - Deque vazio");
    } else {
        elem = (*inicio)->info;
        q = *inicio;

        if(*inicio == *fim) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            *inicio = (*inicio)->next;
            (*inicio)->back = NULL;
        }
        free(q);
        return elem;
    }
}

int remover_fim(deque **inicio, deque **fim) {
    int elem;
    deque *q;

    if(vazia(*inicio)) {
        printf("Erro! - Deque vazio");
    } else {
        elem = (*fim)->info;
        q = *fim;

        if(*inicio == *fim) {
            *inicio = NULL;
            *fim = NULL;
        } else {
            *fim = (*fim)->back;
            (*fim)->next = NULL;
        }
        free(q);
        return elem;
    }
}

void exibir_deque(deque **inicio, deque **fim) {
    if(vazia(*inicio)) {
        printf("Erro! - Deque vazio");
        return;
    }

    do{
        printf("[%d] ", remover_inicio(inicio, fim));
    }while(!vazia(*inicio));
}

void main() {
    deque *inicio;
    deque *fim;

    inicializar(&inicio, &fim);

    inserir_inicio(&inicio, &fim, 1);
    inserir_inicio(&inicio, &fim, 2);
    inserir_inicio(&inicio, &fim, 3);
    inserir_inicio(&inicio, &fim, 4);
    inserir_fim(&inicio, &fim, 5);
    inserir_fim(&inicio, &fim, 6);
    inserir_fim(&inicio, &fim, 7);

    remover_inicio(&inicio, &fim);
    remover_fim(&inicio, &fim);

    exibir_deque(&inicio, &fim);
}
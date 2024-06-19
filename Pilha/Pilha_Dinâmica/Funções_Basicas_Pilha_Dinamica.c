#include <stdlib.h>
#include <stdio.h>

typedef struct sPilha{
    int info;
    struct sPilha *next;
} Pilha;

void inicializar(Pilha **topo){
    *topo = NULL;
}

Pilha* getnode(){
    return (Pilha*) malloc(sizeof(Pilha));
}

void freenode(Pilha *topo){
    free(topo);
}

int vazia(Pilha *topo){
    if (topo == NULL) {
        return 1;
    }
    return 0;
}

void empilhar(Pilha **topo, int elem){
    Pilha *p;

    p = getnode();
    if (p != NULL) {
        p->info = elem;
        p->next = *topo;
        *topo = p;
    }
    else {
        printf("Erro - alocação de no\n");
    }
}

int desempilhar(Pilha **topo){
    Pilha *p;
    int elem;

    if (vazia(*topo)) {
        printf("\nPilha vazia");
    }
    else {
        *topo = (*topo)->next;
        elem = p->info;
        freenode(p);
        return elem;
    }
}

void exibir(Pilha **topo){
    if (vazia(*topo)) {
        printf("\nPilha vazia!!");
        return;
    }
    while (!vazia(*topo)) {
        printf(" %d", desempilhar(topo));
    }
}

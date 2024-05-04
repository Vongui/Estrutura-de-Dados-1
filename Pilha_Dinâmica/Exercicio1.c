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

        if (vazia(*topo))
        {
            p->next = NULL;
        }
        else
        {
            p->next = *topo;   
        }
        *topo = p;
    }
    else {
        printf("Erro - alocação de no\n");
    }
}

int desempilhar(Pilha **topo){
    Pilha *p;
    int elem;

    p = *topo;

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
        printf(" [%d]", desempilhar(topo));
    }
}

int stacktop(Pilha *topo){
    int elemento;

    if (vazia(topo))
    {
        printf("\nPilha vazia");
        return NULL;
    }
    else
    {
        elemento = topo->info;
        return elemento;
    }
}

int ler_elem(){
    int elem;
    printf("\nDigite o elemento: ");
    scanf("%d", &elem);
    return elem;
}

int menu(){
    int escolha;

    printf("\n0 - Sair");
    printf("\n1 - Inserir elemento");
    printf("\n2 - Remover Elemento");
    printf("\n3 - Exibir elementos");
    printf("\n4 - Stacktop");
    printf("\nEscolha: ");
    scanf("%d", &escolha);

    return escolha;
}

void main(){
    Pilha *topo;
    inicializar(&topo);
    int escolha, x;

    do {
    escolha = menu();
    switch (escolha) {
    case 0: 
        printf("\nSaindo.....");
        break;
    case 1:
        x = ler_elem();
        empilhar(&topo, x);
        break;
    case 2:
        desempilhar(&topo);
        break;
    case 3:
        exibir(&topo);
        break;
    case 4:
        printf("\nElemento do topo: %d", stacktop(topo));
        break;
    default:
        printf("\nEscolha um opcao valida!!");
        break;
    }

    }while (escolha != 0);

}
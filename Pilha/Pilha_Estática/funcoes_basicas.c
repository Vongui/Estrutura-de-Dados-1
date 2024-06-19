#include <stdio.h>

#define TAM 5

typedef struct sPilha
{
    int info[TAM];
    int topo;
} Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

int vazia(Pilha *p){
    if (p->topo == -1)
    {
        return 1;
    }
    return 0;
}

int cheia(Pilha *p){
    if (p->topo == TAM - 1)
    {
        return 1;
    }
    return 0;
}

void push(Pilha *p, int elem){
    if (cheia(p))
    {
        printf("Erro - Pilha cheia");
        return;
    }
    else
    {
        p->info[p->topo+1] = elem;
        p->topo++;   
    }
}

int pop(Pilha *p){
    int aux;

    if (vazia(p))
    {
        printf("Erro - pilha vazia");
        return -1;
    }
    else
    {
        aux = p->info[p->topo];
        p->topo--;
        return aux;
    }
}

int stacktop(Pilha *p){
    if (vazia(p))
    {
        printf("Erro - pilha vazia");
        return -1;
    }
    return p->info[p->topo];
}

void exibir(Pilha *p){
    if (vazia(p))
    {
        printf("Erro - pilha vazia");
    }
    while (!vazia(p))
    {
        printf("[%d] ", pop(p));
    }
}

int ler_elemento(){
    int elem;
    printf("Digite o elemento: ");
    scanf("%d", &elem);
    return elem;
}

int menu(){
    int escolha;

    printf("\nMenu");
    printf("\n0 - Sair");
    printf("\n1 - Inserir");
    printf("\n2 - Retirar");
    printf("\n3 - Stackpop");
    printf("\n4 - Exibir");

    printf("\nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

void main(){
    Pilha p;

    int retorno, escolha;
    inicializar(&p);
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("Saindooo....");
            break;
        case 1:
            push(&p, ler_elemento());
            break;
        case 2:
            retorno = pop(&p);
            if (retorno != -1)
            {
                printf("Elemento retirado com sucesso, %d", retorno);
            }
            else
            {
                printf("Elemento nao retirado");
            }
            break;
        case 3: 
            retorno = stacktop(&p);
            printf("Elemento topo da pilha: %d", retorno);
            break;
        case 4:
            exibir(&p);
            break;
        default:
            printf("Opcao invalida!!!");
            break;
        }
    } while (escolha != 0);
    
}
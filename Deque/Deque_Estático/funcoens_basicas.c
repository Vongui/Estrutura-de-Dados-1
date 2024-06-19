#include <stdio.h>

#define TAM 5

typedef struct sDeque
{
    int info[TAM];
    int inicio, fim;
} Deque;

void inicializar(Deque *d){
    d->inicio = TAM - 1;
    d->fim = TAM - 1;
}

int vazia(Deque *d){
    if (d->inicio == d->fim)
    {
        return 1;
    }
    return 0;
}

int cheia(Deque *D){
    if (D->inicio == D->fim)
    {
        return 1;
    }
    return 0;
}

void inserir_inicio(Deque *d, int elem){
    if (d->inicio == 0)
    {
        d->inicio = TAM - 1;
    }
    else
    {
        d->inicio--;
    }
    if (cheia(d))
    {
        printf("\nErro - Deque está cheio");
        d->inicio = (d->inicio+1) % TAM;
        return;
    }
    d->info[(d->inicio+1) % TAM] = elem;
}

void inserir_fim(Deque *d, int elem){
    if (d->fim == TAM - 1)
    {
        d->fim = 0;
    }
    else
    {
        d->fim++;
    }
    if (cheia(d))
    {
        printf("\nErro - Deque esta cheio");
        d->fim--;
        if (d->fim == -1)
        {
            d->fim = TAM - 1;
        }
        return;
    } 
    d->info[d->fim] = elem;
}

int remover_fim(Deque *d){
    int elem;

    if (vazia(d))
    {
        printf("\nErro - Deque esta vazio");
        return -1;
    }
    elem = d->info[d->fim];
    d->fim--;
    if (d->fim == -1)
    {
        d->fim = TAM - 1;
    }
    return elem;   
}

int remover_inicio(Deque *d){
    int elem;

    if (vazia(d))
    {
        printf("\nErro - Deque esta vazio");
        return -1;
    }
    d->inicio++;
    if (d->inicio == TAM)
    {
        d->inicio = 0;
    }
    elem = d->info[d->inicio];
    return elem;
}

void exibir(Deque *d){
    if (vazia(d))
    {
        printf("\nErro - Deque esta vazio");
        return;
    }
    while (!vazia(d))
    {
        printf("[%d] ", remover_inicio(d));
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

    printf("\n-----Menu-----");
    printf("\n0 - Sair");
    printf("\n1 - Inserir inicio");
    printf("\n2 - Inserir Fim");
    printf("\n3 - Remover inicio");
    printf("\n4 - Remover fim");
    printf("\n5 - Exibir");

    printf("\nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

void main(){
    Deque d;
    int escolha;

    inicializar(&d);
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("\nSaindo.....");
            break;
        case 1:
            inserir_inicio(&d, ler_elemento());
            break;
        case 2:
            inserir_fim(&d, ler_elemento());
            break;
        case 3:
            remover_inicio(&d);
            break;
        case 4: 
            remover_fim(&d);
            break;
        case 5:
            exibir(&d);
            break;
        default:
            printf("\nOpcao invalida!!!");
            break;
        }
    } while (escolha != 0);
    
}
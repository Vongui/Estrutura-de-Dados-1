#include <stdio.h>

#define TAM 5

typedef struct sFila
{
    int info[TAM];
    int inicio, fim;
} Fila;

void inicializar(Fila *f){
    f->inicio = TAM - 1;
    f->fim = TAM - 1;
}

int vazia(Fila *f){
    if (f->inicio == f->fim)
    {
        return 1;
    }
    return 0;
}

void enfileirar(Fila *f, int elem){
    if (f->fim == TAM - 1)
    {
        f->fim = 0;
    }
    else
    {
        f->fim++;
    }
    if (vazia(f))
    {
        printf("Erro - Fila cheia");
        f->fim--;
        if (f->fim == -1)
        {
            f->fim = TAM - 1;
        }
        return;
    }
    f->info[f->fim] = elem;
}

int desenfileirar(Fila *f){
    int elem;

    if (!vazia(f))
    {
        if (f->inicio == TAM - 1)
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
        elem = f->info[f->inicio];
    }
    else
    {
        printf("\nErro - Fila vazia");
    }
    return elem;
}

void exibir(Fila *f){
    if (vazia(f))
    {
        printf("\nErro - Fila vazia");
        return;
    }
    while (!vazia(f))
    {
        printf("[%d] ", desenfileirar(f));
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

    printf("\n0 - Sair");
    printf("\n1 - Enfileirar");
    printf("\n2 - Desenfileirar");
    printf("\n3 - Exibir");

    printf("\nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

void main(){
    Fila f;
    int escolha, retorno;

    inicializar(&f);

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("\nSaindooo....");
            break;
        case 1:
            enfileirar(&f, ler_elemento());
            break;
        case 2:
            retorno = desenfileirar(&f);
            printf("\nSaiu da fila: %d", retorno);
            break;
        case 3:
            exibir(&f);
            break;
        default:
            printf("\nOpcao invalida!!");
            break;
        }
    } while (escolha != 0);
    
}
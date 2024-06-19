#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct sLista
{
    int info[TAM];
    int n;
}Lista;

void inicializar(Lista *l){
    l->n = -1;
}

int vazia(Lista *l){
    if (l->n == -1)
    {
        return 1;
    }
    return 0;
}

int cheia(Lista *l){
    if (l->n == TAM - 1)
    {
        return 1;
    }
    return 0;
}

void inserir_fim(Lista *l, int elem){
    if (cheia(l))
    {
        printf("Erro - Lista Cheia");
        return;
    }

    l->info[l->n+1] = elem;
    l->n++;
}

void inserir_inicio(Lista *l, int elem){
    int i;

    if (cheia(l))
    {
        printf("Erro - lista cheia");
        return;
    }

    for ( i = l->n; i >= 0; i--)
    {
        l->info[i+1] = l->info[i];
    }
    l->info[0] = elem;
    l->n++;
}

void inserir_posicao(Lista *l, int elem, int pos){
    if (cheia(l))
    {
        printf("Erro - lista cheia");
        return;
    }
    if (pos < 0 || pos >= l->n)
    {
        printf("Erro - posicao fora dos limites");
        return;
    }
    
    for (int i = l->n; i >= pos; i--)
    {
        l->info[i+1] = l->info[i];
    }
    l->info[pos] = elem;
    l->n++;
}

void alterar(Lista *l, int elem, int pos){
    if (vazia(l))
    {
        printf("Erro - lista vazia");
        return;
    }
    if (pos < 0 || pos >= l->n)
    {
        printf("Erro - posicao fora dos limites");
        return;
    }
    l->info[pos] = elem;
}

int remover_inicio(Lista *l){
    int elem;
    if (vazia(l))
    {
        printf("Erro - lista vazia");
        return -1;
    }
    elem = l->info[0];
    
    for (int i = 0; i <= l->n; i++)
    {
        l->info[i] = l->info[i+1];
    }
    l->n--;
    return elem;
}

int remover_fim(Lista *l){
    int elem;
    if (vazia(l))
    {
        printf("Erro - lista vazia");
        return -1;
    }
    elem = l->info[l->n];
    l->n--;
    return elem;
}

int remover_posicao(Lista *l, int pos){
    int elem;

    if (vazia(l))
    {
        printf("Erro - lista vazia");
        return -1;
    }
    if (pos < 0 || pos >= l->n)
    {
        printf("Erro - posicao fora dos limites");
        return -1;
    }
    else
    {
        elem = l->info[pos];
        for (int i = pos; i <+ l->n; i++)
        {
            l->info[i] = l->info[i+1];
        }
        l->n--;
        
    }
    return elem;
}

void exibir(Lista *l){
    if (vazia(l))
    {
        printf("Erro - lista vazia");
        return;
    }
    for (int i = 0; i <= l->n; i++)
    {
        printf("[%d] ", l->info[i]);
    }
}

int pesquisar(Lista *l, int elem){
    int achou = -1;

    if (vazia(l))
    {
        printf("Erro - lista vazia");
        return -1;
    }
    for (int i = 0; i <= l->n; i++)
    {
        if (l->info[i] = elem)
        {
            achou = l->info[i];
            i = l->n+1;
        }
        
    }
    
    return achou;
}

int pesquisar_posicao(Lista *l, int posicao) {
    if(posicao < 0 || posicao >= l->n) {
        printf("\nErro! - Elemento fora dos limites");
    } else {
        return l->info[posicao];
    }
    return -1;
}

int ler_elemento(){
    int elem;
    printf("\nDigite o elemento: ");
    scanf("%d", &elem);
    return elem;
}

int ler_posica(){
    int elem;
    printf("\nDigite a posicao: ");
    scanf("%d", &elem);
    return elem;
}

int menu(){
    int opcao;

    printf("\nMENU\n");
    printf("1 - Inserir no inicio\n");
    printf("2 - Inserir no fim\n");
    printf("3 - Inserir em uma posição específica\n");
    printf("4 - Remover no início\n");
    printf("5 - Remover no fim\n");
    printf("6 - Remover em uma posição específica\n");
    printf("7 - Modificar um elemento\n");
    printf("8 - Pesquisar Elmento\n");
    printf("9 - Exibir a lista\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    return opcao;
}

void main(){
    Lista l;

    int retorno, escolha;
    
    inicializar(&l);
    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 1:
            inserir_inicio(&l, ler_elemento());
            break;
        case 2:
            inserir_fim(&l, ler_elemento());
            break;
        case 3:
            inserir_posicao(&l, ler_elemento(), ler_posica());
            break;
        case 4: 
            retorno = remover_inicio(&l);
            if (retorno != -1)
            {
                printf("Elemento retirado %d, com sucesso", retorno);
            }
            else
            {
                printf("Elemento nao retirado");
            }
            break;
        case 5: 
            retorno = remover_fim(&l);
            if (retorno != -1)
            {
                printf("Elemento retirado %d, com sucesso", retorno);
            }
            else{
                printf("Elemento nao retirado");
            }
            break;
        case 6: 
            retorno = remover_posicao(&l, ler_posica());
            if (retorno != -1)
            {
                printf("Elemento retirado %d, com sucesso", retorno);
            }
            else{
                printf("Elemento nao retirado");
            }
            break;
        case 7: 
            alterar(&l, ler_elemento(), ler_posica());
            break;
        case 8:
            retorno = pesquisar(&l, ler_elemento());
            if (retorno != -1)
            {
                printf("Elemento encontrado %d, com sucesso", retorno);
            }
            else
                printf("Elemento nao encontrado");
            break;
        case 9: 
            exibir(&l);
            break;
        default:
            printf("Opcao invalida!!!");
            break;
        }
    } while (escolha != 0);
    
}
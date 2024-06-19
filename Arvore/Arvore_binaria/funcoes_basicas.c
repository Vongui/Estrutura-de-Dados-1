#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *esq;
    struct no *dir;
} NO;

NO *getnode(){
    return (NO *) malloc(sizeof(NO));
}

void inicializa(NO **raiz){
    *raiz = NULL;
}

void liberarNO(NO *raiz){
    if (raiz != NULL)
    {
        liberarNO(raiz->esq);
        liberarNO(raiz->dir);
        free(raiz);
    }
}

int vazia(NO *raiz){
    if (raiz == NULL)
    {
        return 1;
    }
    return 0;
    
}

void percorrerPreOrdem(NO* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->info);
        percorrerPreOrdem(raiz->esq);
        percorrerPreOrdem(raiz->dir);
    }
}

void percorrerEmOrdem(NO* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esq);
        printf("%d ", raiz->info);
        percorrerEmOrdem(raiz->dir);
    }
}

void percorrerPosOrdem(NO* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esq);
        percorrerPosOrdem(raiz->dir);
        printf("%d ", raiz->info);
    }
}

void inserir(NO **raiz, int elem){
    if (vazia(*raiz))
    {
        NO* q = getnode();
        if (q != NULL)
        {
            printf("a");
            q->info = elem;
            q->esq = NULL;
            q->dir = NULL;
            *raiz = q;
        }
    }
    else
    {
        if (elem < (*raiz)->info)
        {
            inserir(&(*raiz)->esq, elem);
        }
        else
        {
            inserir(&(*raiz)->dir, elem);
        }
    }
}

int quantidadeNo(NO *raiz)
{
    if (vazia(raiz))
    {
        return 0;
    }
    else
    {
        return 1 + quantidadeNo(raiz->esq) + quantidadeNo(raiz->dir);
    }
}

int quantidadeFolhas(NO *raiz)
{
    if (vazia(raiz))
    {
        return 0;
    }
    else if (raiz->esq == NULL && raiz->dir == NULL)
       return 1;
    else
        return quantidadeFolhas(raiz->esq) + quantidadeFolhas(raiz->dir);
}

int alturaArvore(NO *raiz)
{
    if (vazia(raiz))
    {
        return -1;
    }
    else
    {
        int esquerda = alturaArvore(raiz->esq);
        int direita = alturaArvore(raiz->dir);
        if (esquerda > direita)
            return esquerda + 1;
        else
            return direita + 1;
    }
}

NO *pesquisa(NO *raiz, int elem){
    NO* aux = raiz;
    if (aux == NULL) {
        return NULL;
    } else if (aux->info > elem) {
        return pesquisa(aux->esq, elem);
    } else if (aux->info < elem) {
        return pesquisa(aux->dir, elem);
    } else {
        return aux;
    }
}

// void percursoEmOrdem(struct no* raiz) {
//     struct pilha* pilha = NULL;
//     struct no* atual = raiz;

//     while (atual != NULL || !estaVazia(pilha)) {
//         while (atual != NULL) {
//             empilhar(&pilha, atual);
//             atual = atual->esq;
//         }
//         atual = desempilhar(&pilha);
//         printf("%d ", atual->info);
//         atual = atual->dir;
//     }
// }

// void percursoPreOrdem(struct no* raiz) {
//     if (raiz == NULL)
//         return;

//     struct pilha* pilha = NULL;
//     empilhar(&pilha, raiz);

//     while (!estaVazia(pilha)) {
//         struct no* no = desempilhar(&pilha);
//         printf("%d ", no->info);

//         if (no->dir)
//             empilhar(&pilha, no->dir);
//         if (no->esq)
//             empilhar(&pilha, no->esq);
//     }
// }

// void percursoPosOrdem(struct no* raiz) {
//     if (raiz == NULL)
//         return;

//     struct pilha* pilha = NULL;
//     struct pilha* saida = NULL;
//     empilhar(&pilha, raiz);

//     while (!estaVazia(pilha)) {
//         struct no* no = desempilhar(&pilha);
//         empilhar(&saida, no);

//         if (no->esq)
//             empilhar(&pilha, no->esq);
//         if (no->dir)
//             empilhar(&pilha, no->dir);
//     }

//     while (!estaVazia(saida)) {
//         printf("%d ", desempilhar(&saida)->info);
//     }
// }

int ler_elemento(){
    int elem;
    printf("Digite o valor: \n");
    scanf("%d", &elem);
    return elem;
}

int menu(){
    int escolha;
    
    printf("\n====== Menu =====\n");
    printf("0 - Sair\n");
    printf("1 - Inserir\n");
    printf("2 - Exibir em Ordem\n");
    printf("3 - Exibir em Pre Ordem\n");
    printf("4 - Exibir em Pos Ordem\n");
    printf("5 - Calcular Altura Arvore\n");
    printf("6 - Calcular Nos da Arvore\n");
    printf("7 - Calcular Folhas da Arvore\n");
    printf("8 - pesquisa\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

int main(){
    int retorno, escolha;
    NO *raiz, *aux;
    inicializa(&raiz);

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("\nSaindoooooo....");
            break;
        case 1:
            inserir(&raiz, ler_elemento());
            break;
        case 2:
            percorrerEmOrdem(raiz);
            break;
        case 3:
            percorrerPreOrdem(raiz);
            break;
        case 4:
            percorrerPosOrdem(raiz);
            break;
        case 5: 
            retorno = alturaArvore(raiz);
            printf("\nAltura da arvore: %d", retorno);
            break;
        case 6:
            retorno = quantidadeNo(raiz);
            printf("\nQuantidade de no: %d", retorno);
            break;
        case 7:
            retorno = quantidadeFolhas(raiz);
            printf("\nQuantidade de Folhas: %d", retorno);
            break;
        case 8:
            aux = pesquisa(raiz, ler_elemento());
            printf("Item pesquisado: %d", aux->info);
            break;
        default:
            printf("\nDigite uma opcao valida!!!");
            break;
        }
    } while (escolha != 0);
    
}
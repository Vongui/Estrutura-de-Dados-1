#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct Arvore {
    No* raiz;
} Arvore;

No* pesquisa(No* raiz, int elemento) {
    No* aux = raiz;
    if (aux == NULL) {
        return NULL;
    } else if (aux->dado > elemento) {
        return pesquisa(aux->esquerda, elemento);
    } else if (aux->dado < elemento) {
        return pesquisa(aux->direita, elemento);
    } else {
        return aux;
    }
}

void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

No* getnode() {
    return (No*)malloc(sizeof(No));
}

No* criarNo(int valor) {
    No* novoNo = getnode();
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return NULL;
    }
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        percorrerEmOrdem(raiz->direita);
    }
}

int menu()
{
    int opcao;
    printf("\n\t\tMenu\n");
    printf("\t[1] Inserir na Arvore\n");
    printf("\t[2] Pesquisar na Arvore\n");
    printf("\t[3] Percorrer em ordem\n");
    printf("\t[0] Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    Arvore arvore;
    inicializarArvore(&arvore);
    int opcao, elemento;

    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                arvore.raiz = inserir(arvore.raiz, elemento);
                printf("Elemento inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o elemento a ser pesquisado: ");
                scanf("%d", &elemento);
                if (pesquisa(arvore.raiz, elemento) != NULL) {
                    printf("Elemento encontrado na Arvore.\n");
                } else {
                    printf("Elemento não encontrado na Arvore.\n");
                }
                break;
            case 3:
                percorrerEmOrdem(arvore.raiz);
                break;
            case 0:
                printf("Programa encerrado");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarArvore(arvore.raiz);

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------
					CODIGO SURPRESA DA PROVA DELE
int percorrer_caracter(int elemento)
{
	if(elemento < 10)
			{
		return elemento
	}else{
		return elemento %10 + -----(o operador denpende do exercicio que ele quer) percorrer_caracter(elemento /10);
}
} 

-----------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esquerda;
    struct No *direita;
} No;

typedef struct Arvore {
    No* raiz;
} Arvore;

No* pesquisa(No* raiz, int elemento) {
    No* aux = raiz;
    if (aux == NULL) {
        return NULL;
    } else if (aux->dado > elemento) {
        return pesquisa(aux->esquerda, elemento);
    } else if (aux->dado < elemento) {
        return pesquisa(aux->direita, elemento);
    } else {
        return aux;
    }
}

void inicializarArvore(Arvore* arvore) {
    arvore->raiz = NULL;
}

No* getnode() {
    return (No*)malloc(sizeof(No));
}

No* criarNo(int valor) {
    No* novoNo = getnode();
    if (novoNo == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return NULL;
    }
    novoNo->dado = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void percorrerPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        percorrerPreOrdem(raiz->esquerda);
        percorrerPreOrdem(raiz->direita);
    }
}

void percorrerEmOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        percorrerEmOrdem(raiz->direita);
    }
}

void percorrerPosOrdem(No* raiz) {
    if (raiz != NULL) {
        percorrerPosOrdem(raiz->esquerda);
        percorrerPosOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

int contarNos(No* raiz) {
    if (raiz == NULL)
        return 0;
    else
        return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(No* raiz) {
    if (raiz == NULL)
        return 0;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calcularAltura(No* raiz) {
    if (raiz == NULL)
        return -1;
    else
        return 1 + max(calcularAltura(raiz->esquerda), calcularAltura(raiz->direita));
}

int menu()
{
    int opcao;
    printf("\n\t\tMenu\n");
    printf("\t[1] Inserir na Arvore\n");
    printf("\t[2] Pesquisar na Arvore\n");
    printf("\t[3] Percorrer em pré-ordem\n");
    printf("\t[4] Percorrer em ordem\n");
    printf("\t[5] Percorrer em pós-ordem\n");
    printf("\t[6] Calcular número de nós\n");
    printf("\t[7] Calcular número de folhas\n");
    printf("\t[8] Calcular altura da árvore\n");
    printf("\t[0] Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    Arvore arvore;
    inicializarArvore(&arvore);
    int opcao, elemento;

    do {
        opcao = menu();

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elemento);
                arvore.raiz = inserir(arvore.raiz, elemento);
                printf("Elemento inserido com sucesso!\n");
                break;
            case 2:
                printf("Digite o elemento a ser pesquisado: ");
                scanf("%d", &elemento);
                if (pesquisa(arvore.raiz, elemento) != NULL) {
                    printf("Elemento encontrado na Arvore.\n");
                } else {
                    printf("Elemento não encontrado na Arvore.\n");
                }
                break;
            case 3:
                printf("Percorrendo em pré-ordem: ");
                percorrerPreOrdem(arvore.raiz);
                printf("\n");
                break;
            case 4:
                printf("Percorrendo em ordem: ");
                percorrerEmOrdem(arvore.raiz);
                printf("\n");
                break;
            case 5:
                printf("Percorrendo em pós-ordem: ");
                percorrerPosOrdem(arvore.raiz);
                printf("\n");
                break;
            case 6:
                printf("Número de nós: %d\n", contarNos(arvore.raiz));
                break;
            case 7:
                printf("Número de folhas: %d\n", contarFolhas(arvore.raiz));
                break;
            case 8:
                printf("Altura da árvore: %d\n", calcularAltura(arvore.raiz));
                break;
            case 0:
                printf("Programa encerrado");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    liberarArvore(arvore.raiz);

    return 0;
}

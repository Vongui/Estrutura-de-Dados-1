#include <stdio.h>
#include <stdlib.h>

typedef struct sLista {
    int info;
    struct sLista *next;
}lista;

void inicializar(lista **L) {
    *L = NULL;
}

lista* getnode() {
    return (lista*) malloc (sizeof(lista));
}

void freenode(lista *L) {
    free(L);
}

int vazia(lista *L) {
    if(L == NULL)
        return 1;
    return 0;
}

// // void inserir_inicio(lista **L, int elem) {
//     lista *q;
//     lista *aux = *L;

//     q = getnode();
//     if(q != NULL) {
//         q->info = elem;

//         if(vazia(*L)) {
//             q->next = q;
//             *L = q;
//         } else {
//             while(aux->next != *L) {
//                 aux = aux->next;
//             }
//             q->next = *L;
//             aux->next = q;
//             *L = q;
//         }
//     } else {
//         printf("\nErro ao alocar o no");
//     }
// }

void inserir_inicio(lista **L, int elem){
    lista *q;

    q = getnode();
    if (q != NULL)
    {
        q->info = elem;
        q->next = *L;
        *L = q;
    }
    else
    {
        printf("\nErro na alocação do no!!");
    }
}

void inserir_fim(lista **L, int elem) {
    lista *q;

    q = getnode();
    if(q != NULL) {
        q->info = elem;
        
        if(vazia(*L)) {
            q->next = q;
        } else {
            q->next = (*L)->next;
            (*L)->next = q;
        }
        *L = q;
    } else {
        printf("\nErro ao alocar o no");
    }
}

void remover_inicio(lista **L) {
    lista *q;
    
    q = *L;
    if (!vazia(*L)) 
    {
        *L = q->next;
        freenode(q);
    }
    else
    {
        printf("\nLista vazia!!!");
    }
}

void remover_fim(lista **L) {
    lista *q;

    if(vazia(*L)) {
        printf("Erro! - Lista vazia");
    }

    if((*L)->next == NULL) {
        freenode(*L);
        *L = NULL;
    } else {
        q = *L;
        while(q->next->next != NULL) {
            q = q->next;
        }
        freenode(q->next);
        q->next = NULL;
    }
}

void exibir(lista *l)
{
    lista *exibir;

    if (l != NULL)
    {
        exibir = l->next;
        do
        {
            printf("[%d] ", exibir->info);
            exibir = exibir->next;
        } while (exibir != l->next);
    }
    else
    {
        printf("Erro, lista Vazia.\n");
    }
}

int pesquisar(lista **L, int elem){
    lista *q;
    q = *L;
    int retorno = NULL;

    if (vazia(q))
    {
        printf("\nLista vazia!!!");
    }
    else
    {
        while (q != NULL)
        {
            if (q->info == elem)
            {
                retorno = q->info;
            }
            q = q->next;
        }
    }
    return retorno;
}

int ler_elemento(){
    int elem;

    printf("\nDigite o numero: ");
    scanf("%d", &elem);
    return elem;
}

int menu(){
    int escolha;

    printf("\n\n0 - Sair");
    printf("\n1 - Inserir inicio");
    printf("\n2 - Inserir Fim");
    printf("\n3 - Remover Inicio");
    printf("\n4 - Remover Fim");
    printf("\n5 - Exibir Lista");
    printf("\n6 - Pesquisar");

    printf("\nDigite a opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

void main() {
    lista *L;
    int escolha, retorno;

    inicializar(&L);

    do
    {
        escolha = menu();
        switch (escolha)
        {
        case 0:
            printf("\nSaindooo......");
            break;
        case 1:
            inserir_inicio(&L, ler_elemento());
            break;
        case 2:
            inserir_fim(&L, ler_elemento());
            break;
        case 3:
            remover_inicio(&L);
            break;
        case 4:
            remover_fim(&L);
            break;
        case 5:
            exibir_lista(L);
            break;
        case 6:
            retorno = pesquisar(&L, ler_elemento());
            if (retorno != NULL)
            {
                printf("\nValor encontrado: %d", retorno);
            }
            else
            {
                printf("\nValor nao encontrado");
            }
            break;
        default:
            printf("\nOpacao invalida!!");
            break;
        }
    } while (escolha != 0);
    
}

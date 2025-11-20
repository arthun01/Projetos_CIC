#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
    int info;
    struct TNo* dir;
    struct TNo* esq;
} ArvBin;

// inserir elemeneto na árvore recursivamente
ArvBin* insere(ArvBin* raiz, int valor){
    // árvore vacia, o novo nó será a raiz
    if(raiz == NULL){
        ArvBin* folha = (ArvBin*)malloc(sizeof(ArvBin));
        if(folha == NULL) return NULL;

        folha->info = valor;
        folha->dir = NULL;
        folha->esq = NULL;

        return folha;
    }

    if(valor > raiz->info){
        raiz->dir = insere(raiz->dir, valor);
    }else{
        raiz->esq = insere(raiz->esq, valor);
    }

    return raiz;
}

// imprime elementos in-order
void imprimeInOrder(ArvBin* raiz){
    if(raiz == NULL) return;

    imprimeInOrder(raiz->esq);
    printf("%d ", raiz->info);
    imprimeInOrder(raiz->dir);
}

// imprime elementos pos-order
void imprimePosOrder(ArvBin* raiz){
    if(raiz == NULL) return;
    imprimePosOrder(raiz->esq);
    imprimePosOrder(raiz->dir);
    printf("%d ", raiz->info);
}

int main(void){
    ArvBin* minha_arvore = NULL;

    minha_arvore = insere(minha_arvore, 50);
    minha_arvore = insere(minha_arvore, 15);
    minha_arvore = insere(minha_arvore, 25);
    minha_arvore = insere(minha_arvore, 75);
    minha_arvore = insere(minha_arvore, 30);
    minha_arvore = insere(minha_arvore, 100);

    printf("In-Order\n");
    imprimeInOrder(minha_arvore);
    printf("\n----------------------\n");

    printf("Pós-Order\n");
    imprimePosOrder(minha_arvore);
    printf("\n");

    return 0;
}
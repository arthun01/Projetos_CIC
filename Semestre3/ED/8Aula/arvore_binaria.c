#include <stdio.h>
#include <stdlib.h>

typedef struct TNo{
    int info;
    struct TNo* dir;
    struct TNo* esq;
} ArvBin;

ArvBin* insere(ArvBin* arvore, int valor){
    ArvBin* novo = (ArvBin*)malloc(sizeof(ArvBin));
    if(novo == NULL){
        printf("Erro na alocação\n");
        return NULL;
    }

    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    // árvore vazia, o novo nó será a raiz
    if(arvore == NULL){
        return novo;
    }

    // se não for vazia, a mágica acontece
    ArvBin* aux = arvore;
    ArvBin* pai = NULL;

    // loop que encontra posição correta
    while(aux != NULL){
        pai = aux;

        if(aux->info < valor){
            aux = aux->dir;
        }else{
            aux = aux->esq;
        }
    }

    // insere novo nó no filho esq ou dir
    if(pai->info < valor){
        pai->dir = novo;
    }else{
        pai->esq = novo;
    }

    return arvore;
}

void imprimeInOrder(ArvBin* arvore){
    if(arvore == NULL) return;

    ArvBin* pilha[100];
    int topo = -1;
    ArvBin* aux = arvore;

    while(aux != NULL || topo != -1){
        while(aux != NULL){
            pilha[++topo] = aux;
            aux = aux->esq;
        }

        aux = pilha[topo--];
        printf("%d ", aux->info);

        aux = aux->dir;
    }
    printf("\n");
}

int main(void){
    ArvBin* minha_arvore = NULL;

    minha_arvore = insere(minha_arvore, 50);
    minha_arvore = insere(minha_arvore, 25);
    minha_arvore = insere(minha_arvore, 75);
    minha_arvore = insere(minha_arvore, 65);
    minha_arvore = insere(minha_arvore, 15);
    minha_arvore = insere(minha_arvore, 30);
    minha_arvore = insere(minha_arvore, 100);

    imprimeInOrder(minha_arvore);

    return 0;
}
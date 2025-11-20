// Implementação de uma PILHA
// ou seja, inserção no inicio, retirada no inicio
// push (inserção) e pop (retirada)
#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int numero;
    struct pilha* proximo;
} Pilha;

Pilha* inicializacao(){
    return NULL;
}

int push(Pilha** pilha, int num){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if(novo == NULL) return 0;

    novo->numero = num;
    novo->proximo = *pilha;
    *pilha = novo;

    return 1;
}

int pop(Pilha** pilha){
    if(*pilha == NULL){
        return 0;
    }

    Pilha* novo = *pilha;
    *pilha = (*pilha)->proximo;

    free(novo);
    return 1;
}

void topo(Pilha** pilha){
    if(*pilha == NULL){
        printf("Pilha Vazia\n");
    }
    printf("Topo: %d\n", (*pilha)->numero);
}

void imprimir(Pilha* pilha){
    while(pilha != NULL){
        printf("%d\n", pilha->numero);
        pilha = pilha->proximo;
    }
    printf("--------\n");
}

int main(void){
    Pilha* p;

    p = inicializacao();
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);

    imprimir(p);

    pop(&p);
    pop(&p);
    pop(&p);
    pop(&p);

    imprimir(p);

    return 0;
}
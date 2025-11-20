#include <stdio.h>
#include <stdlib.h>

typedef struct pilha{
    int numero;
    struct pilha* proximo;
} Pilha;

Pilha* push(Pilha* p, int valor){
    Pilha* no = (Pilha*)malloc(sizeof(Pilha));
    if(no == NULL) exit(1);

    no->numero = valor;

    if(p == NULL){
        no->proximo = NULL;
        return no;
    }

    no->proximo = p;

    return no;
}

void pop(Pilha** p){
    if(*p == NULL){
        return;
    }

    Pilha* novo = *p;
    *p = (*p)->proximo;

    free(novo);
}

void imprimir(Pilha* pilha){
    while(pilha != NULL){
        printf("%d\n", pilha->numero);
        pilha = pilha->proximo;
    }
    printf("--------\n");
}

void liberar(Pilha** pilha){
    Pilha* aux;
    while(*pilha != NULL){
        aux = *pilha;
        *pilha = (*pilha)->proximo;
        free(aux);
    }
}

int main(void){
    Pilha* pratos = NULL;

    // empilhando
    pratos = push(pratos, 10);
    pratos = push(pratos, 20);
    pratos = push(pratos, 30);
    pratos = push(pratos, 40);

    imprimir(pratos);

    // desimpilhando
    pop(&pratos);
    pop(&pratos);

    imprimir(pratos);

    liberar(&pratos);

    return 0;
}
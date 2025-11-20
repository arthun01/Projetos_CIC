// fila
// questão 1, aula 6 prática

// fila = lista encadeada com inserção no final e retirada na frente

#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int numero;
    struct fila* proximo;
} Fila;

Fila* push(Fila* fila, int valor){
    Fila* no = (Fila*)malloc(sizeof(Fila));
    if(no == NULL) exit(1);

    if(fila == NULL){
        no->numero = valor;
        no->proximo = NULL;
        return no;
    }

    no->numero = valor;

    Fila* aux = fila;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }

    no->proximo = NULL;
    aux->proximo = no;

    return fila;
}

void pop(Fila** fila){
    Fila* novo = *fila;

    (*fila) = novo->proximo;

    free(novo);
}

void imprimir(Fila* fila){
    if(fila == NULL){
        printf("Fila vazia\n");
    }else{
        while(fila != NULL){
            printf("%d ", fila->numero);
            fila = fila->proximo;
        }
        printf("\n");
    }
}

int main(void){
    Fila* fila_posto = NULL;
    char n;

    while(1){
        char carac;
        scanf(" %c", &carac);

        if(carac == 'E'){
            int aux;
            scanf("%d", &aux);
            fila_posto = push(fila_posto, aux);
        }else if(carac == 'P'){
            printf("%d\n", fila_posto->numero);
        }else if(carac == 'D'){
            if(fila_posto != NULL){
                pop(&fila_posto);
            }
            imprimir(fila_posto);
        }
    }

    return 0;
}
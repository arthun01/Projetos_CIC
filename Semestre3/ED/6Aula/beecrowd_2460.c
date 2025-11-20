#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int numero;
    struct fila* proximo;
} Fila;

Fila* inicializa(){
    return NULL;
}

void inserir(Fila** fila, int valor){
    Fila* no = (Fila*)malloc(sizeof(Fila));
    if(no == NULL) exit(1);

    no->numero = valor;
    no->proximo = NULL;

    if((*fila) == NULL){
        no->proximo = NULL;
        (*fila) = no;
    }else{
        Fila* aux = (*fila);
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = no;
    }
}

Fila* desenfilha(Fila* fila){
    // lendo as "pessoas" que querem sair fora
    scanf("%d", &n);
    while(n > 0){
        int aux;
        scanf("%d", &aux);
        n--;
    }
}

void imprimir(Fila* fila){
    while(fila != NULL){
        printf("%d > ", fila->numero);
        fila = fila->proximo;
    }
    printf("NULL\n");
}

int main(void){
    Fila* fila;
    fila = inicializa();

    Fila* fila_final = inicializa();

    unsigned int n;
    scanf("%d", &n);

    // lendo a primeira fila
    while(n > 0){
        int aux;
        scanf("%d", &aux);
        inserir(&fila, aux);
        n--;
    }

    imprimir(fila);

    fila_final = desenfilha(fila);

    imprimir(fila);


    return 0;
}
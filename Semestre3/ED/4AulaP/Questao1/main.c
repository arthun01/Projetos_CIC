#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int numero;
    struct lista* proximo;
} Lista;

Lista* inserir_inicio(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL){
        exit(1);
    }

    no->numero = valor;
    no->proximo = l;

    return no;
}

Lista* inserir_final(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL){
        exit(1);
    }

    no->numero = valor;
    no->proximo = NULL;

    if(l == NULL){
        return no;
    }

    Lista* l_aux = l;
    while(l_aux->proximo != NULL){
        l_aux = l_aux->proximo;
    }
    l_aux->proximo = no;

    return l;
}

void imprimir(Lista* l){
    Lista* atual = l;

    while(atual != NULL){
        // printf("%d -> ", atual->numero);
        printf("%d ", atual->numero);
        atual = atual->proximo;
    }
    printf("\n");
}

Lista* reoordena_lista(Lista* l){
    Lista* l_esquerda = NULL;
    Lista* l_aux = l;

    int n = 1;
    while(l_aux != NULL){
        n++;

        if(n % 2 != 0){
            l_esquerda = inserir_final(l_esquerda, l_aux);
        }

        l_aux = l_aux->proximo;
    }

}

int main(void){
    Lista* l = NULL;
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        int aux;
        scanf("%d", &aux);
        l = inserir_final(l, aux);
    }

    // reoordena_lista(l);
    imprimir(l);

    return 0;
}
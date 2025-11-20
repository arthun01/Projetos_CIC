// implementação de Lista Simplesmente Encadeada
// Inserção no inicio e no final
// Autor: Arthur Ramos Vieira

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int numero;
    struct lista* proximo;
} Lista;

Lista* inserir_inicio(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL) exit(1);

    no->numero = valor;
    no->proximo = l;

    return no;
}

Lista* inserir_final(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL) exit(1);

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

void imprimir_lista(Lista* l){
    while(l != NULL){
        printf("%d -> ", l->numero);
        l = l->proximo;
    }
    printf("NULL\n");
}

int main(void){
    Lista* listasimples = NULL;

    // listasimples = inserir_inicio(listasimples, 10);
    // listasimples = inserir_inicio(listasimples, 20);
    // listasimples = inserir_inicio(listasimples, 30);
    // listasimples = inserir_inicio(listasimples, 40);
    // listasimples = inserir_inicio(listasimples, 50);

    listasimples = inserir_final(listasimples, 10);
    listasimples = inserir_final(listasimples, 20);
    listasimples = inserir_final(listasimples, 30);
    listasimples = inserir_final(listasimples, 40);
    listasimples = inserir_final(listasimples, 50);

    imprimir_lista(listasimples);

    return 0;
}
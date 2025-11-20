#include <stdio.h>
#include <stdlib.h>

typedef struct listadupla{
    int numero;
    struct listadupla* proximo;
    struct listadupla* anterior;
} ListaDupla;

ListaDupla* inserir_inicio(ListaDupla* l, int valor){
    ListaDupla* no = (ListaDupla*)malloc(sizeof(ListaDupla));
    if(no == NULL) exit(1);

    no->numero = valor;
    no->anterior = NULL;

    if(l == NULL){
        no->proximo = NULL;
        return no;
    }

    no->proximo = l;

    return no;
}

ListaDupla* inserir_final(ListaDupla* l, int valor){
    ListaDupla* no = (ListaDupla*)malloc(sizeof(ListaDupla));
    if(no == NULL) exit(1);

    no->numero = valor;
    no->proximo = NULL;

    if(l == NULL){
        no->anterior = NULL;
        return no;
    }

    ListaDupla* l_aux = l;

    while(l_aux->proximo != NULL){
        l_aux = l_aux->proximo;
    }
    l_aux->proximo = no;
    no->anterior = l_aux;

    return l;
}

void imprimir_lista(ListaDupla* l){
    printf("NULL ");
    while(l != NULL){
        printf("<> %d ", l->numero);
        l = l->proximo;
    }
    printf("<> NULL\n");
}

int main(void){
    ListaDupla* lista_dupla = NULL;

    // lista_dupla = inserir_inicio(lista_dupla, 10);
    // lista_dupla = inserir_inicio(lista_dupla, 20);
    // lista_dupla = inserir_inicio(lista_dupla, 30);
    // lista_dupla = inserir_inicio(lista_dupla, 40);
    // lista_dupla = inserir_inicio(lista_dupla, 50);

    lista_dupla = inserir_final(lista_dupla, 10);
    lista_dupla = inserir_final(lista_dupla, 20);
    lista_dupla = inserir_final(lista_dupla, 30);
    lista_dupla = inserir_final(lista_dupla, 40);
    lista_dupla = inserir_final(lista_dupla, 50);

    imprimir_lista(lista_dupla);

    return 0;
}
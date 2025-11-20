#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int numero;
    struct lista* proximo;
} Lista;

Lista* inserir_inicio_circ(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL) exit(1);

    no->numero = valor;

    if(l == NULL){
        no->proximo = no;
        return no;
    }
    Lista* l_aux = l;

    while(l_aux->proximo != l){
        l_aux = l_aux->proximo;
    }
    l_aux->proximo = no;
    no->proximo = l;

    return no;
}

Lista* inserir_final_circ(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL) exit(1);

    no->numero = valor;

    if(l == NULL){
        no->proximo = no;
        return no;
    }

    Lista* l_aux = l;

    while(l_aux->proximo != l){
        l_aux = l_aux->proximo;
    }
    l_aux->proximo = no;
    no->proximo = l;

    return l;
}

void imprimir_lista_circ(Lista* l){
    if(l == NULL){
        printf("Lista vazia\n");
        return;
    }

    Lista* l_aux = l;

    do{
        printf("%d -> ", l_aux->numero);
        l_aux = l_aux->proximo;
    }while(l_aux != l);

    printf("(volta ao inicio)\n");
}

int main(void){
    Lista* lista_circular = NULL;

    // lista_circular = inserir_inicio_circ(lista_circular, 10);
    // lista_circular = inserir_inicio_circ(lista_circular, 20);
    // lista_circular = inserir_inicio_circ(lista_circular, 30);
    // lista_circular = inserir_inicio_circ(lista_circular, 40);
    // lista_circular = inserir_inicio_circ(lista_circular, 50);

    lista_circular = inserir_final_circ(lista_circular, 10);
    lista_circular = inserir_final_circ(lista_circular, 20);
    lista_circular = inserir_final_circ(lista_circular, 30);
    lista_circular = inserir_final_circ(lista_circular, 40);
    lista_circular = inserir_final_circ(lista_circular, 50);

    imprimir_lista_circ(lista_circular);

    return 0;
}
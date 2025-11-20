#include <stdio.h>
#include <stdlib.h>

typedef struct listaduplacirc{
    int numero;
    struct listaduplacirc* proximo;
    struct listaduplacirc* anterior;
} ListaDuplaCirc;

ListaDuplaCirc* inserir_inicio_lista_dupla_circ(ListaDuplaCirc* l, int valor){
    ListaDuplaCirc* no = (ListaDuplaCirc*)malloc(sizeof(ListaDuplaCirc));
    if(no == NULL) exit(1);

    no->numero = valor;
    
    if(l == NULL){
        no->proximo = no;
        no->anterior = no;
        return no;
    }

    ListaDuplaCirc* l_aux = l;

    while(l_aux->proximo != l){
        l_aux = l_aux->proximo;
    }
    no->proximo = l;
    no->anterior = l_aux;
    l_aux->proximo = no;
    l_aux->anterior = no;

    return no;
}

ListaDuplaCirc* inserir_final_lista_circ(ListaDuplaCirc* l, int valor){
    ListaDuplaCirc* no = (ListaDuplaCirc*)malloc(sizeof(ListaDuplaCirc));
    if(no == NULL) exit(1);

    no->numero = valor;

    if(l == NULL){
        no->proximo = no;
        no->anterior = no;
        return no;
    }

    ListaDuplaCirc* l_aux = l->anterior;

    no->proximo = l;
    no->anterior = l_aux;

    l_aux->proximo = no;
    l->anterior = no;

    return l;
}

void imprimir_lista_dupla_circ(ListaDuplaCirc* l){
    if(l == NULL){
        printf("Lista vazia\n");
        return;
    }

    ListaDuplaCirc* l_aux = l;

    do{
        printf("%d -> ", l_aux->numero);
        l_aux = l_aux->proximo;
    }while(l_aux != l);

    printf("(volta ao inicio)\n");
}

int main(void){
    ListaDuplaCirc* lista_dupla_circ = NULL;

    // lista_dupla_circ = inserir_inicio_lista_dupla_circ(lista_dupla_circ, 10);
    // lista_dupla_circ = inserir_inicio_lista_dupla_circ(lista_dupla_circ, 20);
    // lista_dupla_circ = inserir_inicio_lista_dupla_circ(lista_dupla_circ, 30);
    // lista_dupla_circ = inserir_inicio_lista_dupla_circ(lista_dupla_circ, 40);
    // lista_dupla_circ = inserir_inicio_lista_dupla_circ(lista_dupla_circ, 50);

    lista_dupla_circ = inserir_final_lista_circ(lista_dupla_circ, 10);
    lista_dupla_circ = inserir_final_lista_circ(lista_dupla_circ, 20);
    lista_dupla_circ = inserir_final_lista_circ(lista_dupla_circ, 30);
    lista_dupla_circ = inserir_final_lista_circ(lista_dupla_circ, 40);
    lista_dupla_circ = inserir_final_lista_circ(lista_dupla_circ, 50);

    imprimir_lista_dupla_circ(lista_dupla_circ);

    return 0;
}
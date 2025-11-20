#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* prox;
} No;

typedef struct lista{
    No* inicio;
    No* fim;
} Lista;

Lista* lista_cria(void){
    Lista* l = (Lista*)malloc(sizeof(Lista));
    if(l == NULL){
        printf("Erro em alocação\n");
        return NULL;
    }

    l->inicio = NULL;
    l->fim = NULL;

    return l;
}

int lista_vazia(Lista* l){
    if(l == NULL){
        return 1;
    }

    if(l->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

void lista_libera(Lista* l){
    No* p = l->inicio;

    while(p != NULL){
        No* temp = p;
        p = p->prox;
        free(temp);
    }

    free(l);
}

void lista_insere_inicio(Lista* l, int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro em alocação\n");
        return ;
    }

    novo->info = valor;
    novo->prox = l->inicio;

    l->inicio = novo;

    if(l->fim == NULL){
        l->fim = novo;
    }
}

void lista_insere_fim(Lista* l, int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro na alocação\n");
        return;
    }

    novo->info = valor;
    novo->prox = NULL;

    if(lista_vazia(l) == 1){
        l->inicio = novo;
        l->fim = novo;
    }else{
        l->fim->prox = novo;
        l->fim = novo;
    }
}

int lista_remove_inicio(Lista* l){
    if(lista_vazia(l) == 1){
        printf("Não da para remover pois está vazia\n");
        return -1;
    }

    No* temp = l->inicio;
    int valor = temp->info;

    l->inicio = l->inicio->prox;

    if(l->inicio == NULL){
        l->fim = NULL;
    }

    free(temp);

    // retorna o valor removido
    return valor;
}

int lista_remove_fim(Lista* l){
    if(lista_vazia(l) == 1){
        printf("Não da para remover pois a lista está vazia\n");
        return -1;
    }

    int valor;

    if(l->inicio == l->fim){
        valor = l->inicio->info;
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
    }else{
        No* p = l->inicio;
        while(p->prox != l->fim){
            p = p->prox;
        }

        valor = l->fim->info;
        free(l->fim);
        l->fim = p;
        l->fim->prox = NULL;
    }

    // retorna o valor removido
    return valor;
}

void lista_imprime(Lista* l){
    No* p = l->inicio;

    printf("Lista: [ ");
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
    printf("]\n");
}

int main(void){
    printf("Criando a lista....\n");
    Lista* minha_lista = lista_cria();
    lista_imprime(minha_lista);

    // --------------

    lista_insere_inicio(minha_lista, 10);
    lista_insere_inicio(minha_lista, 20);
    lista_insere_inicio(minha_lista, 30);
    lista_insere_inicio(minha_lista, 40);
    lista_imprime(minha_lista);

    lista_remove_fim(minha_lista);
    lista_imprime(minha_lista);

    lista_insere_fim(minha_lista, 50);
    lista_insere_fim(minha_lista, 60);
    lista_insere_fim(minha_lista, 70);
    lista_insere_fim(minha_lista, 80);
    lista_imprime(minha_lista);

    lista_libera(minha_lista);
    return 0;
}
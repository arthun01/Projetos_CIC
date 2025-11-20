#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char info[10];
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

void lista_insere_inicio(Lista* l, char valor[]){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro em alocação\n");
        return ;
    }

    strcpy(novo->info, valor);
    novo->prox = l->inicio;
    

    l->inicio = novo;

    if(l->fim == NULL){
        l->fim = novo;
    }
}

void lista_insere_fim(Lista* l, char valor[]){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro na alocação\n");
        return;
    }

    strcpy(novo->info, valor);
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

    l->inicio = l->inicio->prox;

    if(l->inicio == NULL){
        l->fim = NULL;
    }

    free(temp);

    // retorna o valor removido
    return 1;
}

int lista_remove_fim(Lista* l){
    if(lista_vazia(l) == 1){
        printf("Não da para remover pois a lista está vazia\n");
        return -1;
    }

    if(l->inicio == l->fim){
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
    }else{
        No* p = l->inicio;
        while(p->prox != l->fim){
            p = p->prox;
        }

        free(l->fim);
        l->fim = p;
        l->fim->prox = NULL;
    }

    // retorna o valor removido
    return 1;
}

void lista_imprime(Lista* l){
    No* p = l->inicio;

    printf("Lista: [ ");
    while(p != NULL){
        printf("%s ", p->info);
        p = p->prox;
    }
    printf("]\n");
}

int main(void){
    printf("Criando a lista....\n");
    Lista* minha_lista = lista_cria();
    lista_imprime(minha_lista);

    // --------------

    lista_insere_inicio(minha_lista, "oibbb");
    lista_insere_inicio(minha_lista, "oiccc");
    lista_insere_inicio(minha_lista, "oiddd");
    lista_insere_inicio(minha_lista, "oieee");
    lista_insere_inicio(minha_lista, "oifff");
    lista_insere_inicio(minha_lista, "arthursexa");
    lista_imprime(minha_lista);

    printf("%s\n", minha_lista->inicio->info);

    lista_libera(minha_lista);
    return 0;
}
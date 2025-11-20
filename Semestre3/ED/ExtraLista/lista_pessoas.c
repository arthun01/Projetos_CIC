#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    int idade;
    float altura;
    char nome[50];
} Pessoa;

typedef struct no{
    Pessoa pessoa;
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

void lista_insere_inicio(Lista* l, Pessoa p_insere){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro em alocação\n");
        return ;
    }

    novo->pessoa = p_insere;
    novo->prox = l->inicio;
    

    l->inicio = novo;

    if(l->fim == NULL){
        l->fim = novo;
    }
}

void lista_insere_fim(Lista* l, Pessoa p_insere){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro na alocação\n");
        return;
    }

    novo->pessoa = p_insere;
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

    int count = 1;
    while(p != NULL){
        printf("N°%d: %s -- %d Anos, %.2fm de Altura\n", count, p->pessoa.nome, p->pessoa.idade, p->pessoa.altura);
        p = p->prox;
        count++;
    }
    printf("\n");
}

int main(void){
    printf("Criando a lista....\n");
    Lista* minha_lista = lista_cria();
    lista_imprime(minha_lista);
    
    for(int i = 0; i < 2; i++){
        Pessoa p1;
        printf("Idade: ");
        int idade;
        scanf("%d", &idade);
        p1.idade = idade;

        printf("Altura: ");
        float altura;
        scanf("%f", &altura);
        p1.altura = altura;

        printf("Nome: ");
        char nome[50];
        scanf(" %49[^\n]", nome);
        strcpy(p1.nome, nome);

        lista_insere_inicio(minha_lista, p1);
        printf("----------------\n");
    }

    lista_imprime(minha_lista);
    lista_remove_fim(minha_lista);
    lista_imprime(minha_lista);

    lista_libera(minha_lista);
    return 0;
}
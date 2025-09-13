#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int numero;
    struct node* proximo;
} Node;

typedef struct lista{
    struct node* primeiro;
    struct node* ultimo;
} Lista;

novo_node = new Node(123);
novo_node.proximo = lista.primeiro;

lista.primeiro = novo_node

Lista* inserir_inicio(Lista* l, int valor){
    if(no == NULL){
        exit(1);
    }

    novo_node = new Node(valor);
    novo_node.proximo = l.primeiro;

    l.primeiro = novo_node;

    return no;
} // O(1)

Lista* inserir_final(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL){
        exit(1);
    }

    
    novo_node = new Node(valor);

    l.ultimo.proximo = novo_node;

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
} // O(n) -> O(1)

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
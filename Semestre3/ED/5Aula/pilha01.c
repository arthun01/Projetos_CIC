// Autor: Arthur Ramos Vieira
// ED, CIC 2025.2

#include <stdio.h>
#include <stdlib.h>

// estrutura da pilha
typedef struct pilha{
    int numero;
    struct pilha* proximo;
} Pilha;

// empilha
Pilha* push(Pilha* p, int num){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if(novo == NULL) exit(1);

    novo->numero = num;
    novo->proximo = p;
    return novo;
}

// desempilha
void pop(Pilha** p){
    if(*p == NULL) return;

    Pilha* temp = *p;
    *p = (*p)->proximo;
    free(temp);
}

// imprime a pilha
void imprimir_pilha(Pilha* p){
    if(p == NULL){
        printf("*\n");
        return;
    }

    Pilha* aux = p;
    while(aux != NULL){
        printf("%d", aux->numero);
        if(aux->proximo != NULL) printf(" ");
        aux = aux->proximo;
    }
    printf("\n");
}

// libera pilha
void liberar_pilha(Pilha* p){
    while(p != NULL){
        Pilha* temp = p;
        p = p->proximo;
        free(temp);
    }
}

int main(void){
    int n;
    int primeiro_caso = 1;

    // Loop de vários casos de teste
    while(scanf("%d", &n) && n != 0){
        if(!primeiro_caso) printf("\n");
        primeiro_caso = 0;

        Pilha* pilha = NULL;

        for(int i = 0; i < n; i++){
            printf("linha %d\n", i+1);
            char operacao;
            scanf(" %c", &operacao);

            if(operacao == 'E'){
                int valor;
                scanf("%d", &valor);
                pilha = push(pilha, valor);
            } else if(operacao == 'D'){
                pop(&pilha);
            }

            imprimir_pilha(pilha);
        }
        imprimir_pilha(pilha);
        liberar_pilha(pilha);
    }

    return 0;
}

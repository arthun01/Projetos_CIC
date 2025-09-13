// Autor: Arthur Ramos Vieira
// ED, CIC 2025.2

#include <stdio.h>
#include <stdlib.h>

// TAD da lista
typedef struct lista{
    int numero;
    struct lista* proximo;
} Lista;

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

// função que reordena uma lista e retorna ordenada
Lista* reoordena_lista(Lista* l){
    // se a lista original for vazia retorna nulo
    if(l == NULL){
        return NULL;
    }

    // declaração das listas
    Lista* l_esquerda = NULL;
    Lista* l_direita = NULL;
    Lista* l_aux = l;
    // index para comparar se é par ou impar
    int index = 1;

    // percorrendo a lista original por uma auxiliar
    while(l_aux != NULL){
        // indice par(if) e impar(else)
        if(index % 2 == 0){
            l_direita = inserir_final(l_direita, l_aux->numero);
        }else{
            l_esquerda = inserir_final(l_esquerda, l_aux->numero);
        }
        // avançando uma no l_aux
        l_aux = l_aux->proximo;
        // avançando um index
        index++;
    }

    if(l_esquerda == NULL){
        return l_direita;
    }

    Lista* ultimo_esquerda = l_esquerda;
    while (ultimo_esquerda->proximo != NULL) {
        ultimo_esquerda = ultimo_esquerda->proximo;
    }

    // junto as duas e retornando
    ultimo_esquerda->proximo = l_direita;

    return l_esquerda;
}

// função para liberar memória das listas
void liberar_lista(Lista* l){
    Lista* atual = l;
    Lista* proximo_no;

    while(atual != NULL){
        proximo_no = atual->proximo;
        free(atual);
        atual = proximo_no;
    }
}

int main(void){
    // declaração das lista
    Lista* l = NULL;
    Lista* l_ordenada = NULL;

    // n elementos da lista
    int n;
    scanf("%d", &n);

    // verificação do intervalo de n
    if(n < 1 || n > 100){
        printf("O valor de N fora do intervalo\n");
        return 0;
    }

    // for para inserir todos na lista
    for(int i = 1; i <= n; i++){
        int aux;
        scanf("%d", &aux);
        l = inserir_final(l, aux);
    }

    // nossa lista recebe uma lista ordenada
    l_ordenada = reoordena_lista(l);

    // saida com lista ordenada
    imprimir(l_ordenada);

    // liberar listas
    liberar_lista(l);
    liberar_lista(l_ordenada);

    return 0;
}
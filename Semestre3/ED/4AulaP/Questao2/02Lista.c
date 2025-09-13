// Autor: Arthur Ramos Vieira
// ED, CIC 2025.2

#include <stdio.h>
#include <stdlib.h>

// TAD da nossa lista
typedef struct lista{
    int numero;
    struct lista* proximo;
} Lista;

// função para inserir um novo no no inicio da lista
Lista* inserir_inicio(Lista* l, int valor){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL){
        exit(1);
    }

    no->numero = valor;
    no->proximo = l;

    return no;
}

// função para inserir um novo no no final da lista
Lista* inserir_final(Lista* l, int valor){
    Lista* l_aux = l;

    Lista* no = (Lista*)malloc(sizeof(Lista));
    if(no == NULL){
        exit(1);
    }

    no->numero = valor;
    no->proximo = NULL;

    // caso da borda (quando a lista é nula ou seja, estamos iniciando)
    if(l == NULL){
        return no;
    }

    while(l_aux->proximo != NULL){
        l_aux = l_aux->proximo;
    }
    l_aux->proximo = no;

    return l;
}

// procedimento para printar a lista
void imprimir_lista(Lista* l){
    while(l != NULL){
        printf("%d ", l->numero);
        l = l->proximo;
    }
    printf("\n");
}

// procedimento para liberar a memória da lista que passar
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
    // declaração lista e variaveis auxiliares
    Lista* l = NULL;
    int aux;
    char part;
    
    // quantas vezes vamos ler o teclado
    int n;
    scanf("%d", &n);

    // while para inserir ou no inicio ou no final
    while(n > 0){
        scanf("%s %d", &part, &aux);
        if(part == 'P'){
            l = inserir_inicio(l, aux);
        }else if(part == 'U'){
           l = inserir_final(l, aux);
        }
        n--;
    }

    // imprimir a lista
    imprimir_lista(l);

    // liberando a memória da nossa lista
    liberar_lista(l);

    return 0;
}
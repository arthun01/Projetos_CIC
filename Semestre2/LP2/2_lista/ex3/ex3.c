/* Exercício 3: Encontrar o Maior Elemento de um Vetor
Implemente uma função int *maior_elemento(int *vetor, int tamanho) que retorna um ponteiro para
o maior elemento de um vetor de inteiros. Se o vetor estiver vazio (tamanho = 0), retorne NULL.
Dica:
Compare os valores apontados por um ponteiro auxiliar que percorre o vetor. */

#include <stdio.h>

int* maior_elemento(int* vetor, int tamanho){
    int* maior = vetor;

    if(tamanho == 0){
        return NULL;
    }

    for(int i = 0; i < tamanho; i++){
        if(*(vetor + i) > *maior){
            maior = vetor + i;
        }
    }

    return maior;
}


int main(void){
    int arr[5] = {10, 0, -20, 30, 22};
    int tamanho = 5;
    
    int* maior = maior_elemento(arr, tamanho);

    if(maior != NULL){
        printf("o maior é %d\n", *maior);
    }else{
        printf("o vetor está vazio!!\n");
    }


    return 0;
}
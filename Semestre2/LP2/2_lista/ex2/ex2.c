/* Exercício 2: Soma de Vetores com Ponteiros
Crie uma função void soma_vetores(int *vetor1, int *vetor2, int *resultado, int tamanho) que calcula
a soma elemento a elemento de dois vetores (vetor1 e vetor2) e armazena o resultado em um terceiro vetor (resultado).
Todos os acessos aos vetores devem ser feitos exclusivamente com ponteiros. */

#include <stdio.h>

void soma_vetores(int* vetor1, int* vetor2, int* resultado, int tamanho){
    for(int i = 0; i < tamanho; i++){
        *(resultado + i) = *(vetor1 + i) + *(vetor2 + i);
    }
}

int main(void){
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5] = {1, 2, 3, 4, 5};
    int resultado[5];

    soma_vetores(arr1, arr2, resultado, 5);

    for(int i = 0; i < 5; i++){
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
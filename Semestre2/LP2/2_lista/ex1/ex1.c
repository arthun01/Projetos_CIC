/* Exercício 1: Inversão de Vetor usando Ponteiros
Escreva uma função void inverte_vetor(int *vetor, int tamanho) que recebe um ponteiro para um vetor de inteiros e inverte a ordem dos seus elementos usando apenas aritmética de ponteiros (sem usar índices []).
Dica: */

#include <stdio.h>

void inverter_vetor(int* vetor, int tamanho){
    int* inicio = vetor;
    int* final = vetor + tamanho - 1;
    int temp;

    while(inicio < final){
        temp = *inicio;
        *inicio = *final;
        *final = temp;

        inicio++;
        final--;
    }
}


int main(void){
    int array[5] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    printf("Vetor original:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");

    inverter_vetor(array, tamanho);

    printf("Vetor ao contrário:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");

    return 0;
}
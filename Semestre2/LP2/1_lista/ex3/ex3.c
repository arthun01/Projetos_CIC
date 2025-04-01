/* Declarar um array de inteiros e printar na tela utilizando ponteiros, ou seja, sem usar indices */

#include <stdio.h>

int main(void){
    int vetor[5] = {10, 20, 30, 40, 50};
    int* ptr;

    ptr = vetor;

    for(int i = 0; i < 5; i++){
        printf("%d\n", *ptr);
        *ptr++;
    }

    return 0;
}
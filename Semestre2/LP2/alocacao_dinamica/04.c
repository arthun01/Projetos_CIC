//matrizes dinâmicas em C

#include <stdio.h>
#include <stdlib.h>

#define LIN 4
#define COL 6

int main(void){

    int** matriz;
    
    //alocando a matriz
    matriz = malloc(LIN * sizeof(int*));

    for(int i = 0; i < LIN; i++){
        *(matriz + i) = malloc(COL * sizeof(int));
    }

    //atribuição comum
    matriz[3][2] = 42;

    //atribuição com aritmetica de ponteiros
    *(*(matriz + 2) + 1) = 99;

    //printando as paradas
    printf("matriz[3][2] = %d\n", *(*(matriz + 3) + 2));
    printf("matriz[2][1] = %d\n", *(*(matriz + 2) + 1));

    //liberando a memória
    for(int i = 0; i < LIN; i++){
        free(*(matriz + i));
    }

    free(matriz);

    return 0;
}
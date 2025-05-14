#include <stdio.h>
#include <stdlib.h>

int main(void){
    int lin1, col1;

    printf("Digite a ordem da matriz: ");
    scanf("%d %d", &lin1, &col1);

    int** matriz1;

    matriz1 = malloc(lin1 * sizeof(int*));

    for(int i = 0; i < lin1; i++){
        *(matriz1 + i) = malloc(col1 * sizeof(int));
    }

    int* vetor;
    vetor = malloc(col1 * sizeof(int));

    //---------------------------------------

    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col1; j++){
            *(*(matriz1 + i) + j) = i + j;
            *(vetor + j) = j + 2;
        }
    }
    
    //---------------------------------------

    printf("-- 1° Matriz\n");
    for(int i = 0; i < lin1; i++){
        for(int j = 0; j < col1; j++){
            printf("%d ", *(*(matriz1 + i) + j));
        }
        printf("\n");
    }

    printf("-- 2° Matriz\n");
    for(int i = 0; i < col1; i++)
        printf("%d ", *(vetor + i));
    printf("\n");

    //---------------------------------------

    int* resultado;
    resultado = malloc(lin1 * sizeof(int));

    for(int i = 0; i < lin1; i++){
        *(resultado + i) = 0;
        for(int j = 0; j < col1; j++){
            *(resultado + i) += *(*(matriz1 + i) + j) * *(vetor + j); 
        }
    }

    printf("-- Resultado da Multiplicação\n");
    for(int i = 0; i < col1; i++)
        printf("%d ", *(resultado + i));
    printf("\n");

    //---------------------------------------

    //liberando a memória
    for(int i = 0; i < lin1; i++){
        free(*(matriz1 + i));
    }

    free(matriz1);

    return 0;
}
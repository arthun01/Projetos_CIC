/*
Arthur Ramos Vieira (202420022)
- Multiplicar de Matriz
-- O programa le do usuario a ordem da 1° matriz e a cria dinamicamente,
-- depois cria uma matriz coluna (vetor) onde tem o número de linhas das colunas da primeira (dinamica tmb),
-- depois cria outro vetor dinamico para armazenar o resultado da multiplicação
*/

#include <stdio.h>
#include <stdlib.h>

// Função para alocar uma matriz de inteiros
int** alocar_matriz(int linhas, int colunas){
    int** matriz = malloc(linhas * sizeof(int*));

    if (matriz == NULL) {
        printf("Erro ao alocar linhas.\n");
        return (int**)-1;
    }

    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));

        if (matriz[i] == NULL) {
            printf("Erro ao alocar colunas.\n");
            return (int**)-1;
        }
    }

    return matriz;
}

// Função para liberar a memória de uma matriz
void liberar_matriz(int** matriz, int linhas){
    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(void){
    int lin1, col1;

    printf("Digite a ordem da matriz: ");
    scanf("%d %d", &lin1, &col1);

    int** matriz1 = alocar_matriz(lin1, col1);
    int* vetor = malloc(col1 * sizeof(int));
    int* resultado = malloc(lin1 * sizeof(int));

    // Preenchendo matriz1 e vetor
    for (int i = 0; i < lin1; i++){
        for (int j = 0; j < col1; j++){
            matriz1[i][j] = i + j;
            vetor[j] = j + 2;
        }
    }

    printf("-- 1° Matriz\n");
    for (int i = 0; i < lin1; i++){
        for (int j = 0; j < col1; j++){
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("-- 2° Matriz (vetor)\n");
    for (int i = 0; i < col1; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Multiplicação matriz x vetor
    for (int i = 0; i < lin1; i++){
        resultado[i] = 0;
        for (int j = 0; j < col1; j++){
            resultado[i] += matriz1[i][j] * vetor[j];
        }
    }

    printf("-- Resultado da Multiplicação\n");
    for (int i = 0; i < lin1; i++){
        printf("%d ", resultado[i]);
    }
    printf("\n");

    // Liberação de memória
    liberar_matriz(matriz1, lin1);
    free(vetor);
    free(resultado);

    return 0;
}

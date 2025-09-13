// Autor: Arthur Ramos Vieira
// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>

#define LIN 2

// Função principal
int main(void){
    // Declaração e leitura do tamanho
    int tamanho;
    scanf("%d", &tamanho);

    // Verificação da entrada entre 1 e 1000
    if(tamanho < 0 || tamanho > 1000){
        printf("Valor errado de N!!\n");
        return 0;
    }

    // Declaração de três vetores unidimensionais dinamicos
    // E verificação de alocação correta
    int* vetor1 = (int*)malloc(tamanho * sizeof(int));
    if(vetor1 == NULL){
        printf("Não alocou!!\n");
        return 0;
    }

    int* vetor2 = (int*)malloc(tamanho * sizeof(int));
    if(vetor2 == NULL){
        printf("Não alocou!!\n");
        return 0;
    }

    // Iteração sobre o primeiro vetor para preencher
    for(int i = 0; i < tamanho; i++)
        scanf("%d", &vetor1[i]);

    // Iteração sobre o segundo vetor para preencher
    for(int i = 0; i < tamanho; i++)
        scanf("%d", &vetor2[i]);

    // Declação de X colunas e leitura
    // Verificação de quantidade de colunas
    int x;
    scanf("%d", &x);

    if(x < 0 || x > 1000){
        printf("Número de colunas errado!!\n");
        return 0;
    }

    // Declaração da matriz resultante
    // Alocando dinâmicamente as linhas
    // Alocando dinâmicamente as colunas
    int** matriz_resultante = (int**)malloc(LIN * sizeof(int*));
    
    if(matriz_resultante == NULL){
        printf("Erro ao alocar matriz!!\n");
        return 0;
    }

    for(int i = 0; i < LIN; i++){
        matriz_resultante[i] = (int*)malloc(x * sizeof(int));

        if(matriz_resultante[i] == NULL){
            printf("Erro ao alocar colunas!!\n");
            return 0;
        }

    }

    int* vetor_resultante = (int*)malloc(tamanho * sizeof(int));
    if(vetor_resultante == NULL){
        printf("Não alocou!!\n");
        return 0;
    }

    // Iteração para realizar a soma entre eles no terceiro vetor
    for(int i = 0; i < tamanho; i++){
        vetor_resultante[i] = vetor1[i] + vetor2[i];
    }


    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < LIN; j++){
            matriz_resultante[j][i] = vetor1[i] + vetor2[i];
        }
    }

    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < x; j++){
            printf("%d ", matriz_resultante[i][j]);
        }
        printf("\n");
    }


    // Liberação de memória dos três vetores dinâmicos
    free(vetor1);
    free(vetor2);
    free(vetor_resultante);
    free(matriz_resultante);

    return 0;
}
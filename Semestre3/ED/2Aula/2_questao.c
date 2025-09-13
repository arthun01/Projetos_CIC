// Autor: Arthur Ramos Vieira
// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>

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

    int* vetor_resultante = (int*)malloc(tamanho * sizeof(int));
    if(vetor_resultante == NULL){
        printf("Não alocou!!\n");
        return 0;
    }


    // Iteração sobre o primeiro vetor para preencher
    for(int i = 0; i < tamanho; i++)
        scanf("%d", &vetor1[i]);

    // Iteração sobre o segundo vetor para preencher
    for(int i = 0; i < tamanho; i++)
        scanf("%d", &vetor2[i]);

    // Iteração para realizar a soma entre eles no terceiro vetor
    int j = tamanho - 1;
    for(int i = 0; i < tamanho; i++){
        vetor_resultante[i] = vetor1[i] + vetor2[j];
        j--;
    }

    // Iteração para mostrar o resultado na tela
    for(int i = 0; i < tamanho; i++)
        printf("%d ", vetor_resultante[i]);
    
    printf("\n");

    // Liberação de memória dos três vetores dinâmicos
    free(vetor1);
    free(vetor2);
    free(vetor_resultante);

    return 0;
}
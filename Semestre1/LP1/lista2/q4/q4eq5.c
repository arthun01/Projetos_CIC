#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LINHA 20
#define COLUNA 20

void printar_matriz(float matriz[][COLUNA]);
float fuc_media(float matriz[][COLUNA], int lins, int cols);
void ord_matriz(float matriz[][COLUNA], int lins, int cols);
float calc_mediana(float matriz[][COLUNA], int lins, int cols);
float fuc_desvio_padrao(float matriz[][COLUNA], float media, int lins, int cols);

int main(){
    float matriz[LINHA][COLUNA];
    float media, mediana, desvio;

    srand(time(NULL));

    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            matriz[i][j] = ((float)rand() / (float)RAND_MAX) * 1000;
        }
    }   

    printf("--> Matriz 20x20 aleatória:\n");
    printar_matriz(matriz);

    //ordenando a matriz
    ord_matriz(matriz, LINHA, COLUNA);
    printf("--> Matriz 20x20 ordenada:\n");
    printar_matriz(matriz);

    //calculando a media
    media = fuc_media(matriz, LINHA, COLUNA);
    printf("-> Media dos valores: %.2f\n", media);

    //calculando a mediana
    mediana = (matriz[9][9] + matriz[10][10]) / 2;
    printf("-> Mediana dos valores: %.2f\n", mediana);

    //calculando o desvio
    desvio = fuc_desvio_padrao(matriz, media, LINHA, COLUNA);
    printf("-> Desvio padrão: %.2f\n", desvio);


    return 0;
}

//----------FUNÇÕES----------//

//função para printar a matriz no easy
void printar_matriz(float matriz[][COLUNA]){
    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("-------------------------\n");
}

//função das médias
float fuc_media(float matriz[][COLUNA], int lins, int cols){
    float soma = 0;

    for(int i = 0; i < lins; i++){
        for(int j = 0; j < cols; j++){
            soma += matriz[i][j];
        }
    }

    return soma / (lins * cols);
}

//ordena a matriz que role de função
void ord_matriz(float matriz[][COLUNA], int lins, int cols){
    //total de elementos na matriz
    int total = lins * cols;
    float vetor[total];
    int index = 0;

    //copiando elementos da matriz para um vetor
    for (int i = 0; i < lins; i++){
        for (int j = 0; j < cols; j++){
            vetor[index++] = matriz[i][j];
        }
    }

    //insertion sort
    for(int i = 1; i < total; i++){
        float aux = vetor[i];
        int j = i - 1;

        while(j >= 0 && vetor[j] > aux){
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = aux;
    }

    //voltando os elementos para a matriz
    index = 0;
    for(int i = 0; i < lins; i++){
        for (int j = 0; j < cols; j++){
            matriz[i][j] = vetor[index++];
        }
    }
}

//função para o desvio padrão
float fuc_desvio_padrao(float matriz[][COLUNA], float media, int lins, int cols){
    float soma_diferencas_quadradas = 0;

    for(int i = 0; i < lins; i++){
        for(int j = 0; j < cols; j++){
            soma_diferencas_quadradas += pow(matriz[i][j] - media, 2);
        }
    }

    return sqrt(soma_diferencas_quadradas / (lins * cols));
}
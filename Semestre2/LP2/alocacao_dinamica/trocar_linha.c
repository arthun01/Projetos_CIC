#include <stdio.h>
#include <stdlib.h>

//ordem da matriz em stack
#define LIN 5
#define COL 5

//funções para a matriz em stack

//função para preencher a matriz com um padrão simples mas poderia ser aleatorio ou manual
void preencher(int matriz[LIN][COL]){
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            matriz[i][j] = (i + j) * 2;
        }
    }
}

//função que troca as linhas que o usuario pediu, usando um loop e uma variável auxiliar
void trocar_linha(int matriz[LIN][COL], int primeira, int segunda){
    int aux;

    for(int i = 0; i < COL; i++){
        aux = matriz[primeira-1][i];
        matriz[primeira-1][i] = matriz[segunda-1][i];
        matriz[segunda-1][i] = aux;
    }
}

//função para printar a matriz na tela
void printar(int matriz[LIN][COL]){
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
}
//-------------------------

//funções para matriz em heap

//função que aloca dinamicamente a matriz
int** alocar_matriz(int linhas, int colunas){
    int** matriz = malloc(linhas * sizeof(int*));
    if(matriz == NULL){
        return (int**)-1;
    }

    for(int i = 0; i < linhas; i++){
        *(matriz + i) = malloc(colunas * sizeof(int));
        if(*(matriz + i) == NULL){
            return (int**)-1;
        }
    }

    return matriz;
}

//função que libera a matriz dinamica na memória usando o free
void liberar_matriz(int** matriz, int linhas){
    for(int i = 0; i < linhas; i++){
        free(*(matriz + i));
    }

    free(matriz);
}

//função para preencher a matriz dinamica no mesmo padrão da outra porém com uma abordagem diferente
void preencher_dinamica(int** matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            *(*(matriz + i) + j) = (i + j) * 2;
        }
    }
}

//função para printar a matriz dinamica (também com uma abordagem diferente)
void printar_dinamica(int** matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%2d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
}

//função que troca as linhas da matriz dinamica só que sem o loop (melhorando a peformidade)
void trocar_linha_dinamica(int** matriz, int primeira, int segunda, int colunas){
    int* aux;

    aux = *(matriz + (primeira-1));
    *(matriz + (primeira - 1)) = *(matriz + (segunda - 1));
    *(matriz + (segunda - 1)) = aux;
}

int main(void){
    //-- troca as linhas versão stack
    int matriz_n[LIN][COL];
    int linha1, linha2;

    preencher(matriz_n);
    printar(matriz_n);

    printf("Digite as linhas que quer trocar: ");
    scanf("%d %d", &linha1, &linha2);

    trocar_linha(matriz_n, linha1, linha2);
    printar(matriz_n);

    printf("=-=-=-= ALOCAÇÃO DINAMICA -=-=-=-=\n\n ");

    //----------------------------------

    //-- troca as linhas versão heap

    int lin, col;
    printf("Digite a ordem da matriz: ");
    scanf("%d %d", &lin, &col);

    int** matriz_d = alocar_matriz(lin, col);
    preencher_dinamica(matriz_d, lin, col);
    printar_dinamica(matriz_d, lin, col);

    int lin1, lin2;

    printf("Digite as linhas que quer trocar: ");
    scanf("%d %d", &lin1, &lin2);

    trocar_linha_dinamica(matriz_d, lin1, lin2, col);
    printar_dinamica(matriz_d, lin, col);

    liberar_matriz(matriz_d, lin);

    //----------------------------------
    return 0;
}
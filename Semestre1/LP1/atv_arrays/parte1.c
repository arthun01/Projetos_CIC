/*
Aluno: Arthur Ramos Vieira
N° de Matrícula: 202420022
Línguagem de Programação I, 2024.2
----------------------------------
Parte 1: Determinar o número de interações
necessárias para inicializar e somar um
array 1D, array 2D e um array 3D (utilizando
multiplos até o milhão)
*/

#define VER    "\x1b[31m"
#define RESET   "\x1b[0m"    

#include <stdio.h>

int uni();
int bi();
int tri();

int main(){
    int ask = 0;

    printf(" 1D[1]\n 2D[2]\n 3D[3] || Resposta: ");
    scanf("%d", &ask);

    if(ask == 1){
        uni();
    }else if(ask == 2){
        bi();
    }else if(ask == 3){
        tri();
    }

    return 0;
}

int uni(){

    printf(VER "ARRAY 1D COM 10 VALORES\n" RESET);
    int arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = i + 1;
        printf("%d, ", arr[i]);
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 1D COM 100 VALORES\n" RESET);
    int arr1[100];
    for(int i = 0; i < 100; i++){
        arr1[i] = i + 1;
        printf("%d, ", arr1[i]);
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 1D COM 1000 VALORES\n" RESET);
    int arr2[1000];
    for(int i = 0; i < 1000; i++){
        arr2[i] = i + 1;
        printf("%d, ", arr2[i]);
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 1D COM 10,000 VALORES\n" RESET);
    int arr3[10000];
    for(int i = 0; i < 10000; i++){
        arr3[i] = i + 1;
        printf("%d, ", arr3[i]);
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 1D COM 100,000 VALORES\n" RESET);
    int arr4[100000];
    for(int i = 0; i < 100000; i++){
        arr4[i] = i + 1;
        printf("%d, ", arr4[i]);
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 1D COM 1,000,000 VALORES\n" RESET);
    int arr5[1000000];
    for(int i = 0; i < 1000000; i++){
        arr5[i] = i + 1;
        printf("%d, ", arr5[i]);
    }
    printf("\n------------------------------\n");

    return 0;
}

int bi(){
    printf(VER "ARRAY 2D COM 10 e 10 VALORES\n" RESET);
    int arr[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = i + j;
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 2D COM 100 e 10 VALORES\n" RESET);
    int arr1[100][10];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 10; j++){
            arr1[i][j] = i + j;
            printf("%4d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 2D COM 1,000 e 10 VALORES\n" RESET);
    int arr2[1000][10];
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 10; j++){
            arr2[i][j] = i + j;
            printf("%4d ", arr2[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 2D COM 10,000 e 10 VALORES\n" RESET);
    int arr3[10000][10];
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 10; j++){
            arr3[i][j] = i + j;
            printf("%5d ", arr3[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------\n");

    printf(VER "ARRAY 2D COM 100,000 e 10 VALORES\n" RESET);
    int arr4[100000][10];
    for(int i = 0; i < 100000; i++){
        for(int j = 0; j < 10; j++){
            arr4[i][j] = i + j;
            printf("%6d ", arr4[i][j]);
        }
        printf("\n");
    }
    printf("\n------------------------------\n");
}

int tri(){
    int array[10][10][10000];

    // Preenchendo o array com a soma dos índices
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10000; k++) {
                array[i][j][k] = i + j + k;
            }
        }
    }

    // Imprimindo o array 100x100x100
    for (int i = 0; i < 10; i++) {
        printf("Camada %d:\n", i + 1);
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10000; k++) {
                printf("%5d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

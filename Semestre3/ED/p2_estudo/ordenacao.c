#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int chave = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > chave){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = chave;
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int menorIndice = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[menorIndice]){
                menorIndice = j;
            }
        }

        int temp = arr[menorIndice];
        arr[menorIndice] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printVetor(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void){
    int arr[] = {24, 12, 76, 10, 80, 2, 100};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    // insertionSort(arr, tamanho);
    // selectionSort(arr, tamanho);
    bubbleSort(arr, tamanho);

    printVetor(arr, tamanho);

    return 0;
}
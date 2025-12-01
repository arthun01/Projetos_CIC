#include <stdio.h>
#include <stdlib.h>

// Implementação do Insertion Sort conforme solicitado
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    // 2. Definir o limite (Teto da divisão N/3)
    // Ex: N=7 -> (7+2)/3 = 3. Ex: N=9 -> (9+2)/3 = 3.
    int limite = (n + 2) / 3; 
    
    int encontrou_registro = 0;
    int i = 0;

    // 3. Contar ocorrências no vetor ordenado
    while (i < n) {
        int numero_atual = arr[i];
        int contagem = 0;

        // Conta quantos números iguais existem consecutivamente
        while (i < n && arr[i] == numero_atual) {
            contagem++;
            i++;
        }

        // Verifica o critério corrigido
        if (contagem >= limite) {
            printf("%d ", numero_atual);
            encontrou_registro = 1;
        }
    }

    // Se ninguém atendeu ao critério
    if (!encontrou_registro) {
        printf("Nao possui registros");
    }
    
    printf("\n");

    free(arr);
    return 0;
}
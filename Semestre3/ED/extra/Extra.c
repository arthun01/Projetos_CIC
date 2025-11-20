/*
- Alunos: Arthur Ramos Vieira, Lucas Diniz Bezerra
- Prática Extra 01 - Estrutura de Dados, CIC 2025.2
- Data: 17/11/2025
*/

// Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// trocarXporY
// Recebe dois ponteiros para inteiros
// Troca os valores entre si diretamente no endereço de memória
void trocarXporY(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// --- Implementação dos Algoritmos de Ordenação ---

// insertionSort
// Recebe um vetor e seu tamanho
// Retorna o vetor ordenado (ordenação por referência)
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move os elementos de arr[0..i-1], que são maiores que key,
        // uma posição à frente de sua posição atual
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


// selectionSort
// Recebe um vetor e seu tamanho
// Retorna o vetor ordenado (ordenação por referência)
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        // Encontra o elemento mínimo no vetor não ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Troca o elemento mínimo encontrado com o primeiro elemento
        if (min_idx != i) {
            trocarXporY(&arr[min_idx], &arr[i]);
        }
    }
}


// bubbleSort
// Recebe um vetor e seu tamanho
// Retorna o vetor ordenado (ordenação por referência)
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped; // Otimização: para se já estiver ordenado
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocarXporY(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // Se nenhuma troca ocorreu na passagem interna, o vetor está ordenado
        if (swapped == 0)
            break;
    }
}

// partition_random
// Recebe um vetor, o índice inicial (low) e o índice final (high)
// Faz a partição usando um pivô aleatório
// Retorna o índice da partição (pivô)
int partition_random(int arr[], int low, int high) {
    // Escolhe um pivô aleatório entre low e high
    int pivot_index = low + rand() % (high - low + 1);
    
    // Troca o pivô aleatório com o último elemento
    trocarXporY(&arr[pivot_index], &arr[high]);
    
    int pivot_value = arr[high];
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot_value) {
            i++;
            trocarXporY(&arr[i], &arr[j]);
        }
    }
    trocarXporY(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// quickSortRecursive
// Recebe um vetor, o índice inicial (low) e o índice final (high)
// Executa a lógica recursiva do Quick Sort
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de particionamento
        int pi = partition_random(arr, low, high);

        // Ordena separadamente os elementos antes e depois da partição
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

// quickSortWrapper
// Recebe um vetor e seu tamanho
// Faz a chamada inicial para a função recursiva
void quickSortWrapper(int arr[], int n) {
    // A semente do rand() já foi definida no main
    quickSortRecursive(arr, 0, n - 1);
}

// --- Funções de Utilitário e Benchmark ---

// generateRandomArray
// Recebe o tamanho (size) do vetor
// Retorna um ponteiro para um vetor alocado dinamicamente com valores aleatórios
int* generateRandomArray(int size) {
    // Aloca memória dinamicamente para o tamanho
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL){
        fprintf(stderr, "Falha ao alocar memória para o vetor.\n");
        return NULL;
    }

    // Números aleatórios entre 0 e 99999
    for (int i = 0; i < size; i++){
        arr[i] = rand() % 100000;
    }

    // Retorna um vetor aleatório
    return arr;
}

// copyArray
// Recebe o vetor original e o seu tamanho
// Retorna um ponteiro para uma cópia idêntica do vetor
int* copyArray(int* original, int size) {
    // Aloca memória dinamicamente para o novo vetor com o mesmo tamanho do original
    int* copy = (int*)malloc(size * sizeof(int));

    // Verifica se deu tudo certo na alocação
    if (copy == NULL) {
        fprintf(stderr, "Falha ao alocar memória para a cópia.\n");
        return NULL;
    }

    // Copia os valores elemento por elemento do vetor original para a cópia
    for (int i = 0; i < size; i++) {
        copy[i] = original[i];
    }

    // retorna o vetor copia
    return copy;
}

// main
// Ponto de entrada do programa
// Faz a orquestração de todo o teste de execução (medição de tempo)
// Retorna 0 em caso de sucesso
int main(void) {
    // Configurações dos tamanhos
    int sizes[] = {1000, 5000, 10000};
    int num_sizes = 3;
    int num_instances = 3; // Número de repetições por teste

    // Matriz para guardar os resultados finais
    // Linha 0: Insertion, 1: Selection, 2: Bubble, 3: Quick
    double avg_results[4][3]; 

    // Define a semente inicial para geração aleatória
    srand((unsigned int)time(NULL));

    printf("Iniciando testes de execução (Tempos em milissegundos)...\n");
    printf("Alunos: Arthur Ramos Vieira e Lucas Diniz Bezerra\n");
    printf("=================================================\n");

    // Loop dos Tamanhos (1000, 5000 e 10000)
    for (int i = 0; i < num_sizes; i++) {
        int N = sizes[i];
        printf("\n--- Testando N = %d ---\n", N);
        
        double total_time;
        unsigned int seed;

        // 1. Insertion Sort
        printf("  Algoritmo: Insertion Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instâncias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável para garantir vetores diferentes
            seed = (unsigned int)time(NULL) + k + 1;
            srand(seed);
            
            // Gera um Array aleatório e copia para ordenar (fora da medição)
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Medição de tempo (apenas da ordenação)
            clock_t inicio = clock();
            insertionSort(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instância %d: %.4f ms\n", k+1, ms);

            // Libera memória alocada
            free(original);
            free(copia);
        }
        // Guarda média do Insertion na Matriz de resultados
        avg_results[0][i] = total_time / num_instances;
        printf("    -> Média Insertion: %.4f ms\n", avg_results[0][i]);

        // 2. Selection Sort
        printf("  Algoritmo: Selection Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instâncias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável
            seed = (unsigned int)time(NULL) + k + 2; 
            srand(seed);

            // Gera e copia fora da medição
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Medição de tempo
            clock_t inicio = clock();
            selectionSort(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instância %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Selection na Matriz de resultados
        avg_results[1][i] = total_time / num_instances;
        printf("    -> Média Selection: %.4f ms\n", avg_results[1][i]);

        // ============================================================
        // 3. Bubble Sort
        // ============================================================
        printf("  Algoritmo: Bubble Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instâncias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável
            seed = (unsigned int)time(NULL) + k + 3; 
            srand(seed);

            // Gera e copia fora da medição
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Medição de tempo
            clock_t inicio = clock();
            bubbleSort(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instância %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Bubble na Matriz de resultados
        avg_results[2][i] = total_time / num_instances;
        printf("    -> Média Bubble: %.4f ms\n", avg_results[2][i]);

        // 4. Quick Sort
        printf("  Algoritmo: Quick Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instâncias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável
            seed = (unsigned int)time(NULL) + k + 4; 
            srand(seed);

            // Gera e copia fora da medição
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Medição de tempo
            clock_t inicio = clock();
            quickSortWrapper(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instância %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Quick na Matriz de Resultados 
        avg_results[3][i] = total_time / num_instances;
        printf("    -> Média Quick: %.4f ms\n", avg_results[3][i]);

    }

    // -- Impressão da Tabela Final
    printf("\n\n--- Tabela Final de Tempos Médios (ms) ---\n\n");

    // Exibe o cabeçalho (tamanhos dos vetores)
    printf("%-18s", "Algoritmo");
    for (int i = 0; i < num_sizes; i++){
        printf("%-15d", sizes[i]);
    }
    printf("\n");
    
    // Exibe a linha que divide a tabela
    for (int i = 0; i < 18 + num_sizes * 15; i++){
        printf("=");
    }
    printf("\n");

    // Imprime os resultados linha por linha

    // Linha Insertion Sort
    printf("%-18s", "Insertion Sort");
    for(int i=0; i<num_sizes; i++){
        printf("%-15.4f", avg_results[0][i]);
    }
    printf("\n");

    // Linha Selection Sort
    printf("%-18s", "Selection Sort");
    for(int i=0; i<num_sizes; i++){
        printf("%-15.4f", avg_results[1][i]);
    }
    printf("\n");

    // Linha Bubble Sort
    printf("%-18s", "Bubble Sort");
    for(int i=0; i<num_sizes; i++){
        printf("%-15.4f", avg_results[2][i]);
    }
    printf("\n");

    // Linha Quick Sort
    printf("%-18s", "Quick Sort");
    for(int i=0; i<num_sizes; i++){
        printf("%-15.4f", avg_results[3][i]);
    }
    printf("\n");

    printf("\nFim dos testes de execução.\n");
    return 0;
}
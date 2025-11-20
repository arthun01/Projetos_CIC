#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
generateRandomArray
Recebe o tamanho do vetor
Retorna um vetor alocado dinamicamente com valores aleatórios
*/

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

/*
copyArray
Recebe o vetor original e o seu tamanho em inteiro
Retorna uma cópia idêntica do vetor passado
*/
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

int main(void) {
    // Configurações dos tamanhos
    int sizes[] = {1000, 5000, 10000};
    int num_sizes = 3;
    int num_instances = 3;

    // Matriz para guardar os resultados finais
    // Linha 0: Insertion, 1: Selection, 2: Bubble, 3: Quick
    double avg_results[4][3]; 

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

        // Iteração sobre o número de instancias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável para garantir vetores diferentes
            seed = (unsigned int)time(NULL) + k + 1;
            srand(seed);
            
            // Gera um Array aleatorio e copia para ordenar
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Chamando a função de ordenação
            // Chamando as funções de medição de tempo
            clock_t inicio = clock();
            insertionSort(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instancia %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Insertion em uma parte da Matriz de resultados
        avg_results[0][i] = total_time / num_instances;
        printf("    -> Media Insertion: %.4f ms\n", avg_results[0][i]);

        // 2. Selection Sort
        printf("  Algoritmo: Selection Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instancias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável para garantir vetores diferentes
            seed = (unsigned int)time(NULL) + k + 2; 
            srand(seed);

            // Gera um Array aleatorio e copia para ordenar
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Chamando a função de ordenação
            // Chamando as funções de medição de tempo
            clock_t inicio = clock();
            selectionSort(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instancia %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Selection na Matriz de resultados
        avg_results[1][i] = total_time / num_instances;
        printf("    -> Media Selection: %.4f ms\n", avg_results[1][i]);


        // 3. Bubble Sort
        printf("  Algoritmo: Bubble Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instancias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável para garantir vetores diferentes
            seed = (unsigned int)time(NULL) + k + 3; 
            srand(seed);

            // Gera um Array aleatorio e copia para ordenar
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Chamando a função de ordenação
            // Chamando as funções de medição de tempo
            clock_t inicio = clock();
            bubbleSort(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instancia %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Bubble na Matriz de resultados
        avg_results[2][i] = total_time / num_instances;
        printf("    -> Media Bubble: %.4f ms\n", avg_results[2][i]);


        // 4. Quick Sort
        printf("  Algoritmo: Quick Sort\n");
        total_time = 0.0;

        // Iteração sobre o número de instancias
        for (int k = 0; k < num_instances; k++) {
            // Define semente variável para garantir vetores diferentes
            seed = (unsigned int)time(NULL) + k + 4; 
            srand(seed);

            // Gera um Array aleatorio e copia para ordenar
            int* original = generateRandomArray(N);
            int* copia = copyArray(original, N);

            // Chamando a função de ordenação
            // Chamando as funções de medição de tempo
            clock_t inicio = clock();
            quickSortWrapper(copia, N);
            clock_t fim = clock();

            double ms = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
            total_time += ms;
            printf("    Instancia %d: %.4f ms\n", k+1, ms);

            free(original);
            free(copia);
        }
        // Guarda média do Quick na Matriz de Resultados 
        avg_results[3][i] = total_time / num_instances;
        printf("    -> Media Quick: %.4f ms\n", avg_results[3][i]);

    }

    // -- Impressão da Tabela Final
    printf("\n\n--- Tabela Final de Tempos Medios (ms) ---\n\n");

    // Exibe os tamanhos dos vetores
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

    // Imprime linha por linha manualmente para não usar array de nomes

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
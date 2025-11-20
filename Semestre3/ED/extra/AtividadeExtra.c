/*
    Arthur Ramos Vieira e Lucas Diniz Bezerra
    Atividade extra
*/
//bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
trocadorXporY
recebe ponteiro para dois inteiros e os troca de posicao
nao retorna nada pois a troca é feita por endereço de memoria
*/
void trocadorXporY(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

//----------------------------------------------------------
/*
insertion sort
recebe o array e seu tamanho(n)
nao retorna diretamente porem ordena o array
*/
void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        //Avanca no array os elementos maiores que a chave
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

//----------------------------------------------------------
/*
selection sort
recebe o array e seu tamanho(n)
nao retorna diretamente porem ordena o array
*/
void selectionSort(int arr[], int n) {
    int i, j, menor;
    for (i = 0; i < n - 1; i++) {
        // Encontra o menor elemento
        menor = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[menor])
                menor = j;
        }
        // Leva o menor elemento para o comeco do array
        if (menor != i) {
            //funcao de troca
            trocadorXporY(&arr[menor], &arr[i]);
        }
    }
}

//----------------------------------------------------------
/*
bubble sort
recebe o array e seu tamanho(n)
nao retorna diretamente porem ordena o array
*/
void bubbleSort(int arr[], int n) {
    int i, j;
    // verificador caso se ja esta ordenado
    int ordernado; 
    for (i = 0; i < n - 1; i++) {
        ordernado = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocadorXporY(&arr[j], &arr[j + 1]);
                ordernado = 1;
            }
        }
        // Se ordenado nao mudou de valor, nada foi feito
        //logo, vetor está ordenado
        if (ordernado == 0)
            break;
    }
}

//----------------------------------------------------------
//Quick sort e seus auxiliares

/*
QuebraNoMeio
recebe o array, seu maior e menor elemento
retorna a posicao do indicevo
*/
int QuebraNoMeio(int arr[], int chao, int teto) {
    // Escolhe o elemento do meio como indicevô
    int indicevot_index = chao + (teto - chao) / 2;
    
    // Troca o indicevô e o último elemento
    trocadorXporY(&arr[indicevot_index], &arr[teto]);
    
    int indicevo = arr[teto];
    int i = (chao - 1); 
    

    for (int j = chao; j <= teto - 1; j++) {
        // Se o elemento atual for menor ou igual ao indicevô
        if (arr[j] <= indicevo) {
            i++;
            trocadorXporY(&arr[i], &arr[j]);
        }
    }
    trocadorXporY(&arr[i + 1], &arr[teto]);
    return (i + 1);
}


/*
QuickSort
recebe o array ou subarrays, o menor valor e o maior desse intervalo
*/
void QuickSort(int arr[], int chao, int teto) {
    if (chao < teto) {
        int indice = QuebraNoMeio(arr, chao, teto);

        // Ordena os subarrays de antes e depois da partição
        QuickSort(arr, chao, indice - 1);
        QuickSort(arr, indice + 1, teto);
    }
}

//----------------------------------------------------------
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
             QuickSort(copia, 0, N-1);
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
/*
-- 3° Questão da lista de Exercícios, Linguagens de Programação I
-- Docente: Professor Marcelo Honda
-- Discente: Arthur Ramos Vieira
-- N° de Matrícula: 202420022
-- Ciência da Computação 2024.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 10000
#define MAX_VALOR 1000.0
#define MAX_VALOR_INT 1000

// Declarando funções
void insertion_sort(float v[], int tam);
void listar_reps(float v[], int tam);
float fuc_media(float v[], int tam);
float fuc_desvio_padrao(float v[], float media, int tam);
int criar_array_unico(float v[], int tam, float novo_array[]);

int main() {
    float arr[TAM];
    float media, mediana, desvio;

    srand(time(NULL));

    // Preenchendo o array com valores aleatórios entre 0 e 1000
    for (int i = 0; i < TAM; i++) {
        arr[i] = ((float)rand() / RAND_MAX) * MAX_VALOR;
    }

    // Ordenar array
    insertion_sort(arr, TAM);

    printf("---------------------------\n");
    printf("      Primeira parte \n");
    printf("---------------------------\n");

    printf("Os três maiores termos são: %.2f %.2f %.2f\n", arr[TAM - 1], arr[TAM - 2], arr[TAM - 3]);
    printf("Os três menores elementos são: %.2f %.2f %.2f\n", arr[0], arr[1], arr[2]);
    printf("---------------------------\n");

    // Chamando a função que calcula a média
    media = fuc_media(arr, TAM);
    printf("Média: %.2f\n", media);

    // Chamando a função que calcula a mediana
    mediana = (arr[TAM / 2 - 1] + arr[TAM / 2]) / 2.0;
    printf("Mediana: %.2f\n", mediana);

    // Chamando a função que calcula o desvio padrão
    desvio = fuc_desvio_padrao(arr, media, TAM);
    printf("Desvio padrão: %.2f\n", desvio);

    printf("---------------------------\n");
    printf("      Segunda parte \n");
    printf("---------------------------\n");

    // Chama a função que mostra a quantidade de repetições de cada número
    listar_reps(arr, TAM);

    printf("---------------------------\n");
    printf("Array único: \n");

    float arr_unico[TAM];
    int novo_tamanho = criar_array_unico(arr, TAM, arr_unico);

    for (int j = 0; j < novo_tamanho; j++) {
        printf("%.2f ", arr_unico[j]);
    }

    printf("\n---------------------------\n");

    // Chamando a função que calcula a média
    media = fuc_media(arr_unico, novo_tamanho);
    printf("Média: %.2f\n", media);

    // calculando a mediana
    mediana = (arr_unico[novo_tamanho / 2 - 1] + arr_unico[novo_tamanho / 2]) / 2.0;
    printf("Mediana: %.2f\n", mediana);

    // Chamando a função que calcula o desvio padrão
    desvio = fuc_desvio_padrao(arr_unico, media, novo_tamanho);
    printf("Desvio padrão: %.2f\n", desvio);

    return 0;
}

// -- Funções -- //

// Função Insertion Sort, ordena o vetor na ordem crescente
void insertion_sort(float v[], int tam){
    int i, j;
    float aux;

    for(i = 1; i < tam; i++){
        aux = v[i];
        j = i - 1;

        while((j >= 0) && (aux < v[j])){
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = aux;
    }
}

float fuc_media(float v[], int tam){
    float soma = 0;

    for(int i = 0; i < tam; i++){
        soma += v[i];
    }

    return soma / tam;
}

float fuc_desvio_padrao(float v[], float media, int tam){
    float soma_diferencas_quadradas = 0;

    for(int i = 0; i < tam; i++){
        soma_diferencas_quadradas += pow(v[i] - media, 2);
    }

    return sqrt(soma_diferencas_quadradas / tam);
}

void listar_reps(float v[], int tam){
    printf("Valores repetidos e suas quantidades (arredondados):\n");
    int contador[MAX_VALOR_INT + 1] = {0};

    for (int i = 0; i < tam; i++) {
        int valor = (int)round(v[i]);
        contador[valor]++;
    }

    for(int i = 0; i <= MAX_VALOR; i++){
        if(contador[i] > 1){
            printf("%d foi repetido %d vezes\n", i, contador[i]);
        }
    }
}

int criar_array_unico(float v[], int tam, float novo_array[]){
    int i, j, existe;
    int indice = 0;

    for(i = 0; i < tam; i++){
        existe = 0;

        for (j = 0; j < indice; j++) {
            //coparacao para floats
            if(fabs(v[i] - novo_array[j]) < 0.0001){
                existe = 1;
                break;
            }
        }

        if(!existe){
            novo_array[indice] = v[i];
            indice++;
        }
    }

    return indice;
}


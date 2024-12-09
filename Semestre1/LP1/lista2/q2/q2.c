/*
-- 2° Questão da lista de Exercícios, Linguagens de Programação I
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
#define MAX_VALOR 1000

//declarando funções
void insertion_sort(int v[]);
void listar_reps(int v[]);
float fuc_media(int v[], int tam);
float fuc_desvio_padrao(int v[], float media, int tam);
int criar_array_unico(int v[], int tam, int novo_array[]);


int main(){
    int arr[TAM];
    float media, mediana, desvio;

    srand(time(NULL));

    //preenchendo o array com valores aleatorios entre 0 e 1000
    for(int i = 0; i < TAM; i++){
        arr[i] = rand() % 1001;
    }

    //ordenar array
    insertion_sort(arr);

    printf("---------------------------\n");
    printf("      Primeira parte \n");
    printf("---------------------------\n");

    printf("Os três maiores termos são: %d %d %d\n", arr[TAM-1], arr[TAM-2], arr[TAM-3]);
    printf("Os três menores elementos são: %d %d %d\n", arr[0], arr[1], arr[2]);
    printf("---------------------------\n");

    //chamando a função que calcula a media
    media = fuc_media(arr, TAM);
    printf("média: %.2f\n", media);

    //chamando a função que calcula a mediana
    mediana = (arr[4999] + arr[5000]) / 2;
    printf("mediana: %.2f\n", mediana);

    //chamando a função que calcula o desvio
    desvio = fuc_desvio_padrao(arr, media, TAM);
    printf("desvio padrão: %.2f\n", desvio);

    printf("---------------------------\n");
    printf("      Segunda parte \n");
    printf("---------------------------\n");

    //chama a função que mostra a quant de repetições de cada número
    listar_reps(arr);
    printf("---------------------------\n");
    printf("Array unico: \n");

    int arr_unico[TAM];
    int novo_tamanho = criar_array_unico(arr, TAM, arr_unico);

    for(int j = 0; j < novo_tamanho; j++){
        printf("%d ", arr_unico[j]);
    }

    printf("\n---------------------------\n");

    //chamando a função que calcula a media
    media = fuc_media(arr_unico, novo_tamanho);
    printf("média: %.2f\n", media);

    //chamando a função que calcula a mediana
    mediana = ((arr_unico[novo_tamanho / 2 - 1] + arr_unico[novo_tamanho / 2]) / 2);
    printf("mediana: %.2f\n", mediana);

    //chamando a função que calcula o desvio
    desvio = fuc_desvio_padrao(arr_unico, media, novo_tamanho);
    printf("desvio padrão: %.2f\n", desvio);


    return 0;
}

//-- funções --//

//Função Insertion Sort, ordena o vetor na ordem crescente
void insertion_sort(int v[]){
    int i, j, aux; 

    for(i = 1; i < TAM; i++){
        aux = v[i];
        j = i - 1;

        while((j >= 0) && (aux < v[j])){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = aux;
    }
}

float fuc_media(int v[], int tam) {
    float soma = 0;

    for (int i = 0; i < tam; i++){
        soma += v[i];
    }

    //returna a media
    return soma / tam;
}

float fuc_desvio_padrao(int v[], float media, int tam){
    float soma_diferencas_quadradas = 0;

    for (int i = 0; i < tam; i++){
        soma_diferencas_quadradas += pow(v[i] - media, 2);
    }

    //retorna o desvio padrão
    return sqrt(soma_diferencas_quadradas / tam);
}

void listar_reps(int v[]){
    int contador[MAX_VALOR + 1] = {0};

    // Contar a frequência de cada número
    for (int i = 0; i < TAM; i++) {
        contador[v[i]]++;
    }

    // Listar os valores repetidos e sua frequência
    printf("Valores repetidos e suas quantidades:\n");
    for (int i = 0; i <= MAX_VALOR; i++) {
        if (contador[i] > 1) {
            printf("%d foi repetido %d vezes\n", i, contador[i]);
        }
    }
}

// Função para criar um novo array com valores únicos
int criar_array_unico(int v[], int tam, int novo_array[]){
    int i, j, existe;
    int indice = 0;

    for(i = 0; i < tam; i++){
        existe = 0;

        //verifica se o valor já existe no novo array
        for(j = 0; j < indice; j++){
            if(v[i] == novo_array[j]){
                existe = 1;
                break;
            }
        }

        //se o valor não existir no novo array, adiciona
        if(!existe){
            novo_array[indice] = v[i];
            indice++;
        }
    }

    //retorna o novo tamanho
    return indice;
}
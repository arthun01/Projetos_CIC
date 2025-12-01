// Implementação do Algoritmo de Busca Binária
// 1° Forma: Iterativa usando While
// 2° Forma: Recursiva mudando os parâmetros

#include <stdio.h>
#include <stdlib.h>

/*
    buscaBinaria
    recebe: um vetor, o tamanho do vetor, valor a ser encontrado
    retorna: -1 se não achou nada, se achar o valor retorna o indice
*/
int buscaBinaria(int vetor[], int n, int chave){
    // inicio, fim e meio pois a buscaBinaria vai dividindo o vetor ao meio
    int inicio = 0;
    int fim = n - 1;
    int meio;


    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        printf("Verificando indice: %d (Valor: %d)\n", meio, vetor[meio]);


        if(vetor[meio] == chave){
            return meio;
        }else if(vetor[meio] < chave){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }

    }

    // se não achar
    return -1;
}

/*
    buscaBinariaRec
    recebe: um vetor, o inicio(0), o fim(tamanho-1), valor a ser encontrado
    retorna: -1 se não achou nada, se achar o valor retorna o indice
*/
int buscaBinariaRec(int vetor[], int inicio, int fim, int chave){
    // caso em que não achamos nada
    if(inicio > fim){
        return -1;
    }

    // calculando o meio
    int meio = (inicio + fim) / 2;

    // casos recursivos
    if(vetor[meio] == chave){
        return meio;
    }else if(vetor[meio] < chave){
        buscaBinariaRec(vetor, meio + 1, fim, chave);
    }else{
        buscaBinariaRec(vetor, inicio, meio - 1, chave);
    }
}

int main(void){
    int dados[] = {5, 12, 18, 23, 32, 45, 56, 78, 89, 100};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    int valorProcurado = 12;

    // int resultado = buscaBinariaRec(dados, 0, tamanho - 1, valorProcurado);
    int resultado = buscaBinaria(dados, tamanho, valorProcurado);

    if(resultado != -1){
        printf("\nSucesso! Valor encontrado no indice: %d\n", resultado);
    }else{
        printf("\nValor não encontrado no vetor.\n");
    }

    return 0;
}
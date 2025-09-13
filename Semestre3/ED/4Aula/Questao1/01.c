// Autor: Arthur Ramos Vieira
// Estrutura de Dados, CIC 2025.2

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Declaração da struct do intervalo
typedef struct{
    int pontoInicial;
    int pontoFinal;
} Intervalo;


// protótipos
Intervalo adicionar_ponto(Intervalo intervalos[]);
void verificar_ponto(int valor_ponto, Intervalo intervalos[]);
void printar_intervalos(Intervalo intervalos[]);

// função principal (main)
int main(void){
    int valorPonto;

    // declaração do array e "zerando" todos em -1
    Intervalo intervalos[MAX];

    for(int i = 0; i < MAX; i++){
        intervalos[i].pontoInicial = -1;
        intervalos[i].pontoFinal = -1;
    }

    // menu com as opções
    int opt = -1;

    do{
        printf("Escolha uma opção:\n");
        printf("0. Sair\n");
        printf("1. Adicionar Ponto\n");
        printf("2. Verificar ponto\n");
        printf("Escolha: ");
        scanf("%d", &opt);


        switch(opt){
        case 0:
            break;
        case 1:
            adicionar_ponto(intervalos);
            break;
        case 2:
            scanf("%d", &valorPonto);
            verificar_ponto(valorPonto, intervalos);
            break;
        }
    }while(opt != 0);

    printar_intervalos(intervalos);

    return 0;
}

// ---------------

// função printar_intervalos
// parametros: o array de structs
// retorno: nenhum
void printar_intervalos(Intervalo intervalos[]){
    for(int i = 0; i < MAX; i++){
        printf("[%2d, %2d]\n", intervalos[i].pontoInicial, intervalos[i].pontoFinal);
    }
}

// função adicionar_ponto
// parametros: array de structs
// retorno: o proprio array de struct com intervalo novo
Intervalo adicionar_ponto(Intervalo intervalos[]){
    int pontoInicial;
    int pontoFinal;

    // verificação se p1 é maior que p2
    do{
        scanf("%d %d", &pontoInicial, &pontoFinal);
    }while(pontoInicial > pontoFinal);

    int espacoVazio = 0;
    for(int i = 0; i < MAX; i++){
        if(intervalos[i].pontoInicial == -1 && intervalos[i].pontoFinal == -1){
            // achamos um espaço vazio!!
            espacoVazio = i;
            break;
        }
    }

    intervalos[espacoVazio].pontoInicial = pontoInicial;
    intervalos[espacoVazio].pontoFinal = pontoFinal;

    return intervalos[MAX];
}

// função verificar_ponto
// parametro: valor do ponto e array de structs
// retorno: nenhum
void verificar_ponto(int valor_ponto, Intervalo intervalos[]){
    int encontrou = 0;

    for(int i = 0; i < MAX; i++){
        if(valor_ponto >= intervalos[i].pontoInicial && valor_ponto <= intervalos[i].pontoFinal){
            printf("Dentro do intervalo [%d, %d]\n", intervalos[i].pontoInicial, intervalos[i].pontoFinal);
            encontrou++;
        }
    }

    if(encontrou == 0){
        printf("Fora de todos os intervalos\n");
    }
}
/*
- Linguagem de Programação I, Ciência da Computação 2024.2
- Docente: Marcelo Honda
- Discente: Arthur Ramos Vieira
- Algoritmo: Cálculo de IMC usando Struct e Funções
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float peso;
    float altura;
    float imc;
} IMC;

//Função para ler os dados da Struct
void ler_dados(IMC pessoas[], int quant){
    for(int i = 0; i < quant; i++){

        printf("Nome da pessoas %d: ", i+1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);


        printf("== IMC - %s\n", pessoas[i].nome);

        printf("- Peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("- Altura: ");
        scanf("%f", &pessoas[i].altura);

        //limpando buffer dos scanfs
        while (getchar() != '\n');

        printf("----------------------------\n");
    }
}

//Função para calcular os dados da struct
void calc_imc(IMC pessoas[], int quant){
    for(int j = 0; j < quant; j++){
        //fórmula do IMC de fato
        pessoas[j].imc = pessoas[j].peso / (pessoas[j].altura * pessoas[j].altura);
    }
}

void esc_dados(IMC pessoas[], int quant){
    printf("==== RESULTADOS ====\n");

    //Mostrando os resultados
    for(int k = 0; k < quant; k++){
        printf("-> %s", pessoas[k].nome);

        printf("Peso: %.2f kg\n", pessoas[k].peso);
        printf("Altura: %.2f m\n", pessoas[k].altura);

        printf("IMC = %.2f\n", pessoas[k].imc);

        //Calculo das faixas
        if(pessoas[k].imc < 18.49){
            printf("-> abaixo do Peso\n");
        }else if(pessoas[k].imc > 18.5 && pessoas[k].imc < 25){
            printf("-> peso normal\n");
        }else if(pessoas[k].imc > 25.1 && pessoas[k].imc < 30){
            printf("-> sobrepeso\n");
        }else if(pessoas[k].imc >= 30){
            printf("-> obesidade\n");
        }

        printf("-----------------------------\n");
    }
}

//Função Main (principal)
int main(){
    int quant;
    
    //Quantas pessoas calcularemos o IMC
    printf("Digite quantas Pessoas: ");
    scanf("%d", &quant);
    printf("-----------------------------\n");

    //limpar o buffer do scanf
    while (getchar() != '\n');

    IMC pessoas[quant];

    //Chamando as funções
    ler_dados(pessoas, quant);
    calc_imc(pessoas, quant);
    esc_dados(pessoas, quant);

    return 0;
}
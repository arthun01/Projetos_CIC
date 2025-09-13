// Autor: Arthur Ramos Vieira (202420022)

// Biblioteca padrão de entrada e saída de Dados
#include <stdio.h>

// Biblioteca para funções Matemáticas (sqrt, pow)
#include <math.h>

// Calcula e retorna a 1° raiz
// Recebe como três parâmetros os coeficientes em tipo ponto flutuante
float calcular_raiz1(float a, float b, float c){
    float delta = ((pow(b, 2)) - (4 * a * c));
    float raiz = -b + sqrt(delta);

    raiz = (raiz / (2 * a));

    return raiz;
}

// Calcula e retorna a 2° raiz
// Recebe como três parâmetros os coeficientes em tipo ponto flutuante
float calcular_raiz2(float a, float b, float c){
    float delta = ((pow(b, 2)) - (4 * a * c));
    float raiz = -b - sqrt(delta);

    raiz = (raiz / (2 * a));

    return raiz;
}

// Valida se o coeficiente A está correto e o Delta da Função
int validacao(float a, float b, float c){
    float delta = ((b * b) - (4 * a * c));
    
    if(a == 0 || delta < 0){
        return 0;
    }
}

// Função principal e primária
int main(void){
    // Declaração dos Coeficientes
    float a, b, c;

    // Declaração das raizes
    float raiz1, raiz2;

    // Entrada de Dados
    printf("Digite uma função quadrática: ");
    scanf("%f %f %f", &a, &b, &c);

    // Verificação das Entradas (o intervalo de cada coeficiente)
    if((a <= 0.1 || a >= 10.0) || (b <= -1000.0) && (c >= 1000.0)){
        printf("Entrada de dados errada!\n");
        return 0;
    }

    // Chamo a função 'verificacao' e se for 'impossível', fecho o programa
    if(validacao(a, b, c) == 0){
        printf("Impossível calcular\n");
        return 0;
    }

    // Chamada das funções que calcula as Raizes
    raiz1 = calcular_raiz1(a, b, c);
    raiz2 = calcular_raiz2(a, b, c);

    // Saída do Resultado esperado
    printf("Raiz 1: %.5f\n", raiz1);
    printf("Raiz 2: %.5f\n", raiz2);

    return 0;
}
// Autor: Arthur Ramos Vieira (202420022)

// Biblioteca padrão
#include <stdio.h>

// Procedimento que da como saída o Quadrante e a Quantidade de Voltas
void quadrante(float angulo){
    // Variável responsável por armazenar as voltas
    int count = 0;
    
    // Verificação se o ângulo é maior que 360
    // Se sim, contamos as voltas e diminuimos 360 de cada iteração
    if(angulo >= 360){
        while(angulo >= 360){
            angulo = angulo - 360;
            count++;
        }
    }
    
    // Após ter um ângulo agora menor que 360
    // IFs para determinar o Quadrante (Saída)
    if(angulo <= 0 && angulo < 90){
        printf("QUADRANTE: Primeiro Quadrante\n");
    }else if (angulo <= 90 && angulo < 180){
        printf("QUADRANTE: Segundo Quadrante\n");
    }else if (angulo <= 180 && angulo < 270){
        printf("QUADRANTE: Terceiro Quadrante\n");
    }else if (angulo <= 270 && angulo < 360){
        printf("QUADRANTE: Quarto Quadrante\n");
    }

    // Quantidade de Voltas (Saída)
    printf("QUANTIDADE DE VOLTAS: %d\n", count);
}

int main(void){
    // Declaração do Ângulo como real
    float R;

    // Leitura do Teclado
    scanf("%f", &R);

    // Validação da Entrada
    if(R <= 0 || R >= 1000000000){
        return 0;
    }

    // Chama o Procedimento que mostrará as Saídas
    quadrante(R);
    
    return 0;
}
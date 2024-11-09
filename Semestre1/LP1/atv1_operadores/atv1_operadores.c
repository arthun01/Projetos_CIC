/*
    1° Atividade LP1

    Atividades tipos e operadores matemáticos

    - Imprima resultado de operações matemáticas (pesquisar todos operadores)
    - usar precedência de operadores
*/

#include <stdio.h>

int main(){
    int a, b;

    a = 10;
    b = 20;

    printf("Usaremos A e B como variáveis inteiras, A = 10 e B = 20\n");
    printf("========================================================\n");

    printf("A soma de B + A é igual a %d\n", b+a);
    printf("A subtração de B - A é igual a %d\n", b-a);
    printf("A multiplicação de B x A é igual a %d\n", b*a);
    printf("A divisão de B / A é igual a %d\n", b/a);
    printf("O resto da divisão de B e A é igual a %d\n", b%a);
    printf("O incremento de A é igual a %d\n", a++);
    printf("O decremento de A é igual a %d\n", a--);

    printf("--------------------------------------------------------\n");

    int x = 30;
    char carac = 'C';
    float pi = 3.14;
    double euler = 2.718281828459045;

    printf("A variável 'X' do tipo inteiro: %d\n", x);
    printf("A variável 'carac' do tipo char: %c\n", carac);
    printf("A variável 'pi' do tipo float: %f\n", pi);
    printf("A variável 'euler' do tipo double: %lf\n", euler);
    printf("--------------------------------------------------------\n");
    printf("A soma de A + X é igual a: %lf\n", a+pi);
    printf("A soma de 'carac' + 'x' é igual a: %c\n", carac+x);
    printf("A soma de 'pi' + 'euler' é igual a: %f\n", pi+euler);

    printf("Precedencia de operadores matemáticos\n");
    printf("--------------------------------------------------------\n");
    printf("A média entre A e B é igual a: %d\n", (a+b)/2);
    printf("A Subtração de A e B multiplicado por 3 é igual a: %d\n", (a-b)*3);
    printf("O resto da divisão de B e A soma com 'pi' é igual a: %f\n", (b%a)+pi);
    printf("20 porcento de A multiplicado por 40 porcento de B é igual a: %.2f\n", ((a*0.2)*(b*0.4)));

    printf("========================================================\n");

    return 0;
}





















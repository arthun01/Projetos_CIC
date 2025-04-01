/*Exercício 4: Modificar Valor via Ponteiro
Escreva um programa que declare uma variável int numero = 100 e um ponteiro int *p que aponte para numero. Use o ponteiro para alterar o valor de numero para 200.*/

#include <stdio.h>

int main(void){
    int numero = 100;
    int* ptr = &numero;

    printf("número: %d\n", numero);
    printf("trocando valor....\n");

    *ptr = 200;
    printf("número: %d\n", numero);

    return 0;
}
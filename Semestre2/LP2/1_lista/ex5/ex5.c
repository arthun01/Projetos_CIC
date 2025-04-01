/* Exercício 5: Tamanho de Tipos com Ponteiros
Use o operador sizeof para imprimir o tamanho (em bytes) de um int, float, char e double através de ponteiros. */

#include <stdio.h>

int main(void){

    int* p_int;
    float* p_float;
    char* p_char;
    double* p_double;

    printf("Tamanho de int: %zu bytes\n", sizeof(*p_int));
    printf("Tamanho de float: %zu bytes\n", sizeof(*p_float));
    printf("Tamanho de char: %zu bytes\n", sizeof(*p_char));
    printf("Tamanho de double: %zu bytes\n", sizeof(*p_double));

    return 0;
}
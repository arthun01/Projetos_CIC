#include <stdio.h>

int troca_valor(int*, int*);

int main(void){

    int a = 5;
    int b = 4;

    printf("A: %d e B: %d\n", a, b);
    troca_valor(&a, &b);
    printf("A: %d e B: %d\n", a, b);

    return 0;
}

int troca_valor(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
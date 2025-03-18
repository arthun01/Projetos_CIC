#include <stdio.h>

void soma(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
}

void soma_cp_sr(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}

int soma_sp_cr(void){
    int a, b;
    scanf("%d %d", &a, &b);
    
    return a + b;
}

int soma_cp_cr(int a, int b){
    return a + b;
}

void soma_vetor (int arr[]){
    printf("%d + %d = %d\n", arr[0], arr[1], arr[0] + arr[1]);
}


int main(void){
    int vetor[2] = {120, 2};
    soma_vetor(vetor);
    printf("--------\n");

    soma();
    printf("--------\n");

    soma_cp_sr(4, 8);
    printf("--------\n");

    printf("%d\n", soma_sp_cr());
    printf("--------\n");

    printf("%d\n", soma_cp_cr(10, 20));
    printf("--------\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b);
int subs(int a, int b);
int mult(int a, int b);
int divi(int a, int b);


int main(void){
    int ans = 0;

    int a, b;
    scanf("%d %d", &a, &b);

    printf("Qual operação você quer?\n[1] SOMA\n[2] SUBTRAÇÃO\n[3] MULTIPLICAÇÃO\n[4] DIVISÃO || Resposta: ");
    scanf("%d", &ans);
    

    switch(ans){
        case 1:
            printf("soma: %d\n", soma(a,b));
            break;
        case 2:
            printf("subtração: %d\n", subs(a,b));
            break;
        case 3:
            printf("multiplicação %d\n", mult(a,b));
            break;
        case 4:
            printf("divisão %d\n", divi(a,b));
            break;
        break;
    }

    return 0;
}

int soma(int a, int b){
    return a+b;
}

int subs(int a, int b){
    return a-b;
}

int mult(int a, int b){
    return a*b;
}

int divi(int a, int b){
    a = a/b;

    return a;
}
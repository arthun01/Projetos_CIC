#include <stdio.h>

int is_odd(int num){
    if(num & 1){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    int x;

    printf("Digite um número: ");
    scanf("%d", &x);

    printf("O número %d é %d\n", x, is_odd(x));

    return 0;
}
#include <stdio.h>

int count_set_bits(int num){
    
    int c = 0;

    for(int i = 0; i < (sizeof(int) * 8); i++){
        if((num & 1) == 1){
            c++;
        }
        num = num >> 1;
    }

    return c;
}

/*
20 - 10100
05 - 00101
---------->> 2

*/


int main(void){
    int x;

    printf("Digite um número: ");
    scanf("%d", &x);

    printf("tem %d bits no número %d\n", count_set_bits(x), x);

    return 0;
}
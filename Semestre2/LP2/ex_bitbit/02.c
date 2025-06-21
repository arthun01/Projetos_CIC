//verifique se um número é multiplo de 4 sem usar % (Dica: analise os 2 bits menos significativos)


/*
multiplos de 4
4 8 12 16 20

020 - 10100
003 - 00011
-----------
and - 00000
*/

#include <stdio.h>

int is_multiple_of_4(int num){
    unsigned char tres = 0b00000011;

    if (num & tres){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    int x;

    printf("Digite um número: ");
    scanf("%d", &x);

    if(is_multiple_of_4(x) == 0){
        printf("O número %d é multiplo de 4\n", x);
    }else{
        printf("O número %d não é multiplo de 4\n", x);
    }

    return 0;
}
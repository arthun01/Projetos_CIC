/*estudar operador bit a bit*/

#include <stdio.h>

int main(void){
    unsigned char valor = 0b1100100;
    unsigned char mascara2 = 0b0000100;
    unsigned char mascara3 = 0b0001100;

    int a = 5;
    int b = 4;

    b:
    04 -> 00000100

    */

    a = a << 2;
    b = b <


    /*
    a:
    05 -> 00000101
    20 -> 00010100<

    b:
    04 -> 00000100
    64 -> 01000000
    */

    a = a << 2;
    b = b << 4;

    printf("a: %d\tb: %d\n", a, b);

    if ((valor & mascara2) & (valor & mascara3)){
        printf("Bit 2 e 3 está ligado.\n");
    }else{
        printf("erro\n");
    }


    return 0;
}
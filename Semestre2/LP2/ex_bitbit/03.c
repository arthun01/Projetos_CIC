#include <stdio.h>

void swap(int* a, int* b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(void){
    int a = 7;
    int b = 10;

    printf("%d %d agora vira....\n", a, b);

    swap(&a, &b);

    printf(".... %d %d\n", a, b);

    return 0;
}
#include <stdio.h>

int* trocar(int* q){
    int y = 7;
    q = &y;
    *q = y;

    return q;
}

int main(void){
    int x = 10;
    //int y = 20;

    int* ptr = NULL;
    ptr = &x;
    printf("&x: %p | ptr: %p | *ptr: %d\n", (void*)&x, (void*)ptr, *ptr);

    ptr = trocar(ptr);
    printf("&x: %p | ptr: %p | *ptr: %d\n", (void*)&x, (void*)ptr, *ptr);

    return 0;
}
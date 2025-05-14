#include <stdio.h>

int main(void){
    int* ptr;
    int var = 8;

    ptr = &var;

    printf("end var: %p\n", (void*)&var);
    printf("end ptr: %p\n", (void*)&ptr);
    printf("content var: %d\n", var);
    printf("content ptr: %p\n", (void*)ptr);
    printf("content de var para onde ptr aponta: %d\n", *ptr);

    return 0;
}
#include <stdio.h>

void trocar(int** a, int** b){
    int* temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int x = 10, y = 20;
    int* ptr1 = &x;
    int* ptr2 = &y;

    printf("Antes da troca:\nA = %d | B = %d\n", *ptr1, *ptr2);
    printf("ptr1 aponta para %p, ptr2 aponta para %p\n", ptr1, ptr2);

    trocar(&ptr1, &ptr2);

    printf("Depois da troca:\nA = %d | B = %d\n", *ptr1, *ptr2);
    printf("ptr1 aponta para %p, ptr2 aponta para %p\n", ptr1, ptr2);

    return 0;
}
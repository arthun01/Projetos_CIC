#include <stdio.h>

int fatorial(int n){
    if(n == 1){
        return 1;
    }
    return n * fatorial(n - 1);
}


int main(void){

    int x;
    printf("Um número: ");
    scanf("%d", &x);

    printf("!%d = %d\n", x, fatorial(x));

    return 0;
}
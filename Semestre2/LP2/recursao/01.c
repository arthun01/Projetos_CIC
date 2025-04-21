#include <stdio.h>

void binario(int n){
    int div = n;
    int rest = 0;

    if(div == 0){
        return ;
    }else{
        div = n / 2;
        rest = n % 2;
        printf("Empilha - ");
        binario(div);
        printf("\nDesempilha: ");
        printf("%d ", rest);
    }
}

int main(void){
    int a;
    scanf("%d", &a);

    binario(a);

    return 0;
}
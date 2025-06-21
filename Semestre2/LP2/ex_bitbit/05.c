#include <stdio.h>

int is_power_of_2(int num){
    if((num & (num - 1)) == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    int x;

    printf("Digite um número: ");
    scanf("%d", &x);

    int resp = is_power_of_2(x);

    if(resp == 1){
        printf("sim\n");
    }else{
        printf("não\n");
    }


    return 0;
}
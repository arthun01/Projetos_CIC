#include <stdio.h>
#include <math.h>

int sum_digits(int n){
    if(n == 1){
        return 1;
    }else if(n == 0){
        return 0;
    }else{
        return n + sum_digits(n - 1);
    }
}

int main(void){
    int N;
    scanf("%d", &N);

    if(N >= 0 && N <= pow(10,9)){
        printf("%d\n", sum_digits(N));
    }

    return 0;
}
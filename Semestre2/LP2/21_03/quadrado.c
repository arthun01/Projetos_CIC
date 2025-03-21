#include <stdio.h>

int quad_fech(int);

int quad_topefim(int);
int quad_vaza(int);

int tria_ret(int);

int main(void){

    int n;

    printf("N: ");
    scanf("%d", &n);

    quad_fech(n);
    printf("----------------\n");


    quad_vaza(n);
    printf("----------------\n");

    tria_ret(n);

    return 0;
}

int quad_fech(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
}

int quad_topefim(int n){
    for(int i = 0; i < n; i++){
        printf("*");
    }
    printf("\n");
}

int quad_vaza(int n){
    quad_topefim(n);

    for(int i = 0; i < n; i++){
        printf("*");
        for(int j = 0; j < n-2; j++){
            printf(" ");
        }
        printf("*\n");
    }

    quad_topefim(n);
}

int tria_ret(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i+1; j++){
            printf("*");
        }
        printf("\n");
    }
}
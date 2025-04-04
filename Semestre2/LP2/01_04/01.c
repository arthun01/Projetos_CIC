#include <stdio.h>

int main(void){
    int vec0[] = {10, 11, 12};
    int vec1[] = {20, 21, 22, 23};
    int* p[] = {vec0, vec1};

    for(int i = 0; i < 2; i++){
        int vec_size = (i == 0) ? sizeof(vec0) / sizeof(int) : sizeof(vec1) / sizeof(int);

        for(int j = 0; j < vec_size; j++){
            printf("%5d", *(*(p + i) + j));
        }
        printf("\n");
    }


    return 0;
}
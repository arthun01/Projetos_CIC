#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 30

int main(void){
    srand(time(NULL));

    FILE* ptr_arq;

    ptr_arq = fopen("nums.dat", "wb");

    if(ptr_arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    //-------------------------

    long int array[TAM];

    int min = 101;
    int max = 10000;
    
    for(int i = 0; i < TAM; i++){
        array[i] = min + rand() % (max - min + 1);
    }

    size_t quant_elems = sizeof(array) / sizeof(array[0]);

    size_t elementos_escritos = fwrite(array, sizeof(long int), TAM, ptr_arq);


    
    fclose(ptr_arq);

    return 0;
}
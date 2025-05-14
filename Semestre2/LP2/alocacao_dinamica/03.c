#include <stdio.h>
#include <stdlib.h>

#define TAML 4
#define TAMC 3

int main(void){
    //criando um ponteiro duplo para as linhas
    int** ptr_linha;

    //criando um ponteiro para as colunas
    int* ptr_col;

    int x = 10;

    //declarando as linhas 
    ptr_linha = (int**)malloc(TAML * sizeof(int*));

    if(ptr_linha == NULL){
        printf("Erro!!!!\n");
        return 1;
    }
    

    ptr_col = (int*)malloc(TAMC * sizeof(int));


    free(ptr_linha);

    return 0;
}
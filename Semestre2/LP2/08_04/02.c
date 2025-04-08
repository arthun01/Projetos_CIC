#include <stdio.h>

void funcaoRecursiva(int chamarRecursivo){
    printf("Chamada com: %d\n", chamarRecursivo);

    if(!chamarRecursivo){
        // CASO BASE
        printf("Retornando do caso base.\n");
        return;
    }else{
        // CASO RECURSIVO
        funcaoRecursiva(0);
        printf("Retornando do caso recursivo\n");
        return;
    }
}

int main(){
    printf("Chamando com 0: \n");
    funcaoRecursiva(0);

    printf("\nChamando com 1: \n");
    funcaoRecursiva(1);

    return 0;
}
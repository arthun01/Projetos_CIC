#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char placa_veiculo[10];
    char modelo_veiculo[10];
    int ano_veiculo;
} Veiculo;

int main(void){
    int opt;

    do{
        printf("Menu de Opções:\n");
        printf("0. Registrar Veículo\n");
        printf("1. Listar Veículo\n");
        printf("2. Buscar Veículo pela Placa\n");
        printf("3. Remover Veículo pela Placa\n");
        printf("4. Sair\n");

        scanf("%d", &opt);
    }while(opt != 0);

    


}
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* ptr_arq;

    ptr_arq = fopen("log.txt", "w");

    if(ptr_arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    //printar no arquivo
    fprintf(ptr_arq, "Olá, mundo dos arquivos!!\n");
    fprintf(ptr_arq, "Esta é a primeira linha.\n");
    fprintf(ptr_arq, "Botando Inteiro %d\n", 123);
    fprintf(ptr_arq, "Olha um float agora %.2f\n", 45.67);

    //fechar o arquivo para salvar as alterações
    fclose(ptr_arq);

    printf("Arquivo 'log.txt" criado e escrito com sucesso!!\n);

    return 0;
}
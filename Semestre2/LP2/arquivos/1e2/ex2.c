#include <stdio.h>
#include <stdlib.h>

#define TAM_LINHA 256

void printar_arq(FILE*);

int main(void){
    FILE* ptr_arq;
    char linha[TAM_LINHA];

    ptr_arq = fopen("log.txt", "r"); // "r" -> Read

    if(ptr_arq == NULL){
        printf("Erro: Não foi possível abrir o arquivo 'log.txt'.\n");
        exit(1);
    }

    printf("Conteúdo do arquivo 'log.txt':\n");
    printf("------------------------------\n");

    printar_arq(ptr_arq);
    fclose(ptr_arq);

    int ans;
    printf("Você quer adicionar informação ao arquivo?\n[1] SIM\n[2] NÃO || Resposta: ");
    scanf("%d", &ans);

    if(ans == 1){

        ptr_arq = fopen("log.txt", "a"); // "a" -> append

        if(ptr_arq == NULL){
            printf("Erro ao acessar o arquivo.\n");
            exit(1);
        }

        fputs("\n--- Informações Adicionais ---\n", ptr_arq);
        fprintf(ptr_arq, "Esta linha foi adicionada depois.\n");
        fprintf(ptr_arq, "O modo 'a' é muito útil para logs.\n");
    }else{
        fclose(ptr_arq);
    }


    //fclose(ptr_arq);

    return 0;
}

void printar_arq(FILE* ptr_arq){
    char linha[TAM_LINHA];

    while(fgets(linha, sizeof(linha), ptr_arq) != NULL){
        printf("%s", linha);
    }
    printf("-------------------------------\n");
}
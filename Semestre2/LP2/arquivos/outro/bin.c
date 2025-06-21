#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nome[50];
    float media;
} Aluno;

int main(void){
    FILE* arquivo;

    Aluno alunos_para_gravar[2] = {
        {10, "Joao Silva", 8.5f},
        {20, "Maria Souza", 9.2f},
    };

    //escrita binária
    arquivo = fopen("alunos.dat", "wb"); // "wb" -> Write Binary
    if(arquivo == NULL){
        printf("Erro ao criar o arquivo binário.\n");
        exit(1);
    }

    //escrever o array inteiro de alunos de uma só vez
    //parametros: ponteiro para os dados, tamanho de um elemento, número de elementos, arquivos 
    fwrite(alunos_para_gravar, sizeof(Aluno), 2, arquivo);
    fclose(arquivo);
    
    printf("Arquivo 'alunos.dat' gravado com sucesso!\n\n");

    //-- Leitura Binária --
    arquivo = fopen("alunos.dat", "rb"); // "rb" -> Read Binary
    if(arquivo == NULL){
        printf("Erro ao ler o arquivo binário.\n");
        exit(1);
    }

    Aluno alunos_lidos[2];
    //le os dados do arquivo para o nosso array
    fread(alunos_lidos, sizeof(Aluno), 2, arquivo);
    fclose(arquivo);

    printf("Lendo dados do arquivo binário:\n");
    for(int i = 0; i < 1; i++){
        printf("Aluno ID: %d\n", alunos_lidos[i].id);
        printf("Nome: %s\n", alunos_lidos[i].nome);
        printf("Média: %.2f\n", alunos_lidos[i].media);
    }


    return 0;
}
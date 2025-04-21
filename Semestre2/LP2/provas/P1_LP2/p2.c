/*
P2 - Estrutura para cadastro de 3 alunos
utilizando aritmética de ponteiros

Nome
Idade
Sexo
CR

mostrar a saida ordenando por CR

Arthur Ramos Vieira
N° de Matrícula: 202420022
*/

#include <stdio.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo[40];
    float cr;
} Cadastro;

void prn_aluno(Cadastro* aluno){
    for(int i = 0; i < 3; i++){
        printf("Nome: %s\t|", (aluno + i)->nome);
        printf("Idade: %d\t|", (aluno + i)->idade);
        printf("Sexo: %s\t|", (aluno + i)->sexo);
        printf("CR: %.2f\t|", (aluno + i)->cr);

        printf("\n");
    }
}

Cadastro le_aluno(){
    Cadastro aluno;

    //Entradas
    printf("Nome Aluno: ");
    scanf(" %49[^\n]*c", aluno.nome);
    getchar();

    printf("Idade Aluno: ");
    scanf("%d", &aluno.idade);
    getchar();

    printf("Sexo Aluno: ");
    scanf(" %39[^\n]*c", aluno.sexo);

    printf("CR Aluno: ");
    scanf("%f", &aluno.cr);

    printf("------------------------\n");

    return aluno;
}

void ordenar_alunos(Cadastro* aluno){
    Cadastro temp;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            if(aluno[i].cr > aluno[j].cr){
                temp = (*(aluno + i));
                (*(aluno + i)) = (*(aluno + j));
                (*(aluno + j)) = temp;
            }
        }
    }
}

int main(void){
    Cadastro aluno[3];

    for(int i = 0; i < 3; i++){
        *(aluno + i) = le_aluno();
    }

    printf("=== DADOS ORIGINAIS ===\n");
    prn_aluno(aluno);

    ordenar_alunos(aluno);

    printf("==== DEPOIS DA ORDENAÇÃO ====\n");
    prn_aluno(aluno);

    return 0;
}
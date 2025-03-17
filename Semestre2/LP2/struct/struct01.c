#include <stdio.h>

#define TAM 3

int main(){

    typedef struct {
        char nome[50];
        int data[3];
        float salario;
    }Cadastro;

    /*quando eu uso typedef struct eu crio um novo tipo de dado
    com o nome cadastro ai não preciso repetir o nome strcut
    */

   //meio que assim:
   /*
    
    struct Cadastro{
        char nome[10];
        int data[3];
        float salario;
    };

    struct Cadastro empregado[5];

   */

    //typedef struct Cadastro Cadastro;
    Cadastro empregado[TAM];

    for(int i = 0; i < TAM; i++){
        printf("Nome %d: ", i+1);
        scanf("%s", empregado[i].nome);

        printf("Dia: ");
        scanf("%d", &empregado[i].data[0]);

        printf("Mês: ");
        scanf("%d", &empregado[i].data[1]);

        printf("Ano: ");
        scanf("%d", &empregado[i].data[2]);

        printf("Salário: R$");
        scanf("%f", &empregado[i].salario);

        printf("------------------------------\n");
    }

    for(int i = 0;i < TAM; i++){
        printf("'%-15s'", empregado[i].nome);
        printf("%02i/%02i/%4i",   empregado[i].data[0],
                                    empregado[i].data[1],
                                    empregado[i].data[2]);
        printf("'%10.2f'\n", empregado[i].salario);
    }

    return 0;
}
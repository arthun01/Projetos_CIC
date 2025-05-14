#include <stdio.h>
#include <stdlib.h>

int main(void){
    //criando um vetor de ponteiros
    int* vetor;

    //declarando i para usar no for e num_comps para pegar quanto de espaço criarei dinamicamente
    int i, num_comps;

    //pegando num_comps para ver quanto espaço precisarei
    printf("Informe o número de componentes: ");
    scanf("%d", &num_comps);

    //declarando o vetor em heap usaando o malloc e aloco nums_comps * o tamanho do tipo que quero alocar
    vetor = (int*)malloc(num_comps * sizeof(int));

    //vendo se o ponteiro está NULL, ou seja, se o malloc deu errado, pois se o malloc deu errado ele aterra o ponteiro com NULL
    if(vetor == NULL){
        printf("Erro!!!!\n");
        return 1;
    }

    //for para ler os valores
    for(i = 0; i < num_comps; i++){
        printf("Valor da posição %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("valores em vetor dinamicos\n\n");

    //for para printar os valores
    for(i = 0; i < num_comps; i++){
        printf("%d\n", vetor[i]);
    }

    //liberando a memória do vetor dinamico
    free(vetor);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 1001

int resolve(char* expressao){
    int tamanho = strlen(expressao);
    int qtd_abertos = 0;

    for(int i = 0; i < tamanho; i++){
        if(expressao[i] == '('){
            qtd_abertos++;
        }else if(expressao[i] == ')'){
            if(qtd_abertos > 0){
                qtd_abertos--;
            }else{
                return 0;
            }
        }
    }

    if(qtd_abertos == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char expressao[TAM];
    int correto;

    while(fgets(expressao, TAM, stdin)){
        correto = resolve(expressao);

        if(correto == 1){
            printf("Sim\n");
        }else{
            printf("Não\n");
        }
    }

    return 0;
}
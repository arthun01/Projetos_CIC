/*
Fazer uma função recuriva que receba como parametro
uma string e printe ela ao contrário, por exemplo:
-> carro -> orrac
*/

#include <stdio.h>

void reverso (char palavra[], int tamanho){
    if(tamanho == 0){
        printf("\n");
        return ;
    }else{
        printf("%c", palavra[tamanho-1]);
        return reverso(palavra, tamanho-1);
    }
}

int main(void){
    char palavra[5] = "carro";
    int tamanho = sizeof(palavra)/sizeof(palavra[0]);

    printf("%s\n", palavra);

    reverso(palavra, tamanho);


    return 0;
}
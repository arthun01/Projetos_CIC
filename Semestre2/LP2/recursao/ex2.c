/*
Escreva uma função recursiva que receba uma string
e retorne verdadeiro se a string for um palíndromo
ou falso caso contrário
*/

#include <stdio.h>
#include <string.h>

//função recursiva para ver se é palindromo
int palindromo(char palavra[], int inicio, int fim){

    //se o inicio (0) for maior ou igual ao fim (tamanho no vetor)
    if(inicio >= fim){
        return 1;
    }else{
        if(palavra[inicio] == palavra[fim-1]){
            return palindromo(palavra, inicio+1, fim-1);
        }else{
            return 0;
        }
    }
}

int main(void){
    char palavra1[] = "radar";
    char palavra2[] = "luzazul";

    int tam1 = strlen(palavra1);
    int tam2 = strlen(palavra2);

    printf("Palavra 1: %s -> %d\n", palavra1, palindromo(palavra1, 0, tam1));
    printf("Palavra 2: %s -> %d\n", palavra2, palindromo(palavra2, 0, tam2));

    return 0;
}
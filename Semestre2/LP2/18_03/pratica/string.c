#include <stdio.h>

void imprimir(char[]);

int main(void){
    char frase[30];


    printf("Digite uma frase: ");
    scanf("%[^\n]s", frase);
    printf("----------------------------\n");

    imprimir(frase);

    return 0;
}

void imprimir(char frase[]){
    for(int i = 0; frase[i] != '\0'; i++){
        printf("%c\n", frase[i]);
    }
}
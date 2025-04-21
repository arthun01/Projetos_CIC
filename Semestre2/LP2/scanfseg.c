#include <stdio.h>
#include <string.h>

int main(void){
    char v[100];
    int tam = sizeof(v) / sizeof(v[0]);
    char *palavra;

    printf("Digite uma string: ");
    scanf("%99[^\n]%*c", v); //Lê a string e descarta o '\n'

    printf("String lida: %s\n", v);

    palavra = strtok(v, " ");

    int cont = 1;
    while(palavra != NULL){
        printf("palavra %d: %s\n", cont, palavra);
        palavra = strtok(NULL, " ");
        cont++;
    }

    return 0;
}
/* Imprimindo o vetor de ponteiros naipe por caracter */
/* COnverter laço interno while para for para imprimir as palavras*/
#include <stdio.h>

int main(){
    int i;
    char *naipe[4] = {"copas","ouros","paus", "espadas"}, *ptr;
    
    for(i=0; i<4; i++){
        ptr = naipe[i];

        for(; *ptr; ptr++){
            printf("%c",*ptr);
        }
        printf("\n");
    }
    return 0;
}

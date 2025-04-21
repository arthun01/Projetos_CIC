#include <stdio.h>

int main(void){
    int i;

    char* naipe[5] = {"copas", "ouros", "paus", "espadas", "naosei"};
    char* ptr;

    int tam = sizeof(naipe)/sizeof(naipe[0]);

    for(int i = 0; i < tam; i++){
        ptr = naipe[i];

        while(*ptr){
            printf("%c", *ptr);
            ptr++;
        }
        printf("\n");
    }

    return 0;
}
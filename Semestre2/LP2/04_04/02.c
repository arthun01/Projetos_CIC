#include <stdio.h>
#include <string.h>

#define NOME_MAX 30
#define TAM_MAX 100

void ordenar(char **p, int n){
    char* temp;
    int i, j;

    for(i = 0; i < n-1; i++){
        for(j = i + 1; j < n; j++){
            if(strcmp(p[i],p[j]) > 0){
                temp = *(p+i);
                *(p+i) = *(p+j);
                *(p+j) = temp;
            }
        }
    }
}

int main(void){
    char nomes[NOME_MAX][TAM_MAX];
    char *p[30];
    int n, i;

    for(n = 0;; n++){
        printf("Digite nome ou [ENTER] para fim: ");
        gets(nomes[n]);

        if(strlen(nomes[n]) == 0) break;
        p[n] = nomes[n];
    }

    printf("\n\nLista original: \n");
    for(i = 0; i < n; i++){
        printf("%s\n", p[i]);
    }

    ordenar(p, n);

    printf("\n\nLista ordenada: \n");
    for(i = 0; i < n; i++){
        printf("%s\n", p[i]);
    }

    return 0;
}
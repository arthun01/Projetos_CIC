#include <stdio.h>

#define PRI 10
#define SEG 20
#define TER 5

void printar_tri(int tri[PRI][SEG][TER]);

int main(){
    int tri[PRI][SEG][TER];
    int count = 1;

    for(int i = 0; i < PRI; i++){
        for(int j = 0; j < SEG; j++){
            for(int k = 0; k < TER; k++){
                tri[i][j][k] = count++;
            }
        }
    }

    printar_tri(tri);

    return 0;
}

//função para printar na tela
void printar_tri(int tri[PRI][SEG][TER]){
    for(int i = 0; i < PRI; i++){
        printf("Camada %d: \n", i);
        for(int j = 0; j < SEG; j++){
            for(int k = 0; k < TER; k++){
                printf("%4d ", tri[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <string.h>

#define LIN 10
#define COL 10

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

void printar_matriz(char matriz[LIN][COL]);
void inicializar_matriz(char matriz[LIN][COL]);
void inserir(char matriz[LIN][COL], char palavra[], int linha, int coluna, char dir);
void printar_dicas(char matriz[0][100], int n);

int main(){
    char matriz[LIN][COL];
    int ask;
    char tentativa[100];
    int acertos[6] = {0}; // Para rastrear quais charadas foram acertadas
    int total_acertos = 0;

    //funcao que inicia a matriz
    inicializar_matriz(matriz);

    //botando umas palavras
    char palavra1[] = "1>      "; //cachorro
    char palavra2[] = "2v  "; //olho
    char palavra3[] = "3>  "; //rato
    char palavra4[] = "4v   "; //chave
    char palavra5[] = "5>      "; //elefante
    char palavra6[] = "6v  "; //faca

    char charadas[][100] = {
        "Animal de quatro patas, melhor amigo do homem. (8 letras)",
        "Usamos para ver. (4 letras)",
        "Animal que gosta de queijo. (4 letras)",
        "Abre a porta (5 letras)",
        "Mamífero grande com uma tromba. (8 letras)",
        "Usa para cortar as coisas. (4 letras)"
    };

    inserir(matriz, palavra1, 2, 0, 'H'); //1
    inserir(matriz, palavra2, 0, 3, 'V'); //2
    inserir(matriz, palavra3, 4, 6, 'H'); //3
    inserir(matriz, palavra4, 2, 2, 'V'); //4
    inserir(matriz, palavra5, 6, 2, 'H'); //5
    inserir(matriz, palavra6, 6, 5, 'V'); //6

    while(total_acertos < 6){
        printar_dicas(charadas, 6);
        printar_matriz(matriz);

        printf("Digite qual charada quer tentar (1 a 6): ");
        scanf("%d", &ask);

        if (ask < 1 || ask > 6 || acertos[ask - 1]) {
            printf("Opção inválida ou charada já resolvida. Tente novamente.\n\n");
            continue;
        }

        printf("Digite sua tentativa: ");
        scanf("%s", tentativa);

        // Verificar a resposta correta
        if (ask == 1 && strcmp(tentativa, "cachorro") == 0) {
            printf("\nResposta correta!\n\n");

            strcpy(palavra1, "cachorro");
            inserir(matriz, palavra1, 2, 0, 'H');
            acertos[0] = 1;
            total_acertos++;
        } else if (ask == 2 && strcmp(tentativa, "olho") == 0) {
            printf("\nResposta correta!\n\n");

            strcpy(palavra2, "olho");
            inserir(matriz, palavra2, 0, 3, 'V');
            acertos[1] = 1;
            total_acertos++;
        } else if (ask == 3 && strcmp(tentativa, "rato") == 0) {
            printf("\nResposta correta!\n\n");

            strcpy(palavra3, "rato");
            inserir(matriz, palavra3, 4, 6, 'H');
            acertos[2] = 1;
            total_acertos++;
        } else if (ask == 4 && strcmp(tentativa, "chave") == 0) {
            printf("\nResposta correta!\n\n");

            strcpy(palavra4, "chave");
            inserir(matriz, palavra4, 2, 2, 'V');
            acertos[3] = 1;
            total_acertos++;
        } else if (ask == 5 && strcmp(tentativa, "elefante") == 0) {
            printf("\nResposta correta!\n\n");

            strcpy(palavra5, "elefante");
            inserir(matriz, palavra5, 6, 2, 'H');
            acertos[4] = 1;
            total_acertos++;
        } else if (ask == 6 && strcmp(tentativa, "faca") == 0) {
            printf("\nResposta correta!\n\n");

            strcpy(palavra6, "faca");
            inserir(matriz, palavra6, 6, 5, 'V');
            acertos[5] = 1;
            total_acertos++;
        } else {
            printf("Resposta incorreta. Tente novamente.\n\n");
        }
    }

    printf( MAGENTA "Parabéns! Você resolveu todas as charadas!\n" RESET);
    printar_matriz(matriz);

    return 0;
}

// Funções auxiliares permanecem as mesmas
void inicializar_matriz(char matriz[LIN][COL]){
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            matriz[i][j] = '*';
        }
    }
}

void printar_matriz(char matriz[LIN][COL]){
    for(int i = 0; i < LIN; i++){
        for(int j = 0; j < COL; j++){
            if(matriz[i][j] == '*'){
                printf(MAGENTA "%2c " RESET, matriz[i][j]);
            }else{
                printf("%2c ", matriz[i][j]);
            }
        }
        printf("\n");
    }
}

void inserir(char matriz[LIN][COL], char palavra[], int linha, int coluna, char dir){
    int tam = strlen(palavra);

    for(int i = 0; i < tam; i++){
        if(dir == 'H'){
            matriz[linha][coluna + i] = palavra[i];
        }else if(dir == 'V'){
            matriz[linha + i][coluna] = palavra[i];
        }
    }
}

void printar_dicas(char matriz[0][100], int n){
    printf("\nCharadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, matriz[i]);
    }
    printf("\n");
}

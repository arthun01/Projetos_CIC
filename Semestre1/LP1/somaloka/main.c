/*
Aluno: Arthur Ramos Vieira
N° de Matrícula: 202420022
PROVA 1 - LP1 - CIC 2024.2
*/

#include <stdio.h>

int main(){
    int n1 = 0;
    int n2 = 0;

    printf("N1: ");
    scanf("%d", &n1);

    printf("N2: ");
    scanf("%d", &n2);

    int overflow = 0;
    int soma = n1 + n2;

    //analisa se estar dentro da faixa de 1 byte inteiro sem sinao 0...255
    if(n1 > 255 || n2 > 255 || n1 < 0 || n2 < 0){
        //não esta na faixa os valores n1 ou n2, logo, não podemos somar
        printf("Não dá para somar pois ultrapassa a faixa que 1 byte sem sinal permite!!\n");
    }else{
        //n1 e n2 estão na faixa
        //----------------
        //analisa para ver se a soma de n1 e n2 está fora da faixa, se tem então overflow
        if(soma > 255 || soma < 0){

            overflow = soma - 255;
            soma -= overflow;

            printf("Soma de %d + %d = %d\n", n1, n2, soma);
            printf("Overflow de %d\n", overflow);

        }else{
            //a soma não ultrapassa a faixa então soma normal
            soma = n1 + n2;

            printf("Soma de %d + %d = %d\n", n1, n2, soma);
            printf("Overflow de %d\n", overflow);
        }
    }

    return 0;
}
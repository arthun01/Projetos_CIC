/*
- Aluno: Arthur Ramos Vieira
- N° de matrícula: 202420022
- Algoritmo de Monte Carlo - Apoximação do número PI
- Linguagem de Programação I, Ciência da Computação 2024.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int ask;
    long int num_pon, den_cir = 0;
    double dx, dy, pi_es;

    //perguntando o numero de pontos para o usuario
    printf("Número de pontos: ");
    scanf("%ld", &num_pon);

    //começando a gerar a ransomização
    srand(time(NULL));

    for(int i = 0; i < num_pon; i++){
        //gerando as coordenadas x e y
        dx = (double)rand() / RAND_MAX * 2.0 - 1.0;
        dy = (double)rand() / RAND_MAX * 2.0 - 1.0;

        //vendo se ta dentro do circulo
        if((dx * dx + dy * dy) <= 1.0){
            den_cir++;
        }
    }

    //estimando o pi                    
    pi_es = 4.0 * ((double)den_cir / (double)num_pon);

    //mostrando na tela a estimativa do pi
    printf("Estimativa do pi = %lf\n", pi_es);

    printf("Quer estimar Pi de novo:\n [1] SIM\n [2] NÃO || Resposta: ");
    scanf("%d", &ask);
    printf("-----------------------\n");

    if(ask == 1){
        main();
    }else{
        return 0;
    }
}
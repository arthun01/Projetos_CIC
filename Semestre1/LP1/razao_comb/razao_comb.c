#include <stdio.h>
#include <string.h>

int main(){
    //variáveis
    char car[20];
    int ans = 0;
    int perc = 0;

    float etanol = 4.04;
    float gaso = 6.07;
    float gnv = 5.24;

    float c_gaso = 0;
    float c_eta = 0;
    float c_gnv = 0;
    float raz_fix = etanol / gaso;

    //inputs
    printf("Modelo do carro: ");
    fgets(car, sizeof(car), stdin);
    car[strcspn(car, "\n")] = '\0';

    
    printf("Quanto o carro %s roda por Litro de Gasolina: ", car);
    scanf("%d", &perc);
    c_gaso = gaso / perc;


    printf("Quanto o carro %s roda por Litro de Etanol: ", car);
    scanf("%d", &perc);
    c_eta = etanol / perc;

        
    printf("Quanto o carro %s roda por M³: ", car);
    scanf("%d", &perc);
    c_gnv = gnv / perc;

    //saidas
    printf("--------Resultados--------\n");

    if(raz_fix < 0.7){
        printf("O Etanol é mais vantajosa pela regra fixa dos 70%%\n");
    }else{
        printf("A Gasolina é mais vantajoso pela regra fixa dos 70%%\n");
    }

    printf("Custo por KM da Gasolina: R$%.2f\n", c_gaso);
    printf("Custo por KM do Etanol: R$%.2f\n", c_eta);
    printf("Custo por KM do GNV: R$%.2f\n", c_gnv);

    if(c_gnv < c_eta && c_gnv < c_gaso){
        printf("O GNV é mais econômico para o carro %s\n", car);
    }else if(c_eta < c_gaso){
        printf("O Etanol é o mais econômico para o carro %s\n", car);
    }else{
        printf("O GNV é o mais econômico para o carro %s\n", car);
    }

    //--------------
    printf("----------------\nQuer fazer o cálculo de novo? \n [1] Sim\n [2] Não || Resposta: ");
    scanf("%d", &ans);

    if(ans == 1){
        main();
    }else{
        return 0;
    }
}
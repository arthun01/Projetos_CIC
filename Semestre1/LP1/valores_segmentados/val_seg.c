#include <stdio.h>
#include <string.h>

int massa();
int unidade();
int volume();

char prod[20];

int main(){
    //variaveis
    int ask = 0;

    //produto
    printf("Produto para análise: ");
    fgets(prod, sizeof(prod), stdin);
    prod[strcspn(prod, "\n")] = '\0';

    do{
        printf("O produto %s é dado em: \n [1] Massa\n [2] Unidade\n [3] Volume || Resposta: ", prod);
        scanf("%d", &ask);

        if(ask < 1 || ask > 3)
            printf("Inválido!! teste outra.........\n");
    }while(ask < 1 || ask > 3);

    if(ask == 1){
        massa();
    }else if(ask == 2){
        unidade();
    }else if(ask == 3){
        volume();
    }

    printf("Você quer rodar o programa de novo?\n [1] Sim\n [2] Não || Resposta: ");
    scanf("%d", &ask);

    return 0;
}

int massa(){
    printf("---------------------------------------\n");

    int ask = 0;

    float real = 0;
    float real_ki = 0;
    float real_gr = 0;
    float real_mi = 0;

    float ki = 0;
    float gr = 0;
    float mi = 0;

    do{
        printf("O produto %s é em massa, mas é em: \n [1] Quilograma \n [2] Gramas \n [3] Miligramas || Resposta: ", prod);
        scanf("%d", &ask);

        if(ask < 1 || ask > 3)
            printf("Inválido!! teste outra.........\n");
    }while(ask < 1 || ask > 3);



    if(ask == 1){
        //kilo
        printf("Quantos Quilos de %s você comprou: ", prod);
        scanf("%f", &ki);

        printf("Quanto custou: R$");
        scanf("%f", &real);

        real_ki = real / ki;
        real_gr = real_ki / 1000;
        real_mi = real_ki / 1000000;
        
    }else if(ask == 2){
        //grama
        printf("Quantas Gramas de %s você comprou: ", prod);
        scanf("%f", &gr);

        printf("Quanto custou: R$");
        scanf("%f", &real);

        real_gr = real / gr;
        real_ki = (real * 1000) / gr;
        real_mi = real_gr / 1000;
    }else if(ask == 3){
        //miligrama
        printf("Quantas Miligramas de %s você comprou: ", prod);
        scanf("%f", &mi);

        printf("Quanto custou: R$");
        scanf("%f", &real);

        real_mi = real / mi;
        real_gr = (real * 1000) / mi;
        real_ki = (real * 1000000) / mi;
    }

    printf("O produto %s custa R$%.2f por Quilo\n", prod, real_ki);
    printf("O produto %s custa R$%.3f por Grana\n", prod, real_gr);
    printf("O produto %s custa R$%f por Miligrama\n", prod, real_mi);
    printf("-----------------------------------\n");
    printf("10g do produto %s custa R$%.3f\n", prod, real_gr * 10);
    printf("100g do produto %s custa R$%.3f\n", prod, real_gr * 100);
    printf("200g do produto %s custa R$%.3f\n", prod, real_gr * 200);
    printf("500g do produto %s custa R$%.3f\n", prod, real_gr * 500);
    printf("1kg do produto %s custa R$%.3f\n", prod, real_ki);

   return 0;
}

int unidade(){
    printf("---------------------------------------\n");

    int uni = 0;

    float real = 0;

    printf("Unidades compradas do produto %s: ", prod);
    scanf("%d", &uni);

    printf("Por quanto: R$");
    scanf("%f", &real);

    real = real / uni;

    printf("Você pagou R$%.3f por Unidade\n", real);
    printf("-----------------------------------\n");
    printf("1 Unidade vale R$%.3f\n2 Unidades vale R$%.3f\n5 Unidades vale R$%.3f\n10 Unidades vale R$%.3f\n", real, real * 2, real * 5, real * 10);

    return 0;
}

int volume(){
    printf("---------------------------------------\n");

    int ask = 0;

    float real = 0;
    float real_li = 0;
    float real_mi = 0;

    float li = 0;
    float mi = 0;

    do{
        printf("O produto %s é em volume, mas é em: \n [1] Litro \n [2] Mililitro || Resposta: ", prod);
        scanf("%d", &ask);

        if(ask < 1 || ask > 2)
            printf("Inválido!! teste outra.........\n");
    }while(ask < 1 || ask > 2);

    if(ask == 1){
        //Litro
        printf("Quantos Litros do produto %s você comprou: ", prod);
        scanf("%f", &li);

        printf("Quanto custou: R$");
        scanf("%f", &real);

        real_li = real / li;
        real_mi = real_li / 1000;


    }else if(ask == 2){
        //Mililitro
        printf("Quantos Mililitros do produto %s você comprou: ", prod);
        scanf("%f", &mi);

        printf("Quanto custou: R$");
        scanf("%f", &real);

        real_mi = real / mi;
        real_li = real_mi * 1000;
    }

    printf("O produto %s custa R$%.3f por Litro\n", prod, real_li);
    printf("O produto %s custa R$%f por Mililitro\n", prod, real_mi);
    printf("-----------------------------------\n");
    printf("100Ml do produto %s custa R$%f\n", prod, real_mi * 100);
    printf("500Ml do produto %s custa R$%f\n", prod, real_mi * 500);
    printf("1L do produto %s custa R$%f\n", prod, real_li);
    printf("2L do produto %s custa R$%f\n", prod, real_li * 2);
    
    return 0;
}
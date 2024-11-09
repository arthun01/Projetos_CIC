#include <stdio.h>

int empresa(){

}

int pessoa(){

}



int main(){
    int choice = 0;
    printf("Você quer a folha de pagamento por parte da Empresa ou do Trabalhador? \n [1] Empresa\n [2] Trabalhador || Resposta: ");
    scanf("%d", &choice);

    if (choice == 1){
        empresa();
    }else (choice == 2){
        pessoa();
    }


    //variáveis
    int quant_jobs = 0;
    int type_comp = 0;
    int food_tic = 0;
    int again = 0;

    float sal_base = 0;
    float frac_vac = 0.1111;
    float frac_13 = 0.0833;
    float fgts = 0.08;
    float fini_fgts = 0.04;
    float soc_sec = 0.0793;
    float cost_real = 0;
    //-------------
    float acc_ins = 0.02;
    float inss = 0.2;
    float edu_sala = 0.025;
    float paid_wek = 0.2;
    float sss = 0.033;
    float cost_trans = 0;



    //--------começa--------
    printf("Folha de Pagamento 3 - Versão Empresa!!\n");
    printf("=======================================\n");

    printf("Qual Regime Tributário a empresa usa?\n [1] Simples Nacional\n [2] Lucro Real ou Presumido || Resposta: ");
    scanf("%d", &type_comp);

    printf("Quantos Trabalhadores atualmente? Temos ");
    scanf("%d", &quant_jobs);

    printf("A empresa oferece vale-alimentação?\n [1] Sim\n [2] Não || Resposta: ");
    scanf("%d", &food_tic);

    printf("Quanto é o gasto de transporte de cada funionário? Um total de R$");
    scanf("%f", &cost_trans);

    //se tem vale alimentação ou não
    if (food_tic == 1){
        food_tic = 440;
    }else{
        food_tic = 0;
    }

    //pegando o salário base e vendo se ta de acordo com o salário mpinimo vigente, se não, ele pede o salário de novo
    do{
        printf("Qual o salário base que esses %d trabalhadores recebe? Eles recebem R$", quant_jobs);
        scanf("%f", &sal_base);
        if(sal_base < 1412){
            printf("O salário é inválido pois está abaixo do salário mínimo vigente em 2024\n\n");
        }
    }while(sal_base < 1412);

    //descontando do empregado os 40% do transporte
    sal_base -= (cost_trans * 0.4);



    //--------------------final----------------------

    if (type_comp == 1){
        //simples nacional
        printf("A sua empresa é optante pelo regime tributário Simples Nacional!!\n");
        cost_real = sal_base + ((sal_base * frac_vac) + (sal_base * frac_13) + (sal_base * fgts) + (sal_base * fini_fgts) + (sal_base * soc_sec) + food_tic + (cost_trans * 0.6));
    }else if(type_comp == 2){
        //Lucro Real ou Presumido
        printf("A sua empresa é optante pelo regime tributário Lucro Real ou Presumido!!\n");
        cost_real = sal_base + ((sal_base * frac_vac) + (sal_base * frac_13) + (sal_base * fgts) + (sal_base * fini_fgts) + (sal_base * soc_sec) + (sal_base * acc_ins) + (sal_base * inss) + (sal_base * edu_sala) + (sal_base * paid_wek) + (sal_base * sss) + food_tic + (cost_trans * 0.6));
    }

    printf("----------------------------------------------------------\n");

    if (type_comp != 0){
        printf("A empresa separa R$%d para o Vale-Alimentação do trabalhador\n", food_tic);
        printf("A empresa separa R$%.2f para o Vale-Transporte do trabalhador sobrando os 40%% para o Trabalhador\n", cost_trans * 0.6);
        printf("A empresa precisa separar uma Fração para Férias de 11.11%%\n");
        printf("A empresa precisa separar uma Fração para o Decimo Terceiro de 8.33%%\n");
        printf("A empresa precisa separar uma Fração para o FGTS 8.00%%\n");
        printf("A empresa precisa separar uma Fração para a Provisão de multa para rescisão de 4.00%%\n");
        printf("A empresa precisa separar uma Fração para a previdência social de 7.93%%\n");
    }

    if (type_comp == 2){
        printf("A empresa precisa separar uma Fração para Seguro de Acidente de Trabalho de 2.00%%\n");
        printf("A empresa precisa separar uma Fração para INSS de 20.00%%\n");
        printf("A empresa precisa separar uma Fração para Salário Educação de 2.5%%\n");
        printf("A empresa precisa separar uma Fração para Descanço Semanal Remunerado de 20.00%%\n");
        printf("A empresa precisa separar uma Fração para Sistema S {Sebrae, Sesi, Sesc, etc} de 3.3%%\n");
    }

    printf("----------------------------------------------------------\n");

    printf("Cada trabalhador da empresa tem um custo mensal de R$%.2f\n", cost_real);
    printf("Como a empresa tem %d funcionários então o custo total mensal dos funcionários para a empresa totaliza em R$%.2f\n", quant_jobs, cost_real*quant_jobs);

    printf("----------------------------------------------------------\n");

    //Se o usuario quiser repetir a conta, chama a função main de novo.
    printf("Você quer fazer o calculo de novo? \n [1] Sim\n [2] Não || Resposta: ");
    scanf("%d", &again);

    if (again == 1){
        printf("\n");
        main();
    }else{
        return 0;
    }

}
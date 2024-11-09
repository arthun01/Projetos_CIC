// Folha de Pagamento -/- Empresa ou Empresa
// Arthur Ramos Vieira
// Ciência da Computação 2024.2 -/- LP1

#include <stdio.h>

int empresa(){
     //variáveis
    int quant_jobs = 0;
    int type_comp = 0;
    int food_tic = 0;

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
    printf("=======================================\n");
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

    return 0;

}

int pessoa(){
    /*
    -- Folha de Pagamento 2.0
    -- Pesquisar e Implementar os benefícios e descontos de um trabalhador CLT;
    -- Deve apresentar o calculo das faixas do IRPF, conforme lei vigente;
    -- Alunos: Arthur Ramos Vieira
    */

        //variáveis
        int min_sal = 1412;
        int ans1 = 0;
        int week_hr = 0;
        int hea_plan = 0;

        float base_sal = 0;
        float irpf = 0;
        float extra_hr = 0;
        float liq_sal = 0;
        float ded = 0.0;
        float food_voucher = 440.0;
        float inss = 0.0;

        printf("================================================\n");
        printf("Folha de Pagamento 2.0 - Versão do Trabalhador!!\n");
        printf("================================================\n");

        printf("Salário Base: R$");
        scanf("%f", &base_sal);

        if(base_sal >= min_sal){
            //valido
            printf("Você possue plano de saúde pela empresa? \n[1] SIM\n[2] NÃO || Resposta: ");
            scanf("%d", &hea_plan);
            if(hea_plan == 1){
                hea_plan = 300;
                liq_sal += hea_plan;
            }else{
                liq_sal = 0;
                hea_plan = 0;
            }

            do{
                printf("Horas semanais trabalhadas: ");
                scanf("%d", &week_hr);
            }while(week_hr <= 0);

            printf("Você fez horas extras esse mês? \n [1] SIM \n [2] NÃO || Resposta: ");
            scanf("%d", &ans1);

            //Horas extras
            if(ans1 == 1){
                //fez
                printf("Quantas Horas extra: ");
                scanf("%f", &extra_hr);

                //calculo das horas extra
                extra_hr = ((base_sal / (week_hr * 5)) * extra_hr);
                extra_hr += (extra_hr * 0.5);

                liq_sal += extra_hr;
                //printf("vc ganhara R$%.1f de horas extra\n", extra_hr);
            }else{
                //nao fez
                extra_hr = 0.0;
                printf("Então você não terá acrescimos ao seu salário por Horas Extra\n");
            }

            //Imposto de Renda
            if(base_sal >= 2259.21){
                irpf += (169.44 * 0.075);
                if(base_sal >= 2826.66){
                    irpf += (381.44 * 0.15);
                    if(base_sal >= 3751.06){
                        irpf += (662.77 * 0.225);
                        if(base_sal >= 4664.68){
                            irpf += (896.0 * 0.275);
                        }
                    }
                }
            }

            //INSS
            if (base_sal <= 1412.00) {
                inss = base_sal * 0.075;  // 7,5%
            } else if (base_sal <= 2666.68) {
                inss = (base_sal * 0.09) - 21.18;  // 9% com parcela dedutível
            } else if (base_sal <= 4000.03) {
                inss = (base_sal * 0.12) - 101.18;  // 12% com parcela dedutível
            } else if (base_sal <= 7786.02) {
                inss = (base_sal * 0.14) - 181.18;  // 14% com parcela dedutível
            } else {
                // Acima do teto, o valor do INSS é calculado até o teto de 7786.02
                inss = (7786.02 * 0.14) - 181.18;
            }

            if (irpf < 0){
                irpf = 0;
            }

            liq_sal += food_voucher;
            liq_sal += (base_sal - irpf);
            liq_sal -= inss;

            printf("------------------------------\n");
            printf("Seu imposto totalizou R$%.2f\n", irpf);
            printf("Seu INSS totalizou R$%.2f\n", inss);
            printf("Seu vale alimentação é de R$%.1f\n", food_voucher);
            printf("Você possue R$%d de Plano de Saúde\n", hea_plan);
            printf("Você recebeu R$%.1f de Horas Extras\n", extra_hr);
            printf("Seu salário líquido é R$%.2f\n", liq_sal);
            printf("\n");

        }else{
            //invalido
            printf("Seu salário é inválido, está abaixo do salário mínimo vigente que é R$%d\n", min_sal);
            printf("\n");
        }

        return 0;
}

int main(){
    int choice = 0;

    printf("Você quer a folha de pagamento por parte da Empresa ou do Trabalhador? \n [1] Empresa\n [2] Trabalhador || Resposta: ");
    scanf("%d", &choice);

    if (choice == 1){
        empresa();
    }else if (choice == 2){
        pessoa();
    }

    printf("Você quer rodar de novo?\n [1] Sim\n [2] Não || Resposta: ");
    scanf("%d", &choice);
    printf("\n");

    if (choice == 1){
        main();
    }else{
        return 0;
    }

}
/*
-- Folha de Pagamento 2.0
-- Pesquisar e Implementar os benefícios e descontos de um trabalhador CLT;
-- Deve apresentar o calculo das faixas do IRPF, conforme lei vigente;
-- Alunos: Arthur Ramos Vieira
*/

#include <stdio.h>

int main(){
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

    printf("=======================\n");
    printf("Folha de Pagamento 2.0\n");
    printf("=======================\n");


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

        printf("Horas semanais trabalhadas: ");
        scanf("%d", &week_hr);


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

    }else{
        //invalido
        printf("Seu salário é inválido, está abaixo do salário mínimo vigente que é R$%d\n", min_sal);
    }

    return 0;
}
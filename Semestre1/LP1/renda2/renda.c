/* Algoritmo Folha de Pagamento, versão 2
Linguagem de Programação I - 2024.2
Arthur Ramos Vieira	*/

#include <stdio.h>

int main(){
	//Declarando as variáveis
	float sal_base = 0, sal_bruto = 0, sal_liq = 0, temp_serv = 0.0, irrf = 0.275, iss = 0.15, impostos = 0.0;
	int sal_min = 1412, aux_ali = 440, pos = 0;

	printf("------------------------------------\n");
	printf("Programa: Folha de Pagamento\n");
	printf("------------------------------------\n");

	printf("Qual o seu salário base? Eu ganho R$");
	scanf("%f", &sal_base);

	//Verificando se o salário é válido
	if(sal_base < sal_min){
		//não pode
		printf("não pode!! o seu salário está abaixo do salário mínimo\n");
	}else{
		//pode
		printf("Qual sua especialização? \n [1]Doutor\n [2]Mestre\n [3]Especialista\n [4]Não tenho | Resposta: ");
		scanf("%i", &pos);

		printf("Quanto tempo você tem de serviço? ");
		scanf("%f", &temp_serv);

		if(pos == 1){
			//Doutor
			sal_bruto = sal_base + (sal_base * 0.6);
		}else if(pos == 2){
			//Mestre
			sal_bruto = sal_base + (sal_base * 0.4);
		}else if(pos == 3){
			//Especialista
			sal_bruto = sal_base + (sal_base * 0.2);
		}else{
			//Não tem
			sal_bruto = sal_base;
		}

		//Tempo de serviço
		if(temp_serv >= 5){
			//recebe
			sal_bruto = sal_bruto + (sal_bruto * (temp_serv/100));
		}else{
			//nao recebe
		}

		//Impostos!! :(
		if(sal_bruto > 2259.20){
			//vai pagar :(
			sal_liq = sal_bruto;
			impostos = irrf + iss;
			sal_liq = sal_liq - (sal_liq * impostos);
		}else{
			//não vai pagar :)
			sal_liq = sal_bruto;
			impostos = 0.0;
		}

		sal_liq += aux_ali;

		printf("------------------------------------\n");
		printf("O seu salário bruto é R$%.2f\n", sal_bruto);
		printf("Total de impostos: %.2f porcento\n", impostos*100);
		printf("O seu salário líquido é R$%.2f\n", sal_liq);
	}

	return 0;
}
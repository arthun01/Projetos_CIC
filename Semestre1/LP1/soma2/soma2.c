#include <stdio.h>

int main(){
	int var1 = 0, var2 = 0, resp = 0;

	printf("Entre com o 1° valor: ");
	scanf("%i", &var1);

	printf("Entre com 2° valor: ");
	scanf("%i", &var2);

	resp = var1 + var2;

	printf("A resposta é %i\n", resp);

	return 0;
}

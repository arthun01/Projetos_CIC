//quanto cada tipo de dados ocupa em bytes
//Limite maximo e mínimo de cada tipo de dados

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){

	printf("Limites de cada tipo de variável\n");
	printf("================================\n");
	printf("-- Quantos bytes cada tipo ocupa\n");
	printf("================================\n");

	//int
	printf("O short int ocupa %ld bytes\n", sizeof(short int));
	printf("O int ocupa %ld bytes\n", sizeof(int));
	printf("O long int ocupa %ld bytes\n", sizeof(long int));
	printf("O unsigned int ocupa %ld bytes\n", sizeof(unsigned int));
	printf("O signed int ocupa %ld bytes\n", sizeof(signed int));
	printf("--------------------------------\n");

	//char
	printf("O char ocupa %ld byte(s)\n", sizeof(char));
	printf("O signed char ocupa %ld byte(s)\n", sizeof(signed char));
	printf("O unsigned char ocupa %ld byte(s)\n", sizeof(unsigned char));
	printf("--------------------------------\n");

	//short
	printf("O short ocupa %ld byte(s)\n", sizeof(short));
	printf("O unsigned short ocupa %ld byte(s)\n", sizeof(unsigned short));
	printf("O long ocupa %ld byte(s)\n", sizeof(long));
	printf("O unsigned long ocupa %ld byte(s)\n", sizeof(unsigned long));
	printf("--------------------------------\n");

	//float-double
	printf("O float ocupa %ld byte(s)\n", sizeof(float));
	printf("O double ocupa %ld byte(s)\n", sizeof(double));
	printf("O long double ocupa %ld byte(s)\n", sizeof(double));

	printf("================================\n");
	printf("-- Mínimo e Máximo que cada tipo pode assumir\n");
	printf("================================\n");

	printf("mínimo signed char pode assumir: %d\n", SCHAR_MIN);
	printf("máximo signed char pode assumir: %d\n", SCHAR_MAX);

	printf("máximo unsigned char pode assumir: %d\n", UCHAR_MAX);

	printf("mínimo char pode assumir: %d\n", CHAR_MIN);
	printf("máximo char pode assumir: %d\n", CHAR_MAX);

	printf("mínimo short int pode assumir: %d\n", SHRT_MIN);
	printf("máximo short int pode assumir: %d\n", SHRT_MAX);

	printf("máximo unsigned short int pode assumir: %d\n", USHRT_MAX);
	
	printf("mínimo int pode assumir: %d\n", INT_MIN);
	printf("máximo int pode assumir: %d\n", INT_MAX);
	printf("máximo unsigned int pode assumir: %d\n", UINT_MAX);
	printf("máximo unsigned int pode assumir %d\n", UINT_MAX);
	printf("mínimo long int pode assumir: %ld\n", LONG_MIN);
	printf("máximo long int pode assumir: %ld\n", LONG_MAX);
	printf("máximo unsigned long int pode assumir: %ld\n", ULONG_MAX);

	printf("--------------------------------\n");
	printf("o mínimo que um float pode assumir: %f\n", FLT_MIN);
	printf("o máximo que um float pode assumir: %f\n", FLT_MAX);

	printf("o mínimo que um double pode assumir: %f\n", DBL_MIN);
	printf("o máximo que um double pode assumir: %f\n", DBL_MAX);

	return 0;
}

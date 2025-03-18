/*
-- Aula do dia 18/03/2025
-- Funções ou Procedimentos
-- 4 tipos de Função
*/

#include <stdio.h>

// Função SEM parâmetro e SEM retorno
void HelloWorld(void){
    printf("Hello World\n");
}

// Função COM parâmetro e SEM retorno
void cp_sr(int a, int b){
    printf("%d + %d = %d\n", a, b, a+b);
}

// Função SEM parâmetro e COM retorno
int sp_cr(void){
    int b = 5;
    return b;
}

// Função COM parâmetro e COM retorno
int cp_cp(int a){
    int b = 10;
    return a + b;
}


int main(void){

    HelloWorld();
    cp_sr(20, 10);
    printf("%d\n", sp_cr());
    printf("%d\n", cp_cp(20));

    return 0;
}
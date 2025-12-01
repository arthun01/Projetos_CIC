#include <stdio.h>
#include <stdlib.h> // Para a função abs(), se necessário

// Função solicitada na questão
int buscaMaisProximo(int v[], int n, int x) {
    // 1. Verifica se o vetor está vazio 
    if (n == 0) {
        return -1;
    }

    // 2. Otimização de bordas:
    if (x <= v[0]) return v[0];
    if (x >= v[n - 1]) return v[n - 1];

    // 3. Busca Binária
    int esquerda = 0;
    int direita = n - 1;

    while (esquerda <= direita) {
        int meio = (esquerda + direita) / 2;

        if (v[meio] == x) {
            return v[meio];
        }

        if (x < v[meio]) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }

    // 4. Comparação final
    // Quando o while termina, 'esquerda' e 'direita' se cruzaram.
    // O valor 'x' está entre v[direita] e v[esquerda].
    // Como já tratamos as bordas no início, ambos índices são válidos aqui.
    
    int valDireita = v[direita]; // Elemento menor que x
    int valEsquerda = v[esquerda]; // Elemento maior que x

    // Calculamos as distâncias (diferenças absolutas)
    int distDireita = x - valDireita;
    int distEsquerda = valEsquerda - x;

    // Critério de desempate: "Se houver dois números igualmente próximos, retorne o menor deles".
    // O vetor é ordenado, então v[direita] é sempre menor que v[esquerda].
    // Se a distância da direita for menor ou IGUAL, retornamos v[direita].
    if (distDireita <= distEsquerda) {
        return valDireita;
    } else {
        return valEsquerda;
    }
}

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int n = 5;
    
    // Testes
    printf("Mais proximo de 25: %d\n", buscaMaisProximo(v, n, 25)); // Esperado: 20 (empate, retorna menor)
    printf("Mais proximo de 28: %d\n", buscaMaisProximo(v, n, 28)); // Esperado: 30
    printf("Mais proximo de 5: %d\n", buscaMaisProximo(v, n, 5));   // Esperado: 10 (borda)
    printf("Mais proximo de 55: %d\n", buscaMaisProximo(v, n, 55)); // Esperado: 50 (borda)
    
    return 0;
}
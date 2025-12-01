#include <stdio.h>
#include <stdlib.h>

// estrutura (TAD) da árvore
typedef struct TNo{
    int info;
    struct TNo* esq;
    struct TNo* dir;
} ArvBin;

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int altura(ArvBin* raiz){
    if(raiz == NULL){
        return -1;
    }else{
        return max(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int fatorDeBalanceamento(ArvBin* raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return altura(raiz->esq) - altura(raiz->dir);
    }
}

ArvBin* rotacaoDireita(ArvBin* y){
    ArvBin* x = y->esq;
    ArvBin* T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    return x;
}

ArvBin* rotacaoEsquerda(ArvBin* x){
    ArvBin* y = x->dir;
    ArvBin* T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    return y;
}

ArvBin* balancear(ArvBin* no){
    int fatorBalanceamento = fatorDeBalanceamento(no);

    if(fatorBalanceamento > 1 && fatorDeBalanceamento(no->esq) >= 0){
        return rotacaoDireita(no);
    }else{
        if(fatorBalanceamento > 1 && fatorDeBalanceamento(no->esq) < 0){
            no->esq = rotacaoEsquerda(no->esq);
            return rotacaoDireita(no);
        }
    }

    if(fatorBalanceamento < -1 && fatorDeBalanceamento(no->dir) <= 0){
        return rotacaoEsquerda(no);
    }else{
        if(fatorBalanceamento < -1 && fatorDeBalanceamento(no->dir) > 0){
            no->dir = rotacaoDireita(no->dir);
            return rotacaoEsquerda(no);
        }
    }

    return no;
}

/*
    insere
    recebe a raiz da árvore e o valor a ser adicionado
    retorna a árvore atualizada com o novo valor
*/
ArvBin* insere(ArvBin* raiz, int valor){
    if(raiz == NULL){
        ArvBin* folha = (ArvBin*)malloc(sizeof(ArvBin));
        if(folha == NULL){
            printf("Erro ao alocar\n");
            return NULL;
        }

        folha->info = valor;
        folha->dir = NULL;
        folha->esq = NULL;

        return folha;
    }

    if(valor > raiz->info){
        raiz->dir = insere(raiz->dir, valor);
    }else{
        raiz->esq = insere(raiz->esq, valor);
    }

    return balancear(raiz);
}

/*
    buscaBinariaArv
    recebe a raiz da árvore e o valor a ser achado
    retorna -1 se não achar e retorna o valor encontrado se de fato achar
*/
int buscaBinariaArv(ArvBin* raiz, int chave){
    if(raiz == NULL) return -1;

    if(raiz->info == chave){
        return chave;
    }else if(raiz->info > chave){
        return buscaBinariaArv(raiz->esq, chave);
    }else{
        return buscaBinariaArv(raiz->dir, chave);
    }
}


/*
    imprimePreOrder
    recebe a raiz da árvore e imprime no terminal todos os elementos
    visita a raiz, percorre a subárvore esquerda e depois percorre a subárvore direita
*/
void imprimePreOrder(ArvBin* raiz){
    if(raiz == NULL) return;

    printf("%d ", raiz->info);
    imprimePreOrder(raiz->esq);
    imprimePreOrder(raiz->dir);
}


/*
    imprimeInOrder
    recebe a raiz da árvore e imprime no terminal todos os elementos
    percorre a subárvore esquerda, visita a raiz e depois percorre a subárvore direita
*/
void imprimeInOrder(ArvBin* raiz){
    if(raiz == NULL) return;

    imprimeInOrder(raiz->esq);
    printf("%d ", raiz->info);
    imprimeInOrder(raiz->dir);
}

/*
    imprimePosOrder
    recebe a raiz da árvore e imprime no terminal todos os elementos
    percorre a subárvore esquerda, percorre a subárvore direita e depois visita a raiz
*/
void imprimePosOrder(ArvBin* raiz){
    if(raiz == NULL) return;

    imprimePosOrder(raiz->esq);
    imprimePosOrder(raiz->dir);
    printf("%d ", raiz->info);
}

int main(void){
    ArvBin* minhaArvore = NULL;

    // adicionando elementos
    minhaArvore = insere(minhaArvore, 50);
    minhaArvore = insere(minhaArvore, 20);
    minhaArvore = insere(minhaArvore, 80);
    minhaArvore = insere(minhaArvore, 70);
    minhaArvore = insere(minhaArvore, 75);

    // formas de imprimir uma árvore
    printf("Pré-Ordem: ");
    imprimePreOrder(minhaArvore);
    printf("\n");

    printf("Em-Ordem: ");
    imprimeInOrder(minhaArvore);
    printf("\n");

    printf("Pos-Ordem: ");
    imprimePosOrder(minhaArvore);
    printf("\n");

    // testando busca binária na árvore
    int resultado = buscaBinariaArv(minhaArvore, 1);

    if(resultado != -1){
        printf("O valor %d foi achado na árvore\n", resultado);
    }else{
        printf("Valor não achado na árvore\n");
    }

    return 0;
}
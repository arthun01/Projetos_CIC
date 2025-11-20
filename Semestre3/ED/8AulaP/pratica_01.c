// Arthur Ramos Vieira
// ED, CIC 2025.2

// bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>

// estrutura do nó
typedef struct TNo{
  int info;
  struct TNo* dir;
  struct TNo* esq;
} ArvBin;

// protótipos das funções
ArvBin* insere(ArvBin* arvore, int valor);
ArvBin* buscaValor(ArvBin* raiz, int valor);
void liberarArvore(ArvBin* raiz);


int main(void){
  // quantidade de casos teste do programa
  int quant_casos;
  scanf("%d", &quant_casos);

  if(quant_casos <= 0){
    return 0;
  }

  for(int i = 0; i < quant_casos; i++){
    ArvBin* minha_arvore = NULL;

    // variavel para ver quantos elementos teremos na arvore
    int k;
    scanf("%d", &k);

    for(int j = 0; j < k; j++){
      // cada elemento da árvore de forma auxiliar
      int aux;
      scanf("%d", &aux);

      // inserir na lista
      minha_arvore = insere(minha_arvore, aux);
    }

    // entrada da variavel a ser achada na arvore
    int ser_encontrado;
    scanf("%d", &ser_encontrado);

    // procurando o número e "seu galho"
    ArvBin* alvo = NULL;
    alvo = buscaValor(minha_arvore, ser_encontrado);

    // se a buscar não retornar nada, 0
    // se a busca retornar algo, ai printa
    int resultado;
    if(alvo == NULL){
      resultado = 0;
      printf("%d\n", resultado);
    }else{
      resultado = 1;

      ArvBin* folha_esq = alvo->esq;
      ArvBin* folha_dir = alvo->dir;

      // se existe filhos, printa. se não, printa só o resultado 1
      if(folha_esq != NULL || folha_dir != NULL){
        int info_esq = (folha_esq != NULL) ? folha_esq->info : -1;
        int info_dir = (folha_dir != NULL) ? folha_dir->info : -1;
        printf("%d [%d, %d]\n", resultado, info_esq, info_dir);
      }else{
        printf("%d []\n", resultado);
      }
    }

    liberarArvore(minha_arvore);
  }

  return 0;
}

// -- funções utilizadas

/*
 * nome: insere
 * Descrição: Adiciona um novo valor na Árvore Binária de Busca (ABB).
 * Parâmetros:
 * - arvore: Ponteiro para a raiz ou sub-árvore atual.
 * - valor: O valor inteiro a ser inserido.
 * Retorno: A nova raiz da árvore/sub-árvore após a inserção.
*/
ArvBin* insere(ArvBin* arvore, int valor){
  if(arvore == NULL){
    ArvBin* no = (ArvBin*)malloc(sizeof(ArvBin));
    if(no == NULL) return NULL;

    no->info = valor;
    no->dir = NULL;
    no->esq = NULL;

    return no;
  }

  if(valor > arvore->info){
    // direita
    arvore->dir = insere(arvore->dir, valor);
  }else{
    // esquerda
    arvore->esq = insere(arvore->esq, valor);
  }

  return arvore;
}


/*
 * nome: buscaValor
 * Descrição: Procura um valor na Árvore.
 * Parâmetros:
 * - raiz: Ponteiro para a raiz ou sub-árvore atual.
 * - valor: O valor inteiro a ser achado.
 * Retorno: A nova raiz da árvore/sub-árvore após a procura.
*/
ArvBin* buscaValor(ArvBin* raiz, int valor){
  if(raiz == NULL) return NULL;

  if(raiz->info == valor){
    return raiz;
  }

  if(valor < raiz->info){
    return buscaValor(raiz->esq, valor);
  }else{
    return buscaValor(raiz->dir, valor);
  }

}

/*
 * nome: liberaArvore
 * Descrição: Remove da memória (da um free) na Árvore.
 * Parâmetros:
 * - raiz: Ponteiro para a raiz ou sub-árvore atual.
 * Retorno: Nenhum.
*/
void liberarArvore(ArvBin* raiz){
  if(raiz != NULL){
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
  }
}

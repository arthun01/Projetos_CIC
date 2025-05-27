#include <stdio.h>
#include <stdlib.h>

typedef struct S_Node{
    int data;
    struct S_Node* next;
} Node;

//cria um novo nó
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Erro: Falha ao alocar memória para o novo nó!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//inserir nó no final da lista
void insertAtEnd(Node** headRef, int data){
    Node* newNode = createNode(data);
    Node* current = *headRef;

    //Se a lista estiver vazia, o novo nó se torna a cabeça
    if(*headRef == NULL){
        *headRef = newNode;
        return;
    }

    //caso contrario, percorre até o último nó
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

//função para imprimir a lista
void printfList(Node* head){
    Node* current = head;
    printf("Lista: ");

    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

//função para liberar toda a memória da lista
void freeList(Node** headRef){
    Node* current = *headRef;
    Node* nextNode;

    while(current != NULL){
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *headRef = NULL;
}


int main(void){
    Node* myList = NULL;

    int i, n, value;

    printf("Quantos elementos você quer adicionar a lista? ");
    scanf("%d", &n);

    printf("Digite os %d valores:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &value);
        insertAtEnd(&myList, value);
    }

    printfList(myList);
    printf("\n-----------------------------\n");

    printf("Quantos elementos você quer adicionar a lista? ");
    scanf("%d", &n);

    printf("Digite os %d valores:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &value);
        insertAtEnd(&myList, value);
    }

    printfList(myList);

    freeList(&myList);
    printf("\nLista após liberar memória:\n");
    printfList(myList);

    return 0;
}
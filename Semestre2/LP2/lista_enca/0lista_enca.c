#include <stdio.h>
#include <stdlib.h>

typedef struct S_Node{
    int data;
    struct S_Node* next;
} Node;

int main(void){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    //alocando memória para os nós
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    //atribuindo dados e ligando os nós
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    //percorrendo e imprimindo a lista
    printf("lista encadeada: ");
    
    //cria um nó atual para percorrer
    Node* current = head;

    //enquanto o atual não for NULL
    while(current != NULL){
        printf("%d(%p) -> ", current->data, current);
        current = current->next;
    }
    printf("\n");

    //liberar a memória
    free(head);
    free(second);
    free(third);

    return 0;
}
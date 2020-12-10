#include <stdio.h>
#include <stdlib.h>

typedef struct  dataNode{
    int id;
} DataNode;

typedef struct node
{
    DataNode data; //dado
    struct node* next;  //referencia pro próximo nó
} Node;

typedef struct list{
    int size; //tamanho da lsta
    Node* head; //nó cabeça
}  List; //referencia pra list

List* createList(); //retorna uma referencia pra nossa lista

List* createList(){
    List* list =(List*) malloc(sizeof(List));

    list -> size = 0; //inicia o tamanho da lista com0
    list -> head = NULL; //inicia apontando pro null pq a lista está vazia

    return list;
}

int main(){
    List* lista = createList(); 
    printf("Tamanho da lista: %d", lista -> size);
}

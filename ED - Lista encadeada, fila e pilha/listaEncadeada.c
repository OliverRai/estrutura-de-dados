#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode
{
    int id;
} DataNode;

typedef struct node
{
    DataNode data;     //dado
    struct node *next; //referencia pro próximo nó
} Node;

typedef struct list
{
    int size;   //tamanho da lsta
    Node *head; //nó cabeça
} List;         //referencia pra list

List* createList();                   //retorna uma referencia pra nossa lista
void push(List *list, DataNode data); //recebe uma referencia e um dado
void showList(List *lista);           //printa
void pop(List *list);                 //remove primeiro elemento
bool isEmpty(List *list);             //lista vazia ou não
Node* atPos(List *list, int index);   //retorna um nó
int indexOf(List* list, Node* node); //a busca de um nó
void erase(List* list, int index); //para excluir
void insert(List* list, DataNode data, int index);

List *createList()
{
    List *list = (List *)malloc(sizeof(List));

    list->size = 0;    //inicia o tamanho da lista com0
    list->head = NULL; //inicia apontando pro null pq a lista está vazia

    return list;
}

void push(List *list, DataNode data)
{
    Node *node = (Node *)malloc(sizeof(Node)); //criando o nó com o dado na memoria/alocando memóri

    node->data = data;       //passando a informação pro nó
    node->next = list->head; //faz o próximo nó vai ser a head da lista
    list->head = node;       //nosso nó é a primeira posição
    list->size++;            //incrementando o tamanho da lista
}

void showList(List *list)
{
    if (isEmpty(list))
    {
        printf("Lista vazia\n");
        return;
    }
    //percorrer lista
    Node *pointer = list->head; //ponteiro iniciamente aponta para a cabeça da lista

    while (pointer != NULL)
    { //quando o pointer for null é pq chegamos ao fim da lista
        printf("=> %d\n", pointer->data.id);
        pointer = pointer->next; //aponta para o próximo
    }

    printf("\n");
}

bool isEmpty(List *list)
{
    return (list->size == 0);
}

void pop(List *list)
{
    if (!isEmpty(list))
    {
        Node *pointer = list->head; //tipo um ponteiro auxiliar
        list->head = pointer->next; // muda o head para o próximo ponteiro
        free(pointer);              //liberaa
        list->size--;
    }
}

Node* atPos(List* list, int index)
{
    if (index >= 0 && index < list->size)
    {
        Node* node = list->head;
        int i;
        for (i = 0; i < index; i++)
        {
            node = node->next; //node recebe o próximo nó

            return node;
        }
    }
    //index invalido retorna null
    printf("Indice invalido\n");
    return NULL;
}

int indexOf(List* list, Node* node){

    if(node != NULL){
        Node* pointer = list -> head;
        int index = 0;

        while(pointer != node && pointer != NULL){
            pointer =  pointer -> next;
            index++;
        }

        if(pointer != NULL){//não percorreu a lista toda
            return index;
        }
    }

    printf("No nao pertence a lista \n");
    return -1;
}

void erase(List* list, int index){

    if(index == 0){
        pop(list); //remove o primeiro index

    } else {

        Node* current = atPos(list, index);

        if(current != NULL){
            Node* anterior = atPos(list, index - 1); //nó anterior
            anterior -> next = current -> next;

            free(current);
            list -> size--;
        }
    }
}

void insert(List* list, DataNode data, int index){
    if(index == 0){
        push(list, data);
    } else {
        Node* current = atPos(list, index);

        if(current != NULL){
            Node* anterior = atPos(list, index - 1);
            
            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode -> data = data;

            anterior -> next = newNode;
            newNode -> next = current;
            list -> size++;
        }
    }
}

int main()
{
    List *l = createList();

    DataNode data;

    data.id = 5;
    push(l, data);

    data.id = 9;
    push(l, data);

    data.id = 7;
    push(l, data);

    data.id = 1;
    push(l, data);

    data.id = 6;
    push(l, data);

    showList(l);

    pop(l);

    showList(l);

    //erase(l, 3);

    showList(l);

    data.id = 11;
    insert(l, data, 3);

  //  printf("%d \n", indexOf(l, l -> head -> next ->next -> next));

    printf("Tamanho da lista: %d \n", l->size);
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
    node *previ;
};

class linked_list
{
private:
    node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void printList()
    {
        node *atual;
        atual = head;
        while (atual)
        {
            printf("--> %d \n", atual->data);
            atual = atual->next;
        }
    }

    void add_initial(int valor){
        node *novo = (node*)malloc(sizeof(node));
        if(head == NULL){
            head = novo;
            tail = novo;
        }
        else {
            node * atual;
            atual = head;
            novo->next = atual;
            atual -> previ = novo;
            head = novo;
        }
    }
};

int main()
{
    linked_list li;
    li.add_node(1);
    li.add_node(2);
    li.printList();
    return 0;
}
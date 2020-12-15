#include <stdio.h>
#include <malloc.h>

typedef struct NO
{
    int dado;
    struct NO *prox;
} NO;

typedef struct PILHA
{
    NO *topo;
} PILHA;

void inicializarPilha(PILHA *p)
{
    p->topo = NULL;
}

void push(int dado, PILHA *p)
{
    NO *ponteiro = (NO *)malloc(sizeof(NO));
    if (ponteiro == NULL)
    {
        printf("Erro de alocacao");
        return;
    }
    else
    {
        ponteiro->dado = dado;
        ponteiro->prox = p->topo; //aponta para o topo 
        p->topo = ponteiro; 
        //o topo atual passa a ser o dado inserido 
        //o topo atual passa a ser o segundo na pilha 
    }
}

int pop(PILHA *p)
{
    NO *ponteiro = p->topo;
    int dado;
    if (ponteiro == NULL)
    {
        printf("Pilha vazia");
        return;
    }
    else
    {
        p->topo = ponteiro->prox; // atualizo o topo para o futuro topo
        ponteiro->prox = NULL;    //pego o topo que ta sendo removido e desligo el da lista
        dado = ponteiro->dado;
        free(ponteiro);
        return dado;
    }
}

void imprimePilha(PILHA *p)
{
    NO *ponteiro = p->topo;
    if (ponteiro == NULL)
    {
        printf("Pilha vazia \n");
        return;
    }
    else
    {
        while (ponteiro != NULL)
        {
            printf("%d ", ponteiro->dado);
            ponteiro = ponteiro->prox;
        }
        printf("\n");
    }
}

int main()
{
    PILHA *p1 = (PILHA *)malloc(sizeof(PILHA));
    if (p1 == NULL)
    {
        printf("Erro de alocação da pilha \n");
    }
    else
    {
        inicializarPilha(p1);

        push(10, p1);
        push(20, p1);
        push(40, p1);
        push(50, p1);
        push(60, p1);
        push(70, p1);
        push(80, p1);

        imprimePilha(p1);

        printf("Pilha removida:  %d \n", pop(p1));
        imprimePilha(p1);
    }
}

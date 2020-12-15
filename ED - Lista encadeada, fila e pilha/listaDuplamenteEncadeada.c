// LISTA DUPLAMENTE ENCADEADA
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;
struct elemento
{
    int valor;
    Elemento *proximo;
    Elemento *anterior;
};
typedef struct
{
    Elemento *inicio;
    Elemento *fim;
    int tamanho;
} Lista;

Lista *criarLista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    li->inicio = NULL;
    li->fim = NULL;
    li->tamanho = 0;
    return li;
}

Elemento *aloca(int valor)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void push(Lista *lis, int newValor)
{
    Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
    if (lis->inicio == NULL)
    {
        novo->valor = newValor;
        novo->proximo = NULL;
        lis->inicio = novo;
        lis->fim = novo;
    }
    else
    {
        novo->valor = newValor;
        novo->proximo = lis->inicio;
        lis->inicio = novo;
    }
}

void destroy(Lista *lis)
{
    Elemento *p = lis;
    Lista *temp;
    while (p != NULL)
    {
        temp = p->proximo; //guarda ref para prox elemento
        free(p);       //libera memória
        p = temp;       // aponta para o próximo
    }
}

void delete(Lista *lis, int deleteValor) {

    if (lis->inicio == NULL) {

        printf("\nLista Vazia\n ");
    }
    else {
        Elemento *i = lis->inicio, *previous;
        while(i->proximo != NULL) {
            if (i->valor == deleteValor) {
                if (i == lis->inicio) {
                    lis->inicio = i->proximo;
                    free(i);
                    break;
                } else {
                    previous->proximo = i->proximo;
                    free(i);
                    break;
                }
            } else {
                previous = i;
                i = i->proximo;
            }
        }
    }
}

void removeInicio(Lista *lis)
{
    Elemento *atual = lis->inicio;
    lis->inicio = atual->proximo;
    lis->inicio->anterior = NULL;
    lis->tamanho--;
}
void removeFim(Lista *lis)
{
    Elemento *atual = lis->fim;
    lis->fim = atual->anterior;
    lis->fim->proximo = NULL;
    lis->tamanho--;
}

void insereInicio(int valor, Lista *lis)
{
    Elemento *novo = aloca(valor); //criar novo elemento
    //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
    if (lis->inicio == NULL)
    {
        lis->inicio = novo;
        lis->fim = novo;
        //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
    }
    else
    {
        Elemento *atual; //criar novo elemento caso tenha dado no inicio da lista.
        atual = lis->inicio;
        novo->proximo = atual;
        atual->anterior = novo;
        lis->inicio = novo;
    }
    lis->tamanho++;
}

//Inserir no fim da lista:
void insereFim(int valor, Lista *lis)
{
    Elemento *novo = aloca(valor); //criar novo elemento
    //verificar se o inicio for nulo, se sim, inicio recebe novo e o fim vai ser novo também, pois se os dois são nulos o inico e fim recebe o novo.
    if (lis->inicio == NULL)
    {
        lis->inicio = novo;
        lis->fim = novo;
        //Se a lista já tiver dado se cria outro elemento e aponta o ant para o dado 2 e prox do dado 2 para o 1.
    }
    else
    {
        Elemento *atual; //criar novo elemento caso tenha dado no inicio da lista.
        atual = lis->fim;
        novo->anterior = atual;
        atual->proximo = novo;
        lis->fim = novo;
    }
    lis->tamanho++;
}

//Função para imprimir a lista:
void imprimeLista(Lista *lis)
{
    Elemento *atual;
    atual = lis->inicio;
    while (atual)
    {
        printf(" --> %d\n", atual->valor);
        atual = atual->proximo;
    }
}

//Função para imprimir a lista:

int main()
{
    Lista *li = criarLista();

    push(li, 5);
    push(li, 8);
    push(li, 1);
    push(li, 6);

    //  insereInicio(7, li);
    //insereInicio(10, li);
    //insereInicio(1, li);

    imprimeLista(li);
    printf("\n");

 //   removeInicio(li);
    delete(li, 1);
    imprimeLista(li);
    printf("\n");

  //  removeFim(li);
    //imprimeLista(li);

    printf("\n");
    printf("\n");

  //  destroy(li);
    imprimeLista(li);
    //   lisbera(li);
    system("pause");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct FilaDinamica{
    int valor;
    struct FilaDinamica *prox;
};

struct FilaDinamica *inicio, *fim;
int tamanhomaximo = 10;

int filavazia ()
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}

void inserir (int valor)
{
    struct FilaDinamica *novo;
    novo = (struct FilaDinamica*) malloc (sizeof(struct FilaDinamica));
    novo->valor = valor;
    novo->prox = NULL;
    if (fim == NULL)
        inicio = novo;
    else
        fim->prox = novo;
    fim = novo;
}

void remover ()
{
    int removido;
    struct FilaDinamica *aux;
    aux = inicio;
    removido = inicio->valor;
    inicio = inicio->prox;
    if (inicio == NULL)
        fim = NULL;
    printf("\nO valor %d foi removido da fila\n\n", removido);
    free(aux);
}

void listar ()
{
    struct FilaDinamica *aux;
    aux = inicio;
    printf("\nOs valores inseridos na fila sao: ");
    while(aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n\n");
}

void main()
{
    int opcao, valor, tamanhoatual;
    inicio = NULL;
    fim = NULL;
    opcao = 0;
    tamanhoatual = 0;

    while (opcao != 6)
    {
        printf("\nEscolha uma opcao:");
        printf("\n1 - Inserir um valor na fila");
        printf("\n2 - Remover um valor da fila");
        printf("\n3 - Mostrar o inicio da fila");
        printf("\n4 - Mostrar o fim da fila");
        printf("\n5 - Listar os elementos da fila");
        printf("\n6 - Sair do programa");
        printf("\nOpcao escolhida: ");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            if (tamanhoatual < tamanhomaximo)
            {
                printf("\nQual valor sera inserido na fila: ");
                scanf("%d",&valor);
                printf("\n\n");
                inserir(valor);
                tamanhoatual++;
            }
            else
                printf("\nFila cheia - Nao foi possivel executar essa operacao\n\n");
            break;

        case 2:
            if (filavazia()== 0)
            {
                remover();
                tamanhoatual--;
            }
            else
                printf("\nFila vazia - Nao foi possivel executar essa operacao\n\n");
            break;

        case 3:
            if (filavazia()== 0)
                printf("\nO valor no inicio da fila eh: %d\n\n", inicio->valor);
            else
                printf("\nFila vazia - Nao foi possivel executar essa operacao\n\n");
            break;

        case 4:
            if (filavazia()== 0)
                printf("\nO valor no final da fila eh: %d\n\n", fim->valor);
            else
                printf("\nFila vazia - Nao foi possivel executar essa operacao\n\n");
            break;

        case 5:
            if (filavazia()== 0)
                listar();
            else
                printf("\nFila vazia - Nao foi possivel executar essa operacao\n\n");
            break;
        }
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void show(int *vet, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", vet[i]);
    }
}

void merge(int *vet, int inicio, int meio, int fim)
{
    int *aux, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    //p1 e p2 são dois vetores que serão
    //combinados em um terceiro vetor aux
    p1 = inicio;
    p2 = meio + 1;
    aux = (int *)malloc(tamanho * sizeof(int));

    if (aux != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && fim2)
            {
                //primeiro if else para combinar os vetores
                if (vet[p1] < vet[p2])
                    aux[i] = vet[p1++];
                else
                    aux[i] = vet[p2++];

                //verifica se o vetor acabou
                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    aux[i] = vet[p1++];
                else
                    aux[i] = vet[p2++];
            }
        }
    }
    free(aux);
}

void ordenaMergeSort(int *vet, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = floor((inicio + fim) / 2);
        ordenaMergeSort(vet, inicio, meio);
        ordenaMergeSort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim); //combina as duas metades de forma ordenada
    }
}

int main()
{
    int size, i, *numbersVetor;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &size);

    numbersVetor = (int *)malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        numbersVetor[i] = 1 + rand() % 100;
    }

    printf("** Numero desordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    ordenaMergeSort(numbersVetor, 0, size);

    printf("** Numero ordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    free(numbersVetor);

    system("pause");
    return 0;
}

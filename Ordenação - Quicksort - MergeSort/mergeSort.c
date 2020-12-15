#include <string.h>
#include <stdlib.h>

void merge(int vet[], int start, int m, int end)
{
    int i, j, k;
    int n1 = m - start + 1;
    int n2 = end - m;

    // Vetores temporarios
    int L[n1], R[n2];

    // Copiando os dados para os vetores temporarios L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = vet[start + i];
    for (j = 0; j < n2; j++)
        R[j] = vet[m + 1 + j];

    // Mesclar as matrizes temporárias de volta em vet[l..r]

    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = start; //indice inicial de subarray mesclado

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vet[k] = L[i];
            i++;
        }
        else
        {
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    //Copie os elementos restantes de L[], se houver algum
    while (i < n1)
    {
        vet[k] = L[i];
        i++;
        k++;
    }

    // Copie os elementos restantes de R[], se houver algum
    while (j < n2)
    {
        vet[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted

void mergeSort(int vet[], int start, int end)
{
    if (start < end)
    {
        // (l+r)/2, but avoids overflow for large l and h
        int m = start + (end - start) / 2;

        // Ordena de forma recursiva, primeiro esquerda, depois direita
        mergeSort(vet, start, m);
        mergeSort(vet, m + 1, end);

        merge(vet, start, m, end);
    }
}

void show(int *vet, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", vet[i]);
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
    show(numbersVetor, size);

    mergeSort(numbersVetor, 0, size - 1);

    printf("** Numero ordenados ** \n");
    show(numbersVetor, size);

    free(numbersVetor);

    system("pause");
    return 0;
}

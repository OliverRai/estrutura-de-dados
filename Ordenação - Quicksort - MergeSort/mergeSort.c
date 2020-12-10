#include <stdio.h>
#include <limits.h>

void show(int *vet, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", vet[i]);
    }
}

/* Intercala as seqüências v[p]..v[q-1] e v[q]..v[r] */
void intercala (int inicio, int meio, int fim, int v[]) {
  int i, j, k;
  int *vetorAux = (int *)malloc((fim+inicio) * sizeof(int));

  i = inicio; 
  j = meio;
  k = 0;

  while (i < meio && j <= fim) {
    if (v[i] <= v[j])  
      vetorAux[k++] = v[i++];
    else  
      vetorAux[k++] = v[j++];
  }
  
  while (i < meio)  
    vetorAux[k++] = v[i++];

  while (j <= fim)  
    vetorAux[k++] = v[j++];

  for (i = inicio; i <= fim; i++)  
    v[i] = vetorAux[i-inicio];
}

void mergesort (int inicio, int fim, int v[]) {
  if (inicio < fim) {
    int meio = (inicio + fim)/2;
    mergesort (inicio, meio, v);
    mergesort (meio + 1, fim, v);
    intercala (inicio, meio + 1, fim, v);
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

    mergesort(0, size - 1, numbersVetor);
    mergesort(numbersVetor, 0, size - 1);

    printf("** Numero ordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    free(numbersVetor);

    system("pause");
    return 0;
}
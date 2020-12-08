#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void show(int *vet, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("Numero --->  %d \n", vet[i]);
  }
}

void ordenacaoQuicksort(int *vet, int inicio, int size){

}

int main()
{
  int size, i, *vetor;

  printf("Informe o tamanho do vetor: ");
  scanf("%d", &size);

  vetor = (int *)malloc(size * sizeof(int));

  for (i = 0; i < size; i++)
  {
    vetor[i] = 1 + rand() % 100;
  }

  printf("** Numero desordenados ** \n");

  show(vetor, size);

  ordenacaoQuicksort(vetor, 0, size);

  system("pause");
  return 0;

}
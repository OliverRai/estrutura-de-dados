#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void show(int *vet, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", vet[i]);
    }
}

void merge(int *vet, int inicio, int fim)
{
    int meio = (inicio + fim) / 2;
    int i = inicio;
    int j = meio + 1;
    int k = inicio; 
    int *vetorAux = (int *)malloc((fim + inicio) * sizeof(int)); //vetor auxiliar 

    while(i <= meio && j <= fim){
        //compara se o primeiro indice i é menor que o primeiro indice j,
        //se for manda o indice i para o vetor auxiliar
        if(vet[i] < vet[j]){
            vetorAux[k++] = vet[i++]; //incrementa
        }
        //se não for, manda o indice j  para o vetor auxiliar
        else{
            vetorAux[k++] = vet[j++]; //incrementa
        }
    }
    while(i <= meio){
        vetorAux[k++] = vet[i++];
    }
    while(j <= fim){
        vetorAux[k++] = vet[j++];
    }

    //copiar todos os elemetos para o vetor original
    for(i = inicio ; i < fim ;i++){
        vet[i] = vetorAux[i];
    }

    free(vetorAux);
}

void ordenaMergeSort(int vet[], int inicio, int fim)
{
    //verifica 1 ou 0 elementos
    if (inicio >= fim){
        return;
    }
    //divide o vetor
    int meio = (inicio + fim) / 2;
    //chama de forma recursiva
    ordenaMergeSort(vet, inicio, meio); // lado esquerdo
    ordenaMergeSort(vet, meio + 1, fim); //lado direito
    merge(vet, inicio, fim); //combina as duas metades de forma ordenada
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

    ordenaMergeSort(numbersVetor, 0, size - 1);

    printf("** Numero ordenados ** \n");
    show(numbersVetor, size);

    free(numbersVetor);

    system("pause");
    return 0;
}

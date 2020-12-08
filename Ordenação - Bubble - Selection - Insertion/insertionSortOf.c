#include <stdlib.h>
#include <stdio.h>

void ordenar(int vet[], int n)
{
    int i, j, aux;
    for (i = 0; i < n; i++)
    {   
        int aux = vet[i];
        j = i - 1;
        while(j >= 0 && aux < vet[j]){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = aux;
    }
}

int main()
{
    int size, i, aux;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &size);

    int numbersVetor[size];

    for (i = 0; i < size; i++)
    {
        numbersVetor[i] = 1 + rand() % 100;
    }

    printf("** Numero desordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    ordenar(numbersVetor, size);

    printf("** Numero desordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    system("pause");
    return 0;
}

//melhor caso: O(n)
//pior caso: o(n*2)
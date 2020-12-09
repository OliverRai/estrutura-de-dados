#include <stdlib.h>
#include <stdio.h>

void ordenar(int vet[], int n)
{
    int i, j, aux;
    for (i = 0; i < n; i++)
    {   
        //comparar o valor com os outros até que encontre sua posição
        //vetor ex: 1 | 3 | 22 | 54 | 62 | 20
        int aux = vet[i]; //ex aleatorio i = 20 (62)
        j = i - 1; // j = index - 1, uma posição a menos
        while(j >= 0 && aux < vet[j]){ //enquanto j > 0 e o aux(i) < vet[j] // procura o menor
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
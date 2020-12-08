#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void ordena(int vetor[], int n)
{
    int cont, aux, i;
    for (cont = 1; cont < n; cont++)
    {
        bool troca = false;
        for (i = 0; i < n - 1; i++)
        {
            if (vetor[i] > vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                troca = true;
            }   
        }
        if(troca == false){
            break;
        }
    }
}

int main()
{
    int size, i, *numbersVetor;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &size);

    numbersVetor = (int *) malloc(size * sizeof(int));

    for (i = 0; i < size; i++)
    {
        numbersVetor[i] = 1 + rand() % 100;
    }

    printf("** Numero desordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    ordena(numbersVetor, size);

    printf("** Numero ordenados ** \n");
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    free(numbersVetor);

    system("pause");
    return 0;
}

//melhor caso: O(n)
//pior caso: O(n*2)
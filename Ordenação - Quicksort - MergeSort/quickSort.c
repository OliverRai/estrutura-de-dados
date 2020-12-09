#include <stdio.h>

int particiona(int *vetor, int inicio, int final){
    int esquerda, direita, pivo, aux;
    esquerda = inicio;
    direita = final;

    pivo = vetor[inicio];

    while(esquerda < direita){
        while (vetor[esquerda] <= pivo){ //avança a posição da esquerda
            esquerda++;
        }
        while(vetor[direita] > pivo){//recua a posição da direita
            direita--;
        }
        if(esquerda < direita){ // troca esquerda e direita
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;
    return direita;
}

void ordenarQuicksort(int vetor[], int inicio, int fim)
{
   int pivo;
   if(fim > inicio){
       pivo = particiona(vetor, inicio, fim); // pra pegar a posição do pivo
       ordenarQuicksort(vetor, inicio, pivo - 1); 
       ordenarQuicksort(vetor, pivo + 1, fim);
   }
}

void show(int *vet, int size)
{   
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Numero --->  %d \n",  vet[i]);
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

    show(numbersVetor, size);

    ordenarQuicksort(numbersVetor, 0, size);

    printf("** Numero ordenados ** \n");
    show(numbersVetor, size);

    system("pause");
    return 0;
}
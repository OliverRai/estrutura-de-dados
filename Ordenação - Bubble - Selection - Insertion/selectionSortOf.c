#include <stdio.h>
#include <stdlib.h>

void ordenar(int vetNumbers[], int n){
    int menor, aux, i, j;
    for(i=0 ; i < n - 1 ; i++){ //o i começa em 0 e vai até a pneultima posição do vetor
        menor = i; //menor valor no momento da execução, ou seja, 0

        for(j = i + 1 ; j < n ; j++){ // j = 1 ;
            if(vetNumbers[j] < vetNumbers[menor]){ 
                menor = j; // se sim, o menor vai deixar de ser i e será o j
            }
        }
        if(i != menor){
            aux = vetNumbers[i];
            vetNumbers[i] = vetNumbers[menor];
            vetNumbers[menor] = aux;
        }
    }
}

int main(){

    int size, i;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &size);

    int numbersVetor[size];


    for(i = 0; i < size; i++){
        numbersVetor[i] = 1 + rand() % 100;
    }
    printf("** Numero desordenados ** \n");
    for (i = 0; i < size; i++){
        printf("Numero --->  %d \n", numbersVetor[i]);
    }

    ordenar(numbersVetor, size);
       
    printf("** Numero ordenados ** \n");
    for(i = 0 ; i < size ; i++){
         printf("Numero --->  %d \n", numbersVetor[i]);
    }

    system("pause");
    return 0;
}


//melhor caso: O(n^2)
//pior caso: O(n^2)
///n = 10.000.000 
//n = 10 x 10⁹
//Complexidade = n²
//Complexidade = 10 x (10⁹) ²  //10.000.000.000.000.000.000
//Complexidade = 10 x 10¹⁸ // 100.000.000.000.000
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ponto{
    int x, y; //coordenada dos pontos
    struct ponto * proximo; // um ponteiro para o próximo elemento
}t_ponto;

int main()
{
    t_ponto * ini_ponto;
    t_ponto * proxi_ponto;
    int resp;

    ini_ponto = (t_ponto *)  malloc(sizeof(t_ponto)); // retona null se não conseguir alocar
    if(ini_ponto == NULL){
        exit(true); 
        //sai da ex
    }
    //proximo ponto recebe o endereco do ponto inicial
    proxi_ponto = ini_ponto;
    while(true){
        printf("Digite x: ");
        scanf("%d", &proxi_ponto->x); //quando se tem um ponteiro struct se acessa as váriaveis com seta
        printf("Digite y: ");
        scanf("%d", &proxi_ponto->y);
        printf("Deseja continuar? <1> SIM <outro valor> NAO: ");
        scanf("%d", &resp);
    }

    return 0;
}
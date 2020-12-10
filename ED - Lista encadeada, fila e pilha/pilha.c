#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;


typedef struct 
{
    TIPOCHAVE chave;

} Registro;

typedef struct aux
{
    Registro reg;
    struct aux* prox;    
} ELEMENTO, *PONT;

typedef struct
{
    PONT inicio;
    PONT fim;
} FILA;



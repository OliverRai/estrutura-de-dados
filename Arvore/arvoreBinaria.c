#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
  int info; //valor há ser inserido
  struct NO *esq; // crio esquerda e direita na mesma estrutura
  struct NO *dir;
}NO;

typedef struct tree{
  NO *raiz;
} Arvore;

Arvore *criararvore()
{
  Arvore *arv = (Arvore *)malloc(sizeof(Arvore));
  if (arv == NULL)
  {
    return arv;
  } // ele cria uma arvore vazia e retorna a propria arvore com o tamanho alocado

  arv->raiz = NULL;
  return arv;
}

void destroy(NO *raiz){
  if(raiz != NULL){
    destroy(raiz->esq);
    destroy(raiz->dir);
    free(raiz);
  }
}

void destryTree(Arvore *arv){
  if(arv == NULL){
    return;
  }
  destroy(arv->raiz);
  free(arv);
}

 //Funcao que verifica se arvore esta vazia
int vazia(Arvore *arv)
{
  if (arv->raiz == NULL)
  {
    printf("Arvore vazia!\n");
    return 1;
  }
 // if (*raiz == NULL)
 // {
 //   printf("Arvore vazia!\n");
 //   return 1;
 // }
  printf("Arvore não vazia!\n");
  return 0;
}

//Funcao que percorre arvore em pré ordem
void preOrdem(Arvore *arv)
{
  if (arv->raiz == NULL)
  {
    return;
  }
  if (arv->raiz != NULL)
  {
    printf("%d\n", arv->raiz->info); //printa o que tem dentro do
    preOrdem(&((arv->raiz->esq)));     // vai percorrendo pela esquerda até que toda a arvore seja percorrida
    preOrdem(&((arv->raiz->dir)));
  }
}

// //Função que percorre árvore EM ORDEM
void emOrdem(Arvore *arv)
{
  if (arv->raiz == NULL)
  {
    return; //verifica se é um raiz vazia
  }
  if (arv->raiz != NULL)
  {
    emOrdem(&(arv->raiz->esq));
    printf("%d\n", arv->raiz->info); //compara qual é o menor e vai percorrendo todo o lado esquedo para o direito, printando assim em ordem
    emOrdem(&(arv->raiz->dir));
  }
}

// //Função que percorre raiz em PÓS ORDEM
void posOrdem(Arvore *arv)
{
  if (arv->raiz == NULL)
  {
    return;
  }
  if (arv->raiz != NULL)
  {
    posOrdem(&(arv->raiz->esq));
    posOrdem(&(arv->raiz->dir)); //ele percorre a arvore ao contrario, pegando os filhos dos nos mais internos, vai recebend o prox do prox enderaço e asassim sucessivamente
    printf("%d\n", arv->raiz->info);
  }
}

void add(NO *raiz, NO *novo){
  if(raiz->info > novo->info){
    if(raiz->esq == NULL){
      raiz->esq = novo;
    } else {
      add(raiz->esq, novo);
    }
  }
  else if(raiz->info < novo->info){
    if(raiz->dir == NULL){
      raiz->dir = novo;
    }
    else {
      add(raiz->dir, novo);
    }
  }
}

int insere(Arvore *arv, int valor)
{
  if (arv == NULL)
  {
    return 0;
  }                //verifica se esta fazia
  NO *novo; //cria um no auxiliar
  novo = (NO*)malloc(sizeof(NO));
  if(novo == NULL){
    return;
  }
  novo->esq = novo->dir = NULL;
  novo->info = valor;

  if(arv->raiz == NULL){
    arv->raiz = novo;
  }
  else {
    add(arv->raiz, novo);
  }
}

NO *removendo_atual(NO *atual)
{
  NO *no1, *no2;
  if (atual->esq == NULL)
  {
    no2 = atual->dir;
    free(atual);
    return no2;
  }
  no1 = atual;
  no2 = atual->esq;
  while (no2->dir != NULL)
  {
    no1 = no2;
    no2 = no2->dir;
  }

  if (no1 != atual)
  {
    no1->dir = no2->esq;
    no2->esq = atual->esq;
  }
  no2->dir = atual->dir;
  free(atual);
  return no2;
}

//Função que remove um elemento da árvore binária
int remover(Arvore *arv, int valor)
{
  if (arv->raiz == NULL)
  {
    return 0;
  }
  NO *ant = NULL;    //variavel auxiliar
  NO *atual = arv->raiz; //o atual recebe a raiz para poder percorrer a arvore toda
  while (atual != NULL)
  { //enquanto ele for nu, ele continua no laço
    if (valor == atual->info)
    {
      if (atual == arv->raiz)
      {
        arv->raiz = removendo_atual(atual);
        //faz uma chamada recursiva para remover o no ja achado
      }
      else
      {
        if (ant->dir == atual)
        { //faz a comparação se for maior remove pela a direita usando recursividade, mesmo pensamento do inserir
          ant->dir = removendo_atual(atual);
        }
        else
        { //mesmo procedimento
          ant->esq = removendo_atual(atual);
        }
      }
      return 1;
    }
    ant = atual;
    if (valor > atual->info)
    {
      atual = atual->dir; //realocando os nos depois de excluir
    }
    else
    { //realocando os nos depois de excluir
      atual = atual->esq;
    }
  }
}

int main()
{
    Arvore *arv = criararvore();
    insere(arv, 5);
    insere(arv, 2);
    insere(arv, 6);
    insere(arv, 8);
    insere(arv, 3);
    insere(arv, 10);
    preOrdem(arv);
    printf("\n");
    emOrdem(arv);
    printf("\n");
    posOrdem(arv);
    printf("\n");
    remover(arv, 10);
    emOrdem(arv);
  
  system("pause");
  return 0;
}
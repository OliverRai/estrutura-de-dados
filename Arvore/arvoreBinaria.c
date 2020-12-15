#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
  int info;       //valor há ser inserido
  struct NO *esq; // crio esquerda e direita na mesma estrutura
  struct NO *dir;
} NO;

typedef struct tree
{
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

// void destroy(NO *raiz){
//   if(raiz != NULL){
//     destroy(raiz->esq);
//     destroy(raiz->dir);
//     free(raiz);
//   }
// }

// void destroyTree(Arvore *arv){
//   if(arv == NULL){
//     return;
//   }
//   destroy(arv->raiz);
//   free(arv);
// }

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
    preOrdem(&((arv->raiz->esq)));   // vai percorrendo pela esquerda até que toda a arvore seja percorrida
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

void add(NO *raiz, NO *novo)
{
  if (raiz->info > novo->info)
  {
    if (raiz->esq == NULL)
    {
      raiz->esq = novo;
    }
    else
    {
      add(raiz->esq, novo);
    }
  }
  else if (raiz->info < novo->info)
  {
    if (raiz->dir == NULL)
    {
      raiz->dir = novo;
    }
    else
    {
      add(raiz->dir, novo);
    }
  }
}

int insere(Arvore *arv, int valor)
{
  if (arv == NULL)
  {
    return 0;
  }         //verifica se esta fazia
  NO *novo; //cria um no auxiliar
  novo = (NO *)malloc(sizeof(NO));
  if (novo == NULL)
  {
    return;
  }
  novo->esq = novo->dir = NULL;
  novo->info = valor;

  if (arv->raiz == NULL)
  {
    arv->raiz = novo;
  }
  else
  {
    add(arv->raiz, novo);
  }
}

NO *MaiorDireita(NO **no){
   if((*no)->dir != NULL) 
       return MaiorDireita(&(*no)->dir);
    else{
      NO *aux = *no;
      if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
           *no = (*no)->esq;
        else
           *no = NULL;
        return aux;
    }
}

void remover(NO **pRaiz, int numero)
{
  if (*pRaiz == NULL)
  { // esta verificacao serve para caso o numero nao exista na arvore.
    printf("Numero nao existe na arvore!");
    getch(); // getch() é fogo, mas tudo bem
    return;
  }

  if (numero < (*pRaiz)->info)
    remover(&(*pRaiz)->esq, numero);
  else if (numero > (*pRaiz)->info)
    remover(&(*pRaiz)->dir, numero);
  else
  {                    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
    NO *pAux = *pRaiz; // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
    if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL))
    { // se nao houver filhos...
      free(pAux);
      (*pRaiz) = NULL;
    }
    else
    { // so tem o filho da direita
      if ((*pRaiz)->esq == NULL)
      {
        (*pRaiz) = (*pRaiz)->dir;
        pAux->dir = NULL;
        free(pAux);
        pAux = NULL;
      }
      else
      { //so tem filho da esquerda
        if ((*pRaiz)->dir == NULL)
        {
          (*pRaiz) = (*pRaiz)->esq;
          pAux->esq = NULL;
          free(pAux);
          pAux = NULL;
        }
        else
        {                                           //Escolhi fazer o maior filho direito da subarvore esquerda.
          pAux = MaiorDireita(&(*pRaiz)->esq); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
          pAux->esq = (*pRaiz)->esq;      //        pAux = MenorEsquerda(&(*pRaiz)->direita);
          pAux->dir = (*pRaiz)->dir;
          (*pRaiz)->esq = (*pRaiz)->esq = NULL;
          free((*pRaiz));
          *pRaiz = pAux;
          pAux = NULL;
        }
      }
    }
  }
}

int main()
{
  Arvore *arv = criararvore();
  insere(arv, 8);
  insere(arv, 4);
  insere(arv, 12);
  insere(arv, 2);
  insere(arv, 6);
  insere(arv, 10);
  insere(arv, 14);
  insere(arv, 1);
  insere(arv, 3);
  insere(arv, 5);
  insere(arv, 11);
  insere(arv, 13);
  insere(arv, 15);

  preOrdem(arv);
  printf("\n");
  printf("\n");
  remover(arv, 4);
  preOrdem(arv);

  system("pause");
  return 0;
}
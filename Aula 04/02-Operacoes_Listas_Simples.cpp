#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void inserir_inicio(celula **ptr_cabeca, int valor) {
  celula *nova = (celula *)malloc(sizeof(celula));
  nova->conteudo = valor;
  nova->prox = *ptr_cabeca;
  *ptr_cabeca = nova;
}

void inserir_fim(celula **cabeca, int valor) {
  celula *nova = (celula *)malloc(sizeof(celula));
  nova->conteudo = valor;
  nova->prox = NULL;

  // Caso de lista vazia
  if (*cabeca == NULL) {
    *cabeca = nova;
    return;
  }

  celula *aux = *cabeca;
  while (aux != NULL) {
    if (aux->prox == NULL) {
      aux->prox = nova;
      break;
    }
    aux = aux->prox;
  }
}

celula *buscar(celula *aux, int valor) {
  while (aux != NULL) {
    if (aux->conteudo == valor) {
      return aux;  //"Elemento encontrado"
    }
    aux = aux->prox;
  }
  return NULL;  //"Elemento não encontrado"
}

void remover(celula **ptr_cabeca, int valor) {
  // Remover elemento que é cabeça
  if ((*ptr_cabeca)->conteudo == valor) {
    celula *tmp = *ptr_cabeca;
    *ptr_cabeca = (*ptr_cabeca)->prox;
    free(tmp);
    return;
  }

  // Remover demais elementos
  celula *aux = *ptr_cabeca;
  celula *p = NULL;
  while (aux != NULL) {
    p = aux->prox;
    if ((p != NULL) && (p->conteudo == valor)) {
      aux->prox = p->prox;
      free(p);
      return;
    }
    aux = aux->prox;
  }
}

int main(int argc, char const *argv[]) {
  celula *cabeca = NULL;

  inserir_inicio(&cabeca, 5);
  inserir_inicio(&cabeca, 3);
  inserir_fim(&cabeca, 7);
  inserir_fim(&cabeca, 1);

  // remover(&cabeca, 3);

  // celula *res = buscar(cabeca, 7);
  // if (res != NULL) {
  //   printf("Encontrou %d\n", res->conteudo);
  //   // res->conteudo = 9;
  // } else {
  //   printf("Não encontrou\n");
  // }

  imprimir(cabeca);

  return 0;
}

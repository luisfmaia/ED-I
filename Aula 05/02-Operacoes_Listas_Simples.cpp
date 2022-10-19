#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
  struct cel *ant;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void troca(celula *elem1, celula *elem2) {
  celula *prim = elem1->ant;
  celula *ult = elem2->prox;

  prim->prox = elem2;
  ult->ant = elem1;
  elem2->prox = elem1;
  elem1->prox = ult;
  elem1->ant = elem2;
  elem2->ant = prim;
}

celula *ultimo(celula *aux) {
  if (aux == NULL) {
    return NULL;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }
  return aux;
}

void merge(celula **c1, celula *c2) {
  if (c2 == NULL) return;

  if (*c1 == NULL) {
    *c1 = c2;
    return;
  }

  celula *u = ultimo(*c1);
  u->prox = c2;

  c2->ant = u;
}

int tamanho(celula *cabeca) {
  if (cabeca == NULL) {
    return 0;
  }

  int tam = 0;
  celula *aux = cabeca;
  while (aux != NULL) {
    aux = aux->prox;
    tam++;
  }
  return tam;
}

celula *metade(celula *cabeca1) {
  int tam_total = tamanho(cabeca1);
  if (tam_total == 1) {
    return NULL;
  }

  int tam1 = ceil(tam_total / 2.0f);
  printf("TAM1: %d\n", tam1);

  celula *cabeca2 = NULL;

  celula *aux = cabeca1;
  int i = 0;
  while (i < tam1 - 1) {
    aux = aux->prox;
    i++;
  }

  cabeca2 = aux->prox;
  aux->prox = NULL;
  cabeca2->ant = NULL;

  return cabeca2;
}

int main(int argc, char const *argv[]) {
  celula c1;
  celula c2;
  celula c3;
  celula c4;
  celula c5;

  c1.conteudo = 1;
  c2.conteudo = 2;
  c3.conteudo = 3;
  c4.conteudo = 4;
  c5.conteudo = 5;

  c1.ant = NULL;
  c1.prox = &c2;
  c2.ant = &c1;
  c2.prox = &c3;
  c3.ant = &c2;
  c3.prox = NULL;

  c4.ant = NULL;
  c4.prox = &c5;
  c5.ant = NULL;
  c5.prox = NULL;

  celula *cabeca1 = &c5;
  // celula *cabeca2 = &c4;

  imprimir(cabeca1);
  // imprimir(cabeca2);
  celula *cabeca2 = metade(cabeca1);
  imprimir(cabeca1);
  imprimir(cabeca2);
  // cabeca2 = metade(cabeca1);
  // imprimir(cabeca1);
  // imprimir(cabeca2);

  return 0;
}

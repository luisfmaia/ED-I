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

int main(int argc, char const *argv[]) {
  celula c1;
  celula c2;
  celula c3;
  celula c4;

  c1.conteudo = 1;
  c2.conteudo = 2;
  c3.conteudo = 3;
  c4.conteudo = 4;

  c1.ant = NULL;
  c1.prox = &c2;
  c2.ant = &c1;
  c2.prox = &c3;
  c3.ant = &c2;
  c3.prox = &c4;
  c4.ant = &c3;
  c4.prox = NULL;

  celula *cabeca = &c1;

  imprimir(cabeca);

  troca(&c2, &c3);

  imprimir(cabeca);

  return 0;
}

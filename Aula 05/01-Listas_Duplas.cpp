#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
  struct cel *ant;
} celula;

int main(int argc, char const *argv[]) {
  celula c1;
  celula c2;
  celula c3;
  celula c4;

  c1.conteudo = 3;
  c2.conteudo = 5;
  c3.conteudo = 7;
  c4.conteudo = 1;

  c1.ant = NULL;
  c1.prox = &c2;
  c2.ant = &c1;
  c2.prox = &c3;
  c3.ant = &c2;
  c3.prox = &c4;
  c4.ant = &c3;
  c4.prox = NULL;

  celula *cabeca = &c1;

  celula *cauda = &c4;

  celula *cel = cabeca;
  printf("Do primeiro ao último\n");
  while (cel != NULL) {
    printf("Conteudo: %d\n", cel->conteudo);
    cel = cel->prox;
  }

  cel = cauda;
  printf("Do último ao primeiro\n");
  while (cel != NULL) {
    printf("Conteudo: %d\n", cel->conteudo);
    cel = cel->ant;
  }

  scanf("%d", &c1.conteudo);

  return 0;
}

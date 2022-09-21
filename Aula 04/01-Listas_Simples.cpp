#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

int main(int argc, char const *argv[]) {
  celula c1;
  celula c2;
  celula c3;
  celula c4;

  celula *cabeca;

  c1.conteudo = 3;
  c2.conteudo = 5;
  c3.conteudo = 7;
  c4.conteudo = 1;

  c1.prox = &c2;
  c2.prox = &c3;
  c3.prox = &c4;
  c4.prox = NULL;

  cabeca = &c1;

  celula *cel = cabeca;
  while (cel != NULL) {
    printf("Conteudo: %d\n", cel->conteudo);
    cel = cel->prox;
  }

  return 0;
}

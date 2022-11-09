#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int conteudo;
  struct elem *prox;
} element;

void push(element **top, element *e) {
  e->prox = *top;
  *top = e;
}

element *pop(element **top) {
  if (*top == NULL) {
    return NULL;
  }
  element *p = *top;
  *top = (*top)->prox;
  p->prox = NULL;
  return p;
}

void print(element *aux) {
  while (aux != NULL) {
    printf("%d\n", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}

int size(element *aux) {
  int s = 0;
  while (aux != NULL) {
    s++;
    aux = aux->prox;
  }
  return s;
}

void clear(element **top) {
  element *aux = pop(top);
  while (aux != NULL) {
    // free(aux);
    aux = pop(top);
  }
}

int position(element *aux, element *e) {
  int s = 0;
  while (aux != NULL) {
    s++;
    if (e->conteudo == aux->conteudo) {
      return s;
    }
    aux = aux->prox;
  }
  return -1;
}

bool is_empty(element *top) {
  return (top == NULL);
  //   if (top == NULL) {
  //     return true;
  //   } else {
  //     return false;
  //   }
}

int main(int argc, char const *argv[]) {
  element *top = NULL;

  element e1, e2, e3, e4;
  e1.conteudo = 27;
  e2.conteudo = 22;
  e3.conteudo = 13;
  e4.conteudo = 4;

  push(&top, &e1);
  push(&top, &e2);
  push(&top, &e3);
  push(&top, &e4);
  print(top);

  printf("Tam: %d\n", size(top));

  printf("Position: %d, %d\n", position(top, &e2), e2.conteudo);

  element *p = pop(&top);
  printf("Pop: %d\n", p->conteudo);

  printf("is_empty: %d\n", is_empty(top));

  clear(&top);

  printf("is_empty: %d\n", is_empty(top));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int conteudo;
  struct elem *prox;
} element;

void enqueue(element **last, element *e, element **first = NULL) {
  e->prox = NULL;
  if (*last == NULL) {
    *first = e;
    *last = e;
    return;
  }
  (*last)->prox = e;
  *last = e;
}

element *dequeue(element **first, element **last = NULL) {
  if (*first == NULL) {
    return NULL;
  }
  element *front = *first;
  (*first) = (*first)->prox;
  if (*first == NULL) {
    *last == NULL;
  }
  front->prox = NULL;
  return front;
}

void print(element *aux) {
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
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

void clear(element **first) {
  element *aux = dequeue(first);
  while (aux != NULL) {
    // free(aux);
    aux = dequeue(first);
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

bool is_empty(element *first) {
  return (first == NULL);
  //   if (top == NULL) {
  //     return true;
  //   } else {
  //     return false;
  //   }
}

int main(int argc, char const *argv[]) {
  element *first = NULL;
  element *last = NULL;

  element e1, e2, e3, e4;
  e1.conteudo = 27;
  e2.conteudo = 22;
  e3.conteudo = 13;
  e4.conteudo = 4;

  enqueue(&last, &e1, &first);
  enqueue(&last, &e2);
  enqueue(&last, &e3);
  enqueue(&last, &e4);
  print(first);

  printf("Tam: %d\n", size(first));

  printf("Position: %d, %d\n", position(first, &e2), e2.conteudo);

  element *p = dequeue(&first);
  printf("Dequeue: %d\n", p->conteudo);
  print(first);

  printf("is_empty: %d\n", is_empty(first));

  clear(&first);

  printf("is_empty: %d\n", is_empty(first));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int conteudo = 0;
  struct elem *prox = NULL;
} element;

typedef struct {
  element *top = NULL;
  int length = 0;
} stack;

int size(stack *s) { return s->length; }

element *top(stack *s) { return s->top; }

void print(stack *s) {
  element *aux = s->top;
  while (aux != NULL) {
    printf("%d|", aux->conteudo);
    aux = aux->prox;
  }
  printf("\n");
}

void push(stack *s, int content) {
  element *new_elem = (element *)malloc(sizeof(element));
  new_elem->conteudo = content;
  new_elem->prox = s->top;
  s->top = new_elem;
  s->length++;
}

element *pop(stack *s) {
  if (s->length == 0) return NULL;

  element *rem = s->top;
  s->top = rem->prox;
  rem->prox = NULL;
  s->length--;
  return rem;
}

void clear(stack *s) {
  element *aux = pop(s);
  while (aux != NULL) {
    free(aux);
    aux = pop(s);
  }
}

bool is_empty(stack *s) { return (size(s) == 0); }

int main(int argc, char const *argv[]) {
  stack s;

  push(&s, 27);
  push(&s, 21);
  push(&s, 14);
  push(&s, 36);

  print(&s);
  printf("size: %d\n", size(&s));

  element *p = pop(&s);
  printf("pop: %d\n", p->conteudo);

  print(&s);
  printf("size: %d\n", size(&s));
  printf("is_empty: %d\n", is_empty(&s));

  printf("clear\n");
  clear(&s);

  printf("is_empty: %d\n", is_empty(&s));

  return 0;
}
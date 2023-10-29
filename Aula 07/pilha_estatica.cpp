#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
  int vetor[MAX_SIZE];
  int top = -1;
} stack;

int size(stack *s) { return s->top + 1; }

int top(stack *s) {
  if (size(s) == 0) return 0;

  return s->vetor[s->top];
}

void print(stack *s) {
  for (int i = s->top; i >= 0; i--) {
    printf("%d|", s->vetor[i]);
  }
  printf("\n");
}

void push(stack *s, int content) {
  if (size(s) == MAX_SIZE) return;

  s->top++;
  s->vetor[s->top] = content;
}

int pop(stack *s) {
  if (size(s) == 0) return 0;

  int rem = s->vetor[s->top];
  s->top--;
  return rem;
}

void clear(stack *s) { s->top = -1; }

bool is_empty(stack *s) { return (size(s) == 0); }

int main(int argc, char const *argv[]) {
  stack s;

  push(&s, 27);
  push(&s, 21);
  push(&s, 14);
  push(&s, 36);

  print(&s);
  printf("size: %d\n", size(&s));

  int elem = pop(&s);
  printf("pop: %d\n", elem);

  print(&s);
  printf("size: %d\n", size(&s));
  printf("is_empty: %d\n", is_empty(&s));

  printf("clear\n");
  clear(&s);

  printf("is_empty: %d\n", is_empty(&s));

  return 0;
}
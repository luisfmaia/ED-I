#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct {
  int elements[TAM];
  int top = -1;
} stack;

void push(stack *stack, int element) {
  if (stack->top < TAM - 1) {
    stack->top += 1;
    stack->elements[stack->top] = element;
  }
}

int pop(stack *stack) {
  if (stack->top == -1) {
    return -1;
  }
  int p = stack->elements[stack->top];
  stack->top -= 1;
  return p;
}

void print(stack *stack) {
  for (int i = stack->top; i >= 0; i--) {
    printf("%d\n", stack->elements[i]);
  }
}

int size(stack *stack) { return stack->top + 1; }

void clear(stack *stack) { stack->top = -1; }

int position(stack *stack, int e) {
  for (int i = stack->top; i >= 0; i--) {
    if (stack->elements[i] == e) {
      return i + 1;
    }
  }
}

bool is_empty(stack *stack) { return (stack->top == -1); }

int main(int argc, char const *argv[]) {
  stack s;

  push(&s, 27);
  push(&s, 22);
  push(&s, 13);
  push(&s, 4);
  push(&s, 10);
  push(&s, 99);
  print(&s);

  printf("Tam: %d\n", size(&s));

  printf("Position: %d, %d\n", position(&s, 22), 22);

  int p = pop(&s);
  printf("Pop: %d\n", p);

  printf("is_empty: %d\n", is_empty(&s));

  clear(&s);

  printf("is_empty: %d\n", is_empty(&s));

  return 0;
}

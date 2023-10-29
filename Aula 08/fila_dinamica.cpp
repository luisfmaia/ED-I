#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
  int content = 0;
  struct elem *prox = NULL;
} element;

typedef struct {
  element *first = NULL;
  element *last = NULL;
  int length = 0;
} queue;

void enqueue(queue *q, int content) {
  element *new_elem = (element *)malloc(sizeof(element));
  new_elem->content = content;

  q->length++;
  if (q->last == NULL) {
    q->first = new_elem;
    q->last = new_elem;
  } else {
    q->last->prox = new_elem;
    q->last = new_elem;
  }
}

element *dequeue(queue *q) {
  if (q->length == 0) {
    return NULL;
  }

  q->length--;
  element *front = q->first;
  q->first = q->first->prox;
  if (q->length == 0) {
    q->last = NULL;
  }

  front->prox = NULL;
  return front;
}

void print(queue *q) {
  element *aux = q->first;
  while (aux != NULL) {
    printf("%d->", aux->content);
    aux = aux->prox;
  }
  printf("NULL\n");
}

int size(queue *q) { return q->length; }

void clear(queue *q) {
  element *aux = dequeue(q);
  while (aux != NULL) {
    free(aux);
    aux = dequeue(q);
  }
}

int position(queue *q, element *e) {
  int pos = 0;
  element *aux = q->first;
  while (aux != NULL) {
    pos++;
    if (e->content == aux->content) {
      return pos;
    }
    aux = aux->prox;
  }
  return -1;
}

bool is_empty(queue *q) { return (q->length == 0); }

int main(int argc, char const *argv[]) {
  queue q;

  enqueue(&q, 27);
  enqueue(&q, 21);
  enqueue(&q, 14);
  enqueue(&q, 36);

  print(&q);
  printf("size: %d\n", size(&q));

  element *p = dequeue(&q);
  printf("dequeue: %d\n", p->content);

  print(&q);
  printf("size: %d\n", size(&q));
  printf("is_empty: %d\n", is_empty(&q));

  printf("clear\n");
  clear(&q);

  printf("is_empty: %d\n", is_empty(&q));

  return 0;
}

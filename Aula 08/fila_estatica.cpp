#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct fila {
  int elements[MAX_SIZE];
  int first = -1;
  int last = -1;
} queue;

void enqueue(queue *q, int content) {
  if ((q->last) - (q->first) < MAX_SIZE - 1) {
    q->last += 1;
    q->elements[q->last] = content;
    if (q->first == -1) q->first = 0;
  }
}

int dequeue(queue *q) {
  if (q->first == -1) {
    return -1;
  }

  if (q->last == q->first) {
    int front = q->elements[q->first];
    q->first = -1;
    q->last = -1;
    return front;
  }

  int front = q->elements[q->first];
  q->first += 1;
  return front;
}

void print(queue *q) {
  for (int i = q->first; i <= q->last; i++) {
    printf("%d->", q->elements[i]);
  }
  printf("NULL\n");
}

int size(queue *q) { return (q->last) - (q->first) + 1; }

void clear(queue *q) {
  q->first = -1;
  q->last = -1;
}

int position(queue *q, int e) {
  for (int i = q->first; i <= q->last; i++) {
    if (q->elements[i] == e) {
      return i - q->first + 1;
    }
  }
  return -1;
}

bool is_empty(queue *q) { return (q->first == -1); }

int main(int argc, char const *argv[]) {
  queue q;

  enqueue(&q, 27);
  enqueue(&q, 21);
  enqueue(&q, 14);
  enqueue(&q, 36);

  print(&q);
  printf("size: %d\n", size(&q));

  int elem = dequeue(&q);
  printf("dequeue: %d\n", elem);

  print(&q);
  printf("size: %d\n", size(&q));
  printf("is_empty: %d\n", is_empty(&q));

  printf("clear\n");
  clear(&q);

  printf("is_empty: %d\n", is_empty(&q));

  return 0;
}
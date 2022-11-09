#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct fila {
  int elements[TAM];
  int first = -1;
  int last = -1;
} queue;

void enqueue(queue *queue, int element) {
  if ((queue->last) - (queue->first) < TAM - 1) {
    queue->last += 1;
    queue->elements[queue->last] = element;
    if (queue->first == -1) queue->first = 0;
  }
}

int dequeue(queue *queue) {
  if (queue->first == -1) {
    return -1;
  }

  if (queue->last == queue->first) {
    int front = queue->elements[queue->first];
    queue->first = -1;
    queue->last = -1;
    return front;
  }

  int front = queue->elements[queue->first];
  queue->first += 1;
  return front;
}

void print(queue *queue) {
  for (int i = queue->first; i <= queue->last; i++) {
    printf("%d -> ", queue->elements[i]);
  }
  printf("NULL\n");
}

int size(queue *queue) { return (queue->last) - (queue->first) + 1; }

void clear(queue *queue) {
  queue->first = -1;
  queue->last = -1;
}

int position(queue *queue, int e) {
  for (int i = queue->first; i <= queue->last; i++) {
    if (queue->elements[i] == e) {
      return i - queue->first + 1;
    }
  }
  return -1;
}

bool is_empty(queue *queue) { return (queue->first == -1); }

int main(int argc, char const *argv[]) {
  queue q;

  enqueue(&q, 27);
  enqueue(&q, 22);
  enqueue(&q, 13);
  enqueue(&q, 4);
  enqueue(&q, 10);
  enqueue(&q, 99);
  print(&q);

  printf("Tam: %d\n", size(&q));

  printf("Position: %d, %d\n", position(&q, 22), 22);

  int p = dequeue(&q);
  printf("Dequeue: %d\n", p);
  print(&q);

  printf("is_empty: %d\n", is_empty(&q));

  clear(&q);

  printf("is_empty: %d\n", is_empty(&q));

  return 0;
}

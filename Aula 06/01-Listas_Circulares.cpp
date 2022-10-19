#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

celula *ultimo(celula *head) {
  if (head == NULL) return NULL;
  celula *tail = head;
  while (tail->prox != head) {
    tail = tail->prox;
  }
  return tail;
}

void remover(celula **head) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->prox == *head) {
    free(*head);
    *head = NULL;
    return;
  }

  celula *tail = ultimo(*head);
  tail->prox = (*head)->prox;
  free(*head);
  *head = tail->prox;
}

void inserir(celula **head, int valor) {
  celula *nova = (celula *)malloc(sizeof(celula));
  nova->conteudo = valor;

  if (*head == NULL) {
    *head = nova;
    nova->prox = *head;
    return;
  }

  nova->prox = *head;
  celula *tail = ultimo(*head);
  tail->prox = nova;
  *head = nova;
}

void imprimir(celula *head) {
  celula *aux = head;
  if (aux != NULL) {
    while (aux->prox != head) {
      printf("%d -> ", aux->conteudo);
      aux = aux->prox;
    }
    printf("%d -> ", aux->conteudo);
  }
  printf("HEAD\n");
}

int main(int argc, char const *argv[]) {
  celula *cabeca = NULL;

  imprimir(cabeca);
  inserir(&cabeca, 3);
  imprimir(cabeca);
  inserir(&cabeca, 2);
  imprimir(cabeca);
  inserir(&cabeca, 1);

  imprimir(cabeca);

  remover(&cabeca);
  imprimir(cabeca);
  remover(&cabeca);
  imprimir(cabeca);
  remover(&cabeca);
  imprimir(cabeca);

  return 0;
}

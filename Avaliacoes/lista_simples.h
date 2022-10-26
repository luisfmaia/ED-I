#include <stdio.h>

#include <random>

typedef struct cel {
  int id;
  struct cel *prox;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("(%d) -> ", aux->id);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void inserir_inicio(celula **ptr_cabeca, celula *nova) {
  nova->prox = *ptr_cabeca;
  *ptr_cabeca = nova;
}

void inserir_ordenado(celula **ptr_cabeca, celula *nova) {
  if (*ptr_cabeca == NULL) {
    nova->prox = *ptr_cabeca;
    *ptr_cabeca = nova;
  } else {
    celula *aux = *ptr_cabeca;
    celula *ant = NULL;

    while (aux != NULL) {
      if (nova->id < aux->id) {
        if (ant != NULL) {
          ant->prox = nova;
        } else {
          *ptr_cabeca = nova;
        }
        nova->prox = aux;
        return;
      }
      ant = aux;
      aux = aux->prox;
    }
    ant->prox = nova;
    nova->prox = aux;
  }
}

int tamanho(celula *cabeca) {
  if (cabeca == NULL) {
    return 0;
  }

  int tam = 0;
  celula *aux = cabeca;
  while (aux != NULL) {
    aux = aux->prox;
    tam++;
  }
  return tam;
}

celula *aleatorio(celula *cabeca) {
  srand(std::time(nullptr));
  int tam = tamanho(cabeca);
  int pos = rand() % tam;
  celula *aux = cabeca;
  while (pos > 0) {
    aux = aux->prox;
    pos--;
  }
  return aux;
}

celula *buscar(celula *cabeca, celula *cel) {
  celula *aux = cabeca;
  while (aux != NULL) {
    if (aux->id == cel->id) {
      return aux;  //"Elemento encontrado"
    }
    aux = aux->prox;
  }
  return NULL;  //"Elemento não encontrado"
}

celula *dividir(celula *cabeca1, int id) {
  celula *aux = cabeca1;
  celula *cabeca2 = NULL;

  while (aux != NULL) {
    if (aux->id == id) {
      cabeca2 = aux->prox;
      aux->prox = NULL;
      printf("Lista 1:\n");
      imprimir(cabeca1);
      printf("Lista 2:\n");
      imprimir(cabeca2);
      return cabeca2;
    }
    aux = aux->prox;
  }

  printf("Id não encontrado\n");
  return NULL;
}

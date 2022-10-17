#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void inserir_inicio(celula **ptr_cabeca, int valor) {
  celula *nova = (celula *)malloc(sizeof(celula));
  nova->conteudo = valor;
  nova->prox = *ptr_cabeca;
  *ptr_cabeca = nova;
}

void inserir_fim(celula **cabeca, int valor) {
  celula *nova = (celula *)malloc(sizeof(celula));
  nova->conteudo = valor;
  nova->prox = NULL;

  // Caso de lista vazia
  if (*cabeca == NULL) {
    *cabeca = nova;
    return;
  }

  celula *aux = *cabeca;
  while (aux != NULL) {
    if (aux->prox == NULL) {
      aux->prox = nova;
      break;
    }
    aux = aux->prox;
  }
}

celula *buscar(celula *aux, int valor) {
  while (aux != NULL) {
    if (aux->conteudo == valor) {
      return aux;  //"Elemento encontrado"
    }
    aux = aux->prox;
  }
  return NULL;  //"Elemento não encontrado"
}

void remover(celula **ptr_cabeca, int valor) {
  // Remover elemento que é cabeça
  if ((*ptr_cabeca)->conteudo == valor) {
    celula *tmp = *ptr_cabeca;
    *ptr_cabeca = (*ptr_cabeca)->prox;
    free(tmp);
    return;
  }

  // Remover demais elementos
  celula *aux = *ptr_cabeca;
  celula *p = NULL;
  while (aux != NULL) {
    p = aux->prox;
    if ((p != NULL) && (p->conteudo == valor)) {
      aux->prox = p->prox;
      free(p);
      return;
    }
    aux = aux->prox;
  }
}

/**
 * Retorna a posição do elemento començando por 0.
 * Retorna -1 se não encontrar o elemento.
 * **/
int posicao(celula *cabeca, int valor) {
  celula *aux = cabeca;
  int pos = 0;
  while (aux != NULL) {
    if (aux->conteudo == valor) {
      return pos;  //"Elemento encontrado"
    }
    aux = aux->prox;
    pos++;
  }
  return -1;  //"Elemento não encontrado"
}

celula *troca_prox(celula *cabeca, int valor) {
  celula *a = NULL;
  celula *c = cabeca;
  celula *p = NULL;

  if (c->conteudo == valor) {
    if (c->prox == NULL) {
      printf("O proximo é NULL\n");
      return cabeca;
    }
    p = c->prox;
    c->prox = p->prox;
    p->prox = c;
    return p;
  }

  while ((c != NULL) && (c->prox != NULL)) {
    if (c->conteudo == valor) {
      a->prox = p;
      c->prox = p->prox;
      p->prox = c;
      return cabeca;
    }
    a = c;
    c = c->prox;
    p = c->prox;
  }
  return cabeca;
  // return -1;  //"Elemento não encontrado"
}

void concatena(celula *cabeca1, celula *cabeca2) {
  celula *aux = cabeca1;

  while ((aux != NULL) && (aux->prox != NULL)) {  // Encontrar o último
    aux = aux->prox;
  }
  aux->prox = cabeca2;
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

celula *metade(celula *cabeca1) {
  int tam1 = ceil(tamanho(cabeca1) / 2.0f);
  printf("TAM1: %d\n", tam1);
  celula *cabeca2 = NULL;

  celula *aux = cabeca1;
  int i = 0;
  while (i < tam1 - 1) {
    aux = aux->prox;
    i++;
  }

  cabeca2 = aux->prox;
  aux->prox = NULL;

  return cabeca2;
}

celula *reverter(celula *cabeca1) {
  celula *aux = cabeca1;
  celula *ant = NULL;
  celula *prox = NULL;

  while (aux != NULL) {
    prox = aux->prox;
    aux->prox = ant;
    ant = aux;
    aux = prox;
  }

  celula *cabeca2 = ant;

  return cabeca2;
}

int main(int argc, char const *argv[]) {
  // TROCA
  //  celula *cabeca = NULL;
  //  inserir_fim(&cabeca, 5);
  //  inserir_fim(&cabeca, 7);
  //  inserir_fim(&cabeca, 9);
  //  inserir_fim(&cabeca, 12);
  //  printf("Antes\n");
  //  imprimir(cabeca);
  //  cabeca = troca_prox(cabeca, 7);
  //  printf("Depois\n");
  //  imprimir(cabeca);

  // CONCATENA
  // celula *cabeca1 = NULL;
  // celula *cabeca2 = NULL;

  // inserir_fim(&cabeca1, 2);
  // inserir_fim(&cabeca1, 3);
  // inserir_fim(&cabeca1, 5);

  // inserir_fim(&cabeca2, 7);
  // inserir_fim(&cabeca2, 8);

  // printf("Antes\n");
  // imprimir(cabeca1);
  // imprimir(cabeca2);

  // concatena(cabeca1, cabeca2);

  // printf("Depois\n");
  // imprimir(cabeca1);

  celula *cabeca1 = NULL;
  inserir_fim(&cabeca1, 2);
  inserir_fim(&cabeca1, 3);
  inserir_fim(&cabeca1, 5);
  inserir_fim(&cabeca1, 7);
  inserir_fim(&cabeca1, 9);

  printf("Antes\n");
  imprimir(cabeca1);

  celula *cabeca2 = reverter(cabeca1);

  printf("Depois\n");
  imprimir(cabeca2);

  return 0;
}

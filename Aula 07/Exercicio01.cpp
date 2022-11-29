#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>

typedef struct reg_site {
  char nome[30];
  char link[100];
  struct reg_site *prox;
} Site;

typedef struct Pilha {
  Site *topo;
  int tamanho;
} Pilha;

Site *inicializaSite(char *nome, char *link) {
  Site *site = (Site *)malloc(sizeof(Site));
  strcpy(site->nome, nome);
  strcpy(site->link, link);
  site->prox = NULL;
  return site;
}

Pilha *inicializaPilha() {
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  pilha->tamanho = 0;
  return pilha;
}

void push(Pilha *pilha, Site *site) {
  site->prox = pilha->topo;
  pilha->topo = site;
  pilha->tamanho++;
}

Site *pop(Pilha *pilha) {
  if (pilha->tamanho == 0) {
    printf("Erro: pilha vazia \n");
    return NULL;
  }
  Site *site = pilha->topo;
  pilha->topo = pilha->topo->prox;
  site->prox = NULL;
  pilha->tamanho--;
  return site;
}

void imprime(Pilha *pilha) {
  Site *aux = pilha->topo;
  printf("\nTamanho pilha: %d\n", pilha->tamanho);
  while (aux != NULL) {
    printf("%s - %s\n", aux->nome, aux->link);
    aux = aux->prox;
  }
  printf("\n");
}

Site *voltar(Pilha *pilha, int n) {
  // n = std::min(n, pilha->tamanho);
  // n = (n > pilha->tamanho) ? pilha->tamanho : n;
  if (n > pilha->tamanho) {
    n = pilha->tamanho;
  }

  printf("Voltando %d sites.\n", n);
  for (int i = 0; i < n; i++) {
    Site *s = pop(pilha);
    free(s);
  }
  return pilha->topo;
}

int main(int argc, char const *argv[]) {
  Pilha *pilha = inicializaPilha();
  Site *s1, *s2, *s3, *s4;
  s1 = inicializaSite("Google", "www.google.com");
  s2 = inicializaSite("Uol", "www.uol.com.br");
  s3 = inicializaSite("Globo", "www.globo.com");
  s4 = inicializaSite("BetsBola", "www.betsbola.com");

  push(pilha, s1);
  push(pilha, s2);
  push(pilha, s3);
  push(pilha, s4);
  imprime(pilha);
  Site *s = voltar(pilha, 2);
  if (s != NULL) {
    printf("Topo: %s\n", s->nome);
  }
  imprime(pilha);

  return 0;
}

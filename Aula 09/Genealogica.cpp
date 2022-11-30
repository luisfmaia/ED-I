#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *nome;
  int idade;

} Pessoa;

typedef struct node {
  Pessoa *pessoa;
  struct node *filho1;
  struct node *filho2;
  struct node *filho3;
} No;

No *criar_no() {
  Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
  No *node = (No *)malloc(sizeof(No));

  printf("Digite o nome: ");
  scanf("%s", p->nome);
  printf("Digite a idade: ");
  scanf("%d", &p->idade);

  node->pessoa = p;
  node->filho1 = NULL;
  node->filho2 = NULL;
  node->filho3 = NULL;

  return;
}

void inserir_no(No *pai, No *novo) {
  if (pai->filho1 == NULL) {
    pai->filho1 = novo;
    return;
  }

  if (pai->filho2 == NULL) {
    pai->filho2 = novo;
    return;
  }

  if (pai->filho3 == NULL) {
    pai->filho3 = novo;
    return;
  }

  printf("Não inseriu. Excesso de filhos.\n");
}

No *busca_larg(No *node, char *nome) {
  if (node == NULL) return NULL;

  if (strcmp(node->pessoa->nome, nome) == 0) {
    return node;
  }

  No *f1, *f2, *f3;
  f1 = node->filho1;
  f2 = node->filho2;
  f3 = node->filho3;

  if ((f1 != NULL) && (strcmp(f1->pessoa->nome, nome) == 0)) {
    return f1;
  }

  if ((f2 != NULL) && (strcmp(f2->pessoa->nome, nome) == 0)) {
    return f2;
  }

  if ((f3 != NULL) && (strcmp(f3->pessoa->nome, nome) == 0)) {
    return f3;
  }

  No *res = NULL;
  res = busca_larg(node->filho1, nome);
  if (res != NULL) {
    return res;
  }

  res = busca_larg(node->filho2, nome);
  if (res != NULL) {
    return res;
  }

  res = busca_larg(node->filho3, nome);
  if (res != NULL) {
    return res;
  }

  return NULL;
}

No *busca_prof(No *node, char *nome) {
  if (node == NULL) return NULL;

  if (strcmp(node->pessoa->nome, nome) == 0) {
    return node;
  }

  No *res = NULL;
  res = busca_prof(node->filho1, nome);
  if (res != NULL) {
    return res;
  }

  res = busca_prof(node->filho2, nome);
  if (res != NULL) {
    return res;
  }

  res = busca_prof(node->filho3, nome);
  if (res != NULL) {
    return res;
  }

  return NULL;
}

void imprimir(No *node, int tab = 0) {
  if (node == NULL) return;

  for (int i = 0; i < tab; i++) {
    printf("\t");
  }

  printf("%s - %d\n", node->pessoa->nome, node->pessoa->idade);
  imprimir(node->filho1, tab + 1);
  imprimir(node->filho2, tab + 1);
  imprimir(node->filho3, tab + 1);
}

int main(int argc, char const *argv[]) {
  Pessoa p1, p2, p3, p4;

  No n1, n2, n3, n4;

  No *raiz = &n1;

  n1.pessoa = &p1;
  n2.pessoa = &p2;
  n3.pessoa = &p3;
  n4.pessoa = &p4;

  n1.filho1 = &n2;
  n1.filho2 = &n3;
  n1.filho3 = NULL;

  n2.filho1 = &n4;
  n2.filho2 = NULL;
  n2.filho3 = NULL;

  n3.filho1 = NULL;
  n3.filho2 = NULL;
  n3.filho3 = NULL;

  n4.filho1 = NULL;
  n4.filho2 = NULL;
  n4.filho3 = NULL;

  p1.nome = "Pedro";
  p1.idade = 60;

  p2.nome = "Andre";
  p2.idade = 30;

  p3.nome = "Marcelo";
  p3.idade = 40;

  p4.nome = "Marcelo";
  p4.idade = 10;

  imprimir(raiz);

  No *res = busca_prof(raiz, "Marcelo");
  if (res != NULL)
    printf("%s - %d\n", res->pessoa->nome, res->pessoa->idade);
  else
    printf("Não encontrado\n");

  res = busca_larg(raiz, "Marcelo");
  if (res != NULL)
    printf("%s - %d\n", res->pessoa->nome, res->pessoa->idade);
  else
    printf("Não encontrado\n");

  No *n = criar_no();
  No *pai = busca_prof(raiz, "George");
  inserir_no(pai, n);

  return 0;
}

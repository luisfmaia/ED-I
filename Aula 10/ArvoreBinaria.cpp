#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int num;
  struct node *esq;
  struct node *dir;
} No;

No *criar_no() {
  No *node = (No *)malloc(sizeof(No));

  printf("Digite o numero: ");
  scanf("%d", &node->num);

  node->esq = NULL;
  node->dir = NULL;

  return node;
}

void inserir_no(No *node, No *novo) {
  if (node == NULL) {
    printf("Erro\n");
    return;
  }

  if (node->num == novo->num) {
    printf("Número já existe\n");
    return;
  }

  if (node->num < novo->num) {
    if (node->dir == NULL) {
      node->dir = novo;
      return;
    }
    inserir_no(node->dir, novo);
  } else {
    if (node->esq == NULL) {
      node->esq = novo;
      return;
    }
    inserir_no(node->esq, novo);
  }
}

No *buscar_no(No *node, int num) {
  if (node == NULL) {
    // printf("Número não encontrado\n");
    return NULL;
  }

  if (node->num == num) {
    return node;
  }

  if (node->num > num) {
    return buscar_no(node->dir, num);
  } else {
    return buscar_no(node->esq, num);
  }
}

void imprimir(No *node, int tab = 0) {
  if (node == NULL) return;

  imprimir(node->dir, tab + 1);
  for (int i = 0; i < tab; i++) {
    printf("\t");
  }
  printf("%d\n", node->num);
  imprimir(node->esq, tab + 1);
}

void inserir_raiz(No **raiz) {
  if (*raiz == NULL) {
    *raiz = criar_no();
    return;
  }

  No *novo = criar_no();
  inserir_no(*raiz, novo);
}

void buscar_raiz(No *raiz) {
  int num = 0;
  printf("Digite o numero: ");
  scanf("%d", &num);
  No *res = buscar_no(raiz, num);
  if (res == NULL) {
    printf("Numero não encontrado");
  } else {
    imprimir(res);
  }
}

void menu() {
  printf("MENU\n");
  printf("1-Inserir\n");
  printf("2-Buscar\n");
  printf("3-Imprimir Árvore\n");
  printf("0-Sair\n");
}

int main(int argc, char const *argv[]) {
  No *root = NULL;

  int opc = 1;
  while (opc != 0) {
    menu();
    scanf("%d", &opc);
    switch (opc) {
      case 1:
        inserir_raiz(&root);
        break;
      case 2:
        buscar_raiz(root);
        break;
      case 3:
        imprimir(root);
        break;
      case 0:
        break;
      default:
        printf("Opção inválida\n");
        break;
    }
  }

  return 0;
}

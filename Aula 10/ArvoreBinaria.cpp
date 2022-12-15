#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
  int num;
  struct node *esq;
  struct node *dir;
} No;

No *remover(No *node, int num);

No *criar_no() {
  No *node = (No *)malloc(sizeof(No));

  // printf("Digite o numero: ");
  // scanf("%d", &node->num);
  node->num = rand() % 100;
  printf("%d, ", node->num);

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

  if (node->num < num) {
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

No *buscar_pai(No *node, int num) {
  if (node == NULL) return NULL;

  if ((node->esq != NULL) && (node->esq->num == num)) {
    return node;
  }

  if ((node->dir != NULL) && (node->dir->num == num)) {
    return node;
  }

  if (node->num < num) {
    return buscar_pai(node->dir, num);
  } else {
    return buscar_pai(node->esq, num);
  }
}

bool um_filho(No *node) {
  // return (node->esq == NULL) && (node->dir == NULL);
  if ((node->esq == NULL) && (node->dir != NULL)) {
    return true;
  }

  if ((node->esq != NULL) && (node->dir == NULL)) {
    return true;
  }

  return false;
}

bool eh_folha(No *node) {
  // return (node->esq == NULL) && (node->dir == NULL);
  if ((node->esq == NULL) && (node->dir == NULL)) {
    return true;
  } else {
    return false;
  }
}

No *maior(No *node) {
  if (node == NULL) return NULL;
  if (node->dir == NULL) return node;
  return maior(node->dir);
}

void substituir(No *pai, No *removido) {
  if (um_filho(removido)) {
    if (removido->esq != NULL) {
      pai->esq = removido->esq;
    } else {
      pai->dir = removido->dir;
    }
  } else {
    No *substituto = maior(removido->esq);
    remover(pai, substituto->num);
    substituto->esq = removido->esq;
    substituto->dir = removido->dir;
    if (pai->num < substituto->num) {
      pai->dir = substituto;
    } else {
      pai->esq = substituto;
    }
    removido->dir = NULL;
    removido->esq = NULL;
  }
}

No *remover(No *node, int num) {
  No *pai = buscar_pai(node, num);
  if (pai == NULL) {
    printf("Numero não encontrado");
    return NULL;
  } else {
    // printf("Pai: %d\n", pai->num);
    No *removido = NULL;
    if (pai->num < num) {
      removido = pai->dir;
      if (eh_folha(removido)) {
        pai->dir = NULL;
      } else {
        substituir(pai, removido);
      }
    } else {
      removido = pai->esq;
      if (eh_folha(removido)) {
        pai->esq = NULL;
      } else {
        substituir(pai, removido);
      }
    }
    // printf("Removido: %d\n", removido->num);
    return removido;
  }
}

void remover_raiz(No **raiz) {
  int num = 0;
  printf("Digite o numero: ");
  scanf("%d", &num);

  if (*raiz == NULL) {
    printf("Árvore vazia\n");
    return;
  }

  if ((*raiz)->num == num) {
    if (eh_folha(*raiz)) {
      free(*raiz);
      *raiz = NULL;
      return;
    }

    if (um_filho(*raiz)) {
      No *remover = *raiz;
      if ((*raiz)->esq != NULL) {
        *raiz = (*raiz)->esq;
      } else {
        *raiz = (*raiz)->dir;
      }
      free(remover);
    } else {
      No *substituto = maior((*raiz)->esq);
      remover(*raiz, substituto->num);
      substituto->esq = (*raiz)->esq;
      substituto->dir = (*raiz)->dir;
      (*raiz)->esq = NULL;
      (*raiz)->dir = NULL;
      free(*raiz);
      *raiz = substituto;
    }

  } else {
    remover(*raiz, num);
  }
}

void menu() {
  printf("MENU\n");
  printf("1-Inserir\n");
  printf("2-Buscar\n");
  printf("3-Imprimir Árvore\n");
  printf("4-Remover\n");
  printf("5-Arvore aleatoria\n");
  printf("0-Sair\n");
}

void arvore_aleatoria(No **root) {
  for (int i = 0; i < 10; i++) {
    inserir_raiz(root);
  }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));

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
      case 4:
        remover_raiz(&root);
        break;
      case 5:
        arvore_aleatoria(&root);
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>

typedef struct cel {
  char nome[30];
  int qnt;
  int qntMin;
  float preco;
  struct cel *prox;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("(%s,%d,%d,%.2f) -> ", aux->nome, aux->qnt, aux->qntMin, aux->preco);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void valor_total_medio(celula *aux) {
  float total = 0.0f;
  float media = 0.0f;
  int cont = 0;

  while (aux != NULL) {
    total += aux->qnt * aux->preco;
    media += aux->preco;
    cont++;
    aux = aux->prox;
  }
  media = media / cont;

  printf("O valor total do estoque é: R$ %.2f\n", total);
  printf("O preço médio dos produtos é: R$ %.2f\n", media);
}

void inserir(celula **ptr_cabeca) {
  celula *nova = (celula *)malloc(sizeof(celula));

  printf("Digite o nome do produto: ");
  scanf("%30[^\n]s", nova->nome);
  printf("Digite a quantidade atual: ");
  scanf("%d", &nova->qnt);
  printf("Digite a quantidade minima: ");
  scanf("%d", &nova->qntMin);
  printf("Digite o preço: ");
  scanf("%f", &nova->preco);

  if (*ptr_cabeca == NULL) {
    nova->prox = *ptr_cabeca;
    *ptr_cabeca = nova;
  } else {
    celula *aux = *ptr_cabeca;
    celula *ant = NULL;

    while (aux != NULL) {
      if (strcmp(nova->nome, aux->nome) < 0) {
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

celula *dividir(celula *cabeca1) {
  char nome[30];
  printf("Digite o nome do produto: ");
  scanf("%30[^\n]s", nome);

  celula *aux = cabeca1;
  celula *cabeca2 = NULL;

  while (aux != NULL) {
    if (strcmp(nome, aux->nome) == 0) {
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

  printf("Produto não encontrado\n");
  return NULL;
}

void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir produto\t*\n");
  printf("*\t2 - Imprimir produtos\t*\n");
  printf("*\t3 - Valores do estoque\t*\n");
  printf("*\t4 - Dividir a lista\t*\n");
  printf("*\t0 - Sair\t\t*\n");
}

int main(int argc, char const *argv[]) {
  celula *head = NULL;
  int opc = 1;
  while (opc != 0) {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc) {
      case 1:
        inserir(&head);
        break;

      case 2:
        imprimir(head);
        break;

      case 3:
        valor_total_medio(head);
        break;

      case 4:
        dividir(head);
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

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

typedef struct cel {
  char nome[30];
  struct cel *prox;
} celula;

void imprimir(celula *aux) {
  while (aux != NULL) {
    printf("%s -> ", aux->nome);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void inserir(celula **ptr_cabeca) {
  celula *nova = (celula *)malloc(sizeof(celula));

  printf("Digite o nome do produto: ");
  scanf("%30[^\n]s", nova->nome);
  nova->prox = *ptr_cabeca;
  *ptr_cabeca = nova;
}

void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir produto\t*\n");
  printf("*\t2 - Imprimir produtos\t*\n");
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

      case 0:
        break;

      default:
        printf("Opção inválida\n");
        break;
    }
  }

  return 0;
}

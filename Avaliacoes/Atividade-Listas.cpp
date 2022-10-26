#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "lista_simples.h"

void imprimir_menu() {
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir inicio\t*\n");
  printf("*\t2 - Inserir ordenado\t*\n");
  printf("*\t3 - Imprimir produtos\t*\n");
  printf("*\t4 - Dividir a lista\t*\n");
  printf("*\t5 - Aleatorio\t*\n");
  printf("*\t0 - Sair\t\t*\n");
}

int main(int argc, char const *argv[]) {
  celula *head = NULL;
  celula *nova = NULL;
  int opc = 1;
  while (opc != 0) {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc) {
      case 1:
        nova = (celula *)malloc(sizeof(celula));
        printf("Digite o id do produto: ");
        scanf("%d", &nova->id);
        inserir_inicio(&head, nova);
        break;

      case 2:
        nova = (celula *)malloc(sizeof(celula));
        printf("Digite o id do produto: ");
        scanf("%d", &nova->id);
        inserir_ordenado(&head, nova);
        break;

      case 3:

        imprimir(head);
        break;

      case 4:
        int id;
        printf("Digite o id do produto: ");
        scanf("%d", &id);
        dividir(head, id);
        break;
      case 5:
        printf("%d\n", aleatorio(head)->id);
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

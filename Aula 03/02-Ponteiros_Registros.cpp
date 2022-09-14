#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

int main(int argc, char const *argv[]) {
  data hoje;
  hoje.dia = 0;
  hoje.mes = 0;
  hoje.ano = 0;

  data *ptr_data = &hoje;
  // (*ptr_data).dia = 01;  // notação confusa
  // *ptr_data.dia = 01;    // erro
  ptr_data->dia = 13;
  ptr_data->mes = 9;
  ptr_data->ano = 2022;

  printf("Data: %02d/%02d/%04d\n", ptr_data->dia, ptr_data->mes, ptr_data->ano);

  printf("Digite o dia: ");
  scanf("%d", &ptr_data->dia);

  printf("Digite o mês: ");
  scanf("%d", &ptr_data->mes);

  printf("Digite o ano: ");
  scanf("%d", &ptr_data->ano);

  printf("Hoje: %02d/%02d/%04d\n", ptr_data->dia, ptr_data->mes, ptr_data->ano);

  return 0;
}

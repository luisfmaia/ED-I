#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

int main(int argc, char const *argv[]) {
  data nasc_cristo;
  nasc_cristo.dia = 0;
  nasc_cristo.mes = 0;
  nasc_cristo.ano = 0;

  printf("Digite o dia: ");
  scanf("%d", &nasc_cristo.dia);

  printf("Digite o mês: ");
  scanf("%d", &nasc_cristo.mes);

  printf("Digite o ano: ");
  scanf("%d", &nasc_cristo.ano);

  printf("Data: %02d/%02d/%04d\n", nasc_cristo.dia, nasc_cristo.mes,
         nasc_cristo.ano);

  return 0;
}

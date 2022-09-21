#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

int main(int argc, char const *argv[]) {
  int total = 0;
  printf("Informe a quantidade de registros: ");
  scanf("%d", &total);

  data *datas = (data *)malloc(sizeof(data) * total);

  for (int i = 0; i < total; i++) {
    printf("\nDATA %d\n", i + 1);

    printf("Digite o dia: ");
    scanf("%d", &datas[i].dia);

    printf("Digite o mes: ");
    scanf("%d", &datas[i].mes);

    printf("Digite o ano: ");
    scanf("%d", &datas[i].ano);
  }

  printf("\nDATAS\n");
  for (int i = 0; i < total; i++) {
    printf("%d: %02d/%02d/%04d\n", i + 1, datas[i].dia, datas[i].mes,
           datas[i].ano);
  }

  free(datas);

  return 0;
}

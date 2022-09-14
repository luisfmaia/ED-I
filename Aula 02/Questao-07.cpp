#include <stdio.h>
#include <stdlib.h>

void inicializar(char *v, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Digite o valor do %dº elemento: ", i + 1);
    scanf(" %c", &v[i]);
  }
}

int main(int argc, char const *argv[]) {
  int n = 0;

  printf("Digite a quantidade de elementos do vetor: ");
  scanf("%d", &n);

  char *vetor = (char *)malloc(sizeof(char) * n);

  inicializar(vetor, n);

  printf("\nVETOR\n");
  for (int i = 0; i < n; i++) {
    printf("%d - %c\n", i, vetor[i]);
  }

  free(vetor);
  vetor = NULL;

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

void inicializar(float *v, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Digite a nota do %dº aluno: ", i + 1);
    scanf("%f", &v[i]);
  }
}

float calcular_media(float *v, int tam) {
  float total = 0.0f;
  for (int i = 0; i < tam; i++) {
    total += v[i];
  }
  return (total / tam);
}

void imprimir(float *v, int tam) {
  printf("\nNOTAS\n");
  for (int i = 0; i < tam; i++) {
    printf("Aluno %d: %.1f\n", i + 1, v[i]);
  }
}

int main(int argc, char const *argv[]) {
  int n = 0;

  printf("Digite a quantidade de alunos: ");
  scanf("%d", &n);

  float *notas = (float *)malloc(sizeof(float) * n);

  inicializar(notas, n);

  float media = calcular_media(notas, n);
  printf("\nMÉDIA DA TURMA: %.1f\n", media);

  imprimir(notas, n);

  free(notas);
  notas = NULL;

  return 0;
}

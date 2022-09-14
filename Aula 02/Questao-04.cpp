#include <stdio.h>

int main(int argc, char const *argv[]) {
  int i = 0;
  float f = 0.0f;
  char c = ' ';

  printf("i: %d\n", i);
  printf("f: %.2f\n", f);
  printf("c: %c\n", c);

  int *p_i = &i;
  float *p_f = &f;
  char *p_c = &c;

  printf("Digite o inteiro: ");
  scanf("%d", p_i);

  printf("Digite o float: ");
  scanf("%f", p_f);

  printf("Digite o char: ");
  scanf(" %c", p_c);

  printf("\nNovo Conteúdo\n");

  printf("i: %d\n", i);
  printf("f: %.2f\n", f);
  printf("c: %c\n", c);

  return 0;
}

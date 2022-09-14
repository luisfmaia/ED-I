#include <stdio.h>

int soma_dobro(int *p_a, int *p_b) {
  *p_a = (*p_a) * 2;  // a = a * 2;
  *p_b = (*p_b) * 2;  // b = b * 2;

  return (*p_a) + (*p_b);
}

int main(int argc, char const *argv[]) {
  int a = 0;
  int b = 0;

  printf("Digite o valor de a: ");
  scanf("%d", &a);

  printf("Digite o valor de b: ");
  scanf("%d", &b);

  printf("Soma do dobro: %d\n", soma_dobro(&a, &b));

  printf("a: %d\n", a);
  printf("b: %d\n", b);

  return 0;
}

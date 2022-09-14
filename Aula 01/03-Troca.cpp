#include <stdio.h>

void troca1(int i, int j) {
  int temp;
  temp = i;
  i = j;
  j = temp;
}

void troca2(int *p, int *q) {
  int temp;
  temp = *p;
  *p = *q;
  *q = temp;
}

int main(int argc, char const *argv[]) {
  int a = 2;
  int b = 3;

  troca1(a, b);
  printf("Troca 1 => a: %d, b:%d\n", a, b);

  troca2(&a, &b);
  printf("Troca 2 => a: %d, b:%d\n", a, b);

  return 0;
}

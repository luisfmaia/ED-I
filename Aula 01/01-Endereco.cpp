#include <stdio.h>

typedef struct {
  int x, y;
} ponto;

int main(int argc, char const *argv[]) {
  char c;
  int i;
  ponto p;
  int v[5];

  printf("%d\n", &c);
  printf("%d\n", &i);
  printf("%d\n", &p);
  printf("%d\n", &v);

  return 0;
}

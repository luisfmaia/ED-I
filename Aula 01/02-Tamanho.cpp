#include <stdio.h>

typedef struct {
  int x, y;
} ponto;

int main(int argc, char const *argv[]) {
  char c;
  int i;
  ponto p;
  int v[5];

  printf("sizeof (c) = %d\n", sizeof(c));
  printf("sizeof (i) = %d\n", sizeof(i));
  printf("sizeof (p) = %d\n", sizeof(p));
  printf("sizeof (v) = %d\n", sizeof(v));

  return 0;
}

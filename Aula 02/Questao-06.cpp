#include <stdio.h>

int main(int argc, char const *argv[]) {
  int v[] = {7, 4, 1, 2, 9};
  int *p = v;

  printf("v[0]: %d\n", *p);
  p += 2;
  printf("v[1]: %d\n", *p);
  p--;
  printf("v[2]: %d\n", p[1]);
  p = p - 4;
  printf("v[3]: %d\n", p[6]);

  return 0;
}

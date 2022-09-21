#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

typedef struct {
  char *nome;
  int telefone;
  data *nascimento;
} contato;

int main(int argc, char const *argv[]) {
  char n[100];
  contato *cnt = (contato *)malloc(sizeof(contato));
  cnt->nascimento = (data *)malloc(sizeof(data));

  printf("Digite o nome: ");
  scanf("%100[^\n]s", n);
  cnt->nome = n;

  printf("Digite o telefone: ");
  scanf("%d", &cnt->telefone);

  printf("Digite o dia: ");
  scanf("%d", &cnt->nascimento->dia);

  printf("Digite o mes: ");
  scanf("%d", &cnt->nascimento->mes);

  printf("Digite o ano: ");
  scanf("%d", &cnt->nascimento->ano);

  printf("\nContato\n");
  printf("Nome: %s\n", cnt->nome);
  printf("Telefone: %d\n", cnt->telefone);
  printf("Nascimento: %02d/%02d/%04d\n", cnt->nascimento->dia,
         cnt->nascimento->mes, cnt->nascimento->ano);

  free(cnt->nascimento);
  free(cnt);

  return 0;
}

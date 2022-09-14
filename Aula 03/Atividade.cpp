#include <stdio.h>
#include <stdlib.h>

#include <iostream>

typedef struct {
  int dia;
  int mes;
  int ano;
} data;

typedef struct {
  char rua[50];
  int casa;
  char cidade[30];
} endereco;

typedef struct {
  char nome[100];
  endereco endereco;
  int telefone;
  data nascimento;
} contato;

void show_contatos(contato *contatos, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Contato %d\n", i + 1);

    printf("Nome: %s\n", contatos[i].nome);
    printf("Endereco\n");
    printf("\tRua: %s\n", contatos[i].endereco.rua);
    printf("\tCasa: %d\n", contatos[i].endereco.casa);
    printf("\tCidade: %s\n", contatos[i].endereco.cidade);

    printf("Telefone: %d\n", contatos[i].telefone);

    printf("Data de Nascimento\n");
    printf("\tDia: %d\n", contatos[i].nascimento.dia);
    printf("\tMes: %d\n", contatos[i].nascimento.mes);
    printf("\tAno: %d\n", contatos[i].nascimento.ano);
  }
}

void add_contato(contato *c) {
  printf("ADICIONAR NOVO CONTATO\n");

  printf("Digite o nome: ");
  scanf("%100[^\n]s", c->nome);

  printf("Digite o telefone: ");
  scanf("%d", &c->telefone);
  fflush(stdin);

  printf("Digite a rua: ");
  scanf("%50[^\n]s", c->endereco.rua);

  printf("Digite a casa: ");
  scanf("%d", &c->endereco.casa);
  fflush(stdin);

  printf("Digite a cidade: ");
  scanf("%30[^\n]s", c->endereco.cidade);

  printf("Digite o dia: ");
  scanf("%d", &c->nascimento.dia);

  printf("Digite o mês: ");
  scanf("%d", &c->nascimento.mes);

  printf("Digite o ano: ");
  scanf("%d", &c->nascimento.ano);
  fflush(stdin);
}

int main() {
  int tam = 0;
  printf("Digite a quantidade de contatos da agenda: ");
  scanf("%d", &tam);
  fflush(stdin);

  contato *contatos = (contato *)malloc(sizeof(contato) * tam);

  for (int i = 0; i < tam; i++) {
    add_contato(&contatos[i]);
  }

  show_contatos(contatos, tam);

  return 0;
}
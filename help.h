//arquivo onde serão declaradas as bibliotecas e protótipos de função
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define NULL 0

typedef struct  {
   char nome[25];
   char sobrenome[25];
   char telefone [15];
   char sexo;
   int idade;
   char cpf[14];
   int ativo;
}cliente ;

//FILE para hospedes
FILE *hos;
//FILE para relatorio
FILE *rel;

int menu ();

char * busca_cliente(char *cpf);

void cadastra_cliente(char *cpf);

void atualiza_cliente(char *cpf);

void remove_cliente(char *cpf);

//void imprime_cliente(char *cpf);

void imprime_cliente(cliente c);

void gerar_relatorio(cliente c);

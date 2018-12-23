#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct Clientes {
	int codigo;
	char nome[50];
	int nif;
	char morada[80];
	int contato;
	int existe;
}CLIENTES;

typedef struct Contratados {
	int data;
	char necessidade[50];
}CONTRATADOS;

typedef struct Servicos {
	int codigo;
	char descricao[100];
	char equipamento[50];
	char estado[20];
}SERVICOS;

typedef struct Admin {
	char login[25];
	char password[25];
	int id;
}ADMIN;

void inicializa(CLIENTES *c, int n) {
	int i;

	for (i = 0; i < n; i++) {
		(c++)->existe = 0;
	}
}

void trim(const char *input, char *output) {
	int i = 0, j = 0, flag = 1;

	for (i; input[i] != '\0'; i++) {
		if (flag && (isspace((unsigned char)input[i]))) {
			flag = 1;
		}
		else {
			flag = 0;
			output[j++] = input[i];
		}
	}

	output[j] = '\0';
}

void registroC(SERVICOS *s, int n) {
	int i;

	printf("Digite o código desejado do novo serviço: ");
	scanf("%i", &s->codigo);

	for (i = 0; i < 2; i++) {
		if (1 == 1) {
			printf("O código atribuído já pertence a outro serviço.");
		}
		else {
			printf("\n");
		}
	}
}

void registroU(CLIENTES *c, int n) {
	char nome[50];
	int i;

	for (i = 0; i < n && c->existe == 1; i++) {
		c++;
	}

	printf("Digite o código do serviço desejado: ");
	scanf("%i", &c->codigo);
	printf("Digite o seu nome: ");
	trim(fgets(nome, 100, stdin), c->nome);
	printf("Digite o seu NIF: ");
	scanf("%i", &c->nif);
	printf("Digite a sua morada: ");
	trim(fgets(nome, 100, stdin), c->morada);
	printf("Digite o seu contato: ");
	scanf("%i", &c->contato);
	c->existe = 1;
}

double calculaValor() {

}



int main() {
	setlocale(LC_ALL, "Portuguese");

	CLIENTES cliente[30];
	SERVICOS servico[15];
	int totalDeClientes, totalDeServicos;
	double valor;
	char nome[50], nome2[50];

	registroC(servico, totalDeServicos);

	system("pause");
	return 0;
}

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
	double preco;
}SERVICOS;

typedef struct Funcionario {
	char login[25];
	char password[25];
	int id;
}FUNCIONARIO;

typedef struct Admin {
	char login[25];
	char password[25];
}ADMIN;

void inicializa(CLIENTES *c, int n) {
	int i;

	for (i = 0; i < n; i++) {
		(c++)->existe = 0;
	}
}

void testeFuncionario(FUNCIONARIO *f, char login, char password) {

}

void menuInicial() {
	printf(" ---------------------------------------------\n");
	printf(" |Bem-vindo a loja de computadores Nova Era  |\n");
	printf(" ---------------------------------------------\n\n\n");
	printf(" ------------------------------------------------\n");
	printf(" |Por favor, indique o tipo de acesso que deseja|\n");
	printf(" |----------------------------------------------|\n");
	printf(" |1. Administrador                              |\n");
	printf(" |2. Funcionário                                |\n");
	printf(" |3. Cliente                                    |\n");
	printf(" |----------------------------------------------|\n\n");
	printf(" Número do tipo de acesso: ");
}

void menuAdmin() {
	printf(" ---------------------------------------------\n");
}

void loginFuncionario(FUNCIONARIO *f) {
	char login, password;

	printf(" --------------------------------------------------------\n");
	printf(" |Por favor insira suas credenciais de acesso ao sistema|\n");
	printf(" --------------------------------------------------------\n\n");
	printf(" Login: ");
	scanf("%s", &login);
	printf(" Password: ");
	scanf("%s", &password);

	testeFuncionario(f, login, password);
}

void menuFuncionario() {
	printf(" ---------------------------------------------\n");
	printf(" |          Bem-vindo Funcionário             |\n");
	printf(" ---------------------------------------------\n");
}

void menuCliente() {
	printf(" ---------------------------------------------\n");
	printf(" |          Bem-vindo Cliente                |\n");
	printf(" ---------------------------------------------\n");
}

void registroS(SERVICOS *s, int n) {
	int i, codigo, flag = 1;

	printf("Digite o código desejado do novo serviço: ");
	scanf("%i", &s->codigo);

	for (i = 0; i < n && flag == 1; i++) {
		if (s->codigo == codigo) {
			printf("O código atribuído já pertence a outro serviço.");
			flag = 0;
		}
		else {
			if (s->codigo == 0) {
				s->codigo = codigo;
			}
			else {
				s++;
			}
		}
	}
}

void registroC(CLIENTES *c, int n) {
	char nome[50];
	int i;

	for (i = 0; i < n && c->existe == 1; i++) {
		c++;
	}

	printf("Digite o código do serviço desejado: ");
	scanf("%i", &c->codigo);
	printf("Digite o seu nome: ");
	fgets(c->nome, 100, stdin);
	printf("Digite o seu NIF: ");
	scanf("%i", &c->nif);
	printf("Digite a sua morada: ");
	fgets(c->morada, 100, stdin);
	printf("Digite o seu contato: ");
	scanf("%i", &c->contato);
	c->existe = 1;
}

void registroF(FUNCIONARIO *f, int n) {
	int i, id = 0;

	for (i = 0; i < n && f->id == 0; i++) {
		f++;
		id++;
	}

	printf("Digite um nome de login: ");
	scanf("%i", &f->login);
	printf("Digite uma password: ");
	scanf("%i", &f->password);
	f->id = id;
}

double calculaValor(SERVICOS *s, double valor) {
	valor = 10 + s->preco;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	CLIENTES cliente[30];
	FUNCIONARIO funcionario[20];
	SERVICOS servico[15];
	int totalDeClientes, totalDeServicos, choiceInicial = 1;
	double valor;
	char nome[50], nome2[50];

	do {
		if (choiceInicial < 1 || choiceInicial > 3) {
			printf(" Número de operação inválido, por favor escolha um correto.\n\n");
		}
		menuInicial();
		scanf("%i", &choiceInicial);
		system("cls");
	} while (choiceInicial < 1 || choiceInicial > 3);

	switch (choiceInicial) {
	case 1:
		menuAdmin();
		break;

	case 2:
		menuFuncionario(funcionario);
		break;

	case 3:
		menuCliente();
		break;
	}

	system("pause");
	return 0;
}
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
}*CLIENTES;

typedef struct Contratados {
	int data;
	char necessidade[50];
}*CONTRATADOS;

typedef struct Servicos {
	int codigo;
	char descricao[100];
	char equipamento[50];
	char estado[20];
	double preco;
}*SERVICOS;

typedef struct Funcionario {
	int id;
	char login[10];
	char password[16];
}*FUNCIONARIO;

typedef struct Admin {
	char login[25];
	char password[25];
}*ADMIN;

void inicializa(CLIENTES *c, int n) {
	int i;

	for (i = 0; i < n; i++) {
		(c++)->existe = 0;
	}
}

void menuInicial() 
{
	FILE *fp;

	FUNCIONARIO *f;

	char login[10], password[16]; int i; char c;
	FUNCIONARIO pUser = (struct Funcionario *)malloc(sizeof(struct Funcionario));

	if ((fp = fopen("funcionarios.dat", "r+")) == NULL) 
	{
			printf("Não foi possível abrir o ficheiro.\n");
			exit(1);
	}
	printf("Username: ");
	scanf("%9s", login);
	printf("Password: ");
	scanf("%15s", password);
	while (fread(pUser, sizeof(struct Funcionario), 1, fp) == 1) {
		if (strcmp(pUser->login, login) == 0) {
			if (strcmp(pUser->password, password) == 0) {
				menuFuncionario();
			}
		}
	}

	free(pUser);
	fclose(fp);
}

void menuFuncionario() 
{
	printf(" ---------------------------------------------\n");
	printf(" |          Bem-vindo Funcionário             |\n");
	printf(" ---------------------------------------------\n");
	printf(" ---------------------------------------------\n");
	printf(" |      Por favor, o que deseja efetuar?      |\n");
	printf(" |--------------------------------------------|\n");
	printf(" |1. Criar Cliente                            |\n");
	printf(" |2. Criar Funcionário                        |\n");
	printf(" |3. Criar Serviço                            |\n");
	printf(" |--------------------------------------------|\n\n");
	printf(" Número do tipo de acesso: ");

	CLIENTES cliente[30];
	FUNCIONARIO funcionario[20];
	SERVICOS servico[15];
	int choiceInicial = 1;

	do 
	{
		if (choiceInicial < 1 || choiceInicial > 3) 
			printf(" Número de operação inválido, por favor escolha um correto.\n\n");

		scanf("%i", &choiceInicial);
		system("cls");
	} while (choiceInicial < 1 || choiceInicial > 3);

	switch (choiceInicial) 
	{
		case 1:
			registroC(cliente);
			break;

		case 2:
			registroF(funcionario);
			break;

		case 3:
			registroS(servico);
			break;
	}
}

void registroS(SERVICOS *s, int n) {
	int i, codigo, flag = 1;

	printf("Digite o código desejado do novo serviço: ");
	scanf("%i", &(*s)->codigo);

	for (i = 0; i < n && flag == 1; i++) {
		if ((*s)->codigo == codigo) {
			printf("O código atribuído já pertence a outro serviço.");
			flag = 0;
		}
		else {
			if ((*s)->codigo == 0) {
				(*s)->codigo = codigo;
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

	for (i = 0; i < n && (*c)->existe == 1; i++) {
		c++;
	}

	printf("Digite o código do serviço desejado: ");
	scanf("%i", &(*c)->codigo);
	printf("Digite o seu nome: ");
	fgets((*c)->nome, 100, stdin);
	printf("Digite o seu NIF: ");
	scanf("%i", &(*c)->nif);
	printf("Digite a sua morada: ");
	fgets((*c)->morada, 100, stdin);
	printf("Digite o seu contato: ");
	scanf("%i", &(*c)->contato);
	(*c)->existe = 1;
}

void registroF(FUNCIONARIO *f, int n) {
	int i, id = 0;

	for (i = 0; i < n && (*f)->id == 0; i++) {
		f++;
		id++;
	}

	printf("Digite um nome de login: ");
	scanf("%i", &(*f)->login);
	printf("Digite uma password: ");
	scanf("%i", &(*f)->password);
	(*f)->id = id;
}

double calculaValor(SERVICOS s, double valor) {
	valor = 10 + s->preco;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	CLIENTES cliente[30];
	FUNCIONARIO funcionario[20];
	SERVICOS servico[15];
	int totalDeClientes, totalDeServicos;
	double valor;
	char nome[50], nome2[50];

	menuInicial();

	system("pause");
	return 0;
}
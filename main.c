#include "help.h"

int main() {
	setlocale(LC_ALL,"PORTUGUESE");
	char opc;
	char cpf[14], co[14];
	cliente c;
    printf("// ----- // ----- // Bem Vindo // ----- // ----- // \n\n\n");
	printf("\nEste sistema foi desenvolvido pelo aluno:\n\n");
	printf("\n       MARCOS VINÍCIUS PEDROSO\n");
	system("pause");
	system("cls");
    opc=menu();
	do {
		switch (opc) {
			case '1':
				system("cls");
				fflush(stdin);
				printf("// ----- // ----- // BUSCA HÓSPEDE // ----- // ----- // \n\n");
				printf("\nDigite o CPF: ");
				gets(cpf);
				if(busca_cliente(&cpf) != NULL){
					system("cls");
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\n\nCadastro encontrado \n\n");
					printf("\n\nCPF: %s \n\n", cpf);
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					system("pause");
					system("cls");
				}else{
					system("cls");
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\n\nCadastro não encontrado\n\n");
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					system("pause");
					system("cls");
				}
			break;

			case '2':
			    system("cls");
			    fflush(stdin);
				printf("// ----- // ----- // CADASTRA HÓSPEDE // ----- // ----- // \n\n");
				printf("\nDigite o CPF: ");
				gets(cpf);
				cadastra_cliente (&cpf);
			break;

			case '3':
			    fflush(stdin);
                system("cls");
                printf("// ----- // ----- // Atualiza Hospede // ----- // ----- // \n\n");
                printf("\nDigite o CPF do cadastro que será atualizado: ");
                gets(cpf);
				atualiza_cliente(&cpf);
			break;

			case '4':
			    fflush(stdin);
			    system("cls");
                printf("// ----- // ----- // Remove Hóspede // ----- // ----- // \n\n");
                printf("\nDigite o CPF do cadastro que será Removido: ");
                gets(cpf);
				remove_cliente(&cpf);
			break;

			case '5':
				imprime_cliente(c);
				/*fflush(stdin);
			    system("cls");
                printf("// ----- // ----- // Remove Hóspede // ----- // ----- // \n\n");
                printf("\nDigite o CPF do cliente: ");
                gets(cpf);
				imprime_cliente(&cpf);*/

			break;

			case '6':
				gerar_relatorio(c);
			break;

			case '9':
				exit(1);
			break;

			default:
				printf("\nOpção Inválida!\n\n");
				system("pause");
				system("cls");
			break;
		}

		opc=menu();

	} while (opc != '9');

	return 0;
}


int menu () {
	int op;
	printf("\n\n// ----- // ----- // MENU PRINCIPAL // ----- // ----- // \n\n[1] - Buscar por cadastro \n[2] - Cadastrar novo\n[3] - Atualizar cadastro\n[4] - Remover cadastro\n[5] - Imprimir todos cadastrados\n[6] - Gerar relatório\n[9] - Finalizar \n-------------------------------\nEntre com a sua opção: ");
	scanf("\n%c",&op);
	return op;
}

char * busca_cliente(char *cpf) {

	hos = fopen("hospede.dat", "rb");
	cliente c;

	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 ) {
			if(strcmp(cpf, c.cpf)==0 && c.ativo!=0)
        {
            return cpf;
        }
        system("cls");
    };
    fclose(hos);
}
return NULL;
}

void cadastra_cliente(char *cpf) {
	system("cls");
	printf("// ----- // ----- // CADASTRO HÓSPEDE // ----- // ----- // \n\n");
	cliente c;
	hos = fopen("hospede.dat", "ab+");
	fseek(hos, 0, SEEK_SET);
	fflush(stdin);
	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 && strcmp(cpf, c.cpf)!=0) {}
		if(strcmp(cpf, c.cpf)==0 && c.ativo!=0) {
			system("cls");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\n\n Não foi possivel realizar o cadastro");
			printf("\n Motivo: esse CPF já possui cadastro \n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			system("pause");
			system("cls");
			return 0;
		} else
            hos = fopen("hospede.dat", "rb+");
			while(fread(&c, sizeof(cliente), 1, hos)==1 && c.ativo!=0) {}
            if(c.ativo==0) {
                    fseek(hos, -sizeof(cliente), SEEK_CUR);
					fflush(stdin);
					printf("Nome: ");
					gets(c.nome);
					printf("Sobrenome: ");
					gets(c.sobrenome);
					printf("Telefone: ");
					gets(c.telefone);
					printf("Sexo: ");
					scanf("%c", &c.sexo);
					printf("Idade:");
					scanf("%d", &c.idade);
                    strcpy(c.cpf, cpf);
                    c.ativo=1;
					fwrite(&c ,sizeof (cliente),1, hos);
					fclose(hos);
					system("cls");
		} else {
		    hos = fopen("hospede.dat", "ab+");
			fflush(stdin);
			printf("Nome: ");
			gets(c.nome);
			printf("Sobrenome: ");
			gets(c.sobrenome);
			printf("Telefone: ");
			gets(c.telefone);
			printf("Sexo: ");
			scanf("%c", &c.sexo);
			printf("Idade:");
			scanf("%d", &c.idade);
			c.ativo=1;
			strcpy(c.cpf, cpf);
			fwrite(&c,sizeof (cliente),1, hos);
			fclose(hos);
			system("cls");
		}
		fclose(hos);
		return 0;
	}
	system("cls");
}

void atualiza_cliente(char * cpf) {
	fseek(hos, 0, SEEK_SET);
	hos = fopen("hospede.dat", "rb+");
	cliente c;
	char op;
	int val=0;

	if (hos == NULL) {
		puts("Não foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 && strcmp(cpf, c.cpf)!=0) {
		}
		if(strcmp(cpf, c.cpf)==0 &&c.ativo!=0) {

			system("cls");
			printf("\nOs dados desse cliente são:\n");
			fread(&c, sizeof(cliente), 0, hos);
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nCPF: %s", c.cpf);
			printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			system("pause");
			system("cls");
			 printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nNome: %s", c.nome);
			printf("\n\n// ----- // ----- //// ----- // ----- // \n");
            fseek(hos, -sizeof(cliente), SEEK_CUR);
			printf("\nDeseja atualizar este campo?\n \n--> SIM (s)<--\n\n\n--> NÃO (n) <--\n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			scanf("\n%c",&op);
			switch (op) {
				case 's':
				    system("cls");
				    fflush(stdin);
				    printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\nNovo Nome: ");
					gets(c.nome);
					system("cls");
					break;
                case'n':
                    system("cls");
                    break;
                default:
					printf("\nEntrada desconhecida\n");
					system("pause");
					system("cls");
					break;
			}
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            printf("\nSobrenome: %s", c.sobrenome);
            printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nDeseja atualizar este campo?\n \n--> SIM (s)<--\n\n\n--> NÃO (n) <--\n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			scanf("\n%c",&op);
			switch (op) {
			    fflush(stdin);
				case 's':
				    system("cls");
				    fflush(stdin);
				    printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\nNovo Sobrenome: ");
                    gets(c.sobrenome);
					system("cls");
					break;
                case'n':
                    system("cls");
                    break;
			}
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            printf("\nTelefone: %s ", c.telefone);
            printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nDeseja atualizar este campo?\n \n--> SIM (s)<--\n\n\n--> NÃO (n) <--\n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			scanf("\n%c",&op);
			switch (op) {
				case 's':
				    system("cls");
                    printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("Novo Telefone: ");
					fflush(stdin);
					gets(c.telefone);
					system("cls");
					break;
                case'n':
                    system("cls");
                    break;
			}

            printf("\n// ----- // ----- //// ----- // ----- // \n");
            printf("\nSexo: %c ", c.sexo);
            printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nDeseja atualizar este campo?\n \n--> SIM (s)<--\n\n\n--> NÃO (n) <--\n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			scanf("\n%c",&op);
			switch (op) {
				case 's':
				    fflush(stdin);
				    system("cls");
				    printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("Novo Sexo: ");
					scanf("%c", &c.sexo);
					system("cls");
					break;
                case'n':
                    system("cls");
                    break;
			}while(op=!'n');

            printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nIdade: %d ", c.idade);
			printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nDeseja atualizar este campo?\n \n--> SIM (s)<--\n\n\n--> NÃO (n) <--\n\n");
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			scanf("\n%c",&op);
			switch (op) {
				case 's':
				    system("cls");
				    printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("Nova Idade: ");
					scanf("%d", &c.idade);
					system("cls");
					break;
                case'n':
                    system("cls");
                    break;
			}
			fwrite(&c ,sizeof (cliente),1, hos);
            fclose(hos);
            system("cls");
		}
		else
        {
            system("cls");
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            printf("\nCliente não encontrado\n\n");
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            system("pause");
        }
	}
	system("cls");
}

void remove_cliente(char *cpf) {
	system("cls");
	hos = fopen("hospede.dat", "rb+");
	cliente c;
	char op;
	int val=0;
	fseek(hos, 0, SEEK_SET);
	if (hos == NULL) {
		puts("Não foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 && strcmp(cpf, c.cpf)!=0) {}
		if(strcmp(cpf, c.cpf)==0 && c.ativo!=0) {
			system("cls");
			printf("\nOs dados desse cliente serão:\n");
			fread(&c, sizeof(cliente), 0, hos);
			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nCPF: %s \n", c.cpf);
			printf("Nome: %s \n", c.nome);
			printf("Sobrenome: %s \n", c.sobrenome);
			printf("Telefone: %s \n", c.telefone);
			printf("Sexo: %c \n", c.sexo);
			printf("Idade: %d ", c.idade);
			printf("\n\n// ----- // ----- //// ----- // ----- // \n");
			system("pause");
			system("cls");

			printf("\n// ----- // ----- //// ----- // ----- // \n");
			printf("\nOs dados serão Deletados...\n\n");
			printf("\nDeseja continuar?\n \n--> SIM (s)<--\n\n\n--> NÃO (n) <--\n\n");
			("\n// ----- // ----- //// ----- // ----- // \n");
			fflush(stdin);
			scanf ("%c", &op);

			switch (op) {
				case 's':
					fseek(hos, -sizeof(cliente), SEEK_CUR);
					fflush(stdin);
					system("cls");
					c.ativo=0;
					printf("\n// ----- // ----- //// ----- // ----- // \n\n");
					printf("Cliente deletado");
					printf("\n\n// ----- // ----- //// ----- // ----- // \n\n");
					fwrite(&c ,sizeof (cliente),1, hos);
					fclose(hos);
					system("pause");
					system("cls");
				break;

				case 'n':
					system("cls");
					printf("\n// ----- // ----- //// ----- // ----- // \n");
					printf("\nOperação cancelada\n");
					printf("\n// ----- // ----- //// ----- // ----- // \n\n");
					system("pause");
					system("cls");
				break;

				default:
					printf("\nEntrada desconhecida\n");
					system("pause");
					system("cls");
				break;
			}
		}
		else{
            system("cls");
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            printf("\nCliente não encontrado\n\n");
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            system("pause");
		}

	}
	system("cls");
}

/*void imprime_cliente(char *cpf ) {
    hos = fopen("hospede.dat", "rb");
	cliente c;

	if (hos == NULL) {
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		while(fread(&c, sizeof(cliente), 1, hos)==1 ) {
			if(strcmp(cpf, c.cpf)==0 && c.ativo!=0)
        {
            system ("cls");
            printf("\n// ----- // ----- // Dados do cliente // ----- // ----- // \n");
            printf("\nCPF: %s \n", c.cpf);
            printf("Nome: %s \n", c.nome);
            printf("Sobrenome: %s \n", c.sobrenome);
            printf("Telefone: %s \n", c.telefone);
            printf("Sexo: %c \n", c.sexo);
            printf("Idade: %d \n ", c.idade);
            printf("\n// ----- // ----- //// ----- // ----- // \n");
            system("pause");
            system ("cls");
            fclose(hos);
            return 0;
        }
    };
    system("cls");
    printf("\n// ----- // ----- // Cliente não encontrado // ----- // ----- // \n\n");
    system("pause");
    system("cls");
    fclose(hos);
}
}*/

void imprime_cliente(cliente c) {
	system("cls");

	hos = fopen("hospede.dat", "rb");

	if (hos == NULL) {
		puts("Não foi possivel abrir o arquivo!\n");
		exit(1);
	} else {
		printf("\n// ----- // ----- // LISTA DE CADASTROS // ----- // ----- // \n");
		while(fread(&c, sizeof(cliente), 1, hos)==1) {
			if(c.ativo!=0) {
				printf("\nCPF: %s \n", c.cpf);
				printf("Nome: %s \n", c.nome);
				printf("Sobrenome: %s \n", c.sobrenome);
				printf("Telefone: %s \n", c.telefone);
				printf("Sexo: %c \n", c.sexo);
				printf("Idade: %d ", c.idade);

				printf("\n// ----- // ----- //// ----- // ----- // \n");
			}
		}
		fclose(hos);
	}
	system("pause");
	system("cls");
}

void gerar_relatorio(cliente c){
	system("cls");
	hos = fopen("hospede.dat", "rb");
	rel = fopen("relatorio.txt", "w");

	if (hos == NULL) {
		puts("Não foi possivel abrir o arquivo!\n");
		exit(1);
	} else if(rel != NULL) {
		printf("\n// ----- // ----- //// ----- // ----- // \n");
		printf("\n Gerando Relatório...\n\n");

		while(fread(&c, sizeof(cliente), 1, hos)==1) {
			printf(" .\n");
			if(c.ativo!=0) {
				fprintf(rel, "%s%s%s%s%s%s%s%s%s%c%s%d%s", "{ CPF: " , c.cpf, ", Nome: ", c.nome, ", Sobrenome: ", c.sobrenome, ", Telefone: ", c.telefone, ", Sexo: ", c.sexo, ", Idade: ", c.idade, " }, " );
			}
		}
		printf("\n Relatório GERADO COM SUCESSO \n\n");
	}else{
		puts("Nao foi possivel abrir o arquivo!\n");
		exit(1);
	}
	fclose(hos);
	fclose(rel);

	system("pause");
	system("cls");

}

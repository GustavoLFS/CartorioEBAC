#include <stdio.h> //biblioteca de comunica��o com o user
#include <stdlib.h> //aloca��o de espa�o na mem�ria
#include <locale.h> //aloca��o de texto por regi�o
#include <string.h> //respons�vel por cuidar das strings

int main ()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada: \n\n");
		printf("\t1 - Registrar\n");
		printf("\t2 - Consultar\n");
		printf("\t3 - Deletar\n"); 
		printf("\t4 - Sair do sistema\n\n"); //fim do menu
		printf("Op��o:  ");
	
		scanf("%d", &opcao); //armazenando a escolha do user
	
		system("cls"); //apagar as mensagens anteriores
	
		switch (opcao) //inicio das valida��es
		{ 
		
			case 1:
				registro();	
			break;
		
			case 2:
				consultar();	
			break;	
		
			case 3:
				deletar();	
			break;
			
			case 4:
				printf("Saindo...Obrigado por utilizar o sistema\n\n");
				return 0;	
			break;
			
			default:
				printf("Op��o invalida\n");
				system("pause");
			break;
		} //fim das valida��es
	
		printf("\nEsse Software � de livre uso dos alunos\n");
	
	}
}

int registro() //fun��o respons�vel por cadastrar novos usu�rios
{
	//inicio da cria��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//termino da cria��o das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do user
	scanf("%s", cpf); //%s para string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, "\nCPF: "); //salvo a descri��o do valor
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //"a" atualiza o arquivo
	fprintf(file, "\nNome: ");
	fprintf(file,nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: "); 
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, "\nCargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	system("cls");
	
	printf("\tCadastro realizado com sucesso!\n\n");
	
	system("pause");
	
}


int consultar() //fun��o respons�vel pela consulta dos usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	//inicio abertura das vari�veis
	char cpf[40];
	char conteudo[200];
	//termino abertura das vari�veis
	
	printf("Digite o CPF que deseja consultar: "); //coletando informa��es para a consulta
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir o arquivo "r" para leitura
	
	system("cls");
	
	printf("Dados do usu�rio:\n\n");
	
	if(file == NULL) //valida��o para dados inexistentes
	{
		printf("\n\nDados inexistentes!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando o valor dos dados na vari�vel
	{
		printf("%s", conteudo);	//exibindo os dados do user
	}
	
	fclose(file); //fechando o arquivo
	
	printf("\n\n\n");	
	
	system("pause");
}

int deletar() //fun��o criada para a exclus�o de usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	//inicio abertura das vari�veis
	char cpf[40];
	int opcao=0;
	char conteudo[200];
	//termino abertura das vari�veis	
	
	printf("Digite o CPF que deseja excluir: "); //coletando informa��es para a exclus�o
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir o arquivo "r" para leitura	
	
	if (file == NULL) //valida��o para usu�rio inexistente
	{
		printf("\n\nUsu�rio n�o encontrado!\n\n\n");
		system("pause");
		return 0; //saindo da fun��o
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando o valor dos dados na vari�vel
	{
		printf("%s", conteudo);	//exibindo os dados do user
	}
		fclose(file);
		printf("\n\nDeseja excluir os dados desse usu�rio? \n"); //questionando se os dados exibidos s�o os que deseja excluir
		printf("1 - Sim\t");
		printf("\t2 - N�o\n");
		printf("Op��o: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch (opcao) 
		{
			case 1:
				printf("\tDados excluidos com sucesso!\n\n\n");
				system("pause");
			break;
			
			case 2:
				printf("\tRetornando ao in�cio!\n\n\n");
				system("pause");
				return 0; //saindo da fun��o
			break;
			
			default:
				printf("\tOp��o invalida! Retornando ao in�cio!\n\n\n");
				system("pause");
				return 0; //saindo da fun��o
			break;
		}
		remove(cpf); //excluindo os dados caso passe nas valida��es
	}




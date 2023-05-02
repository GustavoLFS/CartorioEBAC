#include <stdio.h> //biblioteca de comunicação com o user
#include <stdlib.h> //alocação de espaço na memória
#include <locale.h> //alocação de texto por região
#include <string.h> //responsável por cuidar das strings

int main ()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada: \n\n");
		printf("\t1 - Registrar\n");
		printf("\t2 - Consultar\n");
		printf("\t3 - Deletar\n"); 
		printf("\t4 - Sair do sistema\n\n"); //fim do menu
		printf("Opção:  ");
	
		scanf("%d", &opcao); //armazenando a escolha do user
	
		system("cls"); //apagar as mensagens anteriores
	
		switch (opcao) //inicio das validações
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
				printf("Opção invalida\n");
				system("pause");
			break;
		} //fim das validações
	
		printf("\nEsse Software é de livre uso dos alunos\n");
	
	}
}

int registro() //função responsável por cadastrar novos usuários
{
	//inicio da criação das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//termino da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do user
	scanf("%s", cpf); //%s para string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, "\nCPF: "); //salvo a descrição do valor
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


int consultar() //função responsável pela consulta dos usuários
{
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	//inicio abertura das variáveis
	char cpf[40];
	char conteudo[200];
	//termino abertura das variáveis
	
	printf("Digite o CPF que deseja consultar: "); //coletando informações para a consulta
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir o arquivo "r" para leitura
	
	system("cls");
	
	printf("Dados do usuário:\n\n");
	
	if(file == NULL) //validação para dados inexistentes
	{
		printf("\n\nDados inexistentes!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando o valor dos dados na variável
	{
		printf("%s", conteudo);	//exibindo os dados do user
	}
	
	fclose(file); //fechando o arquivo
	
	printf("\n\n\n");	
	
	system("pause");
}

int deletar() //função criada para a exclusão de usuários
{
	setlocale(LC_ALL, "Portuguese"); //definir linguagem
	
	//inicio abertura das variáveis
	char cpf[40];
	int opcao=0;
	char conteudo[200];
	//termino abertura das variáveis	
	
	printf("Digite o CPF que deseja excluir: "); //coletando informações para a exclusão
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir o arquivo "r" para leitura	
	
	if (file == NULL) //validação para usuário inexistente
	{
		printf("\n\nUsuário não encontrado!\n\n\n");
		system("pause");
		return 0; //saindo da função
	}
	
	while(fgets(conteudo, 200, file) != NULL) //salvando o valor dos dados na variável
	{
		printf("%s", conteudo);	//exibindo os dados do user
	}
		fclose(file);
		printf("\n\nDeseja excluir os dados desse usuário? \n"); //questionando se os dados exibidos são os que deseja excluir
		printf("1 - Sim\t");
		printf("\t2 - Não\n");
		printf("Opção: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch (opcao) 
		{
			case 1:
				printf("\tDados excluidos com sucesso!\n\n\n");
				system("pause");
			break;
			
			case 2:
				printf("\tRetornando ao início!\n\n\n");
				system("pause");
				return 0; //saindo da função
			break;
			
			default:
				printf("\tOpção invalida! Retornando ao início!\n\n\n");
				system("pause");
				return 0; //saindo da função
			break;
		}
		remove(cpf); //excluindo os dados caso passe nas validações
	}




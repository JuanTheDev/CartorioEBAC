#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{ 
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Esse "w" � de write/criar o arquivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Esse "a" significa atualizar arquivo
	fprintf(file, ","); //Adiciona a virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",nome); //Salva a inform��o do usu�rio no local determinado
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualiza-lo
	fprintf(file,nome); //Fala qual informa��o coletada ser� usada para atualizar
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualiza-lo
	fprintf(file, ","); //Atualiza-o com a virgula
	fclose(file); //FEcha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coleta informa��o do usu�rio
	scanf("%s",sobrenome); //Salva a informa��o no local especificado
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file,sobrenome); //Dizendo para onde a atualiza��o vai
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre para atualizar
	fprintf(file,","); //Adiciona a virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //PEde para o usu�rio digitar a inform��o
	scanf("%s",cargo); //Sala a informa��o
	
	file = fopen(arquivo, "a"); //Abre para atualizar
	fprintf(file,cargo); //Atualiza com a iforma��o salva
	fclose(file); //Fecha o arquivo
	
	system("pause");
}

int consulta() //Fun��o necessaria por consultar usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coleta a informa��o
	scanf("%s",cpf); //L� a informa��o escrita pelo usu�rio e salva no local escolhido
	
	FILE *file; //Acha o arquivo e o seleciona para abri-lo
	file = fopen(cpf,"r"); //Abre o arquivo descrito para Ler/read
	
	if(file == NULL) //Diz se o arquivo existe ou n�o
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Quando o arquivo n�o existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Quando o arquivo existe no sistema
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Retorno para o usu�rio das informa��es
		printf("%s", conteudo); //Mostra o conte�do da informa��o
		printf("\n\n"); //pula linha
	}
	
	system("pause");
}

int deletar() //Fun��o necessaria para deletar informa��es
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletar a informa��o
	scanf("%s",cpf); //Ler a informa��o escrita pelo usu�rio
	
	remove(cpf); //Remove a informa��o
	
	FILE *file; //Acessa o arquivo e o seleciona
	file =fopen(cpf,"r"); //Abre o arquivo para ler
	
	if(file == NULL) //Caso o arquivo n�o exista
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Denifindo Vari�vel
	int laco=1; //Definindo vari�vel
	
	for(laco=1;laco=1;) //Inicio do la�o
	{
		
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
		
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do Menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a Escolha do Usu�rio
	
		system("cls"); //Para deixar a tela mais limpa
		
		switch(opcao) //Inicio da Sele��o
		{
			case 1:
			registro(); //Chamada das fun��es
			break;
			
			case 2:
			consulta(); //Chamada das fun��es
			break;
			
			case 3:
			deletar(); //Chamada das fun��es
			break;
			
			default:
			printf("Essa op��o n�o esta disponivel!\n"); //Retorno ao usu�rio
			system("pause"); //pausa no sistema
			break;
		} //Fim da Sele��o
	} //Fim do la�o
}

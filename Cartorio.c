#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{ 
	//Inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Esse "w" é de write/criar o arquivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Esse "a" significa atualizar arquivo
	fprintf(file, ","); //Adiciona a virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s",nome); //Salva a informção do usuário no local determinado
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualiza-lo
	fprintf(file,nome); //Fala qual informação coletada será usada para atualizar
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo para atualiza-lo
	fprintf(file, ","); //Atualiza-o com a virgula
	fclose(file); //FEcha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coleta informação do usuário
	scanf("%s",sobrenome); //Salva a informação no local especificado
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo
	fprintf(file,sobrenome); //Dizendo para onde a atualização vai
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre para atualizar
	fprintf(file,","); //Adiciona a virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //PEde para o usuário digitar a informção
	scanf("%s",cargo); //Sala a informação
	
	file = fopen(arquivo, "a"); //Abre para atualizar
	fprintf(file,cargo); //Atualiza com a iformação salva
	fclose(file); //Fecha o arquivo
	
	system("pause");
}

int consulta() //Função necessaria por consultar usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //Coleta a informação
	scanf("%s",cpf); //Lê a informação escrita pelo usuário e salva no local escolhido
	
	FILE *file; //Acha o arquivo e o seleciona para abri-lo
	file = fopen(cpf,"r"); //Abre o arquivo descrito para Ler/read
	
	if(file == NULL) //Diz se o arquivo existe ou não
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Quando o arquivo não existe
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Quando o arquivo existe no sistema
	{
		printf("\nEssas são as informações do usuário: "); //Retorno para o usuário das informações
		printf("%s", conteudo); //Mostra o conteúdo da informação
		printf("\n\n"); //pula linha
	}
	
	system("pause");
}

int deletar() //Função necessaria para deletar informações
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletar a informação
	scanf("%s",cpf); //Ler a informação escrita pelo usuário
	
	remove(cpf); //Remove a informação
	
	FILE *file; //Acessa o arquivo e o seleciona
	file =fopen(cpf,"r"); //Abre o arquivo para ler
	
	if(file == NULL) //Caso o arquivo não exista
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Denifindo Variável
	int laco=1; //Definindo variável
	
	for(laco=1;laco=1;) //Inicio do laço
	{
		
		system("cls"); //limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
		
		printf("### Cartório da EBAC ###\n\n"); // Inicio do Menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a Escolha do Usuário
	
		system("cls"); //Para deixar a tela mais limpa
		
		switch(opcao) //Inicio da Seleção
		{
			case 1:
			registro(); //Chamada das funções
			break;
			
			case 2:
			consulta(); //Chamada das funções
			break;
			
			case 3:
			deletar(); //Chamada das funções
			break;
			
			default:
			printf("Essa opção não esta disponivel!\n"); //Retorno ao usuário
			system("pause"); //pausa no sistema
			break;
		} //Fim da Seleção
	} //Fim do laço
}

#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por regiõa
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//incio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado:"); //colentado informações do usuario
	scanf("%s", cpf); //%s refere-se a bibliocate string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digte o nome a ser cadastrado:");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta() //criação da função consulta
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");		
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}



int deletar() //criação da função deletar
{
	char cpf[40]; //variavel a ser consultada
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //remove o cpf indicado
	
	FILE *file; //abre o arquivo
	file = fopen(cpf, "r"); //lendo o arquivo "r"
	
	if(file == NULL) //analisa usuario inexistente
	{
		printf("O usuario não se encontra no sistema! \n");
		system("Pause");	
	}
		else
		{
			fclose(file);
			
		if(remove(cpf) == 0)
		{
			printf("Usuario deletado com sucesso!\n");
			system("Pause");
		}
		
		else
		{
			printf("Erro ao deletar usuario. \n");
			system("Pause");
		}
		}
	
}

int main()
{
	int opcao=0; //definindo variavéis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
	
		system("cls"); //responsavel por limpar a tela
				
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de função
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa Opção não está disponivel!\n");
			system("pause");
			break;
			
		} //fim da seleção
	}
	
}

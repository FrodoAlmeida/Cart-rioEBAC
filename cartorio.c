#include <stdio.h>  //blibioteca de comunicação com o usário
#include <stdlib.h> //blibioteca de alocação de espaço em memória
#include <locale.h> //blibioteca de alocações de texto por região
#include <string.h> // bliblioteca de alocação em string / responsável por cuidar das string's

	int registro() // Função responsável por cadastrar os usuários no sistema
	{
		// Início da criação de variáveis/string's
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// Final da criação de variáveis/string's
		
		printf("Digite o CPF a ser cadastrado: "); // Coletando informações dos usuários
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); // Renponsável por copiar os valores das string
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo na pasta na onde foi feito o sistema e o "w" significa escrever
		fprintf(file,cpf); //Salva o valor da variável
		fclose(file); // Fecha o arquivo da variável 
		
		file = fopen(arquivo, "a"); // "a" significa atualizar o file que já existe
		fprintf(file,","); // "," para quando for escrito a atualização no file para que cada file novo tenha uma virgula antes, caso não tivesse, ficaria tudo junto na hora de pesquisar
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file= fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file= fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o Cargo dessa pessoa: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		

		
	}
	
	int consulta()
	{
		
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o Cpf a ser Consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL) // "NULL" na biblioteca significa se não for igual ao pesquisado
		{
			
			printf(" Não existe esse CPF, Digite novamente o CPF! \n");
		
		}
		
		while(fgets(conteudo, 200,file) != NULL)
		{
			printf("\nEssas são as informações do usário:");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
		
	}

	int deletar()
	{
		char cpf[40];
		
		printf("Digite o CPF de quem deseja deletar:  ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("CPF apagado ou esse CPF não existe no sistema! \n");
			system("pause");
		
		}
	}
	
	
	
	int main()
	{
	int opcao=0; // Definindo Variáveis
	int rept=1; // Variavel do tipo de repetição por isso rept
	
	for(rept=1;rept=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");	// Início do menu
	
			printf("Escolha a opção desejada do menu:\n\n");
		
				printf("\t1 - Registrar nomes\n\n");
			
					printf("\t2 - Consultar nomes\n\n");
				
						printf("\t3 - Deletar nomes\n\n"); // Fim do menu
					
							printf("Opção: \t"); // Coloquei \t pra ficar mais bonito
						
		scanf("%d", &opcao); // Armazenando a escolha do user
	
		system("cls"); // responsável por limpar a tela
		
		switch(opcao) // Inicio da seleção de menus
		{
			case 1:
			registro(); // Chamada de funções
			break;
			
			case 2:	
			consulta();
			break; // para quando requisitar o 'case' para poder sair
			
			case 3:
			deletar();
			break;
			
			default:	
			printf("Essa opção não existe! Obrigado tente novamente! \n"); // Fim da Seleção
			system("pause");
			break;
			
		}
	}
}
	

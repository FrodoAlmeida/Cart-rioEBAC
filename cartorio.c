#include <stdio.h>  //blibioteca de comunica��o com o us�rio
#include <stdlib.h> //blibioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //blibioteca de aloca��es de texto por regi�o
#include <string.h> // bliblioteca de aloca��o em string / respons�vel por cuidar das string's

	int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
	{
		// In�cio da cria��o de vari�veis/string's
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		// Final da cria��o de vari�veis/string's
		
		printf("Digite o CPF a ser cadastrado: "); // Coletando informa��es dos usu�rios
		scanf("%s", cpf); //%s refere-se a string
		
		strcpy(arquivo, cpf); // Renpons�vel por copiar os valores das string
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo na pasta na onde foi feito o sistema e o "w" significa escrever
		fprintf(file,cpf); //Salva o valor da vari�vel
		fclose(file); // Fecha o arquivo da vari�vel 
		
		file = fopen(arquivo, "a"); // "a" significa atualizar o file que j� existe
		fprintf(file,","); // "," para quando for escrito a atualiza��o no file para que cada file novo tenha uma virgula antes, caso n�o tivesse, ficaria tudo junto na hora de pesquisar
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
		
		if(file == NULL) // "NULL" na biblioteca significa se n�o for igual ao pesquisado
		{
			
			printf(" N�o existe esse CPF, Digite novamente o CPF! \n");
		
		}
		
		while(fgets(conteudo, 200,file) != NULL)
		{
			printf("\nEssas s�o as informa��es do us�rio:");
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
			printf("CPF apagado ou esse CPF n�o existe no sistema! \n");
			system("pause");
		
		}
	}
	
	
	
	int main()
	{
	int opcao=0; // Definindo Vari�veis
	int rept=1; // Variavel do tipo de repeti��o por isso rept
	
	for(rept=1;rept=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");	// In�cio do menu
	
			printf("Escolha a op��o desejada do menu:\n\n");
		
				printf("\t1 - Registrar nomes\n\n");
			
					printf("\t2 - Consultar nomes\n\n");
				
						printf("\t3 - Deletar nomes\n\n"); // Fim do menu
					
							printf("Op��o: \t"); // Coloquei \t pra ficar mais bonito
						
		scanf("%d", &opcao); // Armazenando a escolha do user
	
		system("cls"); // respons�vel por limpar a tela
		
		switch(opcao) // Inicio da sele��o de menus
		{
			case 1:
			registro(); // Chamada de fun��es
			break;
			
			case 2:	
			consulta();
			break; // para quando requisitar o 'case' para poder sair
			
			case 3:
			deletar();
			break;
			
			default:	
			printf("Essa op��o n�o existe! Obrigado tente novamente! \n"); // Fim da Sele��o
			system("pause");
			break;
			
		}
	}
}
	

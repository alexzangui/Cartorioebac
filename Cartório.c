#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por regiões
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuário no sistema
{   
    //início criação de variáveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser Cadastrado:"); //coletando informção do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
   	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrver
	fprintf(file,cpf); //salva o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa escrver
	fprintf(file,","); //salva o valor da variável e a ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a ser Cadastrado: "); //coletando informção do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa escrver
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //cria o arquivo e o "a" significa escrver
	fprintf(file,","); //salva o valor da variável e a ","
	fclose(file);  //fecha o arquivo
		
    printf("Digite o Sobrenome a ser Cadastrado: "); //coletando informção do usuário
	scanf("%s", sobrenome);  //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa escrver
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser Cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consultar()
{
	setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	
    char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");	
	
	if(file == NULL)
	{
		printf("\nNão foi Possível Abrir o Arquivo, Não Localizado!.\n");
        printf("\n");
	}
    
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas são as Informações do Usuário: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
    
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do Usuáro a ser Deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	   printf("\nO Usuário não se encontra no Sistema!.\n\n");
	   system("pause");
	}	

}

int main()
{
    int opcao=0; //definindo às variavéis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	   setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	   
	   system("cls");
	   
	   printf("### Cartório Ebac ###\n\n");//início do menu
	   printf("Escolha a Opção Desejada do Menu:\n\n");
	   printf("\t1 - Registrar Nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar Nomes\n");
	   printf("\t4 - Sair do Sistema\n");
	   printf("Opção"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usuário
	
	   system("cls"); //responsável por limpar a tela
	
	
	   switch(opcao) //início da seleção do menu
	   {
	   	   case 1:
	   	   registro(); //chamada de funções
	       break; //para a função
		   
	   	   case 2: 
	       consultar(); //chamada de funções
	       break; //para a função
	       
	       case 3:
	       deletar(); //chamada de funções
	       break; //para a função

	       case 4:
	       printf("Obrigado por Utilizar o Sistema!\n");
	       return 0;
	       break;
	       
		   default:
	       printf("Essa Opção não está Disponível!\n");
	       system("pause");
	       break; //para a função
	    }//fim de funções    
		   	
    } 
}

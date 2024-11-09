#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�es
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rio no sistema
{   
    //in�cio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser Cadastrado:"); //coletando inform��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
   	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrver
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa escrver
	fprintf(file,","); //salva o valor da vari�vel e a ","
	fclose(file); //fecha o arquivo
	
	printf("Digite o Nome a ser Cadastrado: "); //coletando inform��o do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa escrver
	fprintf(file,nome); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //cria o arquivo e o "a" significa escrver
	fprintf(file,","); //salva o valor da vari�vel e a ","
	fclose(file);  //fecha o arquivo
		
    printf("Digite o Sobrenome a ser Cadastrado: "); //coletando inform��o do usu�rio
	scanf("%s", sobrenome);  //%s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa escrver
	fprintf(file,sobrenome); //salva o valor da vari�vel
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
		printf("\nN�o foi Poss�vel Abrir o Arquivo, N�o Localizado!.\n");
        printf("\n");
	}
    
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as Informa��es do Usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
    }
    
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do Usu�ro a ser Deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	   printf("\nO Usu�rio n�o se encontra no Sistema!.\n\n");
	   system("pause");
	}	

}

int main()
{
    int opcao=0; //definindo �s variav�is
    int laco=1;
    
    for(laco=1;laco=1;)
    {
	
	   setlocale (LC_ALL, "Portuguese"); //definindo linguagem
	   
	   system("cls");
	   
	   printf("### Cart�rio Ebac ###\n\n");//in�cio do menu
	   printf("Escolha a Op��o Desejada do Menu:\n\n");
	   printf("\t1 - Registrar Nomes\n");
	   printf("\t2 - Consultar Nomes\n");
	   printf("\t3 - Deletar Nomes\n");
	   printf("\t4 - Sair do Sistema\n");
	   printf("Op��o"); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	   system("cls"); //respons�vel por limpar a tela
	
	
	   switch(opcao) //in�cio da sele��o do menu
	   {
	   	   case 1:
	   	   registro(); //chamada de fun��es
	       break; //para a fun��o
		   
	   	   case 2: 
	       consultar(); //chamada de fun��es
	       break; //para a fun��o
	       
	       case 3:
	       deletar(); //chamada de fun��es
	       break; //para a fun��o

	       case 4:
	       printf("Obrigado por Utilizar o Sistema!\n");
	       return 0;
	       break;
	       
		   default:
	       printf("Essa Op��o n�o est� Dispon�vel!\n");
	       system("pause");
	       break; //para a fun��o
	    }//fim de fun��es    
		   	
    } 
}

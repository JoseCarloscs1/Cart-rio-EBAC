#include <stdio.h> //biblioteca de coimunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string's

int registro() //funçãao responsavel por cadasatrar usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do string
	scanf("%s", cpf); // %s refere-se a string 
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string's
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo //"w"siginifica escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file= fopen(arquivo, "a"); //"a" significa atualizar 
	fprintf(file, ","); // salva o que foi adicionado colocando uma virgula no fim
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações 
	scanf("%s",nome); //atribuindo as informações coletadas 
	
	file = fopen(arquivo, "a");//"a" significa atualizar 
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	
	file= fopen(arquivo, "a"); //abre o arquivo para atualiza-lo
	fprintf(file, ","); //salva o que foi adicionado colocando uma virgula no fim
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações
	scanf("%s",sobrenome); //atribuindo informações coletadas
	
	file = fopen(arquivo, "a"); //abrindo arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file= fopen(arquivo, "a"); //abre o arquivo para atualizar 
	fprintf(file, ","); //salva o que foi adicionado colocando uma virgula no fim
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando irformações 
	scanf("%s", cargo); //atribuindo informações coletadas  
	file = fopen(arquivo, "a"); //abre arquivo para atualizar 
	fprintf(file,cargo); //salva o que foi adicionado 
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa o sistema 
	
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf [40];
	char conteudo[200];
	
	
	printf("Digite o cpf a ser consultado.");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!. \n ");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{printf("\nEssas são as informkações do usuário: ");
	printf("%s", conteudo);
	printf ("\n\n");
	}
	
	system("pause");
}

int deleta()
{
	char cpf[40];
	
	printf("Digite o CPf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	 if(file == NULL)
	 {
	 	printf("O usuário não se encontra no sistema!.\n");
	 	system("pause");
	 }

	
	
}



int main()
{
	int opcao=0; //definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
	    system("cls");
	
	
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n" );
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("\t4 - Sair do Sistema\n");
	    printf("opção: "); //fim do menu

        scanf("%d", &opcao);
    
        system("cls"); //responsavel por limpar a tela
        
        switch(opcao) //inicio da seleção de menu
		{
			case 1:
			registro(); //chamada de funções
    	    break;
    	    
    	    case 2:
    	    consulta();
		    break;
		    
		    case 3:
		    deleta();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!");
	        return 0;
	        break;
	        
	        default:
			printf("Essa opção não está disponivel!\n");
		    system("pause");
		    break;
        
		}

}
}

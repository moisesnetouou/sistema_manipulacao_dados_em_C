/*
Moisés Serrão da Mata Neto
Finalizado: 22/05/2021
Sistema Simples de Manipulação de Dados
*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
//Structs
typedef struct Data{
	int dia, mes, ano;
}DATA;

typedef struct Pessoa{
	char nome[100];
	float salario;
	struct Data dt_nasc;
	int ativo;
}PESSOA;

//Prototipos
void cadastroPessoa();
void imprimirDadosPessoa();
void alterarPessoa();
void retorno();
void excluirPessoa();

int main(){
	setlocale(LC_ALL, "Portuguese");
	PESSOA pessoas[4];
	int op,cont_livre, n,cont_vet, cont_pessoa, quantidade, z;
	//variaveis para poder controlar o sistema, percorrer vetor e retornar dado.
	z = 0;
	cont_livre = 0;
	cont_vet = 0;
	quantidade = 0;
	//Zerar campos ativo antes de iniciar sempre.
	while(z <= 4){
		pessoas[z].ativo = 0;
		z++;
	}
	
	while(op != 6){ //Enquanto for diferente de 6, executa o sistema.
		printf("\n-----------SISTEMA DE DADOS-----------\n\n");
		printf("\n-->1. Cadastrar Pessoa.");
		printf("\n-->2. Alterar dados de uma pessoa.");
		printf("\n-->3. Quantidade de Pessoas armazenadas.");
		printf("\n-->4. Excluir Pessoa.");
		printf("\n-->5. Mostrar Dados.");
		printf("\n-->6. Sair\n");
		
		printf("\n-->O que deseja? : ");
		scanf("%d", &op);
		
		//laço de repetição para poder controlar o cadastro, caso esteja cheio.
		for(cont_vet = 0; cont_vet <= 4; cont_vet++ ){
			if(pessoas[cont_vet].ativo == 0){
				cont_livre++;
			}else{
				cont_livre = cont_livre + 0;
				
			}
		}
		
		if(op==1 && cont_livre == 0){
			system("cls");
			printf("->Armazenamento está cheio.\n");
			printf("->Necessita excluir alguem (utilize opção 4 - Excluir Pessoa.).\n");
			retorno();
		}else{		
			cont_livre = 0;
			switch(op){
				case 1: //Cadastro
					system("cls");
					printf("\n-----------CADASTRO DE USUÁRIOS-----------\n\n");
					while(cont_pessoa <= 4){
						if(pessoas[cont_pessoa].ativo == 0){
							cadastroPessoa(&pessoas[cont_pessoa]);
							cont_pessoa = 5;
							/*Quando cadastrar, forçar que cont_pessoa assuma 5
							para que apenas um seja cadastrado.*/
					}else{
						cont_pessoa++;
						}
					}
					cont_pessoa = 0;
					retorno();;
					break;
				
				case 2://Alterar
					system("cls");
					printf("\n-----------ALTERAR DADOS DE USUÁRIOS-----------\n\n");
					printf("\nQual pessoa deseja alterar? \nEscolha de 0 a 4\n\n[0]\n[1]\n[2]\n[3]\n[4]\n\n ");
					printf("\n-->Usuário: ");
					scanf("%d", &n);
					if(pessoas[n].ativo == 0){
						printf("\nNão há pessoa cadastrada na posição digitada\n\n");	
					}else{
						alterarPessoa(&pessoas[n]);
					}
					n = 0;
					retorno();
					break;
				
				case 3:	//Quantidade
					system("cls");
					printf("\n-----------QUANTIDADE DE USUÁRIOS-----------\n\n");
					while(cont_pessoa <= 4){
						if(pessoas[cont_pessoa].ativo == 1 ){
							cont_pessoa++;
							quantidade++;
						}else{
							cont_pessoa++;
							quantidade = quantidade+0;
						}
					}
					printf("\nPessoas Ativas: %d\n\n", quantidade);
					cont_pessoa = 0;
					quantidade = 0;
					retorno();
				break;
				
				case 4: //Excluir
					system("cls");
					printf("\n-----------EXCLUIR USUÁRIO-----------\n\n");
					printf("\nQual usuario deseja excluir?\nEscolha de 0 a 4\n");
					printf("\n->[0]\n->[1]\n->[2]\n->[3]\n->[4]\n");
					printf("\n-->Usuário: ");
					scanf("%d", &n);
					if(pessoas[n].ativo == 0){
						printf("\n\nNão há pessoa cadastrada na posição digitada\n");	
					}else{
						system("cls");
						excluirPessoa(&pessoas[n]);
					}
					n = 0;
					retorno();
					break;
				
				case 5:
					system("cls");
					printf("\n-----------EXIBIR USUÁRIO-----------\n\n");
					printf("\n\nQual pessoa deseja exibir? \n\n->[0]\n->[1]\n->[2]\n->[3]\n->[4]\n\n");
					printf("\nUsuário: ");
					scanf("%d", &n);
					if(pessoas[n].ativo == 0){
						printf("\n\nNão há pessoa cadastrada na posição digitada\n");
						retorno();
					}else{
						system("cls");
						imprimirDadosPessoa(pessoas[n]);
						retorno();
					}
					break;
				
				case 6:
					system("cls");
					if(op == 6){
						printf("\nCerteza? \n->[1]-SIM \n->[2]-NAO");
						scanf("%d",&op);
						if(op == 1){
							op = 6;
							system("cls");
						}else{
							op = 1;
							system("cls");
						}
					}
					break;
					
				default:
					system("cls");
					printf("\nEscreveu errado");
					retorno();
					break;
			}
		}
	}	
	printf("\nTecle qualquer tecla para fechar......");
}

//Funções
void cadastroPessoa(PESSOA *x){
	fflush(stdin);
	printf("Nome: ");
	gets((*x).nome);
	fflush(stdin);
	printf("Salario: R$");
	scanf("%f", &(*x).salario);
	printf("Dia de Nascimento: ");
	scanf("%d", &(*x).dt_nasc.dia);
	printf("Mês de Nascimento: ");
	scanf("%d", &(*x).dt_nasc.mes);
	printf("Ano de Nascimento: ");
	scanf("%d", &(*x).dt_nasc.ano);
	(*x).ativo = 1;
	printf("\nCadastro realizado com sucesso!!\n");
}

void imprimirDadosPessoa(PESSOA x){
	printf("\nNome: %s\nSalario: R$%.2f\nData Nascimento: %d/%d/%d\n", x.nome, x.salario, x.dt_nasc.dia, x.dt_nasc.mes, x.dt_nasc.ano) ;	
}

void alterarPessoa(PESSOA *x){
	int sel;
		system("cls");
		printf("\nO que deseja alterar?\n1. Nome.\n2. Salario.\n3. Data\n");
		scanf("%d",&sel);
			switch(sel){
				case 1:
					fflush(stdin);
					printf("Digite o nome da pessoa: ");
					gets((*x).nome);
					fflush(stdin);
					printf("\nDados alterados com sucesso!!\n");
					break;
					
				case 2:
					printf("Digite o salario da pessoa: ");
					scanf("%f", &(*x).salario);				
					printf("\nDados alterados com sucesso!!\n");
					break;
					
				case 3:
					printf("Digite o dia de nascimento da pessoa: ");
					scanf("%d", &(*x).dt_nasc.dia);
					printf("Digite o mes de nascimento da pessoa: ");
					scanf("%d", &(*x).dt_nasc.mes);
					printf("Digite o ano de nascimento da pessoa: ");
					scanf("%d", &(*x).dt_nasc.ano);
					printf("\nDados alterados com sucesso!!\n");
					break;
				
				default:
					printf("Opção invalida");	
					break;
			}
	}

void retorno(){
		printf("\n");
		system("pause");
		printf("\n");
		system("cls");
}

void excluirPessoa(PESSOA *x){
	int n;
	printf("\nCerteza que deseja excluir usuario?");
	printf("\n->[1].SIM \n->[2].NÃO");
	printf("\nEscolha: ");
	scanf("%d", &n);
	if(n == 2){
		(*x).ativo = 1;
		printf("\nDados não alterados.");
	}else{
		(*x).ativo = 0;
		printf("\n---------Usuário excluido com sucesso!!!---------");
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "func.h"
#include <unistd.h>
#include "base.h"
#define MAX 100
#define MAX_TAM 260


int main() {
	

	Mercado m[MAX];
	FILE *arquivo;
	int n_Mercados=0,select=4;
	char arquivo_mercados[MAX_TAM];
	Lista_de_compras Lista_Final;
	Inicia_Compras(&Lista_Final);
	printf("\n\n      INSIRA NOME DO ARQUIVO QUE CONTEM OS MERCADOS->");
	fflush(stdin);
	gets(arquivo_mercados);

	n_Mercados=Recebe_Mercado(m,arquivo_mercados,n_Mercados); 
	while(select!=0)
	{
		menu();
		printf("      ->");
		scanf("%d",&select);
		if(select==1)
		{	
			int adiciona=1;
			char nome_produto[MAX_TAM];
			while(adiciona!=0)
			{
				printf("\n\n");
				printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
				printf("      @                                     @\n");
				printf("      @     ADICONAR PRODUTO A LISTA -> 1   @\n");
				printf("      @     VOLTAR AO MENU PRINCIPAL -> 0   @\n");
				printf("      @                                     @\n");
				printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
				printf("      ->");
				scanf("%d",&adiciona);

				if(adiciona==1)
				{
					printf("      INSIRA O NOME DO PRODUTO SEM ACENTOS E SINAIS DE NASALIZACAO->");
					fflush(stdin);
					gets(nome_produto);
					Consulta_Menor_Preco(m,nome_produto,&Lista_Final,n_Mercados);
				}
			}
		}
		
		if(select==2)
		{	
			char get_lista[MAX_TAM],txt[MAX_TAM]=".txt";
			printf("      INSIRA O NOME DO ARQUIVO COM OS PRODUTOS SA LISTA DE COMPRAS->");
			fflush(stdin);
			gets(get_lista);
			strcat(get_lista,txt);
			Abre_Lista_De_Compras(get_lista,&Lista_Final,m,n_Mercados);	
			//printf("\n\t%d\n",Lista_Final.tamanho);

	
		}

		if(select==3)
		{
			printf("\n\n");
			Gera_Guia(&Lista_Final,n_Mercados,m);
		}

	}
	
	
	
	

	return 0;
}

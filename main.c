#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "func.h"
#include "base.h"
#define MAX 10
#define MAX_TAM 100


int main() {
	

	Mercado m[MAX];
	FILE *arquivo;
	int n_Mercados=0,select=4;
	char arquivo_mercados[MAX_TAM];
	Lista_de_compras Lista_Final;
	Inicia_Compras(&Lista_Final);
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
				printf("      @                           			@\n");
				printf("      @     ADICONAR PRODUTO A LISTA -> 1   @\n");
				printf("      @     VOLTAR AO MENU PRINCIPAL -> 0   @\n");
				printf("      @                                     @\n");
				printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
				printf("      ->");
				scanf("%d",&adiciona);

				if(adiciona==1)
				{
					printf("      INSIRA O NOME DO PRODUTO SEM ACENTOS E SINAIS DE NASALIZAÇÃO->");
					gets(nome_produto);
					Consulta_Menor_Preco(m,nome_produto,Lista_Final,n_Mercados);
				}
			}
		}
		
		if(select==2)
		{	
			char get_lista[MAX_TAM],txt[MAX_TAM]=".txt";
			printf("      INSIRA O NOME DO ARQUIVO COM OS PRODUTOS SA LISTA DE COMPRAS->");
			gets(get_lista);
			strcat(get_lista,txt);
			Abre_Lista_De_Compras(get_lista,Lista_Final,m,n_Mercados);	
	
		}

		if(select==3)
		{
			Gera_Guia(Lista_Final);
		}

	}
	
	
	
	

	return 0;
}

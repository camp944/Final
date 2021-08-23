#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "func.h"
#include "base.h"
#include "lista.h"
#define MAX 10
#define MAX_TAM 100






int Recebe_Mercado(Mercado m[MAX],char arquivo_mercados[MAX_TAM],int cont_mercados)//L� o arquivo com o nome dos mercados e gera uma lista para cada mercado com seus produtos IDs e valores.
{
	
    char txt[MAX]=".txt";
    strcat(arquivo_mercados,txt);
    
    FILE *f_Mercados;
    f_Mercados=NULL;
   

    while(f_Mercados==NULL)//Abre o arquivo com o nome dos mercados
    {
    
    	f_Mercados=fopen(arquivo_mercados,"rt");
        

        if(f_Mercados!=NULL)
        {
            printf("\n\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf( "      @                          @\n");
            printf( "      @      ARQUIVO ABERTO      @\n");
            printf( "      @                          @\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        }
        else
        {
            printf("\n\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf( "      @                          @\n");
            printf( "      @  ARQUIVO NAO ENCONTRADO  @\n");
            printf( "      @                          @\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

            printf("      INSIRA UM NOME PARA O ARQUIVO COM A INFORMACAO DOS MERCADOS -> ");
            fflush(stdin);
            gets(arquivo_mercados);
            strcat(arquivo_mercados,txt);
        }
    }

    int opera=0;
    char *token;
    char leitor[MAX_TAM];


    while((fgets(leitor,MAX_TAM,f_Mercados)!=NULL))
	{
		char abre_mercado[MAX_TAM];
		token=strtok(leitor,"->");

        while(token!=NULL)
        {        
            char copia[MAX_TAM];
            strcpy(copia,token);

            if(opera==0)
            {
            	int ID;                
            	ID=atoi(copia);
                m[cont_mercados].ID_mercado=ID;
                opera++;
            }else
            {   
                if(opera==1)
                {
                	strcpy(m[cont_mercados].nome_mercado,token);
                	opera++;
				}
				else
				{
					opera=0;
					break;
				}
            }

            

            token=strtok(NULL,"->");
        }

        strcpy(abre_mercado,m[cont_mercados].nome_mercado);
        strcat(abre_mercado,txt);
        Recebe_Produto(&m[cont_mercados],abre_mercado);
		cont_mercados++;
		
	}

    fclose(f_Mercados);
    
    return cont_mercados;
}
void Recebe_Produto(Mercado *i,char nome_Mercado[MAX_TAM])//Gera a lista com os produtos de cada mercado
{

    
    char leitor[MAX_TAM],*token,copia[MAX_TAM];

    int operador=0;
	FILE *f_Mercado;
    f_Mercado=NULL;
    f_Mercado=fopen(nome_Mercado,"rt");
    

    if(f_Mercado!=NULL)
    {
        printf("\n\n");
        printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf("      @                              @\n");
        printf("      @       MERCADO ENCONTRADO     @\n");
        printf("      @                              @\n");
        printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    }
    else
    {
        printf("\n\n");
        printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
        printf( "      @                                  @\n");
        printf( "      @       MERCADO NAO ENCONTRADO     @\n");
        printf( "      @                                  @\n");
        printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");

        return;
    }
    
    
    
    LVazia(i);
    

    while(fgets(leitor,MAX_TAM,f_Mercado)!=NULL)
    {
        int ID;
        float Valor;
        char Nome[MAX_TAM];
        token=strtok(leitor,"->");
        

        while(token!=NULL)
        {   
            strcpy(copia,token);
			
            if(operador==0)
            {
                
                ID=atoi(copia);
                operador++;
            }
            else
            {
                if (operador==1)
                {
                    strcpy(Nome,token);
                    
                    operador++;
                }
                else
                {
                    Valor=atof(copia);
                    operador=0;
                }

            }
            token=strtok(NULL,"->");
        }
        
       

        LInserir(i,ID,Nome,Valor);
           
        
    }

    fclose(f_Mercado);    
    
}
void Consulta_Menor_Preco(Mercado m[MAX],char nome[MAX_TAM],Lista_de_compras Lista_final,int n_linhas)//Compara os pree�os de um determinado produto para todos os mercados em que ele está disponível e adiciona-o a um lista com outros produtos prourados.
{
    Mercado aux;
    Lista_de_compras l;
    Bloco *rider;
    int cont_linhas=0;
    LVazia(&aux);

    while(cont_linhas<n_linhas)
    {
        
        rider=m[cont_linhas].first->prox;

        while(rider!=NULL)
        {
            if(strcmp(rider->p.nome_produto,nome)==0)
            {
                Insere_Produto(&l,rider->p.valor,m[cont_linhas].ID_mercado,rider->p.ID_produto,rider->p.nome_produto,m[cont_linhas].nome_mercado);
                break;
            }
            rider=rider->prox;
        }
        cont_linhas++;
    }

    Ordena_Crescente(&l,0,l.tamanho-1,0,0);

    Insere_Produto(&Lista_final,l.best->valor,l.best->ID_Market,l.best->ID_produto,l.best->nome_produto,l.best->Market);
}
void Gera_Guia(Lista_de_compras Lista_Final)//Gera um arquivo .txt com uma lista dos menores pre�oss por produto e qual o mercado em que pode ser encontrado.
{
    FILE *arquivo;
    char *get_string;
    arquivo=fopen("Lista de Compra.txt","w");

    int cont_produtos=0;
    while(cont_produtos<Lista_Final.tamanho)
    {  
        char gera_linha[MAX_TAM]="";
        char separador1[MAX_TAM]="\t[",separador2[MAX_TAM]="]";
        int cont_op=0;
        
        while(cont_op<3)
        {   
            
            strcat(gera_linha,separador1);
            if(cont_op==0)
            {   
                strcat(gera_linha,Lista_Final.best->nome_produto);
            }
            if(cont_op==1)
            {
                
                strcat(gera_linha,Lista_Final.best->Market);
            }
            if (cont_op==2)
            {	
            	
            }
            
            cont_op++;
        }
        strcat(gera_linha,"\n");
        fputs(gera_linha,arquivo);
        cont_produtos++;
    }

    fclose(arquivo);
}

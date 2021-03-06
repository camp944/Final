#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "func.h"
#include "base.h"
#include "lista.h"
#define MAX 100
#define MAX_TAM 260



void menu()
{
    printf("\n\n");
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("      @                                                 @\n");
    printf("      @                        MENU                     @\n");
    printf("      @          DIGITAR PRODUTOS DA LISTA -> 1         @\n");
    printf("      @         INSERIR ARQUIVO COM A LISTA -> 2        @\n");
    printf("      @    GERAR ARQUIVO COM OS MELHORES PRECOS -> 3    @\n");
    printf("      @               ENCERRA O PROGRAMA -> 0           @\n");
    printf("      @                                                 @\n");
    printf("      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
}
void Get_Desktop_Adress(char cwd[MAX_TAM],char adress[MAX_TAM])
{

    char *token;
    token=strtok(cwd,"\\");
    int ver=0;
    char Desktop[MAX_TAM]="Desktop",copia[MAX_TAM];

    while(token!=NULL)
    {
        
        strcpy(copia,token);
        strcat(adress,copia);
        strcat(adress,"\\");
        if(ver==1)
        {
            strcat(adress,"Desktop\\");
            break;            
        }
        if(strcmp(copia,"Users")==0)
        {
            ver=1;
        }

        token=strtok(NULL,"\\");
    }

}

int Recebe_Mercado(Mercado m[MAX],char arquivo_mercados[MAX_TAM],int cont_mercados)//Le o arquivo com o nome dos mercados e gera uma lista para cada mercado com seus produtos IDs e valores.
{
	
    char cwd[MAX_TAM];
	getcwd(cwd, sizeof(cwd));
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
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n");
        }
        else
        {
            printf("\n\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf( "      @                          @\n");
            printf( "      @  ARQUIVO NAO ENCONTRADO  @\n");
            printf( "      @                          @\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n\n");
            fflush(stdin);
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
        strcpy(abre_mercado,cwd);
        strcat(abre_mercado,"\\Mercados\\");
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
		
        strcat(abre_mercado,m[cont_mercados].nome_mercado);
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
    LImprime(i);
    fclose(f_Mercado);    
    
}
void Consulta_Menor_Preco(Mercado m[MAX],char nome[MAX_TAM],Lista_de_compras *Lista_final,int n_linhas)//Compara os pree???os de um determinado produto para todos os mercados em que ele est?? dispon??vel e adiciona-o a um lista com outros produtos prourados.
{
    Mercado aux;
    Lista_de_compras l;
    Bloco *rider;
    int cont_linhas=0;
    LVazia(&aux);
    Inicia_Compras(&l);
    
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

    

    if(l.tamanho==0)
    {
        printf("\n\tO produto %s nao foi encontrado!\n");
        return;
    }

    

    Ordena_Crescente(&l,0,l.tamanho-1,0,0);

    
    
    Insere_Produto(Lista_final,l.best->valor,l.best->ID_Market,l.best->ID_produto,l.best->nome_produto,l.best->Market);
    printf("\n\t[%s]\t[%s]\t[R$%.2f]\t[%d]\n",Lista_final->best[Lista_final->tamanho-1].nome_produto,Lista_final->best[Lista_final->tamanho-1].Market,Lista_final->best[Lista_final->tamanho-1].valor,Lista_final->tamanho);
}
void Abre_Lista_De_Compras(char nome_arquivo[MAX_TAM],Lista_de_compras *Lista_Final,Mercado m[MAX],int n_linhas)
{
    FILE *arquivo;
    char txt[MAX_TAM]=".txt",leitor[MAX_TAM],*token;
    arquivo=NULL;
    while(arquivo==NULL)
    {
        arquivo=fopen(nome_arquivo,"rt");
        
        if(arquivo!=NULL)
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
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf( "      @                              @\n");
            printf( "      @      ARQUIVO NAO ABERTO      @\n");
            printf( "      @                              @\n");
            printf( "      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
            printf("      INSIRA O VALIDO DO ARQUIVO COM OS PRODUTOS DA LISTA DE COMPRAS->");
			gets(nome_arquivo);
            strcat(nome_arquivo,txt);

        }
    }

    while(fgets(leitor,MAX_TAM,arquivo)!=NULL)
    {
        char Nome[MAX_TAM];
        int operador=0;
        token=strtok(leitor,"->");

        while(token!=NULL)
        {   
            strcpy(Nome,token);
			
            if(operador==0)
            {
                Consulta_Menor_Preco(m,Nome,Lista_Final,n_linhas);
                operador++;                
            }
            
            token=strtok(NULL,"->");
        }
        
        
    }

    fclose(arquivo);
}
void Gera_Guia(Lista_de_compras *l,int n_mercado,Mercado m[MAX])//Gera um arquivo .txt com uma lista dos menores precos por produto e qual o mercado em que pode ser encontrado.
{
    FILE *arquivo;
    char *get_string;
    int i=0;
    char cwd[MAX_TAM],adress[MAX_TAM]="";
	getcwd(cwd, sizeof(cwd));
    Get_Desktop_Adress(cwd,adress);
    strcat(adress,"Lista de Compras.txt");
    arquivo=fopen(adress,"w");

    Lista_de_compras Ranking_Mercados;
    Inicia_Compras(&Ranking_Mercados);
    
    
    while(i<n_mercado)
    {
        Insere_Produto(&Ranking_Mercados,0,0,0,"",m[i].nome_mercado);
        i++;
    }


    fputs("\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n",arquivo);
    fputs("\t @                                      @\n",arquivo);
    fputs("\t @     LISTA COM OS MELHORES PRE??OS     @\n",arquivo);
    fputs("\t @                                      @\n",arquivo);
    fputs("\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n",arquivo);
    fputs("   [Produto]\t\t[Mercado]\t\t[Pre??o]\n\n",arquivo);
    
    int cont_produtos=0;
    while(cont_produtos<l->tamanho)
    {  
        char gera_linha[MAX_TAM]="";
        char separador0[MAX_TAM]="   [",separador1[MAX_TAM]="\t\t[",separador2[MAX_TAM]="]";
        int cont_op=0;
        
        while(cont_op<3)
        {   
            
            if(cont_op==0)
            {   strcat(gera_linha,separador0);
                strcat(gera_linha,l->best[cont_produtos].nome_produto);
            }
            if(cont_op==1)
            {   
                strcat(gera_linha,separador1);
                strcat(gera_linha,l->best[cont_produtos].Market);
                i=0;
                
                while(i<n_mercado)
                {
                    if(strcmp(l->best[cont_produtos].Market,Ranking_Mercados.best[i].Market)==0)
                    {
                        Ranking_Mercados.best[i].valor=Ranking_Mercados.best[i].valor+1;
                        break;
                    }
                    i++;
                }
                
            }
            if (cont_op==2)
            {
                strcat(gera_linha,separador1);
                char convertido[MAX_TAM];
                strcat(gera_linha,"R$");
            	sprintf(convertido, "%.2f", l->best[cont_produtos].valor);
                strcat(gera_linha,convertido);
            }
            strcat(gera_linha,separador2);
            cont_op++;
        }
        strcat(gera_linha,"\n");
		fputs(gera_linha,arquivo);
        cont_produtos++;
    }
   
   
    
    Ordena_Crescente(&Ranking_Mercados,0,n_mercado-1,0,0);
    
    fputs("\n\n\n\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n",arquivo);
    fputs("\t @                                         @\n",arquivo);
    fputs("\t @     MERCADOS COM OS MELHORES PRE??OS     @\n",arquivo);
    fputs("\t @                                         @\n",arquivo);
    fputs("\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n",arquivo);
    fputs("\t[Mercado]\t\t  [Pontos/10]\n\n",arquivo);
    i=0;
    
    if(n_mercado<15)
    {
        while(i<n_mercado/3)
        {
            char convertido[MAX_TAM];
            sprintf(convertido,"\t[%s]\t\t  [%.1f]\n",Ranking_Mercados.best[cont_produtos-1-i].Market,Ranking_Mercados.best[cont_produtos-1-i].valor/l->tamanho*10);
            fputs(convertido,arquivo);
            i++;
        }
    }
    else
    {
        if(n_mercado<40)
        {
            while(i<n_mercado/4)
            {
                char convertido[MAX_TAM];
                sprintf(convertido,"\t[%s]\t\t  [%.1f]\n",Ranking_Mercados.best[cont_produtos-1-i].Market,Ranking_Mercados.best[cont_produtos-1-i].valor/l->tamanho*10);
                fputs(convertido,arquivo);
                i++;
            }
        }
        else
        {
            while(i<10)
            {
                char convertido[MAX_TAM];
                sprintf(convertido,"\t[%s]\t\t  [%.1f]\n",Ranking_Mercados.best[cont_produtos-1-i].Market,Ranking_Mercados.best[cont_produtos-1-i].valor/l->tamanho*10);
                fputs(convertido,arquivo);
                i++;
            }
        }

    }
  
    fclose(arquivo);
}

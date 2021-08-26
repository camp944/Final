#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#define MAX_TAM 260



void LVazia(Mercado *m)
{
    m->first=(Bloco*)malloc(sizeof(Bloco));
    m->last=m->first;
    m->first->prox=NULL;
}
void LInserir(Mercado *m,int ID,char Nome[MAX_TAM],float Valor)
{
	
    m->last->prox=(Bloco*)malloc(sizeof(Bloco));
	m->last=m->last->prox;
	m->last->p.ID_produto=ID; 
	strcpy(m->last->p.nome_produto,Nome);
    m->last->p.valor=Valor;
	m->last->prox=NULL;

	


}
void LRemove(Mercado *m,int ID)
{
	
    Bloco *aux, *tmp;

	if(m->first == m->last || m == NULL || m->first->prox == NULL){
		printf("LISTA VAZIA!\n");
		return;
	}
	
	aux = m->first;
	while(aux->prox != NULL){
		if (aux->prox->p.ID_produto != ID)
			aux = aux->prox;
		else{
			tmp = aux;
			aux = aux->prox;
			tmp->prox = aux->prox;
			free(aux);
			aux = NULL;
		}
	}
}
void LImprime(Mercado *m)
{
	
    int cont=0;
	Bloco *aux;
	aux=m->first->prox;
	
	printf("\n\n");
	while(aux!=NULL)
	{
		
		//cout << "     " << aux->p.ID_produto << "    " << aux->p.nome_produto << "    " << aux->p.valor << endl;
		printf("\t%d\t%s\t%.2f\n",aux->p.ID_produto,aux->p.nome_produto,aux->p.valor);
		aux=aux->prox;
		
		
		
	}
	printf("\n\n");
}


void Inicia_Compras(Lista_de_compras *l)
{
    l->best=(Produto_Custo*)malloc(MAX_TAM*sizeof(Produto_Custo));
    l->tamanho=0;
}
void Troca(Produto_Custo *a, Produto_Custo *b)
{
	Produto_Custo aux = *a;
	*a = *b;
	*b = aux;
}
void Particao(Lista_de_compras *l, int p, int r, int *i, int *j)
{
    Produto_Custo pivo;
	int idx = (p+r)/2;
	*i = p;
	*j = r;
	pivo = l->best[idx];

	while(*i<=*j){
		while(l->best[*i].valor  < pivo.valor && *i < r)
			*i = *i + 1;
		while(l->best[*j].valor > pivo.valor && *j > p)
			*j = *j - 1;
		if(*i<=*j){
			Troca(&l->best[*i], &l->best[*j]);
			*i = *i + 1;
			*j = *j - 1;
		
		}

	}
	
	
}
void Ordena_Crescente(Lista_de_compras *l, int i, int j, int auxi, int auxj)
{
	
    Particao(l, i,j,&auxi,&auxj);
	
	if(auxj > i)
	{
		Ordena_Crescente(l,i,auxj,auxi,auxj);
	}
		
	if(auxi < j)
	{
		Ordena_Crescente(l,auxi,j, auxi, auxj);
	}
    
}
void Insere_Produto(Lista_de_compras *l, float valor, int ID_Market, int ID_Produto, char Nome_Produto[MAX_TAM], char Nome_Market[MAX_TAM])
{
    l->best[l->tamanho].ID_Market=ID_Market;
	l->best[l->tamanho].ID_produto=ID_Produto;
	strcpy(l->best[l->tamanho].nome_produto,Nome_Produto);
	strcpy(l->best[l->tamanho].Market,Nome_Market);
	l->best[l->tamanho].valor=valor;
    l->tamanho++;
}
void Imprime_LCompras(Lista_de_compras *l)
{
	int cont_produtos=0;
    while(cont_produtos<l->tamanho)
    {  
        char gera_linha[MAX_TAM]="";
        char separador1[MAX_TAM]="\t[",separador2[MAX_TAM]="]";
        int cont_op=0;
        
        while(cont_op<3)
        {   
            
            strcat(gera_linha,separador1);
            if(cont_op==0)
            {   
                strcat(gera_linha,l->best[cont_produtos].nome_produto);
            }
            if(cont_op==1)
            {
                strcat(gera_linha,l->best[cont_produtos].Market);
            }
            if (cont_op==2)
            {	
                char convertido[MAX_TAM];
                strcat(gera_linha,"R$");
            	sprintf(convertido, "%.2f", l->best[cont_produtos].valor);
                strcat(gera_linha,convertido);
            }
            strcat(gera_linha,separador2);
            cont_op++;
        }
        strcat(gera_linha,"\n");
		printf("%s",gera_linha);
        cont_produtos++;
    }
}

//FALTA IMPRIMIR A LISTA

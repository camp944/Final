#include "base.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>
#define MAX_TAM 100



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
	
	while(aux!=NULL)
	{
		
		//cout << "     " << aux->p.ID_produto << "    " << aux->p.nome_produto << "    " << aux->p.valor << endl;
		printf("\t%d\t%s\t%.2f\n",aux->p.ID_produto,aux->p.nome_produto,aux->p.valor);
		aux=aux->prox;
		
		
		
	}
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
void Particao(Lista_de_compras *l, int i, int j, int *auxi, int *auxj)
{
    Produto_Custo pivo;
	int idx = (i+j)/2;
	*auxi = i;
	*auxj = j;
	pivo = l->best[idx];

    while(*auxi<=*auxj)
    {
        while(l->best[*auxi].valor<pivo.valor && *auxi < j)
		{
			*auxi++;
		}
		while(l->best[*auxj].valor > pivo.valor && *auxj > i)
		{
			*auxj--;
		}
		if(*auxi<=*auxj){
			Troca(&l->best[*auxi], &l->best[*auxj]);
			*auxi++;
			*auxj--;
		
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

//PARECE

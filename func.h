#ifndef FUNC_H_
#define FUNC_H_
#include "lista.h"
#include "base.h"
#define MAX 10
#define MAX_TAM 100


void menu();

int Recebe_Mercado(Mercado m[MAX],char arquivo_mercados[MAX_TAM],int cont_mercados);//PRONTO
void Recebe_Produto(Mercado *i,char nome_Mercado[MAX_TAM]);//PRONTO
void Consulta_Menor_Preco(Mercado m[MAX],char nome[MAX_TAM],Lista_de_compras Lista_final,int n_linhas);//PRONTO APARENTEMENTE
void Abre_Lista_De_Compras(char nome_arquivo[MAX_TAM],Lista_de_compras Lista_Final,Mercado m[MAX],int n_linhas);
void Gera_Guia(Lista_de_compras Lista_Final);//CRIAR UMA FORMA DE INSERIR O VALOR DO PRODUTO NO ARQUIVO


#endif

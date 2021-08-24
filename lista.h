#ifndef LISTA_H_
#define LISTA_H_
#include "base.h"
#define MAX_TAM 100



void LVazia(Mercado *m);
void LInserir(Mercado *m,int ID,char Nome[MAX_TAM],float Valor);
void LRemove(Mercado *m,int ID);
void LImprime(Mercado *m);

void Inicia_Compras(Lista_de_compras *l);
void Troca(Produto_Custo *a, Produto_Custo *b);
void Particao(Lista_de_compras *l, int i, int j, int *auxi, int *auxj);
void Ordena_Crescente(Lista_de_compras *l, int i, int j, int auxi, int auxj);
void Insere_Produto(Lista_de_compras *l, float valor, int ID_Market, int ID_Produto, char Nome_Produto[MAX_TAM], char Nome_Market[MAX_TAM]);
void Imprime_LCompras(Lista_de_compras *l);

//ESTA TUDO PRONTO AQUI

#endif

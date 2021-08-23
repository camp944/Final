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
	int n_Mercados=0,i;
	char arquivo_mercados[MAX_TAM];
	gets(arquivo_mercados);

	n_Mercados=Recebe_Mercado(m,arquivo_mercados,n_Mercados); 
	
	
	

	return 0;
}

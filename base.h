#ifndef BASE_H
#define BASE_H
#define MAX_TAM 100

typedef struct Produto_Custo Produto_Custo;
typedef struct Lista_de_compras Lista_de_compras;
typedef struct Bloco Bloco;
typedef struct Mercado Mercado;
typedef struct Produto Produto;

struct Produto{
	char nome_produto[MAX_TAM];
    int ID_produto;
    float valor;
};

struct Bloco{
	Produto p;
    Bloco *prox;
	
};

struct Produto_Custo{
	
	char nome_produto[MAX_TAM],Market[MAX_TAM];
    int ID_produto,ID_Market;
    float valor;
};

struct Mercado{
	
	Bloco *first;
    Bloco *last;
    char nome_mercado[MAX_TAM];
    int ID_mercado;
	
};



struct Lista_de_compras{
	Produto_Custo *best;
    int tamanho;
};



#endif

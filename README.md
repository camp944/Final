:construction: EM CONSTRUÇÃO :construction: 






<h1 align="center">
 Trabalho AEDS|CEFET 
</h1>

<h4 align="center">	
  Esse projeto é uma aplicação que seleciona a partir dos dados dos produtos dos mercados (varejos em geral) cadastrados os melhores preços escolhidos pelo usuário, imprimindo e criando um arquivo .txt dos resultados obtidos 
</h4>
<h1></h1>

<!--ts-->
* [Sobre](#Sobre)

* [Como funciona](#rockey-Como-funciona)

* [Pré requisitos](#computer-Pré-requisitos)

* [Execução dos testes | Descrição do Programa](#gear-Execução-dos-testes)    
	
	* [Abertura dos arquivos](#Abertura-da-pasta-dos-arquivos)

	* [Menu](#Menu) 
 
* [Custo computacional](#wrench-Custo-computacional)
 
	* [Leitura inicial dos arquivos](#Leitura-inicial-dos-arquivos-txt-cadastrados)

	* [Opção 1](#Opção-1)
	
	* [Opção 2](#Opção-2)
 <!--te-->  


## Sobre 

  Nos dias atuais a necessidade de otimização do tempo tem sido primordial devido a rotina cada vez mais acelerada. Devido à essa falta de tempo, muitas das vezes, as pessoas não têm a possibilidade de comparar preços, deixando de economizar um dinheiro que parece pouco em um primeiro momento, mas que ao longo do tempo poderá fazer falta.
Portanto, avaliando essa necessidade, surge a proposta de um sistema que permite a partir dos interesses de compra do usuário, a busca dos produtos de melhores preço, ecomizando tanto o tempo quanto o dinheiro desse usuário. Diante desse fato, e seguindo alguns sistemas já criado como presente nos sites [Zoom](https://www.zoom.com.br) e [Buscapé](https://www.buscape.com.br) nossa aplicação tem como objetivo buscar essa facilitação para esse usuário.<p>

 - Desafios a serem cumpridos:
 
 :white_check_mark: Lista dinâmica 
 
 :white_check_mark: Lista estática
 
 :white_check_mark: Ordenação: QuickShort 


## :rocket: Como funciona

<p> Na pasta Mercados criasse arquivos .txt para cada mercado, tendo como o nome o proprio nome do mercado. Dentro desses arquivos estão os dados dos diferentes tipos de produtos cadastrados contendo o identificador, nome e preço do mesmo. Ao iniciar o programa o usuário insere um arquivo contendo as informações de todos esses mercados presente nessa pasta, no qual a partir da escolha do usuário o programa irá fazer uma busca e encontrar dentre esse mercados o produto com o menor preço e apresenta-lo a partir de um arquivo criado<p>


## :computer: Pré-requisitos

<p>[Informar modo de execução] <p>

## :gear: Execução dos testes
<p>Execução do programa a partir do arquivo 'teste' presente no repositório<p>

![insira](https://user-images.githubusercontent.com/78819692/131023845-99c5d825-d755-445f-aaaf-d6f2bd08b7f5.png)

<p>Após a abertura do arquivo .txt no qual contém os ID's e nomes dos mercados cadastrados, o programa realiza a tokenização dos nomes de cada mercado presente, (no qual contém um arquivo .txt para cada um com os dados dos produto) e faz o encaminhamento para a pasta Mercados e realiza a leitura desses arquivos.<p>

	
### Abertura da pasta dos arquivos
	
```sh
    char cwd[MAX_TAM];
	getcwd(cwd, sizeof(cwd));
```
- Usando a função getcwd pertencente a biblioteca <unistd.h>, pegamos o caminho do diretório no qual encontra a pasta do projeto e armazenamos na variavel cwd. 
	
```sh
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
```  
- Dentro do primeiro While iremos ler todo conteúdo do arquivo inserido (teste), no qual foi utilizado na tokenização o separador <strong>-></strong>.
- A variável "abre_mercado" recebe cwd e é adicionado "\\\Mercaodos\\\" no final dessa string, tendo assim salva o endereço dentro da pasta Mercados.
- O segundo While varre linha por linha do arquivo, sendo sempre o primeiro token o ID e o segundo token o nome do mercado, adicionando ambos em uma lista estática.
- Ao final do primeiro While, é adicionado a variável em que contém o endereço da pasta Mercados (abre_mercado) o nome do mercado e o .txt, tendo assim o endereço do arquivo .txt dos dados mercado de cada um, sendo o nome desses arquivos o proprio nome do mercado.
- Chamamos a função Recebe_Produto para todo nome de mercado recebido, no qual é usado na tokenização o mesmo separador <strong>-></strong>, tendo a ordem a cada linha percorrida o ID, nome do produto e o preço.
##### Modelo arquivo mercado :
![mercado](https://user-images.githubusercontent.com/78819692/131039101-6015c913-34d5-4353-8431-84b1d131f9e9.png)


	
### Menu 

![Menu](https://user-images.githubusercontent.com/78819692/131042136-760cca43-21f5-4084-a0d6-8f1ee5d4e029.png)

:point_right: Opção 1:
	
<p>O usuário insere produto por produto, no qual será avaliado o de melhor preço entre os mercados cadastrados e adicionado em sua lista de compras (Lista dinâmica)<p>
	
- Procura pelo melhor preço:
<p>A função Consulta_Menor_Preco é realizada usando o método <strong>QuickShort</strong>, no qual sempre após encontrando o produto de menor custo entre os mercados cadastrados, adiciona na lista de compras no fim do método<p>
	
:point_right: Opção 2:
	
<p>O usuário entra com o arquivo .txt com os nomes dos produtos escolhidos para a seleção de melhor preço <p>
	
![op2](https://user-images.githubusercontent.com/78819692/131122060-23e9a0e6-e378-4dc0-8fb9-a1094c3d9b5a.png)
	
#### Exemplo Lista 
	
![listacompra](https://user-images.githubusercontent.com/78819692/131122233-194ddf01-169f-4094-847a-0ac6f75f861b.png)
	
<p>É utilizado no final de cada item da lista o separador ->, no qual servirá de auxilio na execução da tokenização desse arquivo<p>
	
:point_right: Opção 3:
	
<p>Após inserir os produtos escolhidos, seja usando a opção 1 ou a opção 2, é criado um arquivo .txt (Lista de Compras.txt) na área de trabalho contendo em qual mercado cada produto se encontra com o menor preço e o ranking dos mercados melhor avaliado de acordo com o preço dos itens selecionados.<p>
	
- Exemplo da Lista de Compras gerado a partir da Lista inserida na opção 2:
	

<img src="https://user-images.githubusercontent.com/78819692/131125390-f90bbe4a-5bf2-4c56-b9f4-7cdd84f7dbe9.png" width="400">
	
## :wrench: Custo computacional
	
#### Leitura inicial dos arquivos .txt cadastrados
	
> :exclamation: Trecho de código pertencente a função `Recebe_Mercado`:	

```sh
 while((fgets(leitor,MAX_TAM,f_Mercados)!=NULL))
	{
	char abre_mercado[MAX_TAM]; //+1
        strcpy(abre_mercado,cwd); //+1
        strcat(abre_mercado,"\\Mercados\\"); //+1
	token=strtok(leitor,"->"); //+1
	
        while(token!=NULL) 
        {        
            char copia[MAX_TAM];   
            strcpy(copia,token);   //+2 todo loop
	 	
            if(opera==0)   
            { 
            	int ID;                
            	ID=atoi(copia);  
                m[cont_mercados].ID_mercado=ID;  
                opera++;  // Custo IF = +5 (Comparação,Declaração,3 ações variaveis) 
            }else
            {   
                if(opera==1)
                {
                	strcpy(m[cont_mercados].nome_mercado,token);
                	opera++; // Custo IF = +4 (Compação 1 If, Comparação 2 If, strcpy, soma)
				}
				else
				{
					opera=0;
					break;  //Custo Else +4 (Compação 1 If, Comparação 2 If, ação variavel, break) 
				}
            }
            token=strtok(NULL,"->");
        }
		
        strcat(abre_mercado,m[cont_mercados].nome_mercado);  //+1
        strcat(abre_mercado,txt);  //+1
        Recebe_Produto(&m[cont_mercados],abre_mercado);  //+27
	cont_mercados++;  //+1	
	}
```
	
- Dentro da função Recebe_Mercado iremos fazer a leitura inicial dos mercados cadastrados. Analisando o trecho de maior custo dentro dessa função, na qual esta em função de N (números de mercados cadastrados) temos no primeiro While N loops a serem processados.Em um primeiro momento, ignorando o segundo While, temos como custo computacional de 7 + 27P nesse primeiro While ( 7 com ações simples de custo singular e 27P da função `Recebe_Produto`, função essa a ser demostrada) Sendo igual a 7 + 27P.

- No segundo While, teremos 3 tokens por mercado cadastrado (ID,nome,"quebra-linha) ou seja, 3N. Calculando as 3 entradas nesse while, vemos que na primeira entrada (Condição do primeiro IF) teremos o custo de +7, na segunda entrada ( Condição do 2 IF) o custo de +6 e na ultima entrada o custo de +6 somando assim um total de 19 de custo, que somado com +3 do strtok a cada loop. Portanto a cada mercado cadastrado teremos 22 de custo nesse While, que é igual a 22 <p>
	
- Portanto, somando esses custos, temos o custo para a leitura inicial desses arquivos de  (22 + 7) N * 27P = <strong>29N * 27P</strong>
		
   

> :exclamation: Trecho de código pertencente a função `Recebe_Produto` :
	
```sh
while(fgets(leitor,MAX_TAM,f_Mercado)!=NULL) // Le P vezes ( P = qtidade de produtos em cada mercado)
    {
        int ID; 
        float Valor;
        char Nome[MAX_TAM];
        token=strtok(leitor,"->");//+4
       
        while(token!=NULL) // ENTRA 3 tokens a cada produto (ID, nome, preço)
        {   
            strcpy(copia,token); 			
            if(operador==0) 
            {             
                ID=atoi(copia);
                operador++;
            } //CUSTO PRA CHEGAR NESSE IF = +4 (strcpy, comparação, 2 açoes variavel)
            else
            {
                if (operador==1)
                {
                    strcpy(Nome,token);                  
                    operador++;
                }//CUSTO PRA CHEGAR NESSE IF = +5 (strcpy, comparação 1 If,comparação 2 if,strcpy,soma)
                else
                {
                    Valor=atof(copia);
                    operador=0;
                }//CUSTO PRA CHEGAR NESSE ELSE = +5 (strcpy, comparação 1 If,comparação 2 if,2 ações variavel)

            }
            token=strtok(NULL,"->"); //+1 a cada loop
        }
        LInserir(i,ID,Nome,Valor);  //+6     
	}
```
	
- Dentro da função Recebe_Produto iremos fazer a leitura dos arquivos de cada mercado cadastrado. Isolando o trecho de maior impacto no custo computacional, trecho esse que é  em função de P (sendo P o número de produtos cadastrado nesse mercado) temos o seguintes valores: No primeiro While iremos percorrer todo esse arquivo, no qual, isolando o segundo While interno a esse em um primeiro momento, temos o custo computacional de 10 ( 4 de ações singulares e 6 da função `LInserir`, função responsavel por adicionar os dados de cada produto na lista dinâmica de cada mercado).
- Analisando o segundo While, temos que a cada produto cadastrado sera realizado 3 loops ( 3 loops pois entrará 3 tokens válidos -ID,nome e preço-). No primeiro loop( Condição válida do primeiro IF) teremos o custo de +5, no segundo loop (condição válida do segundo IF) teremos o custo de +6 e por último o else, tendo o custo de +6. Sendo assim, somamdo
todos esses loops que irá acontecer a cada produto cadastrado, teremos o custo de 17.
- Portanto, somando esses custos, temos o custo para a leitura dos arquivos separado de cada mercado de (17+10)*P = <strong>27P</strong>
	
> :warning: A variável P foi usada em todos os mercados para facilitação matemática, cada mercado não necessariamente precisa ter a mesma quantidade de produtos.
	
<h1></h1>
	
#### Opção 1
	
 Ao escolher a opção 1_(DIGITAR PRODUTOS DA LISTA) a função chamada Consulta_Menor_Preco possui dois trechos de código no qual define seu custo computacional. O primeiro trecho refere-se a estrutura While no qual irá procurar em cada mercado o produto selecionado e adiciona-lo a uma lista estática.

> :exclamation: Trecho de código pertencente a função `Consulta_Menor_Preco` :
	
```sh
	
   while(cont_linhas<n_linhas) //Entrará N vezes, N = número de mercados
    {
        rider=m[cont_linhas].first->prox;  //+1
        while(rider!=NULL)  //Irá percorrer todo a lista de produtos do mercado até encontrar 
        {
            if(strcmp(rider->p.nome_produto,nome)==0) //+1
            {                
                Insere_Produto(&l,rider->p.valor,m[cont_linhas].ID_mercado,rider->p.ID_produto,rider->p.nome_produto,m[cont_linhas].nome_mercado); //6
                break;
            }
            rider=rider->prox;  //+1
        }
        cont_linhas++; //+1
    }
```
	
- No primeiro While irá percorrer N vezes, sendo N o número de mercados cadastrados. Ignorando o segundo While (interno a esse), temos que a cada loop dessa primeiro While teremos o custo de +2 a cada loop.
- Já no segundo While (interno) irá percorrer por todos produtos cadastrados ate encontrar o produto selecionado pelo usuário. <strong> Para fins de facilitação matemática iremos considerar a variável P para a quantidade de produtos em todos os mercados e que encontraremos esse produto sempre no meio dessa lista, ou seja, P/2 </strong>. Sendo assim, esse While irá percorrer P/2 vezes e, a cada loop, irá realizar +2 de custo e, uma vez o IF sendo validado, +6 de custo referente a função `Insere_Produto`.
- Portanto, o custo geral desse While será de N(2+2P/2+6) = 2N + PN + 6N = <strong>8N + PN</strong>.

\
A segunda parte do trecho dentro da função  Consulta_Menor_Preco é logo após o While comentado, em que assim que adicionado dentro da lista as informações do produto (ID,nome,preço) de cada mercado no qual ele se encontra, é chamado a função `Ordena_Crescente`, em que utilizará do modelo de ordenação <strong>QuickShort</strong> para ordenar o produto em ordem de preço crescente dentro dessa lista 
	

 `Ordena_Crescente`:  Utilizando da literatura, sabendo que essa função utiliza-se do método de ordenação <strong>QuickShort</strong>, temos como caso médio <img src="https://user-images.githubusercontent.com/78819692/131732133-5f09ebb2-607b-4059-a8f0-746f6ac8501f.png" width="70"> matematicamente provada como demostrado no site [khanacademy](https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/analysis-of-quicksort). Como N na equação significa a quantidade de elementos dentro dessa lista a ser ordenada e, considerando que cada mercado tem um produto do qual o usuário escolheu, podemos substituir essa variável N como sendo a quantidade de mercados cadastrados.
	
- Juntando esses valores, teremos como custo na opção 1 o custo de <img src="https://user-images.githubusercontent.com/78819692/131744845-d20c8f7e-b214-4b67-88be-9096086eaa10.png" width="100"> , sendo:
	
	> N o número de mercados cadastrados;
	
	> P a quantidade de produtos cadastrados em cada mercado;
	
	> K a quantidade de produtos escolhidos pelo usuário.
	
	
<h1></h1>
	
	
#### Opção 2
	
Na opção 2_(INSERIR ARQUIVO COM A LISTA) se difere da opção 1 pois os produtos a serem inseridos pelo usuário será por meio de um arquivo informando os produtos. Portanto, será feito uma tokenização desse arquivo para que assim chamar a função `Consulta_Menor_Preco` estudada na opção 1.
	
> :exclamation: Trecho de código pertencente a função `Abre_Lista_De_Compras` :
	
```sh
 while(fgets(leitor,MAX_TAM,arquivo)!=NULL)  //3
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
```
	
- No trecho de maior custo da função, o While irá ser responsável pela tokenização da lista de compras (usando o serapador <strong>-></strong>) e a partir disso chamar a função Consulta_Menor_Preco para cada produto. No While mais interno, a cada produto na lista ele entrará 2 vezes, no qual a cada vez realizado o loop o custo será de +4 + o custo da função Consulta_Menor_Preço.

- Portanto, o custo dessa função será similar ao da opção 2, contendo o acréscimo no custo computacional referente a essa tokenização  <img src="https://user-images.githubusercontent.com/78819692/132346310-54da7b5a-8b3e-4cf5-b018-34597389d542.png" width="100"> , sendo:
	
	> N o número de mercados cadastrados;
	
	> P a quantidade de produtos cadastrados em cada mercado;
	
	> K a quantidade de produtos escolhidos pelo usuário.

	
<h1></h1>
	

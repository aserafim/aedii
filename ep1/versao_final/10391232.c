/***************************************************
* DISCIPLINA: ALGORITMOS E ESTRUTURAS DE DADOS II
* PROFESSOR: HELTON HIDERALDO BISCARO		
* EP1 - ALGORITMO DE PRIM
* ALEFE SERAFIM - NUSP: 10391232*/
/**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXARQ 350 				//tamanho maximo de entradas para o vetor que armazena o grafo
#define AN -1
#define VERTICE_INVALIDO -1
#define TipoPeso int


//VARIAVEIS GLOBAIS
FILE *grafo, *saida;				//ponteiro para o arquivo grafo a ser lido e para a saida
int custo[MAXARQ], ant[MAXARQ];
int vetorGrafo[MAXARQ];				//vetores do grafo e da arvore final
int ch1 = 0, ch2 =0 , ch3 = 0;			//variavel de apoio para leitura dos caracteres do arquivo grafo
int tamanhoVetor;

//Estrutura que armazena o grafo
typedef struct{
	TipoPeso mat[MAXARQ + 1][MAXARQ + 1];
	int numVertices;
	int numArestas;
}TipoGrafo;


//Funcao para inicialiar o grafo
bool inicializaGrafo(TipoGrafo * grafo){
	int i,j;
	int nv = vetorGrafo[0], na = vetorGrafo[1];
	grafo -> numVertices = nv;
	grafo -> numArestas = na;
	for (i = 0; i < grafo -> numVertices; i++){
		for(j = 0; j < grafo -> numVertices ; j++) grafo -> mat[i][j] = 0;
	}
}


//Funcao para imprimir a matriz de adjacencia
void imprimeMatriz(TipoGrafo *grafo){
    int i, j;
    for(i = 0; i < grafo->numVertices; i++){
        for(j = 0; j < grafo->numVertices; j++){
            printf("%d\t", grafo->mat[i][j]);
        }
        printf("\n");
    }
}


//Funcao para inserir as arestas
bool insereAresta(TipoGrafo *grafo){
	int i = 2;
    	while(i <= tamanhoVetor){
		int v1 = vetorGrafo[i];
		int v2 = vetorGrafo[i + 1];
		int peso = vetorGrafo[i + 2];
		i = i + 3;
		grafo -> mat[v1][v2] = peso;
		grafo -> mat[v2][v1] = peso;
	}
	return true;
} 

//Funcao principal
int main(int argc, char *argv[]){
	
	int i = 2, j = 0, custoTotal, menorAnt;					//variaveis de iteracao
	TipoGrafo grafoIni, AGM;			//grafo inicial
	int vetorArestasFinal[MAXARQ];
	grafo = fopen(argv[1], "r");
	
	//Lendo o arquivo e armazendo no vetor
	grafo = fopen(argv[1], "r");
	fscanf(grafo, "%d %d", &ch1, &ch2);
	vetorGrafo[0] = ch1;
	vetorGrafo[1] = ch2;

	while(!feof(grafo)){
		fscanf(grafo, "\n%d %d %d\n", &ch1, &ch2, &ch3);
		vetorGrafo[i] = ch1;
		i++;
		vetorGrafo[i] = ch2;
		i++;
		vetorGrafo[i] = ch3;
		i++;
	}
	
	//Seta o tamanho do vetorGrafo e fecha o arquivo
	//tamanhoVetor = i - 1;
	tamanhoVetor = i;
	fclose(grafo);
	
		
	//Inicializando os grafos e inserindo as devidas arestas
	inicializaGrafo(&AGM);
	inicializaGrafo(&grafoIni);
	insereAresta(&grafoIni);
//	imprimeMatriz(&grafoIni);
	saida = fopen(argv[2], "w+");
	fprintf(saida, "%d\n\n", 0);

	//-----------------------------------------------//	
	//Testando PRIM

	//Declarando vetor S para controle dos vertices inseridos
	//na AGM
	int qtdVert = vetorGrafo[0];
	int s[qtdVert];
	int menor = 10000;

	//Setando ant e custo
	for(i = 0; i < grafoIni.numVertices; i++){
		custo[i] = 10000;
		ant[i] = -1;
		s[i] = 0;
	}
	custo[0] = 0;
	
//	printf("%d\n", grafoIni.numVertices);

	/*for( i = 0; i < qtdVert ; i++)
	{
		//vertice selecionado
		if(s[i]== 0){

		}
	}*/
	s[0]=1; 
	//Laco que implementa PRIM
	for(i = 0; i < grafoIni.numVertices; i++){
		for(j = 0; j < grafoIni.numVertices; j++){
			if (s[i] == 1){
				if(grafoIni.mat[i][j] > 0 && grafoIni.mat[i][j] <= custo[j]){
					//menor = custo[j];
					ant[j] = i;
					//printf("ant[%d]=%d", j, i);
					custo[j] = grafoIni.mat[i][j];
					//printf("\tcusto[%d]=%d\n", j, grafoIni.mat[i][j]);
					AGM.mat[i][j] = grafoIni.mat[i][j];
				}
			}else {
				if(grafoIni.mat[i][j] > 0){
					//menor = custo[j];
					ant[j] = i;
					//printf("ant[%d]=%d", j, i);
					custo[j] = grafoIni.mat[i][j];
					//printf("\tcusto[%d]=%d\n", j, grafoIni.mat[i][j]);
					AGM.mat[i][j] = grafoIni.mat[i][j];
					//s[i]=1;
				}
			}
		}

		//Variaveis locais para controle
		int indice;

		for(int k = 0; k < grafoIni.numVertices; k++)
		{
			if(s[k] == 0 && custo[k] <= menor){
				menor = custo[k];
				indice = k;
	//			printf("INDICE:%d\n ",indice);
			}
			menorAnt = custo[indice];
	//		printf("%d\n", menorAnt);
		}
		custoTotal = custoTotal + menorAnt;
		
		s[indice] = 1;
	//	printf("Aresta: (%d , %d)\t menor=%d \t menorAnt: %d\n", ant[indice], indice,menor, menorAnt);
		menor = 10000;
		fprintf(saida, "%d %d\n", ant[indice], indice,menor);
	//	printf("\nCusto: \t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", custo[0],custo[1],custo[2],custo[3],custo[4],custo[5],custo[6]);
	//	printf("Ant : \t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",ant[0],ant[1],ant[2],ant[3],ant[4],ant[5],ant[6]);
	//	printf("S: \t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", s[0],s[1],s[2],s[3],s[4],s[5],s[6]);
	//	printf("\n\n");
	}

//		printf("CUSTO TOTAL: %d", custoTotal);

	
	//Testando impreessão da arvore
	//fclose(saida);
	fseek(saida, 0, SEEK_SET);
	fprintf(saida,"%d", custoTotal);
	fclose(saida);
	
	/*
	//Imprimindo vetor de custo e ant para testar
	printf("\n");
	for(i = 0; i < grafoIni.numVertices; i++){
		printf("%d\t", ant[i]);
	}
	printf("\n");
	for(i = 0; i < grafoIni.numVertices; i++){
		printf("%d\t", custo[i]);
	}*/
	//printf("%d", soma);
	
//	printf("\n\n\n");
	
//	imprimeMatriz(&AGM);
	//----------------------------------------------//
	/*
	//Abrindo arquivo de saida
	saida = fopen(argv[2], "wr");
	
	//Testando entrada e saida - APAGAR!!!
	while(j != tamanhoVetor){

		fprintf(saida, "%d\n",vetorGrafo[j]);
		j++;
	}
	fclose(saida);
	*/
	return 0;
}

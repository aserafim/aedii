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
int vetorGrafo[MAXARQ], vetorArvore[MAXARQ];	//vetores do grafo e da arvore final
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
	
	int i = 2, j = 0;					//variaveis de iteracao
	TipoGrafo grafoIni, arvoreGeradora;			//grafo inicial

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
	
		
	//Testando funcoes da struct
	inicializaGrafo(&grafoIni);
	insereAresta(&grafoIni);
	imprimeMatriz(&grafoIni);

	//-----------------------------------------------//	
	//Testando PRIM

	//Setando ant e custo
	for(i = 0; i < grafoIni.numVertices; i++){
		custo[i] = 10000;
		ant[i] = -1;
	}
	custo[0] = 0;
	
	printf("%d\n", grafoIni.numVertices);
		
	//Laco que implementa PRIM
	for(i = 0; i < grafoIni.numVertices; i++){
		for(j = 0; j < grafoIni.numVertices; j++){
			if(grafoIni.mat[i][j] > 0 && grafoIni.mat[i][j] <= custo[j]){
				ant[j] = i;
				custo[j] = grafoIni.mat[i][j];
			}
		}


//		int k = 0;
//		for(k = 0; k < grafoIni.numVertices; k++) printf("%d\t", custo[k]);
//		printf("\n");
	}
	
	//Testando impreessão da arvore
	saida = fopen(argv[2], "wr");
	fprintf(saida, "%d ", grafoIni.numVertices);
	fprintf(saida, "%d\n", grafoIni.numVertices - 1);

	fclose(saida);

	//Imprimindo vetor de custo e ant para testar
	printf("\n");
	for(i = 0; i < grafoIni.numVertices; i++){
		printf("%d\t", ant[i]);
	}
	printf("\n");
	for(i = 0; i < grafoIni.numVertices; i++){
		printf("%d\t", custo[i]);
	}
	printf("\n");

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

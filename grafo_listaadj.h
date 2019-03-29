#define MAXNUMVERTICES 100 /* Sintaxe para definicao de valores fixos / variaveis estaticas */
#define AN -1 /* int used to represent the  */
#define VERTICE_INVALIDO -1 /* invalid node number */
#include<stdio.h>
#include <stdbool.h> /* Its a default library used to handle boolean variables */

FILE *stderr;

typedef int TipoPeso; /* Sintaxe para definição de tipos de variaveis */

typedef struct taresta{
	int vdest;
	TipoPeso peso;
	struct taresta *prox;
}TipoAresta;

//TipoApontador é um ponteiro para TipoAresta
typedef TipoAresta* TipoApontador;

typedef struct{
	TipoApontador *listaAdj;
	int numVertices;
	int numArestas;
}TipoGrafo;

//Initializing a Graph
bool inicializaGrafo(TipoGrafo * grafo, int nv){
	
	int i;

	grafo -> numVertices = nv;
	grafo -> numArestas = 0;
	//Observe que a alocacao de memoria
	//cria automaticamente um vetor
	//de dimensao nv
	grafo -> listaAdj = malloc (nv * sizeof(TipoApontador));
	
	//O vetor alocado pode ser acessado a partir 
	//de um for
	//Sao criados nv + 1 vertices
	//e os vertices do grafo sao contados
	//a partir do vertice de indice 1
        
        //Observe que mesmo apos a alocacao do vetor
        //e necessario inicializar cada um dos ponteiros
        //uma vez que apos a alocacao, o espaco de memoria
        //esta reservado, porem nao possui valor
	for (i = 0; i <= nv; i++){

		grafo -> listaAdj[i] = malloc (sizeof(TipoApontador));

	}	
}

//Verifica a existencia de uma aresta

bool existeAresta(int v1, int v2, TipoGrafo *grafo){

	for (int i = 0; i < grafo -> numVertices; i++){

		if (grafo -> listaAdj[v1] -> vdest == v2) return true;
		else return false;
	}
}

//Insere aresta no vetor
void insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo){

	
	if (existeAresta(v1, v2, grafo)) printf("Esta aresta ja existe\n");
	else{
		grafo -> listaAdj[v1] -> prox = grafo -> listaAdj[v2];
		grafo -> listaAdj[v1] -> peso = peso;
		grafo -> listaAdj[v1] -> vdest = v2;
		grafo -> numArestas++;
	}
	


}

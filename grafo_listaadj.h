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

typedef TipoAresta* TipoApontador;

typedef struct {
	TipoApontador *listaAdj;
	int numVertices;
	int numArestas;
} TipoGrafo;

//Initializing a Graph
bool inicializaGrafo(TipoGrafo * grafo, int nv){

	grafo -> numVertices = nv;
	grafo->numArestas=0;	
	grafo -> listaAdj = NULL;
	return true;
}

#define MAXNUMVERTICES 100 /* Sintaxe para definicao de valores fixos / variaveis estaticas */
#define AN -1 /* int used to represent the  */
#define VERTICE_INVALIDO -1 /* invalid node number */

#include <stdbool.h>
/* Its a default library used to handle boolean variables */

typedef int TipoPeso; /* Sintaxe para definição de tipos de variaveis */

typedef struct {
	TipoPeso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	int numVertices;
	int numArestas;
} TipoGrafo;

typedef int TipoApontador;

//Function responsible for initialize a graph
bool inicializaGrafo(TipoGrafo * grafo, int nv){
	
	//Verifying if the nv number is valid
	if(nv <= 0) {
		fprintf(stderr,"Erro na inicializacao do grafo! Numero de vertices deve ser positivo!\n");
		return false;
	}else if(nv > MAXNUMVERTICES){
		
		fprintf(stderr,"Erro na inicializacao do grafo! Numero de vertices maior do que o limite maximo!\n");
		return false;
	}else{
		grafo -> numVertices = nv;
		grafo -> numArestas = AN;

		int i,j;

		for (i = 0; i < nv; i++){
			for(j = 0; j<nv ; j++)
				grafo -> mat[i][j] = 0;
		}
	}
	return true;
}

bool insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo){
	
	if(!v1 || !v2){
		fprintf(stderr, "Erro! Indice de vertice invalido\n");
		return false;
	}else if(v1 == v2){
        fprintf(stderr, "Não é possível inserir loops.\n");
        return false;
    }else{
	grafo -> numArestas = 1;
	grafo -> mat[v1][v2] = peso;
	return true;
    }
}

bool existeAresta(int v1, int v2, TipoGrafo *grafo){

    if(!grafo->numArestas){
        fprintf(stderr,"Grafo nulo!\n");
        return false;
    }else if(grafo->numVertices==0 || grafo->numVertices==1){
        fprintf(stderr, "Grafo sem arestas!\n");
        return false;
    }else if(grafo->mat[v1][v2]){
        printf("Aresta encontrada! Peso=%d\n", grafo->mat[v1][v2]);
        return true;
    }else{
        printf("Aresta inexistente!\n");
        return false;
    }
}

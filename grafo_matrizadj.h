#define MAXNUMVERTICES 100 /* Sintaxe para definicao de valores fixos / variaveis estaticas */
#define AN -1 /* int used to represent the  */
#define VERTICE_INVALIDO -1 /* invalid node number */
#include<stdio.h>
#include <stdbool.h> /* Its a default library used to handle boolean variables */

FILE *stderr;

typedef int TipoPeso; /* Sintaxe para definição de tipos de variaveis */
typedef int TipoApontador;

typedef struct {
	TipoPeso mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	int numVertices;
	int numArestas;
} TipoGrafo;

//Function responsible for initialize a graph
bool inicializaGrafo(TipoGrafo * grafo, int nv){

    stderr = fopen("stderr.txt", "w+");

	//Verifying if the nv number is valid
	if(nv <= 0) {
		fprintf(stderr,"Erro na inicializacao do grafo! Numero de vertices deve ser positivo!\n");
		fclose(stderr);
		return false;
	}else if(nv > MAXNUMVERTICES){

		fprintf(stderr,"Erro na inicializacao do grafo! Numero de vertices maior do que o limite maximo!\n");
		fclose(stderr);
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

//Function responsible for insert an edge on a graph
bool insereAresta(int v1, int v2, TipoPeso peso, TipoGrafo *grafo){

    stderr = fopen("stderr.txt", "w+");

	if(!v1 || !v2){
		fprintf(stderr, "Erro! Indice de vertice invalido\n");
		fclose(stderr);
		return false;
	}else if(v1 == v2){
        fprintf(stderr, "Não é possível inserir loops.\n");
        fclose(stderr);
        return false;
    }else{
	grafo -> numArestas = 1;
	grafo -> mat[v1][v2] = peso;
	return true;
    }
}

//Function responsible for verify if an edge exists
bool existeAresta(int v1, int v2, TipoGrafo *grafo){

    if(!grafo->numArestas){
        fprintf(stderr,"Grafo nulo!\n");
        fclose(stderr);
        return false;
    }else if(grafo->numVertices==0 || grafo->numVertices==1){
        fprintf(stderr, "Grafo sem arestas!\n");
        fclose(stderr);
        return false;
    }else if(grafo->mat[v1][v2]){
        printf("Aresta encontrada! Peso=%d\n", grafo->mat[v1][v2]);
        return true;
    }else{
        printf("Aresta inexistente!\n");
        fclose(stderr);
        return false;
    }
}

//Function responsible for remove an edge
bool removeAresta(int v1, int v2, TipoGrafo *grafo){

    stderr = fopen("stderr.txt", "w+");

    if (v1 == 0 || v2 == 0 || v1 < 0 || v2 < 0){

        fprintf(stderr, "Erro! Número de vértice inválido. Verifique! V1= %d, V2=%d\n", v1, v2);
        printf("Erro! Número de vértice inválido. Verifique! V1= %d, V2=%d\n", v1, v2);
        fclose(stderr);
        return false;

    }else if(v1 > grafo ->numVertices || v2 > grafo ->numVertices){

        fprintf(stderr, "Erro! Vértice não encontrado. Verifique! V1= %d, V2=%d\n", v1, v2);
        printf("Erro! Vértice não encontrado. Verifique! V1= %d, V2=%d\n", v1, v2);
        fclose(stderr);
        return false;

    }else {

        grafo -> mat[v1][v2] = 0;
        grafo -> numArestas--;

    }

    return true;

}


//Function responsible for verify the adjacency
bool listaAdjVazia(TipoGrafo *grafo){

    int counter, i, j;
    counter = 0; //OBS: Sempre incialize as variaveis

    for(i = 0; i < grafo->numVertices; i++){

        for (j = 0; j < grafo->numVertices; j++){

            if (grafo->mat[i][j] != 0) counter++;
        }
    }
    if (counter != 0){
	    return false;
    } else return true;

}


//Print the adjacency matrix
void imprimeMatriz(TipoGrafo *grafo){

    int i, j;

    for(i = 0; i <= grafo->numVertices; i++){

        for(j = 0; j <= grafo->numVertices; j++){

            printf("%d\t", grafo->mat[i][j]);
        }

        printf("\n");
    }

}

//Return the first element of the adjacency list
TipoApontador primeiroListaAdj(int v, TipoGrafo *grafo){
	
	int i;

	for(i = 0; i < grafo->numVertices; i++){
	
		if (grafo->mat[v][i] != 0) return i;
	}
	if (i > grafo->numVertices) return -1;
}

//Return the next element of the adjacency list
TipoApontador proxListaAdj(int v, TipoGrafo *grafo, TipoApontador atual){
	
	int i;

	for(i = atual + 1; i < grafo->numVertices; i++){
	
		if (grafo->mat[v][i] != 0) return i;
	}
	if (i > grafo->numVertices) return -1;
}


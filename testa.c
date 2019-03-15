#include <stdio.h>
#include<stdlib.h>
#include "grafo_matrizadj.h"

int main(){

	TipoGrafo grafo;
	int nv, v1, v2, peso;
	//FILE *stderr;



	//printf("Entre com o numero de vertices do grafo:");
	//scanf("%d", &nv);

	if(inicializaGrafo(&grafo,5)) printf("Grafo criado!\n");

	//printf("Entre com os vertices e o peso da aresta:");
	//scanf("%d %d %d", &v1, &v2, &peso);

	if(insereAresta(1,2,3,&grafo)) printf("Aresta inserida: (%d,%d)=%d\n", v1,v2,peso);

	if(insereAresta(1,5,2,&grafo)) printf("Aresta inserida: (%d,%d)=%d\n", v1,v2,peso);
   	 //printf("%d\n",grafo.mat[1][2]);

	 imprimeMatriz(&grafo);

	 if(listaAdjVazia(&grafo)){

	 printf("Lista adj vazia\n");

	 } else printf("Lista não vazia\n");
    
    	
	printf("Primeiro adj a 1 eh: %d\n Primeiro adj a 2 eh: %d\n", primeiroListaAdj(1,&grafo), primeiroListaAdj(2,&grafo));

	printf("O vertice seguinte a 2 eh %d\n", proxListaAdj(1,&grafo,2)); 
	return 0;

}

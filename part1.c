#include <stdio.h>
#include<stdlib.h>
#include "grafo_matrizadj.h"

int main(){
	
	TipoGrafo grafo;
	int nv, v1, v2, peso;

	printf("Entre com o numero de vertices do grafo:");
	scanf("%d", &nv);

	if(inicializaGrafo(&grafo,nv)) printf("Grafo criado!\n");
	
	printf("Entre com os vertices e o peso da aresta:");
	scanf("%d %d %d", &v1, &v2, &peso);

	if(insereAresta(v1,v2,peso,&grafo)) printf("Aresta inserida: (%d,%d)=%d\n", v1,v2,peso);
	
	    
    existeAresta(v1,4,&grafo);

	return 0;

}
